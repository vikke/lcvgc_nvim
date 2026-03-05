--- LSPリクエストペイロード構築モジュール
--- デーモンTCP JSON経由でLSPリクエストを送る際に、
--- バッファからsource/offsetを取得し、リクエストペイロードを構築する
local M = {}

--- バッファ全文を文字列で返す
--- @param bufnr number バッファ番号
--- @return string バッファ全文（改行区切り）
function M.get_source(bufnr)
  local lines = vim.api.nvim_buf_get_lines(bufnr, 0, -1, false)
  return table.concat(lines, '\n')
end

--- (row, col) からバイトオフセットに変換する（0始まり）
--- row は 1始まり（Neovim cursor）、col は 0始まり
--- @param bufnr number バッファ番号
--- @param row number 行番号（1始まり）
--- @param col number 列番号（0始まり、バイト単位）
--- @return number バイトオフセット（0始まり）
function M.get_byte_offset(bufnr, row, col)
  local lines = vim.api.nvim_buf_get_lines(bufnr, 0, row, false)
  local offset = 0
  for i = 1, row - 1 do
    offset = offset + #lines[i] + 1 -- 行の長さ + 改行文字
  end
  offset = offset + col
  return offset
end

--- LSPリクエストペイロードを構築する
--- @param type_name string リクエストタイプ（"lsp_completion", "lsp_hover" 等）
--- @param bufnr number バッファ番号
--- @param opts table|nil オプション（offset不要なリクエスト用にoffset=falseを指定可能）
--- @return table リクエストペイロード
function M.build(type_name, bufnr, opts)
  local payload = {
    type = type_name,
    source = M.get_source(bufnr),
  }

  -- opts が nil または opts.offset ~= false の場合にオフセットを追加
  if opts == nil or opts.offset ~= false then
    local cursor = vim.api.nvim_win_get_cursor(0)
    local row = cursor[1]
    local col = cursor[2]
    payload.offset = M.get_byte_offset(bufnr, row, col)
  end

  return payload
end

return M
