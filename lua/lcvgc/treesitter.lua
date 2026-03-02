local M = {}

function M.setup()
  -- nvim-treesitterへのパーサー登録（:TSInstall cvg を可能にする）
  local ok, parsers = pcall(require, 'nvim-treesitter.parsers')
  if ok then
    local parser_configs = parsers.get_parser_configs()
    parser_configs.cvg = {
      install_info = {
        url = 'https://github.com/vikke/tree-sitter-cvg',
        files = { 'src/parser.c', 'src/scanner.c' },
        branch = 'main',
        generate_requires_npm = false,
        requires_generate_from_grammar = false,
      },
      filetype = { 'cvg' },
    }

    -- nvim-treesitterのクエリファイルキャッシュをクリア
    -- 遅延読み込みではnvim-treesitter初期化時にcvgのqueries/が未検出のため
    -- キャッシュにfalseが入りhighlightモジュールのattachが失敗する
    local ts_query_ok, ts_query = pcall(require, 'nvim-treesitter.query')
    if ts_query_ok and ts_query.invalidate_query_cache then
      ts_query.invalidate_query_cache('cvg')
    end
  end

  -- FileType autocmdでcvgバッファのtreesitterハイライトを確実に起動
  -- nvim-treesitterの自動アタッチに依存せず、直接vim.treesitter.start()を呼ぶ
  vim.api.nvim_create_autocmd('FileType', {
    pattern = 'cvg',
    group = vim.api.nvim_create_augroup('lcvgc_treesitter', { clear = true }),
    callback = function(args)
      pcall(vim.treesitter.start, args.buf, 'cvg')
    end,
  })

  -- 既に開かれているcvgバッファに対してもハイライトを有効化
  for _, buf in ipairs(vim.api.nvim_list_bufs()) do
    if vim.api.nvim_buf_is_loaded(buf) and vim.bo[buf].filetype == 'cvg' then
      pcall(vim.treesitter.start, buf, 'cvg')
    end
  end
end

return M
