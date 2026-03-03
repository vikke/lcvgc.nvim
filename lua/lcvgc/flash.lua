--- eval 実行時に対象範囲を extmark で一時的にハイライトするモジュール
local M = {}

--- フラッシュ用の namespace
local ns = vim.api.nvim_create_namespace('lcvgc_eval_flash')

--- 指定範囲を extmark でフラッシュハイライトする
--- @param bufnr number バッファ番号
--- @param start_line number 開始行 (1-indexed)
--- @param end_line number 終了行 (1-indexed, inclusive)
--- @param duration number? フラッシュ持続時間 (ms, default: config の flash_duration)
function M.flash_range(bufnr, start_line, end_line, duration)
  local config = require('lcvgc').opts or {}
  duration = duration or config.flash_duration or 300

  -- 前回のフラッシュをクリア
  vim.api.nvim_buf_clear_namespace(bufnr, ns, 0, -1)

  -- extmark 1つで範囲全体をカバー (end_row は exclusive)
  vim.api.nvim_buf_set_extmark(bufnr, ns, start_line - 1, 0, {
    end_row = end_line,
    hl_group = 'LcvgcEvalFlash',
    hl_eol = true,
  })

  -- 一定時間後にクリア
  vim.defer_fn(function()
    if vim.api.nvim_buf_is_valid(bufnr) then
      vim.api.nvim_buf_clear_namespace(bufnr, ns, 0, -1)
    end
  end, duration)
end

return M
