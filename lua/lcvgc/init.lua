local M = {}

--- プラグインバージョン
M.version = '0.9.0'

local defaults = {
  port = 5555,
  log_path = '/tmp/lcvgc.log',
  auto_connect = true,
  auto_layout = false,
  debounce = 150,
  flash_duration = 300,
}

function M.setup(opts)
  opts = vim.tbl_deep_extend('force', defaults, opts or {})
  M.opts = opts

  require('lcvgc.treesitter').setup()
  require('lcvgc.colors').setup()
  require('lcvgc.commands').setup(opts)
  require('lcvgc.lsp').setup(opts)
  require('lcvgc.midi_in').setup()

  require('lcvgc.completion').setup()
  require('lcvgc.cmp_source').setup(opts)

  if opts.auto_connect then
    local connection = require('lcvgc.connection')
    local display = require('lcvgc.display')
    local ok = connection.connect(opts.port, display.on_message)
    if ok then
      require('lcvgc.ports').fetch()
      -- 接続成功時、現在のバッファが .cvg なら
      -- include 展開した定義（play/stop は除外）を eval 送信する
      -- On successful connect, eval the current .cvg buffer's
      -- definitions (play/stop excluded) with includes expanded
      if vim.bo.filetype == 'cvg' then
        require('lcvgc.eval').eval_definitions()
      end
    end
  end

  -- 新規 .cvg ファイル作成時にサンプルテンプレートを自動挿入
  vim.api.nvim_create_autocmd('BufNewFile', {
    pattern = '*.cvg',
    group = vim.api.nvim_create_augroup('lcvgc_template', { clear = true }),
    callback = function(ev)
      local lines = require('lcvgc.template').get_lines()
      vim.api.nvim_buf_set_lines(ev.buf, 0, -1, false, lines)
      vim.bo[ev.buf].modified = false
    end,
  })

  if opts.auto_layout then
    vim.api.nvim_create_autocmd('BufRead', {
      pattern = '*.cvg',
      group = vim.api.nvim_create_augroup('lcvgc_auto_layout', { clear = true }),
      once = true,
      callback = function()
        require('lcvgc.layout').setup({ log_path = opts.log_path })
      end,
    })
  end
end

return M
