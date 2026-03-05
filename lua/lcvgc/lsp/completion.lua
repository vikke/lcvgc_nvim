--- デーモンTCP JSON経由でLSP補完リクエストを送信し、
--- レスポンスをnvim-cmpのカスタムソース形式に変換するモジュール
local M = {}

local connection = require('lcvgc.connection')
local request = require('lcvgc.lsp.request')
local kinds = require('lcvgc.lsp.kinds')

--- nvim-cmp用のカスタムソースオブジェクト
local source = {}
source.__index = source

--- cmpソースインスタンスを生成する
--- @return table 新しいソースインスタンス
function source.new()
  return setmetatable({}, source)
end

--- CVGファイルでのみ補完を有効にする
--- @return boolean CVGファイルならtrue
function source:is_available()
  return vim.bo.filetype == 'cvg'
end

--- デバッグ用のソース名を返す
--- @return string ソース名
function source:get_debug_name()
  return 'lcvgc_lsp'
end

--- LSPレスポンスのアイテムをnvim-cmp形式に変換する
--- @param items table デーモンが返すアイテム配列
--- @return table nvim-cmp形式のアイテム配列
local function convert_items(items)
  local result = {}
  for _, item in ipairs(items) do
    table.insert(result, {
      label = item.label,
      kind = kinds.completion_kind(item.kind),
      detail = item.detail,
    })
  end
  return result
end

--- 補完候補を返す（connection.request経由でデーモンにlsp_completionリクエスト送信）
--- @param params table nvim-cmpの補完パラメータ
--- @param callback function 補完結果を返すコールバック
function source:complete(params, callback)
  if not connection.is_connected() then
    return
  end

  local bufnr = vim.api.nvim_get_current_buf()
  local payload = request.build('lsp_completion', bufnr)

  connection.request(payload, function(msg)
    if msg.lsp and msg.lsp.type == 'completion' then
      local items = convert_items(msg.lsp.items or {})
      callback({ items = items, isIncomplete = false })
      return true
    end
    return false
  end)
end

--- テスト用: ソースインスタンスを生成する
--- @return table 新しいソースインスタンス
function M.new()
  return source.new()
end

return M
