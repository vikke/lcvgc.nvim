--- lcvgc 文法チュートリアルモジュール
--- 新規 .cvg ファイルに、lcvgc デーモンの tutorial リクエストで取得した文法チュートリアルを挿入する。
--- チュートリアルは lcvgc の各パーサが持つ構文ドキュメントから生成され、例文はパーサで検証済み。
--- 未接続のときは挿入を保留し、接続した時点でバッファがまだ空・未編集なら挿入する。
---
--- Grammar tutorial module. Inserts the tutorial fetched with the daemon's
--- `tutorial` request into new .cvg files. When not connected, insertion is
--- deferred until a connection is made (only if the buffer is still empty and unmodified).
local M = {}

local connection = require('lcvgc.connection')

--- 接続後にチュートリアルを入れる予定のバッファ（bufnr -> true）
--- Buffers waiting for the tutorial until a connection is made (bufnr -> true)
local pending = {}

--- LANG 環境変数を取得する（テスト時に差し替え可能）
--- @return string|nil LANG 環境変数の値 / value of LANG
function M._get_lang()
  return os.getenv('LANG')
end

--- チュートリアルの言語コードを返す（LANG が ja で始まれば ja、それ以外は en）
--- @return string 'ja' または 'en' / 'ja' or 'en'
function M.lang()
  local lang = M._get_lang()
  if lang and lang:sub(1, 2) == 'ja' then
    return 'ja'
  end
  return 'en'
end

--- 本文を行テーブルに分割する（空行を保ち、末尾の改行 1 つは行にしない）
--- Splits text into lines, keeping blank lines; a single trailing newline adds no line.
--- @param text string チュートリアル本文 / tutorial text
--- @return string[] 行テーブル / lines
function M.split_lines(text)
  if text:sub(-1) == '\n' then
    text = text:sub(1, -2)
  end
  local lines = {}
  local start = 1
  while true do
    local nl = text:find('\n', start, true)
    if not nl then
      table.insert(lines, text:sub(start))
      break
    end
    table.insert(lines, text:sub(start, nl - 1))
    start = nl + 1
  end
  return lines
end

--- デーモンにチュートリアルを問い合わせる
--- Requests the tutorial from the daemon.
--- @param callback fun(lines: string[]) 取得した行テーブルを受け取る関数 / receives the lines
--- @return boolean リクエストを送れたら true、未接続なら false / true if sent, false if not connected
function M.fetch(callback)
  if not connection.is_connected() then
    return false
  end
  connection.request({ type = 'tutorial', lang = M.lang() }, function(msg)
    if msg.lsp and msg.lsp.type == 'tutorial' then
      callback(M.split_lines(msg.lsp.text or ''))
      return true
    end
    return false
  end)
  return true
end

--- バッファが空かつ未編集か判定する（チュートリアルで上書きしてよい状態か）
--- Whether the buffer is valid, empty and unmodified (safe to fill with the tutorial).
--- @param bufnr number バッファ番号 / buffer number
--- @return boolean 上書きしてよければ true / true if safe to fill
function M.is_pristine(bufnr)
  if not vim.api.nvim_buf_is_valid(bufnr) then
    return false
  end
  if vim.bo[bufnr].modified then
    return false
  end
  local lines = vim.api.nvim_buf_get_lines(bufnr, 0, -1, false)
  return #lines == 0 or (#lines == 1 and lines[1] == '')
end

--- 空のバッファにチュートリアルを入れる（応答時にもまだ空・未編集の場合だけ）
--- Fills an empty buffer with the tutorial, re-checking emptiness when the reply arrives.
--- @param bufnr number バッファ番号 / buffer number
local function fill_if_pristine(bufnr)
  if not M.is_pristine(bufnr) then
    return
  end
  M.fetch(function(lines)
    if M.is_pristine(bufnr) then
      vim.api.nvim_buf_set_lines(bufnr, 0, -1, false, lines)
      vim.bo[bufnr].modified = false
    end
  end)
end

--- 新規 .cvg バッファが作られたときに呼ぶ（BufNewFile）
--- 接続中ならすぐ挿入し、未接続なら接続後に挿入するよう保留する。
--- Call on BufNewFile: inserts now if connected, otherwise defers until connected.
--- @param bufnr number バッファ番号 / buffer number
function M.on_new_file(bufnr)
  if connection.is_connected() then
    fill_if_pristine(bufnr)
  else
    pending[bufnr] = true
  end
end

--- デーモンに接続したときに呼ぶ。保留中のバッファがまだ空・未編集ならチュートリアルを入れる
--- Call after connecting: fills deferred buffers that are still empty and unmodified.
function M.on_connected()
  local bufs = pending
  pending = {}
  for bufnr in pairs(bufs) do
    fill_if_pristine(bufnr)
  end
end

--- カーソル行の下にチュートリアルを挿入する（:LcvgcTutorial）
--- Inserts the tutorial below the cursor line (:LcvgcTutorial).
--- @return boolean リクエストを送れたら true、未接続なら警告して false
---                 true if sent; false (with a warning) if not connected
function M.insert_at_cursor()
  local bufnr = vim.api.nvim_get_current_buf()
  local row = vim.api.nvim_win_get_cursor(0)[1]
  local sent = M.fetch(function(lines)
    if vim.api.nvim_buf_is_valid(bufnr) then
      vim.api.nvim_buf_set_lines(bufnr, row, row, false, lines)
    end
  end)
  if not sent then
    vim.notify('lcvgc: engine not connected (run :LcvgcConnect first)', vim.log.levels.WARN)
  end
  return sent
end

return M
