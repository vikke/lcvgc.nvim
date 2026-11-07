-- 文法チュートリアルの headless E2E テスト（実デーモン使用）。
-- 起動中の lcvgc デーモンに接続し、新規 .cvg への自動挿入・接続後の挿入・
-- :LcvgcTutorial によるカーソル位置への挿入を、プラグインの setup 経由で検証する。
--
-- Headless E2E test for the grammar tutorial against a running lcvgc daemon.
-- Verifies, through the plugin's setup, automatic insertion into new .cvg files,
-- deferred insertion after connecting, and :LcvgcTutorial insertion at the cursor.
--
-- 事前にデーモンを起動しておく / Start the daemon first:
--   ../lcvgc/target/release/lcvgc &
-- 実行 / Run:
--   LANG=ja_JP.UTF-8 nvim --headless -u NONE +"luafile tests/e2e/tutorial_e2e.lua"
-- ポートは LCVGC_E2E_PORT（省略時 5555）/ port: LCVGC_E2E_PORT (default 5555)

-- プロジェクトの lua/ を package.path に追加
-- Add the project's lua/ to package.path
package.path = './lua/?.lua;./lua/?/init.lua;' .. package.path

-- デーモンのポート / daemon port
local PORT = tonumber(os.getenv('LCVGC_E2E_PORT') or '') or 5555
-- 失敗したテスト名 / names of failed checks
local failures = {}

--- 結果を表示し、失敗を記録する / print a result and record failures
--- @param name string テスト名 / check name
--- @param ok boolean 成否 / result
--- @param detail string|nil 失敗時の補足 / detail on failure
local function check(name, ok, detail)
  if ok then
    print('  ok - ' .. name)
  else
    print('  FAIL - ' .. name .. (detail and ('  (' .. detail .. ')') or ''))
    table.insert(failures, name)
  end
end

--- 条件が満たされるまで待つ（デーモンの応答を受け取る）/ wait until cond() holds
--- @param cond fun(): boolean 待つ条件 / condition
--- @return boolean 時間内に満たされたら true / true if satisfied in time
local function wait_for(cond)
  return vim.wait(3000, cond, 20)
end

--- 存在しない新規ファイルのパスを作る / make a path for a file that does not exist
--- @param name string ファイル名 / file name
--- @return string パス / path
local function new_path(name)
  local dir = vim.fn.tempname()
  vim.fn.mkdir(dir, 'p')
  return dir .. '/' .. name
end

--- 現在のバッファの全文 / full text of the current buffer
local function buf_text()
  return table.concat(vim.api.nvim_buf_get_lines(0, 0, -1, false), '\n')
end

-- 期待する見出し（LANG に応じて日英）/ expected header depending on LANG
local tutorial = require('lcvgc.tutorial')
local header = tutorial.lang() == 'ja' and 'lcvgc DSL チュートリアル' or 'lcvgc DSL tutorial'

-- プラグインを起動（auto_connect でデーモンに接続）
-- Start the plugin (auto_connect connects to the daemon)
local ok, err = pcall(function()
  require('lcvgc').setup({ port = PORT, auto_connect = true, auto_layout = false })
end)
check('setup succeeds', ok, tostring(err))
local connection = require('lcvgc.connection')
check('connected to daemon on port ' .. PORT, connection.is_connected())

-- 1) 接続中に新規 .cvg を開くと、チュートリアルが入り、未変更扱いになる
-- Opening a new .cvg while connected inserts the tutorial, unmodified
vim.cmd('edit ' .. new_path('new1.cvg'))
local filled = wait_for(function() return buf_text():find(header, 1, true) ~= nil end)
check('new .cvg is filled with the tutorial', filled, buf_text():sub(1, 80))
check('filled buffer is not modified', not vim.bo.modified)
check('tutorial contains parser-checked examples', buf_text():find('\ntempo 120\n', 1, true) ~= nil)

-- 2) 未接続で開いた新規 .cvg は空のまま。:LcvgcConnect 後に入る
-- A new .cvg opened while disconnected stays empty, then is filled after :LcvgcConnect
connection.disconnect()
vim.cmd('edit ' .. new_path('new2.cvg'))
vim.wait(200, function() return false end, 20)
check('new .cvg stays empty while disconnected', buf_text() == '', buf_text():sub(1, 80))
vim.cmd('LcvgcConnect ' .. PORT)
filled = wait_for(function() return buf_text():find(header, 1, true) ~= nil end)
check('deferred tutorial is inserted after :LcvgcConnect', filled, buf_text():sub(1, 80))

-- 3) :LcvgcTutorial は既存の内容を残したまま、カーソル行の下に挿入する
-- :LcvgcTutorial inserts below the cursor line, keeping existing content
vim.cmd('enew')
vim.api.nvim_buf_set_lines(0, 0, -1, false, { 'tempo 90', 'scale c_major' })
vim.api.nvim_win_set_cursor(0, { 1, 0 })
vim.cmd('LcvgcTutorial')
filled = wait_for(function() return buf_text():find(header, 1, true) ~= nil end)
local lines = vim.api.nvim_buf_get_lines(0, 0, -1, false)
check(':LcvgcTutorial inserts the tutorial', filled)
check(':LcvgcTutorial keeps the line above', lines[1] == 'tempo 90', lines[1])
check(':LcvgcTutorial inserts right below the cursor', lines[2]:find('^// =+') ~= nil, lines[2])
check(':LcvgcTutorial keeps the line below at the end', lines[#lines] == 'scale c_major', lines[#lines])

connection.disconnect()
print(#failures == 0 and 'ALL PASSED' or (#failures .. ' FAILED'))
vim.cmd(#failures == 0 and 'qa!' or 'cq!')
