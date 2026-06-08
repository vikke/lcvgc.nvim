local M = {}

local cache = nil

function M._handle_response(msg)
  if not msg.ports then
    return false
  end
  cache = msg.ports
  return true
end

--- ポート一覧をデーモンに要求する。
--- cb を渡すと、応答を受信してキャッシュを更新した後に呼ばれる。
--- Request the port list from the daemon. If cb is given, it is called
--- after the response has been received and the cache updated.
--- @param cb fun()|nil 応答受信後のコールバック / called after the response
function M.fetch(cb)
  local connection = require('lcvgc.connection')
  if not connection.is_connected() then
    return
  end
  connection.request({ type = 'list_ports' }, function(msg)
    local ok = M._handle_response(msg)
    if ok and cb then
      cb()
    end
    return ok
  end)
end

function M.get_output_ports()
  if not cache then
    return {}
  end
  local result = {}
  for _, port in ipairs(cache) do
    if port.direction == 'out' then
      table.insert(result, port.name)
    end
  end
  return result
end

--- 入力ポート（direction == "in"）の名前一覧を返す
--- Return the names of input ports (direction == "in")
--- @return string[]
function M.get_input_ports()
  if not cache then
    return {}
  end
  local result = {}
  for _, port in ipairs(cache) do
    if port.direction == 'in' then
      table.insert(result, port.name)
    end
  end
  return result
end

function M.clear_cache()
  cache = nil
end

return M
