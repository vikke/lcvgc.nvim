local M = {}

local handle = 0
local recv_buf = ''
local on_message_cb = nil

function M.connect(port, on_message)
  port = port or 9876
  on_message_cb = on_message

  if handle ~= 0 then
    M.disconnect()
  end

  handle = vim.fn.sockconnect('tcp', 'localhost:' .. port, {
    on_data = function(_, data, _)
      if not data or (#data == 1 and data[1] == '') then
        vim.notify('lcvgc engine disconnected', vim.log.levels.WARN)
        handle = 0
        return
      end
      M._on_data(data)
    end,
  })

  if handle == 0 then
    vim.notify('lcvgc engine not running on port ' .. port, vim.log.levels.ERROR)
    return false
  end
  vim.notify('lcvgc connected on port ' .. port, vim.log.levels.INFO)
  return true
end

function M.disconnect()
  if handle ~= 0 then
    vim.fn.chanclose(handle)
    handle = 0
    recv_buf = ''
    vim.notify('lcvgc disconnected', vim.log.levels.INFO)
  end
end

function M.send(payload)
  if handle == 0 then
    vim.notify('lcvgc not connected', vim.log.levels.WARN)
    return false
  end
  local json = vim.fn.json_encode(payload)
  vim.fn.chansend(handle, json .. '\n')
  return true
end

function M.is_connected()
  return handle ~= 0
end

function M._on_data(data)
  local raw = table.concat(data, '')
  recv_buf = recv_buf .. raw

  while true do
    local nl = recv_buf:find('\n')
    if not nl then break end
    local line = recv_buf:sub(1, nl - 1)
    recv_buf = recv_buf:sub(nl + 1)
    if line ~= '' and on_message_cb then
      local ok, msg = pcall(vim.fn.json_decode, line)
      if ok then
        vim.schedule(function()
          on_message_cb(msg)
        end)
      end
    end
  end
end

return M
