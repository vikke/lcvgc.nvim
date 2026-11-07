--- lcvgc Tree-sitter 連携モジュール
--- nvim-treesitter（master / main 両ブランチ）へ cvg パーサを登録して :TSInstall cvg を可能にし、
--- cvg バッファで Tree-sitter ハイライトを起動する。
--- nvim-treesitter が未導入でも、登録に失敗しても例外は投げない
--- （登録失敗で require('lcvgc').setup() 全体が止まらないようにするため）。
---
--- Tree-sitter integration module. Registers the cvg parser with nvim-treesitter
--- (both the master and main branches) so that :TSInstall cvg works, and starts
--- Tree-sitter highlighting for cvg buffers. Never raises, even when nvim-treesitter
--- is missing or registration fails, so that require('lcvgc').setup() is not aborted.
local M = {}

--- tree-sitter-cvg のリポジトリ URL / URL of the tree-sitter-cvg repository
local REPO_URL = 'https://github.com/vikke/tree-sitter-cvg'

--- tree-sitter-cvg の取得元ブランチ。
--- master では revision が無いと branch（既定 'master'）の tarball を取りに行くため必須。
--- Branch of tree-sitter-cvg to fetch. Required on master: without a revision it
--- downloads the tarball of `branch` (default 'master'), which does not exist.
local REPO_BRANCH = 'main'

--- User TSUpdate autocmd（main ブランチ向け登録）の augroup 名。
--- HIGHLIGHT_AUGROUP と同じにすると clear=true で互いの autocmd を消し合うため分ける。
--- augroup for the User TSUpdate autocmd (registration for the main branch). Kept apart
--- from HIGHLIGHT_AUGROUP, otherwise clear=true would wipe each other's autocmds.
local REGISTER_AUGROUP = 'lcvgc_treesitter_register'

--- ハイライト起動用 FileType autocmd の augroup 名 / augroup for the FileType highlight autocmd
local HIGHLIGHT_AUGROUP = 'lcvgc_treesitter'

--- nvim-treesitter master ブランチ用のパーサ情報を返す（呼ぶたびに新しいテーブル）
--- get_parser_configs() のテーブルへ代入する形式。
--- requires_generate_from_grammar = false は available_parsers() から除外されないために必要。
--- Returns the parser info for the nvim-treesitter master branch (a fresh table per call),
--- in the shape assigned into get_parser_configs().
--- requires_generate_from_grammar = false keeps cvg in available_parsers().
--- @return table master 用 ParserInfo / ParserInfo for master
function M.master_parser_info()
  return {
    install_info = {
      url = REPO_URL,
      files = { 'src/parser.c', 'src/scanner.c' },
      branch = REPO_BRANCH,
      generate_requires_npm = false,
      requires_generate_from_grammar = false,
    },
    filetype = { 'cvg' },
  }
end

--- nvim-treesitter main ブランチ用のパーサ情報を返す（呼ぶたびに新しいテーブル）
--- master 専用キー（files / filetype 等）は含めない。queries を指定するとリポジトリ側の
--- クエリが同梱の queries/cvg/highlights.scm を隠すため指定しない。
--- tier / revision も意味のある値が無いため指定しない。
--- Returns the parser info for the nvim-treesitter main branch (a fresh table per call).
--- Master-only keys (files, filetype, ...) are omitted. `queries` is not set so the
--- repository's queries cannot shadow the bundled queries/cvg/highlights.scm, and
--- tier / revision are omitted as they have no meaningful value here.
--- @return table main 用 ParserInfo / ParserInfo for main
function M.main_parser_info()
  return {
    install_info = {
      url = REPO_URL,
      branch = REPO_BRANCH,
    },
  }
end

--- nvim-treesitter.parsers モジュールの形からブランチ（API）を判定する
--- get_parser_configs 関数を持つテーブルなら master、それ以外は main とみなす。例外は投げない。
--- Detects the nvim-treesitter branch (API shape) from the parsers module:
--- 'master' for a table with a get_parser_configs function, 'main' otherwise. Never raises.
--- @param parsers any require('nvim-treesitter.parsers') の戻り値 / value of require('nvim-treesitter.parsers')
--- @return string 'master' または 'main' / 'master' or 'main'
function M.detect_api(parsers)
  if type(parsers) == 'table' and type(parsers.get_parser_configs) == 'function' then
    return 'master'
  end
  return 'main'
end

--- nvim-treesitter master のクエリファイルキャッシュから cvg を消す（ベストエフォート）
--- 遅延読み込みでは nvim-treesitter 初期化時に cvg の queries/ が未検出のため、
--- キャッシュに false が入り highlight モジュールの attach が失敗する。それを防ぐ。
--- パーサ登録そのものではないので、失敗は通知せず無視する。
--- Best effort: clears cvg from nvim-treesitter master's query-file cache. With lazy loading,
--- queries/cvg may be missing when nvim-treesitter initialises, caching `false` and breaking
--- the highlight module's attach. Not part of the registration, so failures are ignored.
local function invalidate_master_query_cache()
  local found, query = pcall(require, 'nvim-treesitter.query')
  if found and type(query) == 'table' and type(query.invalidate_query_cache) == 'function' then
    pcall(query.invalidate_query_cache, 'cvg')
  end
end

--- nvim-treesitter master ブランチへ cvg パーサを登録する
--- get_parser_configs() のテーブルへ代入する（__newindex で filetype の登録も行われる）。
--- 失敗時は error を投げる（M.register_parser の pcall で捕捉する）。
--- Registers cvg with the nvim-treesitter master branch by assigning into
--- get_parser_configs() (its __newindex also registers the filetype).
--- Raises on failure (caught by the pcall in M.register_parser).
--- @param parsers table require('nvim-treesitter.parsers') の戻り値 / the parsers module
local function register_master(parsers)
  parsers.get_parser_configs().cvg = M.master_parser_info()
  invalidate_master_query_cache()
end

--- nvim-treesitter main ブランチの parsers テーブルへ cvg を代入する
--- 失敗時は error を投げる（呼び出し側の pcall で捕捉する）。
--- Assigns cvg into the nvim-treesitter main branch's parsers table.
--- Raises on failure (caught by the caller's pcall).
--- @param parsers table require('nvim-treesitter.parsers') の戻り値 / the parsers table
local function assign_main(parsers)
  parsers.cvg = M.main_parser_info()
end

--- User TSUpdate autocmd のコールバック（main ブランチ向け）
--- main は install / update の前に parsers モジュールを読み直してから TSUpdate を発火するため、
--- 毎回 require し直して新しいテーブルへ登録する（古いテーブルを掴むと再読込後に登録されない）。
--- master は User TSUpdate を発火しないが、念のため main と判定したときだけ代入する。
--- :TSInstall の補完でも発火するので、失敗しても通知せず無視する。
--- 値を返さないこと（autocmd の Lua コールバックは true を返すとその autocmd が削除される）。
--- Callback for the User TSUpdate autocmd (for the main branch). main reloads the parsers
--- module and then fires TSUpdate before install/update, so re-require it every time and
--- register into the fresh table (a table captured earlier goes stale). master never fires
--- User TSUpdate, but assign only when the module looks like main just in case.
--- It also fires on :TSInstall completion, so failures are ignored without notifying.
--- Must not return a value: a Lua autocmd callback returning true deletes the autocmd.
local function on_ts_update()
  local found, current = pcall(require, 'nvim-treesitter.parsers')
  if found and type(current) == 'table' and M.detect_api(current) == 'main' then
    pcall(assign_main, current)
  end
end

--- main ブランチ向けの User TSUpdate autocmd を登録する
--- nvim-treesitter の有無・ブランチに関わらず常に登録する（後から main が読み込まれても
--- :TSInstall cvg できるようにするため。master は User TSUpdate を発火しないので無害）。
--- augroup の clear=true で、何度呼んでも autocmd は重複しない。
--- Registers the User TSUpdate autocmd for the main branch. Always registered regardless of
--- whether / which nvim-treesitter is present, so :TSInstall cvg works even if main is loaded
--- later (harmless on master, which never fires User TSUpdate). clear=true keeps it single.
function M.register_ts_update_autocmd()
  vim.api.nvim_create_autocmd('User', {
    pattern = 'TSUpdate',
    group = vim.api.nvim_create_augroup(REGISTER_AUGROUP, { clear = true }),
    callback = on_ts_update,
  })
end

--- nvim-treesitter へ cvg パーサを即時に登録する（:TSInstall cvg を可能にする）
--- nvim-treesitter は任意依存なので、未導入なら通知せず false を返す。
--- 登録に失敗しても例外は投げず、WARN で通知して false を返す。
--- Registers the cvg parser with nvim-treesitter right away (enables :TSInstall cvg).
--- nvim-treesitter is optional: returns false without notifying when it is not installed.
--- Never raises: on failure it notifies at WARN level and returns false.
--- @return boolean 登録できたら true / true if registered
function M.register_parser()
  local found, parsers = pcall(require, 'nvim-treesitter.parsers')
  if not found then
    return false
  end

  local api = M.detect_api(parsers)
  local register = api == 'master' and register_master or assign_main
  local ok, err = pcall(register, parsers)
  if not ok then
    vim.notify(
      'lcvgc: failed to register cvg parser with nvim-treesitter (' .. api .. ' branch): ' .. tostring(err),
      vim.log.levels.WARN
    )
    return false
  end
  return true
end

--- nvim 本体の vim.treesitter.query.get のキャッシュから cvg / highlights を消す（ベストエフォート）
--- query.get は「クエリ無し（nil）」もメモ化する。lazy.nvim の遅延ロードでは runtimepath に
--- lcvgc.nvim が加わっても OptionSet が発火せずキャッシュが残り、そのセッション中 cvg が
--- ハイライトされない。master の invalidate_query_cache に相当する対策（ブランチ共通）。
--- clear は公開 API ではないため、型を確かめてから pcall で呼び、失敗は無視する。
--- Best effort: drops cvg / highlights from the cache of Neovim's vim.treesitter.query.get.
--- query.get memoizes "no query" (nil) too; with lazy.nvim's lazy loading, adding lcvgc.nvim
--- to the runtimepath does not fire OptionSet, so the stale entry would keep cvg unhighlighted
--- for the session. The branch-independent counterpart of master's invalidate_query_cache.
--- clear is not a public API, so its type is checked and it is called through pcall.
function M.invalidate_core_query_cache()
  local query = vim.treesitter and vim.treesitter.query
  local get = type(query) == 'table' and query.get or nil
  if type(get) == 'table' and type(get.clear) == 'function' then
    pcall(get.clear, get, 'cvg', 'highlights')
  end
end

--- cvg バッファで Tree-sitter ハイライトを起動する
--- FileType autocmd で vim.treesitter.start() を直接呼ぶ（nvim-treesitter の自動アタッチに
--- 依存しない。main ブランチは自動アタッチしない）。既に開かれている cvg バッファにも適用する。
--- パーサ未インストール等による vim.treesitter.start() の失敗は無視する。
--- Starts Tree-sitter highlighting for cvg buffers by calling vim.treesitter.start() from a
--- FileType autocmd (independent of nvim-treesitter's auto-attach, which main does not do),
--- and for cvg buffers already open. Failures (e.g. parser not installed) are ignored.
function M.start_highlight()
  vim.api.nvim_create_autocmd('FileType', {
    pattern = 'cvg',
    group = vim.api.nvim_create_augroup(HIGHLIGHT_AUGROUP, { clear = true }),
    callback = function(args)
      pcall(vim.treesitter.start, args.buf, 'cvg')
    end,
  })

  for _, buf in ipairs(vim.api.nvim_list_bufs()) do
    if vim.api.nvim_buf_is_loaded(buf) and vim.bo[buf].filetype == 'cvg' then
      pcall(vim.treesitter.start, buf, 'cvg')
    end
  end
end

--- Tree-sitter 連携を初期化する（冪等: 何度呼んでも autocmd は重複しない）
--- パーサ登録に失敗してもクエリキャッシュの破棄とハイライトの起動は続け、例外は投げない。
--- Sets up Tree-sitter integration (idempotent: autocmds are never duplicated).
--- Even when registration fails it still clears the query cache and starts highlighting,
--- and it never raises.
function M.setup()
  M.register_ts_update_autocmd()
  M.register_parser()
  M.invalidate_core_query_cache()
  M.start_highlight()
end

return M
