require('tests.helpers.vim_mock')

describe('lcvgc.tutorial', function()
  local tutorial
  -- 送信されたリクエストの記録 / requests sent to the daemon
  local sent
  -- 接続状態 / connection state used by the stub
  local connected
  -- 応答を返すかどうか / whether the stub answers requests
  local reply
  -- バッファの擬似データ（bufnr -> 行テーブル）/ fake buffer contents
  local buffers
  -- 退避した vim.api の関数 / saved vim.api functions
  local saved_api
  -- カーソル行（1 始まり）/ cursor row (1-based)
  local cursor_row

  -- デーモンが返すチュートリアル本文（末尾改行あり、途中に空行あり）
  -- tutorial text the daemon returns (trailing newline, blank lines inside)
  local TEXT = '// --- Tempo ---\ntempo 120\n\n// --- Scale ---\nscale c_minor\n'
  local TEXT_LINES = { '// --- Tempo ---', 'tempo 120', '', '// --- Scale ---', 'scale c_minor' }

  before_each(function()
    clear_notifications()
    sent = {}
    connected = true
    reply = true
    buffers = { [1] = { '' } }
    cursor_row = 1
    vim._bo_data = { modified = false }

    package.loaded['lcvgc.connection'] = {
      is_connected = function() return connected end,
      request = function(payload, handler)
        table.insert(sent, payload)
        if reply then
          handler({ success = true, lsp = { type = 'tutorial', text = TEXT } })
        end
        return true
      end,
    }

    saved_api = {}
    for _, name in ipairs({
      'nvim_buf_is_valid', 'nvim_buf_get_lines', 'nvim_buf_set_lines',
      'nvim_get_current_buf', 'nvim_win_get_cursor',
    }) do
      saved_api[name] = vim.api[name]
    end
    vim.api.nvim_buf_is_valid = function(b) return buffers[b] ~= nil end
    vim.api.nvim_buf_get_lines = function(b) return buffers[b] end
    vim.api.nvim_buf_set_lines = function(b, s, e, _, lines)
      local cur = buffers[b]
      if e == -1 then e = #cur end
      local new = {}
      for i = 1, s do table.insert(new, cur[i]) end
      for _, l in ipairs(lines) do table.insert(new, l) end
      for i = e + 1, #cur do table.insert(new, cur[i]) end
      buffers[b] = new
    end
    vim.api.nvim_get_current_buf = function() return 1 end
    vim.api.nvim_win_get_cursor = function() return { cursor_row, 0 } end

    tutorial = reload_module('lcvgc.tutorial')
  end)

  after_each(function()
    for name, fn in pairs(saved_api) do
      vim.api[name] = fn
    end
    package.loaded['lcvgc.connection'] = nil
  end)

  describe('lang', function()
    it('LANG が ja で始まれば ja', function()
      tutorial._get_lang = function() return 'ja_JP.UTF-8' end
      assert.equals('ja', tutorial.lang())
    end)

    it('LANG が en_US なら en', function()
      tutorial._get_lang = function() return 'en_US.UTF-8' end
      assert.equals('en', tutorial.lang())
    end)

    it('LANG が無ければ en', function()
      tutorial._get_lang = function() return nil end
      assert.equals('en', tutorial.lang())
    end)
  end)

  describe('split_lines', function()
    it('空行を保ち、末尾の改行 1 つは行にしない', function()
      assert.same(TEXT_LINES, tutorial.split_lines(TEXT))
    end)

    it('末尾改行が無くても最後の行を返す', function()
      assert.same({ 'a', '', 'b' }, tutorial.split_lines('a\n\nb'))
    end)
  end)

  describe('fetch', function()
    it('tutorial リクエストを lang 付きで送り、行テーブルを渡す', function()
      tutorial._get_lang = function() return 'ja' end
      local got
      assert.is_true(tutorial.fetch(function(lines) got = lines end))
      assert.equals('tutorial', sent[1].type)
      assert.equals('ja', sent[1].lang)
      assert.same(TEXT_LINES, got)
    end)

    it('未接続なら送らず false', function()
      connected = false
      assert.is_false(tutorial.fetch(function() end))
      assert.equals(0, #sent)
    end)
  end)

  describe('on_new_file', function()
    it('接続中なら空のバッファにチュートリアルを入れ、未変更扱いにする', function()
      tutorial.on_new_file(1)
      assert.same(TEXT_LINES, buffers[1])
      assert.is_false(vim._bo_data.modified)
    end)

    it('応答が来るまでに編集されていたら上書きしない', function()
      reply = false
      tutorial.on_new_file(1)
      buffers[1] = { 'tempo 90' }
      -- 遅れて届いた応答を手で流す / deliver the late reply by hand
      reply = true
      tutorial.on_new_file(1)
      assert.same({ 'tempo 90' }, buffers[1])
    end)

    it('未接続なら何も入れず、接続後に入れる', function()
      connected = false
      tutorial.on_new_file(1)
      assert.same({ '' }, buffers[1])
      assert.equals(0, #sent)

      connected = true
      tutorial.on_connected()
      assert.same(TEXT_LINES, buffers[1])
    end)

    it('接続前に編集されたバッファには、接続後も入れない', function()
      connected = false
      tutorial.on_new_file(1)
      buffers[1] = { 'tempo 90' }
      connected = true
      tutorial.on_connected()
      assert.same({ 'tempo 90' }, buffers[1])
      assert.equals(0, #sent)
    end)

    it('接続後の挿入は 1 回だけ（2 回目の接続では入れない）', function()
      connected = false
      tutorial.on_new_file(1)
      connected = true
      tutorial.on_connected()
      tutorial.on_connected()
      assert.equals(1, #sent)
    end)

    it('閉じられたバッファは接続後に無視する', function()
      connected = false
      tutorial.on_new_file(1)
      buffers[1] = nil
      connected = true
      tutorial.on_connected()
      assert.equals(0, #sent)
    end)
  end)

  describe('insert_at_cursor', function()
    it('カーソル行の下にチュートリアルを挿入する', function()
      buffers[1] = { 'tempo 90', 'scale c_major' }
      cursor_row = 1
      assert.is_true(tutorial.insert_at_cursor())
      assert.same({
        'tempo 90',
        '// --- Tempo ---', 'tempo 120', '', '// --- Scale ---', 'scale c_minor',
        'scale c_major',
      }, buffers[1])
    end)

    it('未接続なら警告して false', function()
      connected = false
      assert.is_false(tutorial.insert_at_cursor())
      assert.equals(vim.log.levels.WARN, vim._notifications[1].level)
    end)
  end)
end)
