local display = require('lcvgc.display')

local M = {}

local log_win = nil
local log_buf = nil

function M.setup(opts)
  opts = opts or {}
  local log_path = opts.log_path or '/tmp/lcvgc.log'

  -- 現在のウィンドウがメインペイン
  local main_win = vim.api.nvim_get_current_win()

  -- 右に縦分割 → ログ用ターミナル
  vim.cmd('vsplit')
  log_win = vim.api.nvim_get_current_win()
  vim.cmd('terminal tail -f ' .. vim.fn.shellescape(log_path))
  log_buf = vim.api.nvim_get_current_buf()
  vim.bo[log_buf].buflisted = false

  -- 右ペインを上下分割 → eval結果バッファ
  vim.cmd('split')
  local eval_win = vim.api.nvim_get_current_win()
  local eval_buf = display.get_eval_buf()
  vim.api.nvim_win_set_buf(eval_win, eval_buf)
  display.set_eval_win(eval_win)

  -- メインペインにフォーカスを戻す
  vim.api.nvim_set_current_win(main_win)
end

return M
