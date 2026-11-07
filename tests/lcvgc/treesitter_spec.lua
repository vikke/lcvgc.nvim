-- lcvgc.treesitter のユニットテスト（nvim-treesitter master / main 両対応）
-- vim.api の augroup / autocmd を擬似レジストリに差し替え、登録内容をコールバック込みで検証する。
-- 差し替えた vim.api / vim.treesitter / vim.bo / package.loaded / package.preload は after_each で必ず戻す。
-- Unit tests for lcvgc.treesitter (supports both nvim-treesitter master and main).
-- augroup / autocmd in vim.api are replaced by a fake registry so registrations
-- (including callbacks) can be verified. Everything replaced (vim.api / vim.treesitter /
-- vim.bo / package.loaded / package.preload) is always restored in after_each.
describe('lcvgc.treesitter', function()
  local treesitter

  -- テスト中に差し替える nvim-treesitter のモジュール名
  -- nvim-treesitter module names replaced during tests
  local TS_MODULES = { 'nvim-treesitter.parsers', 'nvim-treesitter.query' }

  -- 期待するリポジトリ URL / expected parser repository URL
  local CVG_URL = 'https://github.com/vikke/tree-sitter-cvg'

  -- User TSUpdate 発火時にコールバックへ渡すイベント情報
  -- Event data passed to the callback when User TSUpdate fires
  local TS_UPDATE_EVENT = { event = 'User', match = 'TSUpdate' }

  -- before_each で退避した差し替え前の値（after_each で必ず戻す）
  -- Originals saved in before_each and always restored in after_each
  local saved

  -- 擬似 augroup レジストリ（name -> id）/ fake augroup registry (name -> id)
  local augroups
  -- nvim_create_augroup の呼び出し記録 { name, opts } / recorded augroup calls
  local augroup_calls
  -- 現在有効な autocmd 一覧 { event, opts, group } / currently active autocmds
  local autocmds
  -- vim.treesitter.start の呼び出し記録 { buf, lang } / recorded vim.treesitter.start calls
  local ts_start_calls

  --- 登録失敗時の通知メッセージ接頭辞を返す
  --- Return the prefix of the warning on registration failure
  --- @param api string 'master' | 'main' 判定されたブランチ / detected branch
  --- @return string 通知メッセージの接頭辞 / message prefix
  local function fail_prefix(api)
    return 'lcvgc: failed to register cvg parser with nvim-treesitter (' .. api .. ' branch): '
  end

  --- 単一値またはリストをリストに揃える
  --- Normalize a single value or a list into a list
  --- @param v any 単一値またはリスト / single value or list
  --- @return table リスト / list
  local function as_list(v)
    if type(v) == 'table' then return v end
    return { v }
  end

  --- event / pattern に一致する有効な autocmd を返す
  --- Return active autocmds matching the event and pattern
  --- @param event string イベント名 / event name
  --- @param pattern string パターン / pattern
  --- @return table[] 一致した autocmd / matching autocmds
  local function find_autocmds(event, pattern)
    local found = {}
    for _, au in ipairs(autocmds) do
      if vim.tbl_contains(as_list(au.event), event)
        and vim.tbl_contains(as_list(au.opts.pattern), pattern) then
        table.insert(found, au)
      end
    end
    return found
  end

  --- augroup id から名前を引く / Look up an augroup name by id
  --- @param id integer|nil augroup id
  --- @return string|nil augroup 名（未登録なら nil）/ augroup name (nil if unknown)
  local function group_name(id)
    for name, gid in pairs(augroups) do
      if gid == id then return name end
    end
    return nil
  end

  --- 指定 augroup の作成がすべて clear=true で行われたことを検証する
  --- Assert that every creation of the augroup used clear=true
  --- @param name string augroup 名 / augroup name
  local function assert_augroup_cleared(name)
    local count = 0
    for _, call in ipairs(augroup_calls) do
      if call.name == name then
        count = count + 1
        assert.is_true(call.opts.clear)
      end
    end
    assert.is_true(count > 0)
  end

  --- User TSUpdate の autocmd がちょうど 1 件であることを確認し、そのコールバックを返す
  --- Assert exactly one User TSUpdate autocmd exists and return its callback
  --- @return function TSUpdate コールバック / TSUpdate callback
  local function ts_update_callback()
    local aus = find_autocmds('User', 'TSUpdate')
    assert.equals(1, #aus)
    assert.is_function(aus[1].opts.callback)
    return aus[1].opts.callback
  end

  --- 指定モジュールを「未導入」にする（require がエラーになる）
  --- Make the module unavailable (require raises an error)
  --- @param name string モジュール名 / module name
  local function simulate_missing(name)
    package.loaded[name] = nil
    package.preload[name] = function()
      error('module ' .. name .. ' not found')
    end
  end

  --- master ブランチ相当の nvim-treesitter.parsers を注入する
  --- Inject a master-branch-like nvim-treesitter.parsers
  --- @return table get_parser_configs() が返すテーブル / table returned by get_parser_configs()
  --- @return table 注入したモジュール本体 / injected module table
  local function install_master_parsers()
    local configs = {}
    local module = {
      get_parser_configs = function()
        return configs
      end,
    }
    package.loaded['nvim-treesitter.parsers'] = module
    return configs, module
  end

  --- main ブランチ相当の nvim-treesitter.parsers（言語名 -> ParserInfo のテーブル）を注入する
  --- Inject a main-branch-like nvim-treesitter.parsers (plain lang -> ParserInfo table)
  --- @return table 注入したテーブル / injected table
  local function install_main_parsers()
    local parsers = {
      lua = {
        install_info = { url = 'https://github.com/tree-sitter-grammars/tree-sitter-lua' },
        tier = 1,
      },
    }
    package.loaded['nvim-treesitter.parsers'] = parsers
    return parsers
  end

  --- 代入すると error を投げる main 相当の nvim-treesitter.parsers を注入する
  --- Inject a main-like nvim-treesitter.parsers whose assignment raises an error
  --- @return table 注入したテーブル / injected table
  local function install_readonly_main_parsers()
    local parsers = setmetatable({}, {
      __newindex = function() error('read-only parsers') end,
    })
    package.loaded['nvim-treesitter.parsers'] = parsers
    return parsers
  end

  --- nvim-treesitter.query（master のみ）を注入し invalidate_query_cache の呼び出しを記録する
  --- Inject nvim-treesitter.query (master only) and record invalidate_query_cache calls
  --- @param fail boolean|nil true なら記録後に error を投げる / raise an error after recording if true
  --- @return string[] 渡された言語名の記録 / recorded language names
  local function install_query_module(fail)
    local calls = {}
    package.loaded['nvim-treesitter.query'] = {
      invalidate_query_cache = function(lang)
        table.insert(calls, lang)
        if fail then error('invalidate failed') end
      end,
    }
    return calls
  end

  --- nvim 本体の vim.treesitter.query.get（memoize された呼び出し可能テーブル）を注入する
  --- Inject Neovim's vim.treesitter.query.get (a memoized callable table)
  --- @param clear_impl function|nil clear の実装（省略時は呼び出しを記録）/ clear implementation (records calls if nil)
  --- @return table 注入した get / injected get
  --- @return table[] clear の呼び出し記録 { self, args } / recorded clear calls
  local function install_core_query_get(clear_impl)
    local calls = {}
    local get = setmetatable({}, {
      __call = function() return nil end,
    })
    get.clear = clear_impl or function(self, ...)
      table.insert(calls, { self = self, args = { ... } })
    end
    vim.treesitter.query = { get = get }
    return get, calls
  end

  --- バッファ一覧・読み込み状態・filetype をバッファごとに差し替える
  --- Stub the buffer list, loaded state and per-buffer filetype
  --- @param filetypes table<integer, string> バッファ番号 -> filetype / buffer -> filetype
  --- @param loaded table<integer, boolean> バッファ番号 -> 読み込み済みか / buffer -> loaded
  local function stub_buffers(filetypes, loaded)
    local bufs = {}
    for buf in pairs(filetypes) do table.insert(bufs, buf) end
    table.sort(bufs)
    vim.api.nvim_list_bufs = function() return bufs end
    vim.api.nvim_buf_is_loaded = function(buf) return loaded[buf] == true end
    vim.bo = setmetatable({}, {
      __index = function(_, buf) return { filetype = filetypes[buf] } end,
    })
  end

  --- main 用 ParserInfo が確定仕様どおり url と branch だけを持つことを検証する
  --- Assert the main ParserInfo has only url and branch as specified
  --- @param info table ParserInfo
  local function assert_main_parser_info(info)
    -- files 等の master 専用キーは不要。queries は同梱 queries/cvg を隠すため、
    -- tier / revision は意味のある値が無いため指定しない
    -- No master-only keys (files etc.); queries would hide the bundled queries/cvg,
    -- and tier / revision have no meaningful value
    assert.same({
      install_info = {
        url = CVG_URL,
        branch = 'main',
      },
    }, info)
  end

  before_each(function()
    clear_notifications()

    saved = {
      create_autocmd = vim.api.nvim_create_autocmd,
      create_augroup = vim.api.nvim_create_augroup,
      list_bufs = vim.api.nvim_list_bufs,
      buf_is_loaded = vim.api.nvim_buf_is_loaded,
      bo = vim.bo,
      ts_start = vim.treesitter.start,
      ts_query = vim.treesitter.query,
      loaded = {},
      preload = {},
    }
    for _, name in ipairs(TS_MODULES) do
      saved.loaded[name] = package.loaded[name]
      saved.preload[name] = package.preload[name]
      -- 既定は「nvim-treesitter 未導入」/ default: nvim-treesitter not installed
      simulate_missing(name)
    end

    -- 既定は vim.treesitter.query 無し（vim_mock と同じ）
    -- Default: no vim.treesitter.query (same as vim_mock)
    vim.treesitter.query = nil

    -- 擬似 augroup / autocmd（Neovim と同様 clear は既定 true）
    -- Fake augroup / autocmd (clear defaults to true like Neovim)
    augroups, augroup_calls, autocmds = {}, {}, {}
    local next_group_id = 0
    vim.api.nvim_create_augroup = function(name, opts)
      table.insert(augroup_calls, { name = name, opts = opts })
      local id = augroups[name]
      if not id then
        next_group_id = next_group_id + 1
        id = next_group_id
        augroups[name] = id
      end
      if not opts or opts.clear ~= false then
        for i = #autocmds, 1, -1 do
          if autocmds[i].group == id then table.remove(autocmds, i) end
        end
      end
      return id
    end
    vim.api.nvim_create_autocmd = function(event, opts)
      opts = opts or {}
      local group = opts.group
      if type(group) == 'string' then
        group = augroups[group]
        if not group then error('Invalid augroup: ' .. opts.group) end
      end
      table.insert(autocmds, { event = event, opts = opts, group = group })
      return #autocmds
    end

    ts_start_calls = {}
    vim.treesitter.start = function(buf, lang)
      table.insert(ts_start_calls, { buf = buf, lang = lang })
    end

    -- 差し替え後にモジュールを読み直す / reload the module after installing fakes
    treesitter = reload_module('lcvgc.treesitter')
  end)

  after_each(function()
    vim.api.nvim_create_autocmd = saved.create_autocmd
    vim.api.nvim_create_augroup = saved.create_augroup
    vim.api.nvim_list_bufs = saved.list_bufs
    vim.api.nvim_buf_is_loaded = saved.buf_is_loaded
    vim.bo = saved.bo
    vim.treesitter.start = saved.ts_start
    vim.treesitter.query = saved.ts_query
    for _, name in ipairs(TS_MODULES) do
      package.loaded[name] = saved.loaded[name]
      package.preload[name] = saved.preload[name]
    end
    package.loaded['lcvgc.treesitter'] = nil
  end)

  describe('master_parser_info', function()
    it('既存と同一内容の master 用 ParserInfo を返す', function()
      assert.same({
        install_info = {
          url = CVG_URL,
          files = { 'src/parser.c', 'src/scanner.c' },
          branch = 'main',
          generate_requires_npm = false,
          requires_generate_from_grammar = false,
        },
        filetype = { 'cvg' },
      }, treesitter.master_parser_info())
    end)

    it('呼ぶたびに新しいテーブルを返す', function()
      local first = treesitter.master_parser_info()
      first.install_info.url = 'mutated'

      local second = treesitter.master_parser_info()

      assert.are_not.equal(first, second)
      assert.equals(CVG_URL, second.install_info.url)
    end)
  end)

  describe('main_parser_info', function()
    it('url と branch を持ち master 専用キーを含まない', function()
      assert_main_parser_info(treesitter.main_parser_info())
    end)

    it('呼ぶたびに新しいテーブルを返す', function()
      local first = treesitter.main_parser_info()
      first.install_info.url = 'mutated'

      local second = treesitter.main_parser_info()

      assert.are_not.equal(first, second)
      assert_main_parser_info(second)
    end)
  end)

  describe('detect_api', function()
    it('get_parser_configs 関数を持てば master と判定する', function()
      assert.equals('master', treesitter.detect_api({ get_parser_configs = function() return {} end }))
    end)

    it('言語名 -> ParserInfo のテーブルなら main と判定する', function()
      assert.equals('main', treesitter.detect_api({ lua = { install_info = { url = 'x' } } }))
      assert.equals('main', treesitter.detect_api({}))
    end)

    it('get_parser_configs が関数でなければ main と判定する', function()
      assert.equals('main', treesitter.detect_api({ get_parser_configs = true }))
    end)

    it('テーブル以外（true / nil）を渡しても例外を投げず main と判定する', function()
      assert.has_no.errors(function()
        assert.equals('main', treesitter.detect_api(true))
        assert.equals('main', treesitter.detect_api(nil))
      end)
    end)
  end)

  describe('register_ts_update_autocmd', function()
    it('augroup lcvgc_treesitter_register(clear=true) で User TSUpdate の autocmd を登録する', function()
      treesitter.register_ts_update_autocmd()

      local aus = find_autocmds('User', 'TSUpdate')
      assert.equals(1, #aus)
      assert.is_function(aus[1].opts.callback)
      assert.equals('lcvgc_treesitter_register', group_name(aus[1].group))
      assert_augroup_cleared('lcvgc_treesitter_register')
    end)

    it('コールバックは値を返さない（true を返すと autocmd が削除されるため）', function()
      treesitter.register_ts_update_autocmd()
      local callback = ts_update_callback()

      -- main 導入時（cvg を代入する経路）/ with main installed (assignment path)
      install_main_parsers()
      assert.is_nil(callback(TS_UPDATE_EVENT))

      -- 未導入時（require 失敗の経路）/ not installed (require failure path)
      simulate_missing('nvim-treesitter.parsers')
      assert.is_nil(callback(TS_UPDATE_EVENT))
    end)
  end)

  describe('register_parser', function()
    it('nvim-treesitter 未導入なら false を返し通知しない', function()
      assert.is_false(treesitter.register_parser())
      assert.equals(0, #vim._notifications)
    end)

    it('master で登録に成功すると true を返す', function()
      local configs = install_master_parsers()
      assert.is_true(treesitter.register_parser())
      assert.is_not_nil(configs.cvg)
    end)

    it('main で登録に成功すると true を返す', function()
      local parsers = install_main_parsers()
      assert.is_true(treesitter.register_parser())
      assert.is_not_nil(parsers.cvg)
    end)

    it('登録処理が失敗すると false を返し WARN 通知する', function()
      package.loaded['nvim-treesitter.parsers'] = {
        get_parser_configs = function() error('boom') end,
      }
      assert.is_false(treesitter.register_parser())
      assert.equals(1, #vim._notifications)
      assert.equals(vim.log.levels.WARN, vim._notifications[1].level)
      assert.equals(1, vim._notifications[1].msg:find(fail_prefix('master'), 1, true))
    end)

    it('invalidate_query_cache が error を投げても true を返し通知しない', function()
      local configs = install_master_parsers()
      local calls = install_query_module(true)

      assert.is_true(treesitter.register_parser())

      assert.same({ 'cvg' }, calls)
      assert.equals(0, #vim._notifications)
      assert.same(treesitter.master_parser_info(), configs.cvg)
    end)
  end)

  describe('invalidate_core_query_cache', function()
    it('vim.treesitter.query が無くてもエラーにならない', function()
      assert.is_nil(vim.treesitter.query)

      assert.has_no.errors(function()
        treesitter.invalidate_core_query_cache()
      end)
    end)

    it('query.get が clear を持たない関数でもエラーにならない', function()
      vim.treesitter.query = { get = function() return nil end }

      assert.has_no.errors(function()
        treesitter.invalidate_core_query_cache()
      end)
    end)

    it('query.get:clear("cvg", "highlights") を呼ぶ', function()
      local get, calls = install_core_query_get()

      treesitter.invalidate_core_query_cache()

      assert.equals(1, #calls)
      assert.equals(get, calls[1].self)
      assert.same({ 'cvg', 'highlights' }, calls[1].args)
    end)

    it('clear が error を投げても例外を投げない', function()
      install_core_query_get(function() error('clear failed') end)

      assert.has_no.errors(function()
        treesitter.invalidate_core_query_cache()
      end)
    end)
  end)

  describe('start_highlight', function()
    it('augroup lcvgc_treesitter(clear=true) で FileType cvg の autocmd を登録する', function()
      treesitter.start_highlight()

      local aus = find_autocmds('FileType', 'cvg')
      assert.equals(1, #aus)
      assert.equals('lcvgc_treesitter', group_name(aus[1].group))
      assert_augroup_cleared('lcvgc_treesitter')
    end)

    it('FileType コールバックで vim.treesitter.start(buf, "cvg") を呼ぶ', function()
      treesitter.start_highlight()

      find_autocmds('FileType', 'cvg')[1].opts.callback({ buf = 5 })

      assert.same({ { buf = 5, lang = 'cvg' } }, ts_start_calls)
    end)

    it('vim.treesitter.start が失敗しても例外を投げない', function()
      vim.treesitter.start = function() error('no parser for cvg') end
      treesitter.start_highlight()

      assert.has_no.errors(function()
        find_autocmds('FileType', 'cvg')[1].opts.callback({ buf = 5 })
      end)
    end)

    it('読み込み済みの cvg バッファにだけ vim.treesitter.start を呼ぶ', function()
      stub_buffers({ [1] = 'cvg', [2] = 'lua', [3] = 'cvg' }, { [1] = true, [2] = true, [3] = false })

      treesitter.start_highlight()

      assert.same({ { buf = 1, lang = 'cvg' } }, ts_start_calls)
    end)
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
    end)

    describe('nvim-treesitter 未導入', function()
      it('通知せず FileType autocmd は登録する', function()
        treesitter.setup()

        assert.equals(0, #vim._notifications)
        assert.equals(1, #find_autocmds('FileType', 'cvg'))
      end)

      it('User TSUpdate の autocmd は登録する', function()
        treesitter.setup()

        ts_update_callback()
        assert.equals('lcvgc_treesitter_register', group_name(find_autocmds('User', 'TSUpdate')[1].group))
      end)

      it('後から main の parsers が読めるようになると TSUpdate 発火で cvg を登録する', function()
        treesitter.setup()
        local callback = ts_update_callback()

        -- setup 後に nvim-treesitter(main) が読み込まれた状態にする
        -- nvim-treesitter (main) becomes loadable after setup
        local parsers = install_main_parsers()
        callback(TS_UPDATE_EVENT)

        assert_main_parser_info(parsers.cvg)
        assert.equals(0, #vim._notifications)
      end)
    end)

    describe('master ブランチ', function()
      it('invalidate_query_cache("cvg") を呼ぶ', function()
        install_master_parsers()
        local calls = install_query_module()

        treesitter.setup()

        assert.same({ 'cvg' }, calls)
      end)

      it('User TSUpdate の autocmd は登録されるが、発火しても master の parsers モジュールに cvg を代入しない', function()
        local configs, module = install_master_parsers()

        treesitter.setup()
        local callback = ts_update_callback()
        callback(TS_UPDATE_EVENT)

        -- get_parser_configs を持つモジュール本体には触らない
        -- The module table (which has get_parser_configs) is left untouched
        assert.is_nil(rawget(module, 'cvg'))
        -- get_parser_configs() 側は master 用 ParserInfo のまま
        -- get_parser_configs() still holds the master ParserInfo
        assert.same(treesitter.master_parser_info(), configs.cvg)
        assert.equals(1, #find_autocmds('FileType', 'cvg'))
        assert.equals(0, #vim._notifications)
      end)
    end)

    describe('main ブランチ', function()
      it('get_parser_configs が無くてもエラーにならない', function()
        install_main_parsers()

        assert.has_no.errors(function()
          treesitter.setup()
        end)
        assert.equals(0, #vim._notifications)
      end)

      it('現在の parsers テーブルへ即時に cvg を登録する', function()
        local parsers = install_main_parsers()

        treesitter.setup()

        assert_main_parser_info(parsers.cvg)
        -- 既存の言語定義は壊さない / existing entries are untouched
        assert.is_not_nil(parsers.lua)
      end)

      it('augroup lcvgc_treesitter_register(clear=true) で User TSUpdate の autocmd を登録する', function()
        install_main_parsers()

        treesitter.setup()

        -- start_highlight の augroup clear で消されず残っていること
        -- It must survive the augroup clear done by start_highlight
        local aus = find_autocmds('User', 'TSUpdate')
        assert.equals(1, #aus)
        assert.is_function(aus[1].opts.callback)
        assert.equals('lcvgc_treesitter_register', group_name(aus[1].group))
        assert_augroup_cleared('lcvgc_treesitter_register')
      end)

      it('parsers 再読込後に TSUpdate が発火すると新しいテーブルへ cvg を登録する', function()
        local old_parsers = install_main_parsers()
        treesitter.setup()
        local callback = ts_update_callback()

        -- nvim-treesitter の reload_parsers() 相当: package.loaded を新テーブルに差し替える
        -- Equivalent of nvim-treesitter's reload_parsers(): replace package.loaded
        local new_parsers = install_main_parsers()
        assert.is_nil(new_parsers.cvg)

        callback(TS_UPDATE_EVENT)

        assert.are_not.equal(old_parsers, new_parsers)
        assert_main_parser_info(new_parsers.cvg)
      end)

      it('TSUpdate 時に nvim-treesitter.parsers を読めなくても例外を投げない', function()
        install_main_parsers()
        treesitter.setup()
        local callback = ts_update_callback()
        simulate_missing('nvim-treesitter.parsers')

        assert.has_no.errors(function()
          callback(TS_UPDATE_EVENT)
        end)
      end)

      it('TSUpdate 時に cvg の代入が失敗しても例外を投げず通知しない', function()
        install_main_parsers()
        treesitter.setup()
        local callback = ts_update_callback()
        install_readonly_main_parsers()

        assert.has_no.errors(function()
          callback(TS_UPDATE_EVENT)
        end)
        assert.equals(0, #vim._notifications)
      end)

      it('2 回呼んでも TSUpdate / FileType の autocmd が重複しない', function()
        install_main_parsers()

        treesitter.setup()
        treesitter.setup()

        assert.equals(1, #find_autocmds('User', 'TSUpdate'))
        assert.equals(1, #find_autocmds('FileType', 'cvg'))
      end)
    end)

    describe('nvim 本体の query キャッシュ', function()
      it('vim.treesitter.query.get の cvg / highlights のキャッシュを消す', function()
        local get, calls = install_core_query_get()

        treesitter.setup()

        assert.equals(1, #calls)
        assert.equals(get, calls[1].self)
        assert.same({ 'cvg', 'highlights' }, calls[1].args)
      end)

      it('既存の cvg バッファへ vim.treesitter.start する前にキャッシュを消す', function()
        -- clear と start の呼び出し順の記録 / recorded order of clear and start calls
        local order = {}
        install_core_query_get(function() table.insert(order, 'clear') end)
        vim.treesitter.start = function(buf) table.insert(order, 'start:' .. buf) end
        stub_buffers({ [1] = 'cvg' }, { [1] = true })

        treesitter.setup()

        assert.same({ 'clear', 'start:1' }, order)
      end)
    end)

    describe('登録失敗', function()
      it('master で get_parser_configs が失敗しても例外を投げず WARN 通知し FileType autocmd は登録する', function()
        package.loaded['nvim-treesitter.parsers'] = {
          get_parser_configs = function() error('boom') end,
        }

        assert.has_no.errors(function()
          treesitter.setup()
        end)

        assert.equals(1, #vim._notifications)
        assert.equals(vim.log.levels.WARN, vim._notifications[1].level)
        assert.equals(1, vim._notifications[1].msg:find(fail_prefix('master'), 1, true))
        assert.is_truthy(vim._notifications[1].msg:find('boom', 1, true))
        assert.equals(1, #find_autocmds('FileType', 'cvg'))
        assert.equals(1, #find_autocmds('User', 'TSUpdate'))
      end)

      it('main で parsers への代入が失敗しても例外を投げず WARN 通知し FileType autocmd は登録する', function()
        install_readonly_main_parsers()

        assert.has_no.errors(function()
          treesitter.setup()
        end)

        assert.equals(1, #vim._notifications)
        assert.equals(vim.log.levels.WARN, vim._notifications[1].level)
        assert.equals(1, vim._notifications[1].msg:find(fail_prefix('main'), 1, true))
        assert.is_truthy(vim._notifications[1].msg:find('read-only parsers', 1, true))
        assert.equals(1, #find_autocmds('FileType', 'cvg'))
        assert.equals(1, #find_autocmds('User', 'TSUpdate'))
      end)
    end)
  end)
end)
