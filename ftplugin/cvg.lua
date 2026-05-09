-- cvg filetype plugin
-- インデント設定: タブ文字、幅4
-- Indent settings: tab character, width 4
vim.bo.expandtab = false
vim.bo.tabstop = 4
vim.bo.shiftwidth = 4
vim.bo.softtabstop = 4

-- コメント設定: // 行コメント, /* */ ブロックコメント
-- Comment settings: // line comment, /* */ block comment
vim.bo.commentstring = '// %s'
vim.bo.comments = 's1:/*,mb:*,ex:*/,://'

-- 自動整形フラグ
-- r: <Enter> でコメント継続, o: o/O でコメント継続
-- q: gq でコメント整形, j: J でのコメント結合をスマートに
vim.opt_local.formatoptions:append('croqj')
