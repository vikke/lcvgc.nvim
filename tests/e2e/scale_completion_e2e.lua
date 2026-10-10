-- scale 補完（`<root>_<type>` 単一トークン）の headless E2E テスト。
-- 実デーモン（lcvgc）を空きポートで起動し、lcvgc.lsp.completion の cmp ソース経由で
-- `scale c` / `[scale cs` の位置の補完候補を取得して検証する。
--
-- Headless E2E test for scale completion (single `<root>_<type>` token).
-- Spawns a real lcvgc daemon on a spare port and fetches completion items at
-- `scale c` / `[scale cs` through the lcvgc.lsp.completion cmp source.
--
-- 実行 / Run:
--   LCVGC_BIN=/path/to/lcvgc nvim --headless -u NONE +"luafile tests/e2e/scale_completion_e2e.lua"
-- LCVGC_BIN 未指定時は PATH 上の `lcvgc` を使う。見つからなければ SKIP（exit 0）。
-- Without LCVGC_BIN, `lcvgc` on PATH is used; if absent the test is SKIPPED (exit 0).

-- プロジェクトの lua/ を package.path に追加
-- Add the project's lua/ to package.path
package.path = './lua/?.lua;./lua/?/init.lua;' .. package.path

--- デーモンのバイナリパス / daemon binary path
local bin = os.getenv('LCVGC_BIN') or 'lcvgc'
if vim.fn.executable(bin) ~= 1 then
  print('SKIP: lcvgc daemon binary not found (' .. bin .. ')')
  vim.cmd('qall!')
  return
end

--- テスト用ポート（既定 5555 と衝突させない）/ test port (avoid default 5555)
local port = tonumber(os.getenv('LCVGC_E2E_PORT') or '') or 15931

local failures = {}
local function check(name, ok, detail)
  if ok then
    print('  ok - ' .. name)
  else
    print('  FAIL - ' .. name .. (detail and ('  (' .. detail .. ')') or ''))
    table.insert(failures, name)
  end
end

--- 終了処理（デーモン停止・結果出力）/ teardown (stop daemon, print result)
local daemon_job
local function finish()
  if daemon_job then
    vim.fn.jobstop(daemon_job)
  end
  print('')
  if #failures == 0 then
    print('E2E: all checks passed')
    vim.cmd('qall!')
  else
    print('E2E: ' .. #failures .. ' check(s) failed')
    vim.cmd('cquit 1')
  end
end

-- デーモン起動 / spawn the daemon
daemon_job = vim.fn.jobstart({ bin, '--port', tostring(port), '--log-level', 'error' })
check('daemon started', daemon_job > 0, 'jobstart returned ' .. tostring(daemon_job))

-- notify はテスト出力を汚さないよう黙らせる / silence notifications
vim.notify = function() end

local connection = require('lcvgc.connection')
-- 起動直後は接続拒否で sockconnect が error を投げるため pcall で再試行する
-- sockconnect raises "connection refused" until the daemon listens; retry via pcall
local connected = vim.wait(5000, function()
  local ok, res = pcall(connection.connect, port, function() end)
  return ok and res
end, 100)
check('connected to daemon', connected)
if not connected then
  finish()
  return
end

local completion = require('lcvgc.lsp.completion')
local src = completion.new()

--- 指定行・列で補完を要求し、ラベル集合を返す
--- Request completion at the given line/column and return the label set.
--- @param lines string[] バッファ内容 / buffer lines
--- @param row number カーソル行（1始まり）/ cursor row (1-based)
--- @param col number カーソル列（0始まり、バイト）/ cursor col (0-based byte)
--- @return table<string, string>|nil ラベル -> detail。タイムアウト時 nil / label -> detail, nil on timeout
local function complete_at(lines, row, col)
  vim.api.nvim_buf_set_lines(0, 0, -1, false, lines)
  vim.api.nvim_win_set_cursor(0, { row, col })
  local result
  src:complete({}, function(res) result = res end)
  vim.wait(3000, function() return result ~= nil end, 20)
  if not result then
    return nil
  end
  local labels = {}
  for _, item in ipairs(result.items) do
    labels[item.label] = item.detail or ''
  end
  return labels
end

--- ラベル集合に `#` を含むものがあるか / whether any label contains `#`
--- @param labels table<string, string>
--- @return string|nil 最初に見つかった `#` 付きラベル / first label containing `#`
local function find_sharp_hash(labels)
  for label in pairs(labels) do
    if label:find('#', 1, true) then
      return label
    end
  end
  return nil
end

--- `_` を含むラベルの件数 / number of labels containing `_`
--- @param labels table<string, string>
--- @return number
local function count_scale_tokens(labels)
  local n = 0
  for label in pairs(labels) do
    if label:match('^[a-g][bs]?_') then
      n = n + 1
    end
  end
  return n
end

vim.cmd('enew')

-- 1) グローバル `scale c` の直後（末尾スペースの位置 = 'c' の直後）
-- 1) right after global `scale c` (cursor on trailing space = just after 'c')
local g = complete_at({ 'scale c ' }, 1, 7)
check('global: response received', g ~= nil)
if g then
  check('global: c_major offered', g['c_major'] ~= nil)
  check('global: cs_minor offered', g['cs_minor'] ~= nil)
  check('global: eb_harmonic_minor offered', g['eb_harmonic_minor'] ~= nil)
  check('global: cs_minor detail', g['cs_minor'] == 'C# ナチュラルマイナー', 'got: ' .. tostring(g['cs_minor']))
  local hash = find_sharp_hash(g)
  check('global: no c#_ style label', hash == nil, 'found: ' .. tostring(hash))
  check('global: 153 scale tokens', count_scale_tokens(g) == 153, 'got: ' .. count_scale_tokens(g))
  check('global: legacy root-only "c" not offered', g['c'] == nil)
end

-- 2) clip ヘッダ `[scale cs` の直後
-- 2) right after clip header `[scale cs`
local line = 'clip x [scale cs ] {'
local c = complete_at({ line, '}' }, 1, #'clip x [scale cs')
check('clip: response received', c ~= nil)
if c then
  check('clip: cs_minor offered', c['cs_minor'] ~= nil)
  check('clip: c_major offered', c['c_major'] ~= nil)
  local hash = find_sharp_hash(c)
  check('clip: no c#_ style label', hash == nil, 'found: ' .. tostring(hash))
  check('clip: 153 scale tokens', count_scale_tokens(c) == 153, 'got: ' .. count_scale_tokens(c))
end

finish()
