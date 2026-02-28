---
name: nvim-plugin-testing
description: Neovimプラグインのテスト実行とテストコード作成。plenary.nvimまたはbustedを使ったユニットテスト・統合テストを行う。
---

# Neovimプラグインテスト担当

あなたはNeovimプラグインのテスト作成・実行の専門家。

## テスト構成

```
tests/
├── minimal_init.lua       -- テスト用最小設定
├── lcvgc/
│   ├── connection_spec.lua
│   ├── eval_spec.lua
│   ├── layout_spec.lua
│   ├── display_spec.lua
│   └── commands_spec.lua
```

## テストフレームワーク

### plenary.nvim を使用する場合

```lua
-- tests/minimal_init.lua
vim.cmd([[set runtimepath+=.]])
vim.cmd([[set runtimepath+=~/.local/share/nvim/lazy/plenary.nvim]])
```

実行:
```bash
nvim --headless -c "PlenaryBustedDirectory tests/ {minimal_init = 'tests/minimal_init.lua'}"
```

### busted を使用する場合

```bash
busted tests/
```

## テスト作成方針

- 各モジュールに対応するspecファイルを作成
- ソケット通信のテストではモックを使用する
- `describe` / `it` / `before_each` / `after_each` で構造化
- エッジケース（切断、不正JSON、バッファ閉鎖等）をカバーする
- Neovim APIのモックが必要な場合は `tests/helpers.lua` にヘルパーを配置

## テスト実行コマンド

```bash
# 全テスト実行
make test

# 特定ファイルのテスト
nvim --headless -c "PlenaryBustedFile tests/lcvgc/connection_spec.lua {minimal_init = 'tests/minimal_init.lua'}"
```

## テスト記述例

```lua
local describe = describe
local it = it
local assert = assert

describe("connection", function()
  local connection

  before_each(function()
    connection = require("lcvgc.connection")
  end)

  describe("connect", function()
    it("エンジン未起動時にエラー通知する", function()
      -- テスト実装
    end)
  end)
end)
```
