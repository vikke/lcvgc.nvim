local M = {}

function M.setup()
  local hl = vim.api.nvim_set_hl

  -- 予約語
  hl(0, '@keyword.cvg', { fg = '#C792EA' })
  hl(0, '@keyword.play.cvg', { fg = '#C3E88D', bold = true })
  hl(0, '@keyword.stop.cvg', { fg = '#FF5370', bold = true })
  hl(0, '@keyword.repeat.cvg', { fg = '#C792EA', italic = true })
  hl(0, '@keyword.jump.cvg', { fg = '#FFCB6B', bold = true })

  -- 定義名
  hl(0, '@type.definition.cvg', { fg = '#FFCB6B' })
  hl(0, '@function.definition.cvg', { fg = '#FFCB6B' })

  -- 参照名
  hl(0, '@function.cvg', { fg = '#82AAFF' })
  hl(0, '@type.cvg', { fg = '#82AAFF' })

  -- 音名
  hl(0, '@constant.cvg', { fg = '#F78C6C' })

  -- 数値
  hl(0, '@number.cvg', { fg = '#89DDFF' })

  -- ステップパターン
  hl(0, '@string.cvg', { fg = '#C3E88D' })

  -- 確率・重み・テンポ変化
  hl(0, '@number.special.cvg', { fg = '#FF5370' })
  hl(0, '@number.weight.cvg', { fg = '#FF5370' })

  -- コード名
  hl(0, '@string.special.cvg', { fg = '#FF9CAC' })

  -- アルペジオ方向
  hl(0, '@constant.builtin.cvg', { fg = '#80CBC4' })

  -- シャッフル
  hl(0, '@operator.cvg', { fg = '#FFFFFF', bold = true })

  -- 文字列
  hl(0, '@string.path.cvg', { fg = '#A5D6A7' })

  -- コメント
  hl(0, '@comment.cvg', { fg = '#546E7A', italic = true })

  -- 括弧
  hl(0, '@punctuation.bracket.cvg', { fg = '#89DDFF' })
end

return M
