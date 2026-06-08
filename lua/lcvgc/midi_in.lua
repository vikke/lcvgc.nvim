--- MIDI 入力イベント (midi_in_event) の購読とバッファ挿入を担うモジュール。
--- デーモンに MIDI in を繋いで鍵盤を弾くと、演奏内容が DSL トークン (例 c:4) として
--- 届き、カレントバッファのカーソル位置に挿入される。
--- Module that subscribes to MIDI input events (midi_in_event) and inserts
--- them into the buffer. When a keyboard is played on the daemon's MIDI in,
--- each note arrives as a DSL token (e.g. c:4) and is inserted at the cursor.
local connection = require('lcvgc.connection')

local M = {}

-- 購読中の入力ポート名（未購読なら nil）。
-- 1接続1購読。再 subscribe で張り替える（多重購読しない）。
-- Currently subscribed input port name (nil if not subscribed).
-- One subscription per connection; re-subscribing replaces it.
M._subscribed_port = nil

-- トークン区切り文字。各トークンの後ろに付与し c:4 e:4 g:4 のように並べる。
-- Token separator appended after each token, producing c:4 e:4 g:4.
local SEPARATOR = ' '

--- dsl トークンをカーソル位置に挿入する（区切りスペース付与）。
--- イベントは別スレッド/イベントループ由来になり得るため、
--- vim.schedule でメインループへ載せてからバッファ操作する。
--- Insert a dsl token at the cursor (with a trailing separator).
--- Events may originate off the main loop, so schedule onto it before editing.
--- @param dsl string 挿入するトークン（例 "c:4"）/ token to insert (e.g. "c:4")
function M.insert_dsl(dsl)
  vim.schedule(function()
    vim.api.nvim_put({ dsl .. SEPARATOR }, 'c', true, true)
  end)
end

--- midi_in_event を受信したときの処理：dsl をカーソル位置に挿入する。
--- Handle a received midi_in_event: insert its dsl at the cursor position.
--- @param msg table { type='midi_in_event', dsl=string, note=number, raw=table }
function M._on_midi_in_event(msg)
  if type(msg) ~= 'table' or type(msg.dsl) ~= 'string' or msg.dsl == '' then
    return
  end
  M.insert_dsl(msg.dsl)
end

--- 現在購読中かどうかを返す
--- Return whether a subscription is currently active
--- @return boolean
function M.is_subscribed()
  return M._subscribed_port ~= nil
end

--- 指定した入力ポートを購読する。多重購読しないよう、既存購読は張り替える。
--- Subscribe to the given input port. Re-subscribes (single subscription only).
--- @param port string 入力ポート名 / input port name
function M.subscribe(port)
  if type(port) ~= 'string' or port == '' then
    vim.notify('lcvgc: midi-in port name required', vim.log.levels.WARN)
    return
  end
  connection.request({ type = 'subscribe_midi_in', port = port }, function(msg)
    -- success フィールドを持たない電文はこの購読リクエストの応答ではない
    -- A message without a `success` field is not the response to this request
    if msg.success == nil then
      return false
    end
    if msg.success then
      M._subscribed_port = port
      vim.notify('lcvgc midi-in: ' .. (msg.message or ('subscribed: ' .. port)), vim.log.levels.INFO)
    else
      vim.notify('lcvgc midi-in: ' .. (msg.error or 'subscribe failed'), vim.log.levels.ERROR)
    end
    return true
  end)
end

--- 購読を解除する。未購読でもデーモン側は冪等に成功を返す。
--- Unsubscribe. The daemon responds successfully even if not subscribed.
function M.unsubscribe()
  connection.request({ type = 'unsubscribe_midi_in' }, function(msg)
    if msg.success == nil then
      return false
    end
    M._subscribed_port = nil
    vim.notify('lcvgc midi-in: ' .. (msg.message or 'unsubscribed'), vim.log.levels.INFO)
    return true
  end)
end

--- 入力ポートを vim.ui.select で選ばせてから購読する。
--- Pick an input port via vim.ui.select, then subscribe.
function M.subscribe_interactive()
  if not connection.is_connected() then
    vim.notify('lcvgc not connected', vim.log.levels.WARN)
    return
  end
  local ports = require('lcvgc.ports')
  ports.fetch(function()
    local names = ports.get_input_ports()
    if #names == 0 then
      vim.notify('lcvgc: no MIDI input ports available', vim.log.levels.WARN)
      return
    end
    vim.ui.select(names, { prompt = 'Select MIDI input port' }, function(choice)
      if choice then
        M.subscribe(choice)
      end
    end)
  end)
end

--- 購読のオン/オフをトグルする。オフ→オンは入力ポート選択フローを通す。
--- Toggle the subscription. Off->on goes through the port-selection flow.
function M.toggle()
  if M.is_subscribed() then
    M.unsubscribe()
  else
    M.subscribe_interactive()
  end
end

--- midi_in_event のイベントハンドラ登録と、終了時の後始末を設定する。
--- Register the midi_in_event handler and set up teardown on exit.
function M.setup()
  connection.on_event('midi_in_event', M._on_midi_in_event)

  -- バッファ/セッション終了時に購読解除する
  -- Unsubscribe when the session is about to exit
  vim.api.nvim_create_autocmd('VimLeavePre', {
    group = vim.api.nvim_create_augroup('lcvgc_midi_in', { clear = true }),
    callback = function()
      if M.is_subscribed() then
        M.unsubscribe()
      end
    end,
  })
end

return M
