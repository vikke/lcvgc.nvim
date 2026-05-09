-- cvg DSL ファイル用の filetype 設定
-- インデント: 半角スペース 2 文字 (サンプル/データに合わせた事実上の標準)
-- コメント: // 行コメント, /* */ ブロックコメント

vim.bo.expandtab = true
vim.bo.shiftwidth = 2
vim.bo.softtabstop = 2
vim.bo.tabstop = 2

vim.bo.commentstring = '// %s'
vim.bo.comments = 's1:/*,mb:*,ex:*/,://'

-- r: <Enter> でコメント継続, o: o/O でコメント継続, q: gq でコメント整形
-- j: J でのコメント結合をスマートに
vim.opt_local.formatoptions:append('croqj')
