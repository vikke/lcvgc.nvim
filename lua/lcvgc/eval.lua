local connection = require('lcvgc.connection')

local M = {}

function M.eval_selection()
  local start_line = vim.fn.line("'<")
  local end_line = vim.fn.line("'>")
  local lines = vim.api.nvim_buf_get_lines(0, start_line - 1, end_line, false)
  local text = table.concat(lines, '\n')
  connection.send({ type = 'eval', source = text })
end

function M.eval_paragraph()
  local cursor = vim.api.nvim_win_get_cursor(0)
  local row = cursor[1]
  local line_count = vim.api.nvim_buf_line_count(0)

  -- 上方向に空行を探す
  local start_line = row
  for i = row - 1, 1, -1 do
    local line = vim.api.nvim_buf_get_lines(0, i - 1, i, false)[1]
    if line:match('^%s*$') then
      break
    end
    start_line = i
  end

  -- 下方向に空行を探す
  local end_line = row
  for i = row + 1, line_count do
    local line = vim.api.nvim_buf_get_lines(0, i - 1, i, false)[1]
    if line:match('^%s*$') then
      break
    end
    end_line = i
  end

  local lines = vim.api.nvim_buf_get_lines(0, start_line - 1, end_line, false)
  local text = table.concat(lines, '\n')
  connection.send({ type = 'eval', source = text })
end

return M
