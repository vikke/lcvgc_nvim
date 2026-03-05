--- LSPホバー表示モジュール
--- デーモンTCP JSON経由でLSPホバーリクエストを送信し、
--- floating windowで結果を表示する
local connection = require('lcvgc.connection')
local request = require('lcvgc.lsp.request')

local M = {}

--- ホバーレスポンスのハンドラ
--- @param msg table デーモンからのレスポンスメッセージ
--- @return boolean メッセージを処理したかどうか
function M._handle_response(msg)
  if not msg.lsp then
    return false
  end

  if msg.lsp.type ~= 'hover' then
    return false
  end

  if msg.lsp.info == nil then
    vim.notify('No hover information', vim.log.levels.INFO)
    return true
  end

  local content = msg.lsp.info.content
  local lines = vim.split(content, '\n')
  vim.lsp.util.open_floating_preview(lines, 'markdown', { focus = false })
  return true
end

--- カーソル位置のホバー情報をデーモンから取得してfloating windowで表示する
--- @param bufnr number バッファ番号
function M.show(bufnr)
  if not connection.is_connected() then
    return
  end

  local payload = request.build('lsp_hover', bufnr)
  connection.request(payload, M._handle_response)
end

return M
