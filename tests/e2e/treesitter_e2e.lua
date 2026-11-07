-- nvim-treesitter 連携（cvg パーサ登録）の headless E2E テスト。
-- 実物の nvim-treesitter（master / main ブランチのどちらか）を runtimepath に載せ、
-- lcvgc.treesitter.setup() と lcvgc.setup() 全体が例外無く完走すること、
-- ブランチごとの API で cvg パーサが登録され :TSInstall の補完候補に出ることを検証する。
-- あわせて、nvim-treesitter より先に setup() した場合（後読み）の登録と、
-- nvim 本体の vim.treesitter.query.get に残った古いキャッシュの破棄も検証する。
-- ネットワーク・デーモン・コンパイル済みパーサは不要。
--
-- Headless E2E test for the nvim-treesitter integration (cvg parser registration).
-- Puts a real nvim-treesitter checkout (master or main branch) on the runtimepath and
-- verifies that lcvgc.treesitter.setup() and the whole lcvgc.setup() finish without
-- errors, and that the cvg parser is registered through the branch-specific API and
-- offered by :TSInstall completion. It also verifies registration when setup() runs
-- before nvim-treesitter is loaded (late load), and that a stale entry in the core
-- vim.treesitter.query.get cache is dropped. No network, daemon, or compiled parser is needed.
--
-- nvim-treesitter の checkout を用意する（初回のみネットワークが必要）
-- Prepare nvim-treesitter checkouts (network is needed only once):
--   git clone -b master https://github.com/nvim-treesitter/nvim-treesitter /tmp/nts-master
--   git clone -b main   https://github.com/nvim-treesitter/nvim-treesitter /tmp/nts-main
-- 実行（リポジトリ直下で、ブランチごとに 1 回ずつ）。XDG_* を空の一時ディレクトリに向け、
-- ~/.local 等へ書き込まず、packpath 上の nvim-treesitter も見えないようにする。
-- Run from the repository root, once per branch. Point XDG_* to empty temp directories so
-- nothing is written to ~/.local etc. and no nvim-treesitter on the packpath is visible:
--   export XDG_DATA_HOME=$(mktemp -d) XDG_STATE_HOME=$(mktemp -d)
--   export XDG_CACHE_HOME=$(mktemp -d) XDG_CONFIG_HOME=$(mktemp -d)
--   LCVGC_E2E_EXPECT_BRANCH=master LCVGC_E2E_NVIM_TREESITTER=/tmp/nts-master \
--     nvim --headless -u NONE -i NONE +"luafile tests/e2e/treesitter_e2e.lua"
--   LCVGC_E2E_EXPECT_BRANCH=main LCVGC_E2E_NVIM_TREESITTER=/tmp/nts-main \
--     nvim --headless -u NONE -i NONE +"luafile tests/e2e/treesitter_e2e.lua"
-- ブランチは get_parser_configs() の有無で自動判定する。
-- LCVGC_E2E_EXPECT_BRANCH=master|main を指定すると、判定結果が一致することも検証する。
-- LCVGC_E2E_NVIM_TREESITTER 未指定時は SKIP（exit 0）。
-- The branch is detected by the presence of get_parser_configs().
-- With LCVGC_E2E_EXPECT_BRANCH=master|main, the detected branch is also checked.
-- Without LCVGC_E2E_NVIM_TREESITTER the test is SKIPPED (exit 0).

-- プロジェクトの lua/ を package.path に追加
-- Add the project's lua/ to package.path
package.path = './lua/?.lua;./lua/?/init.lua;' .. package.path

-- 終了時にユーザーの shada を書き換えない / do not overwrite the user's shada on exit
vim.o.shadafile = 'NONE'

--- nvim-treesitter の checkout パス / path to the nvim-treesitter checkout
local nts_path = os.getenv('LCVGC_E2E_NVIM_TREESITTER')
if not nts_path or nts_path == '' then
  print('SKIP: LCVGC_E2E_NVIM_TREESITTER is not set')
  vim.cmd('qall!')
  return
end
nts_path = vim.fs.normalize(nts_path)

--- 期待するブランチ（任意）/ expected branch (optional): 'master' | 'main' | nil
local expect_branch = os.getenv('LCVGC_E2E_EXPECT_BRANCH')

--- tree-sitter-cvg のリポジトリ URL / repository URL of tree-sitter-cvg
local CVG_URL = 'https://github.com/vikke/tree-sitter-cvg'

-- 失敗したテスト名 / names of failed checks
local failures = {}

--- 結果を表示し、失敗を記録する / print a result and record failures
--- @param name string テスト名 / check name
--- @param ok boolean 成否 / result
--- @param detail string|nil 失敗時の補足 / detail on failure
local function check(name, ok, detail)
  if ok then
    print('  ok - ' .. name)
  else
    print('  FAIL - ' .. name .. (detail and ('  (' .. detail .. ')') or ''))
    table.insert(failures, name)
  end
end

--- 結果を出力して終了する（失敗があれば exit 1）
--- Print the summary and quit (exit 1 on failure).
local function finish()
  print('')
  if #failures == 0 then
    print('E2E: all checks passed')
    vim.cmd('qall!')
  else
    print('E2E: ' .. #failures .. ' check(s) failed')
    vim.cmd('cquit 1')
  end
end

-- vim.notify を記録する（出力を汚さず、警告の有無を検証するため）
-- Record vim.notify calls (keeps output clean and lets us assert on warnings)
--- @type { msg: string, level: integer|nil }[]
local notified = {}
vim.notify = function(msg, level)
  table.insert(notified, { msg = tostring(msg), level = level })
end

--- 指定インデックス以降に WARN 以上の通知があれば、その本文を返す
--- Return the first notification at WARN or above since the given index.
--- @param from integer 調べ始める notified のインデックス / first index of `notified` to inspect
--- @return string|nil 見つかった通知の本文。無ければ nil / message, or nil if none
local function warning_since(from)
  for i = from, #notified do
    local level = notified[i].level or vim.log.levels.INFO
    if level >= vim.log.levels.WARN then
      return notified[i].msg
    end
  end
  return nil
end

--- setup 系の関数を実行し、例外も WARN 以上の通知も出ないことを検証する
--- Run a setup function and check that it neither raises nor emits a warning.
--- @param label string check 名の接頭辞 / prefix of the check names
--- @param fn fun() 実行する関数 / function to run
local function check_setup(label, fn)
  local mark = #notified + 1
  local ok, err = pcall(fn)
  check(label .. ' does not raise', ok, tostring(err))
  local warn = warning_since(mark)
  check(label .. ' emits no warning', warn == nil, warn)
end

--- 指定 augroup・イベントの autocmd を取得する（augroup が無ければ空）
--- Get autocmds of the given augroup/event (empty if the augroup does not exist).
--- @param group string augroup 名 / augroup name
--- @param event string イベント名 / event name
--- @return table[] autocmd の一覧 / list of autocmds
local function autocmds_of(group, event)
  local ok, res = pcall(vim.api.nvim_get_autocmds, { group = group, event = event })
  return ok and res or {}
end

--- augroup lcvgc_treesitter に FileType cvg の autocmd があるか
--- Whether augroup lcvgc_treesitter has a FileType autocmd for cvg.
--- @return boolean
local function has_ft_autocmd()
  for _, au in ipairs(autocmds_of('lcvgc_treesitter', 'FileType')) do
    if au.pattern == 'cvg' then
      return true
    end
  end
  return false
end

--- `User TSUpdate` の autocmd 数（全 augroup）/ number of `User TSUpdate` autocmds (all groups)
--- @return integer autocmd 数 / number of autocmds
local function count_tsupdate_autocmds()
  return #vim.api.nvim_get_autocmds({ event = 'User', pattern = 'TSUpdate' })
end

--- リストに値が含まれるか / whether the list contains the value
--- @param list any[]|nil 調べるリスト / list to search
--- @param value any 探す値 / value to find
--- @return boolean 含まれていれば true / true if the list contains the value
local function contains(list, value)
  return type(list) == 'table' and vim.list_contains(list, value)
end

--- `:TSInstall cv<Tab>` の補完候補を取得する
--- Get the completion candidates of `:TSInstall cv<Tab>`.
--- @return boolean ok 補完が例外無く取れたか / whether completion succeeded
--- @return string[]|string 候補、または失敗時のエラー / candidates, or the error on failure
local function tsinstall_completion()
  return pcall(vim.fn.getcompletion, 'TSInstall cv', 'cmdline')
end

--- 登録されたパーサ情報の install_info.url を取り出す（無ければ nil）
--- Extract install_info.url from a registered parser entry (nil if absent).
--- @param info table|nil パーサ情報 / parser entry
--- @return string|nil URL / url
local function install_url(info)
  return type(info) == 'table' and type(info.install_info) == 'table' and info.install_info.url or nil
end

--- nvim 本体の vim.treesitter.query.get('cvg', 'highlights') が nil を返すか（= nil がキャッシュされた状態）
--- Whether the core vim.treesitter.query.get('cvg', 'highlights') returns nil (i.e. a cached nil).
--- 例外（パーサ未インストール等）は「nil ではない」とみなす。
--- An error (e.g. no compiled parser) counts as "not nil".
--- @return boolean nil を返したら true / true if it returned nil
local function cvg_query_is_nil()
  local ok, query = pcall(vim.treesitter.query.get, 'cvg', 'highlights')
  return ok and query == nil
end

-- 0) nvim 本体: vim.treesitter.query.get は memoize され、非公開の clear() を持つ
--    （lcvgc.treesitter.setup() が cvg/highlights のキャッシュ破棄に使う）
-- 0) nvim core: vim.treesitter.query.get is memoized and has the private clear()
--    (used by lcvgc.treesitter.setup() to drop the cvg/highlights cache entry)
local query_get = vim.treesitter.query.get
check('vim.treesitter.query.get has clear() (private memoize API)',
  type(query_get) == 'table' and type(query_get.clear) == 'function', type(query_get))

-- lcvgc の queries/ が rtp に無い状態で cvg/highlights を引き、nil をキャッシュさせる
-- （lcvgc ロード前に markdown の ```cvg injection 等で引かれた状態の再現）。
-- その後 lazy.nvim の遅延ロードと同じく、起動処理中（OptionSet が発火しない）に lcvgc を rtp に載せる。
-- Look up cvg/highlights while lcvgc's queries/ is not on rtp so that nil gets cached
-- (as when a markdown ```cvg injection looks it up before lcvgc is loaded), then put lcvgc
-- on rtp during startup (OptionSet does not fire), like lazy.nvim's lazy loading does.
local query_cache_stale = cvg_query_is_nil()
vim.opt.rtp:prepend(vim.fn.getcwd())
query_cache_stale = query_cache_stale
  and #vim.api.nvim_get_runtime_file('queries/cvg/highlights.scm', true) > 0
  and cvg_query_is_nil()
if query_cache_stale then
  print('  # vim.treesitter.query.get keeps a stale nil for cvg/highlights')
else
  print('  # vim.treesitter.query.get has no stale nil for cvg/highlights; cache check skipped')
end

-- 1) nvim-treesitter を rtp に載せる前（未導入状態）の setup()
-- 1) setup() before nvim-treesitter is on rtp (not installed yet)
local nts_visible = package.loaded['nvim-treesitter.parsers'] ~= nil
  or #vim.api.nvim_get_runtime_file('lua/nvim-treesitter/parsers.lua', true) > 0
check('nvim-treesitter is not on runtimepath yet', not nts_visible,
  'found on runtimepath/packpath; point XDG_DATA_HOME to an empty directory')
if nts_visible then
  finish()
  return
end
check_setup('lcvgc.treesitter.setup() without nvim-treesitter', function()
  require('lcvgc.treesitter').setup()
end)
-- 未導入でも main の後読みに備えて User TSUpdate の autocmd は登録される（master でも 1 個）
-- The User TSUpdate autocmd is registered even without nvim-treesitter, for a later main (also on master)
--- @type integer setup() 1 回目の後の User TSUpdate autocmd 数 / number of User TSUpdate autocmds after the first setup()
local tsupdate_initial = count_tsupdate_autocmds()
check('without nvim-treesitter: User TSUpdate autocmd is registered', tsupdate_initial == 1,
  'count: ' .. tsupdate_initial)
check('without nvim-treesitter: FileType cvg autocmd exists in augroup lcvgc_treesitter', has_ft_autocmd())
if query_cache_stale then
  check('setup() drops the stale cvg/highlights entry of vim.treesitter.query.get', not cvg_query_is_nil())
end

-- 2) nvim-treesitter を lazy.nvim 等と同じく rtp に載せ、plugin/ を読み込む
-- 2) Put nvim-treesitter on rtp and source its plugin/ like a plugin manager does
check('nvim-treesitter checkout exists: ' .. nts_path,
  vim.fn.isdirectory(nts_path .. '/lua/nvim-treesitter') == 1)
vim.opt.rtp:prepend(nts_path)
local plugin_ok, plugin_err = pcall(function()
  for _, file in ipairs(vim.fn.glob(nts_path .. '/plugin/*', false, true)) do
    vim.cmd.source(vim.fn.fnameescape(file))
  end
end)
check('nvim-treesitter plugin/ scripts load', plugin_ok, tostring(plugin_err))

local parsers_ok, parsers = pcall(require, 'nvim-treesitter.parsers')
check('nvim-treesitter.parsers is loadable', parsers_ok, tostring(parsers))
if not parsers_ok then
  finish()
  return
end

-- ブランチ判定: master は get_parser_configs() を持ち、main は持たない
-- Branch detection: master has get_parser_configs(), main does not
--- @type 'master'|'main'
local branch = type(parsers.get_parser_configs) == 'function' and 'master' or 'main'
print('  # nvim-treesitter branch: ' .. branch)
if expect_branch and expect_branch ~= '' then
  check('detected branch is ' .. expect_branch, branch == expect_branch, 'detected: ' .. branch)
end

-- 3) 後読み: setup() の後で nvim-treesitter が読み込まれた場合
-- 3) Late load: nvim-treesitter is loaded after setup()
if branch == 'main' then
  -- main: install/update 冒頭の reload_parsers() と同じ手順（パーサ表の作り直し → User TSUpdate）で
  -- setup() を呼び直さなくても cvg が登録される
  -- main: without calling setup() again, cvg is registered by the same steps as reload_parsers()
  -- at the start of install/update (rebuild the parser table, then fire User TSUpdate)
  package.loaded['nvim-treesitter.parsers'] = nil
  local late = require('nvim-treesitter.parsers')
  local late_ok, late_err = pcall(vim.api.nvim_exec_autocmds, 'User', { pattern = 'TSUpdate' })
  check('main (late load): User TSUpdate autocmds run without error', late_ok, tostring(late_err))
  check('main (late load): cvg is registered by User TSUpdate', install_url(late.cvg) == CVG_URL,
    tostring(install_url(late.cvg)))
  local late_comp_ok, late_comp = tsinstall_completion()
  check('main (late load): :TSInstall completion offers cvg', late_comp_ok and contains(late_comp, 'cvg'),
    late_comp_ok and vim.inspect(late_comp) or tostring(late_comp))
else
  -- master は User TSUpdate を発火しないので後読みは対象外。
  -- 第三者が発火しても master の parsers モジュールに cvg を代入しない（無害）ことだけ確認する
  -- master never fires User TSUpdate, so late load is out of scope. Only check that firing it
  -- (e.g. by a third party) does not put cvg into master's parsers module (harmless)
  print('  # master (late load): not supported because master never fires User TSUpdate')
  local fire_ok, fire_err = pcall(vim.api.nvim_exec_autocmds, 'User', { pattern = 'TSUpdate' })
  check('master: firing User TSUpdate does not raise', fire_ok, tostring(fire_err))
  check('master: User TSUpdate does not put cvg into the parsers module', rawget(parsers, 'cvg') == nil)
end

-- 4) nvim-treesitter 導入後の lcvgc.treesitter.setup()（即時登録）
-- 4) lcvgc.treesitter.setup() with nvim-treesitter available (immediate registration)
check_setup('lcvgc.treesitter.setup()', function()
  require('lcvgc.treesitter').setup()
end)
local tsupdate_count = count_tsupdate_autocmds()
check('setup() again does not duplicate User TSUpdate autocmds', tsupdate_count == tsupdate_initial,
  tsupdate_initial .. ' -> ' .. tsupdate_count)

-- 5) ブランチ別のパーサ登録
-- 5) Branch-specific parser registration
if branch == 'master' then
  -- master: get_parser_configs() に cvg が登録される
  -- master: cvg is registered in get_parser_configs()
  local cfg = parsers.get_parser_configs().cvg
  check('master: get_parser_configs().cvg is registered', cfg ~= nil)
  check('master: cvg install_info.url', install_url(cfg) == CVG_URL, tostring(install_url(cfg)))
  local avail_ok, avail = pcall(parsers.available_parsers)
  check('master: available_parsers() contains cvg', avail_ok and contains(avail, 'cvg'),
    not avail_ok and tostring(avail) or nil)
else
  -- main: require('nvim-treesitter.parsers') のテーブルに cvg が登録される
  -- main: cvg is registered in the table returned by require('nvim-treesitter.parsers')
  local current = require('nvim-treesitter.parsers')
  check('main: parsers.cvg is registered', current.cvg ~= nil)
  check('main: cvg install_info.url', install_url(current.cvg) == CVG_URL, tostring(install_url(current.cvg)))

  -- main: install/update 時の reload_parsers() と同じ手順でパーサ表を作り直しても cvg が残る
  -- main: cvg survives the same parser-table reload that install/update performs
  package.loaded['nvim-treesitter.parsers'] = nil
  local reloaded = require('nvim-treesitter.parsers')
  local exec_ok, exec_err = pcall(vim.api.nvim_exec_autocmds, 'User', { pattern = 'TSUpdate' })
  check('main: User TSUpdate autocmds run without error', exec_ok, tostring(exec_err))
  check('main: table was really reloaded', reloaded ~= current)
  check('main: cvg is re-registered after reload + TSUpdate', reloaded.cvg ~= nil)

  -- main: :TSInstall の候補元である get_available() に cvg が含まれる
  -- main: get_available() (source of :TSInstall candidates) contains cvg
  local avail_ok, avail = pcall(function()
    return require('nvim-treesitter.config').get_available()
  end)
  check('main: config.get_available() contains cvg', avail_ok and contains(avail, 'cvg'),
    not avail_ok and tostring(avail) or nil)
end

-- 6) ユーザーから見える挙動: :TSInstall cv<Tab> で cvg が補完される（両ブランチ共通）
-- 6) User-facing behaviour: `:TSInstall cv<Tab>` completes cvg (both branches)
local comp_ok, comp = tsinstall_completion()
check(':TSInstall completion offers cvg', comp_ok and contains(comp, 'cvg'),
  comp_ok and vim.inspect(comp) or tostring(comp))

-- 7) cvg バッファ用の FileType autocmd（augroup lcvgc_treesitter）
-- 7) FileType autocmd for cvg buffers (augroup lcvgc_treesitter)
check('FileType cvg autocmd exists in augroup lcvgc_treesitter', has_ft_autocmd())

-- コンパイル済みパーサが無くても、cvg バッファを開いて例外にならない
-- Opening a cvg buffer does not raise even without the compiled parser
vim.cmd('enew')
vim.api.nvim_buf_set_lines(0, 0, -1, false, { 'tempo 120' })
local ft_ok, ft_err = pcall(function()
  vim.bo.filetype = 'cvg'
end)
check('setting filetype=cvg does not raise', ft_ok, tostring(ft_err))

-- 8) lcvgc.setup() 全体（デーモン無し）。treesitter.setup() の再呼び出しも兼ねる
-- 8) The whole lcvgc.setup() without a daemon (also calls treesitter.setup() again)
check_setup('lcvgc.setup({ auto_connect = false })', function()
  require('lcvgc').setup({ auto_connect = false })
end)
-- setup() の後段（コマンド定義・最後の BufNewFile autocmd）まで到達している
-- setup() reached its later steps (user commands and the final BufNewFile autocmd)
check('lcvgc.setup() defined :LcvgcConnect', vim.fn.exists(':LcvgcConnect') == 2)
check('lcvgc.setup() reached the end (augroup lcvgc_tutorial)',
  #autocmds_of('lcvgc_tutorial', 'BufNewFile') > 0)
-- setup() を繰り返しても User TSUpdate の autocmd が増えない（augroup clear）
-- Repeated setup() does not duplicate User TSUpdate autocmds (augroup is cleared)
tsupdate_count = count_tsupdate_autocmds()
check('repeated lcvgc.setup() does not duplicate User TSUpdate autocmds', tsupdate_count == tsupdate_initial,
  tsupdate_initial .. ' -> ' .. tsupdate_count)

finish()
