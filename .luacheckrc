-- luacheck 設定 / luacheck configuration
-- Neovim Lua プラグイン向け: グローバル `vim` を許可する
-- For Neovim Lua plugins: allow the global `vim`
std = "luajit"

globals = {
  "vim",
}

-- 既存コードの慣用パターンを許容する
-- Allow idiomatic patterns used throughout the codebase
ignore = {
  "212", -- 未使用の引数（コールバック等の固定シグネチャ由来）/ unused args from fixed callback signatures
  "542", -- 意図的な空 if 分岐 / intentional empty if branch
}

-- テストコードは busted のグローバル(describe/it/assert 等)と
-- ヘルパー(reload_module/clear_notifications)を使う
-- Test code uses busted globals (describe/it/assert ...) and
-- helpers (reload_module/clear_notifications)
files["tests/"] = {
  std = "+busted",
  globals = {
    "vim",
    "reload_module",
    "clear_notifications",
  },
}
