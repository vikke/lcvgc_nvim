local M = {}

function M.setup()
  local hl = vim.api.nvim_set_hl

  -- 予約語
  hl(0, '@keyword.cvg', { fg = '#C792EA', ctermfg = 176 })
  hl(0, '@keyword.play.cvg', { fg = '#C3E88D', ctermfg = 150, bold = true })
  hl(0, '@keyword.stop.cvg', { fg = '#FF5370', ctermfg = 204, bold = true })
  hl(0, '@keyword.repeat.cvg', { fg = '#C792EA', ctermfg = 176, italic = true })
  hl(0, '@keyword.jump.cvg', { fg = '#FFCB6B', ctermfg = 222, bold = true })

  -- 定義名
  hl(0, '@type.definition.cvg', { fg = '#FFCB6B', ctermfg = 222 })
  hl(0, '@function.definition.cvg', { fg = '#FFCB6B', ctermfg = 222 })

  -- 参照名
  hl(0, '@function.cvg', { fg = '#82AAFF', ctermfg = 111 })
  hl(0, '@type.cvg', { fg = '#82AAFF', ctermfg = 111 })

  -- 音名
  hl(0, '@constant.cvg', { fg = '#F78C6C', ctermfg = 209 })

  -- 数値
  hl(0, '@number.cvg', { fg = '#89DDFF', ctermfg = 117 })

  -- ステップパターン
  hl(0, '@string.cvg', { fg = '#C3E88D', ctermfg = 150 })

  -- 確率・重み・テンポ変化
  hl(0, '@number.special.cvg', { fg = '#FF5370', ctermfg = 204 })
  hl(0, '@number.weight.cvg', { fg = '#FF5370', ctermfg = 204 })

  -- コード名
  hl(0, '@string.special.cvg', { fg = '#FF9CAC', ctermfg = 217 })

  -- アルペジオ方向
  hl(0, '@constant.builtin.cvg', { fg = '#80CBC4', ctermfg = 116 })

  -- シャッフル
  hl(0, '@operator.cvg', { fg = '#FFFFFF', ctermfg = 15, bold = true })

  -- 文字列
  hl(0, '@string.special.path.cvg', { fg = '#A5D6A7', ctermfg = 151 })

  -- コメント
  hl(0, '@comment.cvg', { fg = '#546E7A', ctermfg = 66, italic = true })

  -- 括弧
  hl(0, '@punctuation.bracket.cvg', { fg = '#89DDFF', ctermfg = 117 })
end

return M
