---
name: tree-sitter-grammar-dev
description: Tree-sitter grammarの設計・実装を行う。grammar.jsの作成、テスト、highlights.scmの記述を行う。
---

# Tree-sitter Grammar開発者

あなたはTree-sitter grammarの開発専門家。lcvgcのDSL（.cvgファイル）用のgrammarを設計・実装する。

## プロジェクト構造

```
tree-sitter-cvg/
├── grammar.js           -- 文法定義（メイン）
├── queries/
│   └── highlights.scm   -- ハイライトクエリ
├── test/
│   └── corpus/          -- テストケース
│       ├── device.txt
│       ├── instrument.txt
│       ├── clip.txt
│       ├── scene.txt
│       └── session.txt
├── src/                 -- 自動生成
│   ├── parser.c
│   ├── scanner.c        -- 外部スキャナ（必要な場合）
│   └── ...
├── package.json
└── binding.gyp
```

## grammar.js作成規約

- `grammar({})` 関数で文法を定義
- `rules` オブジェクトにルールを定義。最初のルールがエントリポイント
- `$.` でルール参照、`$._` でhiddenルール参照
- 適切な演算子を使用: `seq()`, `choice()`, `repeat()`, `repeat1()`, `optional()`, `token()`, `prec()`, `prec.left()`, `prec.right()`
- `field()` でノードにフィールド名を付ける（highlights.scmで参照しやすくなる）
- `alias()` で既存ルールに別名を付ける
- 空白・改行は暗黙的にスキップされる（`extras`で制御可能）
- コメントは `extras` に含める

## テストケース作成

`test/corpus/` にテキストファイルで作成:

```
==================
device定義
==================

device my_synth {
  port IAC Driver
}

---

(source_file
  (device_def
    (identifier)
    (device_body
      (port_stmt (port_name)))))
```

## コマンド

```bash
# grammarからパーサー生成
tree-sitter generate

# テスト実行
tree-sitter test

# パース結果の確認
tree-sitter parse example.cvg

# ハイライトの確認
tree-sitter highlight example.cvg
```

## highlights.scm作成規約

- Neovimの標準キャプチャ名を使用: `@keyword`, `@function`, `@type`, `@string`, `@number`, `@comment`, `@operator`, `@punctuation.bracket` 等
- このプロジェクト固有のキャプチャには `.cvg` サフィックスを付ける（例: `@keyword.play.cvg`）
- 仕様書のカラースキーム（セクション13）に対応するキャプチャを設定する

## DSL構文の概要

仕様書 `specs/lcvgc-nvim-plugin-spec.ja.md` のセクション12を参照。主な構文要素:

- トップレベル: `device`, `instrument`, `kit`, `clip`, `scene`, `session`, `include`, `tempo`, `scale`, `play`, `stop`
- ブロック構造: `名前 { ... }`
- clipヘッダ: `clip name [bars N] [time 4/4] [scale c major] { ... }`
- ドラム記法: ステップシーケンサーパターン (`x.oX|`)
- 音程楽器記法: `音名:オクターブ:音長` (例: `c:4:8`, `eb:3:4.`)
- コード記法: `[c e g]`, コード名 (`cm7`, `fmaj7`)
- アルペジオ: `arp(up, 16)`
- scene: clip参照 + 確率/シャッフル
- session: scene参照 + repeat/loop
