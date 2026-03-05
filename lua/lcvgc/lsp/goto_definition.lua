--- LSP定義ジャンプモジュール
--- デーモンTCP JSON経由でLSP定義ジャンプリクエストを送信し、
--- カーソルを定義位置に移動する
local connection = require('lcvgc.connection')
local request = require('lcvgc.lsp.request')

local M = {}

--- 定義ジャンプレスポンスのハンドラ
--- @param msg table デーモンからのレスポンスメッセージ
--- @return boolean メッセージを処理したかどうか
function M._handle_response(msg)
  if not msg.lsp then
    return false
  end

  if msg.lsp.type ~= 'goto_definition' then
    return false
  end

  if msg.lsp.location == nil then
    vim.notify('Definition not found', vim.log.levels.INFO)
    return true
  end

  local location = msg.lsp.location
  -- start_line は 0始まりなので +1 して Neovim の 1始まり行番号に変換
  vim.api.nvim_win_set_cursor(0, { location.start_line + 1, location.start_col })
  return true
end

--- カーソル位置のシンボル定義へジャンプする
--- @param bufnr number バッファ番号
function M.goto_def(bufnr)
  if not connection.is_connected() then
    return
  end

  local payload = request.build('lsp_goto_definition', bufnr)
  connection.request(payload, M._handle_response)
end

return M
