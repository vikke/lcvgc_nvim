--- LSP診断情報モジュール
--- デーモンTCP JSON経由でLSP診断リクエストを送信し、
--- vim.diagnostic.set()で診断情報を表示する
local M = {}

local connection = require('lcvgc.connection')
local request = require('lcvgc.lsp.request')
local kinds = require('lcvgc.lsp.kinds')

--- 診断用のnamespaceを作成
local ns = vim.api.nvim_create_namespace('lcvgc_diagnostics')

--- pending フラグ（重複リクエスト排除用）
local pending = false

--- デーモンのレスポンスからvim.diagnostic形式に変換する
--- @param items table[] デーモンが返す診断アイテムのリスト
--- @return table[] vim.diagnostic形式の診断リスト
local function convert_items(items)
  local diagnostics = {}
  for _, item in ipairs(items) do
    table.insert(diagnostics, {
      lnum = item.start_line,
      col = item.start_col,
      end_lnum = item.end_line,
      end_col = item.end_col,
      message = item.message,
      severity = kinds.diagnostic_severity(item.severity),
      source = 'lcvgc',
    })
  end
  return diagnostics
end

--- デーモンから診断情報を取得してvim.diagnosticで表示する
--- @param bufnr number バッファ番号
function M.update(bufnr)
  if not connection.is_connected() then
    return
  end

  if pending then
    return
  end

  pending = true

  local payload = request.build('lsp_diagnostics', bufnr, { offset = false })

  connection.request(payload, function(msg)
    pending = false

    if not msg.lsp or msg.lsp.type ~= 'diagnostics' then
      return false
    end

    local diagnostics = convert_items(msg.lsp.items)
    vim.diagnostic.set(ns, bufnr, diagnostics)

    return true
  end)
end

--- namespaceを返す（テスト用）
--- @return number namespace ID
function M.get_namespace()
  return ns
end

return M
