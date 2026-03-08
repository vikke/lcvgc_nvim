--- nvim-cmp カスタムソース: MIDI ポート補完
--- nvim-cmp 経由で device ブロック内の port 行に MIDI ポート名を補完する
local M = {}

--- LSP CompletionItemKind.Value = 12
local COMPLETION_KIND_VALUE = 12

--- nvim-cmp ソースオブジェクト
local source = {}
source.__index = source

--- ソースインスタンスを生成する
--- @return table source インスタンス
function source.new()
  return setmetatable({}, source)
end

--- CVG ファイルでのみ補完を有効にする
--- @return boolean
function source:is_available()
  return vim.bo.filetype == 'cvg'
end

--- デバッグ用のソース名を返す
--- @return string
function source:get_debug_name()
  return 'lcvgc'
end

--- 補完トリガー文字を返す
--- @return string[]
function source:get_trigger_characters()
  return { ' ' }
end

--- 補完候補を返す
--- port コンテキスト + device ブロック内の場合のみ MIDI ポート名を返す
--- @param params table nvim-cmp の補完パラメータ
--- @param callback function 補完結果を返すコールバック
function source:complete(params, callback)
  local completion = require('lcvgc.completion')
  local ports = require('lcvgc.ports')

  local line = params.context.cursor_before_line

  -- port コンテキスト判定
  if not completion.is_port_context(line) then
    return
  end

  -- device ブロック内判定
  local bufnr = params.context.bufnr
  local row = vim.api.nvim_win_get_cursor(0)[1]
  if not completion.is_in_device_block(bufnr, row) then
    return
  end

  -- MIDI 出力ポート名を取得
  local names = ports.get_output_ports()
  if #names == 0 then
    return
  end

  -- LSP 準拠の補完アイテムを構築（引用符なし構文）
  local items = {}
  for _, name in ipairs(names) do
    table.insert(items, {
      label = name,
      kind = COMPLETION_KIND_VALUE,
      insertText = name,
      detail = '[MIDI Port]',
    })
  end

  callback({ items = items, isIncomplete = false })
end

--- include パス補完用 nvim-cmp ソース
--- cvgファイルのディレクトリを基準にファイルパス候補を返す
local include_source = {}
include_source.__index = include_source

--- include ソースインスタンスを生成する
--- @return table source インスタンス
function include_source.new()
  return setmetatable({}, include_source)
end

--- CVG ファイルでのみ補完を有効にする
--- @return boolean
function include_source:is_available()
  return vim.bo.filetype == 'cvg'
end

--- デバッグ用のソース名を返す
--- @return string
function include_source:get_debug_name()
  return 'lcvgc_include'
end

--- 補完トリガー文字を返す
--- @return string[]
function include_source:get_trigger_characters()
  return { ' ', '/' }
end

--- ファイルパス文字にマッチするキーワードパターン
--- Keyword pattern matching filename characters
--- @return string vim regex pattern
function include_source:get_keyword_pattern()
  return [[\f\+]]
end

--- include パス補完候補を返す
--- @param params table nvim-cmp の補完パラメータ
--- @param callback function 補完結果を返すコールバック
function include_source:complete(params, callback)
  local completion = require('lcvgc.completion')
  local line = params.context.cursor_before_line

  if not completion.is_include_context(line) then
    return
  end

  local buf_name = vim.api.nvim_buf_get_name(params.context.bufnr)
  if buf_name == '' then
    return
  end

  local base_dir = vim.fn.fnamemodify(buf_name, ':h')
  local partial = completion.get_include_partial(line)
  local candidates = completion.list_include_candidates(base_dir, partial)

  if #candidates > 0 then
    callback({ items = candidates, isIncomplete = true })
  end
end

--- nvim-cmp にソースを登録する
--- CVG ファイルでは preselect を無効化し、Enter は明示選択時のみ確定する
--- @param opts table|nil プラグイン設定（opts.debounce で補完遅延を指定）
function M.setup(opts)
  local ok, cmp = pcall(require, 'cmp')
  if not ok then
    return
  end

  local debounce = (opts and opts.debounce) or 150

  cmp.register_source('lcvgc', source.new())

  -- デーモン経由LSP補完ソースを登録
  local lsp_completion = require('lcvgc.lsp.completion')
  cmp.register_source('lcvgc_lsp', lsp_completion.new())

  -- include パス補完ソースを登録
  cmp.register_source('lcvgc_include', include_source.new())
  cmp.setup.filetype('cvg', {
    preselect = cmp.PreselectMode.None,
    mapping = cmp.mapping.preset.insert({
      ['<CR>'] = cmp.mapping.confirm({ select = false }),
    }),
    performance = {
      debounce = debounce,
    },
    sources = {
      { name = 'lcvgc_include' },
      { name = 'lcvgc' },
      { name = 'lcvgc_lsp' },
    },
  })
end

--- テスト用: ソースインスタンスを生成する
--- @return table source インスタンス
function M.new()
  return source.new()
end

--- テスト用: include ソースインスタンスを生成する
--- @return table source インスタンス
function M.new_include()
  return include_source.new()
end

return M
