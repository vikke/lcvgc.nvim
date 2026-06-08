-- MIDI 入力イベントの headless E2E テスト。
-- デーモン実機や MIDI ハードウェア無しで、ダミーのイベント行を
-- connection._on_data に流し込み、バッファ挿入・push/response 判別・
-- 部分行の結合を検証する。
--
-- Headless E2E test for MIDI input events. Without a real daemon or MIDI
-- hardware, it feeds dummy event lines into connection._on_data and verifies
-- buffer insertion, push/response discrimination, and partial-line joining.
--
-- 実行 / Run:
--   nvim --headless -u NONE +"luafile tests/e2e/midi_in_e2e.lua"

-- プロジェクトの lua/ を package.path に追加
-- Add the project's lua/ to package.path
package.path = './lua/?.lua;./lua/?/init.lua;' .. package.path

local failures = {}
local function check(name, ok, detail)
  if ok then
    print('  ok - ' .. name)
  else
    print('  FAIL - ' .. name .. (detail and ('  (' .. detail .. ')') or ''))
    table.insert(failures, name)
  end
end

-- vim.schedule（connection と insert_dsl の二重スケジュール）を消化する
-- Drain pending vim.schedule callbacks (connection + insert_dsl double-schedule)
local function flush()
  vim.wait(50, function() return false end)
end

local connection = require('lcvgc.connection')
local midi_in = require('lcvgc.midi_in')

-- midi_in_event ハンドラを登録する
-- Register the midi_in_event handler
midi_in.setup()

-- カーソル位置から挿入するためのスクラッチバッファを用意
-- Prepare a scratch buffer to insert at the cursor
vim.cmd('enew')
vim.api.nvim_buf_set_lines(0, 0, -1, false, { '' })
vim.api.nvim_win_set_cursor(0, { 1, 0 })

local function current_line()
  return vim.api.nvim_buf_get_lines(0, 0, 1, false)[1]
end

-- 1) 完全なイベント行 -> "c:4 " が挿入される
-- Full event line -> inserts "c:4 "
connection._on_data({ '{"type":"midi_in_event","dsl":"c:4","note":60,"raw":[144,60,100]}\n' })
flush()
check('full event line inserts "c:4 "', current_line() == 'c:4 ', 'got: [' .. current_line() .. ']')

-- 2) push/response 判別: success 応答（type 無し）はバッファに挿入されない
-- push/response discrimination: a success response (no type) is NOT inserted
connection._on_data({ '{"success":true,"message":"subscribed: X"}\n' })
flush()
check('response line is not inserted', current_line() == 'c:4 ', 'got: [' .. current_line() .. ']')

-- 3) 部分行の結合: イベント JSON を2チャンクに分割して送る
-- partial-line joining: split the event JSON across two chunks
connection._on_data({ '{"type":"midi_in_event","ds' })
flush()
check('partial line not yet inserted', current_line() == 'c:4 ', 'got: [' .. current_line() .. ']')
connection._on_data({ 'l":"e:4"}\n' })
flush()
check('partial line joins and inserts "e:4 "', current_line() == 'c:4 e:4 ', 'got: [' .. current_line() .. ']')

-- 4) 複数トークンがスペース区切りで並ぶ
-- multiple tokens line up space-separated
connection._on_data({ '{"type":"midi_in_event","dsl":"g:4","note":67}\n' })
flush()
check('tokens line up as "c:4 e:4 g:4 "', current_line() == 'c:4 e:4 g:4 ', 'got: [' .. current_line() .. ']')

-- 5) dsl の無いイベントは挿入しない
-- an event without dsl is not inserted
connection._on_data({ '{"type":"midi_in_event","note":60}\n' })
flush()
check('event without dsl inserts nothing', current_line() == 'c:4 e:4 g:4 ', 'got: [' .. current_line() .. ']')

print('')
if #failures == 0 then
  print('E2E: all checks passed')
  vim.cmd('qall!')
else
  print('E2E: ' .. #failures .. ' check(s) failed')
  vim.cmd('cquit 1')
end
