local M = {}

function M.setup()
  local ok, parsers = pcall(require, 'nvim-treesitter.parsers')
  if not ok then
    return
  end

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
end

return M
