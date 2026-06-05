local connection = require('lcvgc.connection')
local flash = require('lcvgc.flash')

local M = {}

M._last_source_map = nil

-- ブロックを開く予約語 (device|instrument|kit|clip|scene|session NAME [...] { ... })
-- Block-opening keywords
local BLOCK_KEYWORDS = {
  device = true,
  instrument = true,
  kit = true,
  clip = true,
  scene = true,
  session = true,
}

-- トップレベルの単独行ステートメント
-- Top-level single-line statements
local SINGLE_LINE_KEYWORDS = {
  tempo = true,
  scale = true,
  include = true,
  play = true,
  stop = true,
}

-- 行コメント (//) を除去
-- Strip // line comments
local function strip_comment(line)
  local idx = line:find('//', 1, true)
  if idx then
    return line:sub(1, idx - 1)
  end
  return line
end

-- 行頭の最初の識別子（予約語候補）を取得
-- Return the leading identifier on the line, if any
local function leading_keyword(line)
  return strip_comment(line):match('^%s*([%a_][%w_]*)')
end

-- 行中の { } を順に列挙（コメント除去後）
-- Iterate over braces on a line, after stripping comments
local function iter_braces(line)
  local stripped = strip_comment(line)
  return stripped:gmatch('[{}]')
end

function M.read_file(path)
  local f = io.open(path, 'r')
  if not f then
    return nil, 'Cannot read file: ' .. path
  end
  local content = f:read('*a')
  f:close()
  local lines = {}
  for line in (content .. '\n'):gmatch('(.-)\n') do
    table.insert(lines, line)
  end
  -- 末尾の空行を除去（最後の\nで生成される空文字列）
  if #lines > 0 and lines[#lines] == '' then
    table.remove(lines)
  end
  return lines, nil
end

function M.expand_includes(lines, filepath, base_dir, visited)
  visited = visited or {}
  local result = {}
  local source_map = {}

  for i, line in ipairs(lines) do
    -- 引用符なし構文: include の後から行末コメント（//）の前までをパスとして取得
    local include_path = line:match('^%s*include%s+(.-)%s*$')
    if include_path then
      -- 行末コメントを除去
      include_path = include_path:match('^(.-)%s*//')  or include_path
      -- 前後の空白をトリム
      include_path = include_path:match('^%s*(.-)%s*$')
      if include_path == '' then
        include_path = nil
      end
    end
    if include_path then
      local full_path = base_dir .. '/' .. include_path
      -- 正規化（簡易）
      local normalized = vim.fn.fnamemodify(full_path, ':p')

      if visited[normalized] then
        -- 重複include: スキップ
      else
        visited[normalized] = true
        local inc_lines, err = M.read_file(full_path)
        if not inc_lines then
          return nil, nil, err .. ' (included from ' .. filepath .. ':' .. i .. ')'
        end
        local inc_dir = full_path:match('(.+)/') or base_dir
        local expanded, sub_map, sub_err = M.expand_includes(inc_lines, full_path, inc_dir, visited)
        if sub_err then
          return nil, nil, sub_err
        end
        for _, el in ipairs(expanded) do
          table.insert(result, el)
        end
        for _, sm in ipairs(sub_map) do
          table.insert(source_map, sm)
        end
      end
    else
      table.insert(result, line)
      table.insert(source_map, { file = filepath, line = i })
    end
  end

  return result, source_map, nil
end

--- トップレベルの play / stop 行を除外する純粋関数
--- Pure function that strips top-level play / stop lines
--- 接続時の自動 eval で再生制御を送らないために使う。
--- インデントされた行（ブロック内）やコメント行 (// play ...) は除外しない。
--- playback / stopwatch のような語頭一致は除外しない（play/stop の後は行末か空白）。
--- @param lines string[] 入力行リスト（破壊しない）
--- @return string[] play / stop 行を除いた新しい行リスト
function M.strip_playback_controls(lines)
  local result = {}
  for _, line in ipairs(lines) do
    -- 行頭インデントなしの play / stop（後続は行末または空白）のみ除外
    if line:match('^play%s') or line == 'play'
      or line:match('^stop%s') or line == 'stop' then
      -- 再生制御行: 除外
    else
      table.insert(result, line)
    end
  end
  return result
end

--- 接続時用: 現在のバッファを include 展開し、
--- トップレベルの play / stop を除いた定義のみを eval 送信する
--- Expands includes of the current buffer and sends only definitions
--- (top-level play / stop lines are excluded) as an eval message.
--- 接続しただけで勝手に再生・停止しないようにするため。
--- @return nil
function M.eval_definitions()
  local bufnr = vim.api.nvim_get_current_buf()
  local filepath = vim.api.nvim_buf_get_name(bufnr)
  local line_count = vim.api.nvim_buf_line_count(bufnr)
  local lines = vim.api.nvim_buf_get_lines(bufnr, 0, line_count, false)
  local base_dir = vim.fn.fnamemodify(filepath, ':h')

  local expanded, source_map, err = M.expand_includes(lines, filepath, base_dir, {})
  if err then
    vim.notify('lcvgc: ' .. err, vim.log.levels.ERROR)
    return
  end

  M._last_source_map = source_map
  local filtered = M.strip_playback_controls(expanded)
  local text = table.concat(filtered, '\n')
  flash.flash_range(bufnr, 1, line_count)
  connection.send({ type = 'eval', source = text })
end

function M.eval_file()
  local bufnr = vim.api.nvim_get_current_buf()
  local filepath = vim.api.nvim_buf_get_name(bufnr)
  local line_count = vim.api.nvim_buf_line_count(bufnr)
  local lines = vim.api.nvim_buf_get_lines(bufnr, 0, line_count, false)
  local base_dir = vim.fn.fnamemodify(filepath, ':h')

  local expanded, source_map, err = M.expand_includes(lines, filepath, base_dir, {})
  if err then
    vim.notify('lcvgc: ' .. err, vim.log.levels.ERROR)
    return
  end

  M._last_source_map = source_map
  local text = table.concat(expanded, '\n')
  flash.flash_range(bufnr, 1, line_count)
  connection.send({ type = 'eval', source = text })
end

function M.eval_selection()
  local start_line = vim.fn.line("'<")
  local end_line = vim.fn.line("'>")
  local lines = vim.api.nvim_buf_get_lines(0, start_line - 1, end_line, false)
  local text = table.concat(lines, '\n')
  flash.flash_range(0, start_line, end_line)
  connection.send({ type = 'eval', source = text })
end

-- start_row から } まで前向きにスキャンして閉じ位置を返す
-- Forward-scan from start_row to find the matching closing brace
local function scan_block_end(lines, start_row)
  local depth = 0
  local opened = false
  for j = start_row, #lines do
    for c in iter_braces(lines[j] or '') do
      if c == '{' then
        depth = depth + 1
        opened = true
      else
        depth = depth - 1
      end
    end
    if opened and depth <= 0 then
      return j
    end
  end
  return nil
end

-- カーソル位置 (row, 1-indexed) を含む評価ブロックの (start, end) を返す。
-- 評価ブロックは:
--   1. device/instrument/kit/clip/scene/session のブロック全体（ヘッダ + プロパティ + 本体）
--   2. トップレベルの単独行ステートメント (tempo / scale / include / play / stop)
--
-- Return the (start, end) range of the evaluation block containing row.
-- An evaluation block is either:
--   1. A full device/instrument/kit/clip/scene/session block (header + properties + body)
--   2. A top-level single-line statement (tempo / scale / include / play / stop)
function M.find_block_at_row(lines, row)
  if row < 1 or row > #lines then
    return nil
  end

  -- カーソル行直前までのブレース深度と、深度0→1に遷移したブロック開始行を追跡
  -- Track brace depth up to the cursor line and the row that opened the outermost block
  local depth = 0
  local block_start = nil
  for i = 1, row - 1 do
    for c in iter_braces(lines[i] or '') do
      if c == '{' then
        if depth == 0 then
          block_start = i
        end
        depth = depth + 1
      else
        depth = depth - 1
        if depth <= 0 then
          depth = 0
          block_start = nil
        end
      end
    end
  end

  if depth > 0 and block_start then
    local end_row = scan_block_end(lines, block_start)
    if end_row then
      return block_start, end_row
    end
    return nil
  end

  -- トップレベル: カーソル行の予約語で判定
  -- Top level: dispatch by the leading keyword of the cursor line
  local kw = leading_keyword(lines[row] or '')
  if not kw then
    return nil
  end
  if BLOCK_KEYWORDS[kw] then
    local end_row = scan_block_end(lines, row)
    if end_row then
      return row, end_row
    end
    return nil
  end
  if SINGLE_LINE_KEYWORDS[kw] then
    return row, row
  end
  return nil
end

function M.eval_block()
  local bufnr = vim.api.nvim_get_current_buf()
  local row = vim.api.nvim_win_get_cursor(0)[1]
  local line_count = vim.api.nvim_buf_line_count(bufnr)
  local lines = vim.api.nvim_buf_get_lines(bufnr, 0, line_count, false)

  local start_line, end_line = M.find_block_at_row(lines, row)
  if not start_line then
    vim.notify('lcvgc: no block at cursor', vim.log.levels.WARN)
    return
  end

  local block_lines = {}
  for i = start_line, end_line do
    table.insert(block_lines, lines[i])
  end
  local text = table.concat(block_lines, '\n')
  flash.flash_range(bufnr, start_line, end_line)
  connection.send({ type = 'eval', source = text })
end

return M
