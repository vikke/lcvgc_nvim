--- LSPドキュメントシンボル一覧モジュール
--- デーモンTCP JSON経由でLSPドキュメントシンボルリクエストを送信し、
--- vim.ui.selectで一覧表示する。選択時にカーソルを定義位置へ移動する
local connection = require('lcvgc.connection')
local request = require('lcvgc.lsp.request')

local M = {}

--- シンボルアイテムから表示用ラベルを構築する
--- @param item table シンボルアイテム（name, kind, start_line を含む）
--- @return string 表示用ラベル "[kind] name (line N)"
function M._format_label(item)
  return string.format('[%s] %s (line %d)', item.kind, item.name, item.start_line + 1)
end

--- vim.ui.select の選択コールバック
--- @param items table[] シンボルアイテムのリスト
--- @param choice string|nil 選択されたラベル
--- @param idx number|nil 選択されたインデックス
function M._on_choice(items, choice, idx)
  if not choice or not idx then
    return
  end
  local item = items[idx]
  vim.api.nvim_win_set_cursor(0, { item.start_line + 1, item.start_col })
end

--- ドキュメントシンボルレスポンスのハンドラ
--- @param msg table デーモンからのレスポンスメッセージ
--- @return boolean メッセージを処理したかどうか
function M._handle_response(msg)
  if not msg.lsp then
    return false
  end

  if msg.lsp.type ~= 'document_symbols' then
    return false
  end

  local items = msg.lsp.items
  if not items or #items == 0 then
    vim.notify('No symbols found', vim.log.levels.INFO)
    return true
  end

  local labels = {}
  for _, item in ipairs(items) do
    table.insert(labels, M._format_label(item))
  end

  vim.ui.select(labels, { prompt = 'Document Symbols:' }, function(choice, idx)
    M._on_choice(items, choice, idx)
  end)

  return true
end

--- ドキュメントシンボル一覧を取得してvim.ui.selectで表示する
--- 選択時にカーソルをそのシンボルの定義位置へ移動する
--- @param bufnr number バッファ番号
function M.show(bufnr)
  if not connection.is_connected() then
    return
  end

  local payload = request.build('lsp_document_symbols', bufnr, { offset = false })
  connection.request(payload, M._handle_response)
end

return M
