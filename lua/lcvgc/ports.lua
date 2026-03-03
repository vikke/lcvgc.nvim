local M = {}

local cache = nil

function M._handle_response(msg)
  if not msg.ports then
    return false
  end
  cache = msg.ports
  return true
end

function M.fetch()
  local connection = require('lcvgc.connection')
  if not connection.is_connected() then
    return
  end
  connection.request({ type = 'list_ports' }, M._handle_response)
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

function M.clear_cache()
  cache = nil
end

return M
