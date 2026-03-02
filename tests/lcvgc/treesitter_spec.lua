describe('lcvgc.treesitter', function()
  local treesitter

  before_each(function()
    treesitter = require('lcvgc.treesitter')
  end)

  after_each(function()
    package.loaded['lcvgc.treesitter'] = nil
  end)

  describe('setup', function()
    it('nvim-treesitter が無い場合でもエラーにならない', function()
      -- nvim-treesitter が存在しない環境をシミュレート
      package.loaded['nvim-treesitter.parsers'] = nil
      package.preload['nvim-treesitter.parsers'] = function()
        error('module not found')
      end

      assert.has_no.errors(function()
        treesitter.setup()
      end)

      package.preload['nvim-treesitter.parsers'] = nil
    end)

    it('nvim-treesitter がある場合にパーサー情報を登録する', function()
      local registered = {}
      local mock_parsers = {
        get_parser_configs = function()
          return registered
        end,
      }
      package.loaded['nvim-treesitter.parsers'] = mock_parsers

      treesitter.setup()

      assert.is_not_nil(registered.cvg)
      assert.is_not_nil(registered.cvg.install_info)
      assert.equals('https://github.com/vikke/tree-sitter-cvg', registered.cvg.install_info.url)
      local files = registered.cvg.install_info.files
      local has_parser, has_scanner = false, false
      for _, f in ipairs(files) do
        if f == 'src/parser.c' then has_parser = true end
        if f == 'src/scanner.c' then has_scanner = true end
      end
      assert.is_true(has_parser)
      assert.is_true(has_scanner)
      assert.same({ 'cvg' }, registered.cvg.filetype)

      package.loaded['nvim-treesitter.parsers'] = nil
    end)
  end)
end)
