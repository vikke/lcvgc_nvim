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
  return { '"' }
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

  -- LSP 準拠の補完アイテムを構築（閉じ引用符は自動ペアリングに委ねる）
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

--- nvim-cmp にソースを登録する
--- cmp が未インストールの場合は何もしない
--- nvim-cmp にソースを登録する
--- cmp が未インストールの場合は何もしない
--- nvim-cmp にソースを登録する
--- cmp が未インストールの場合は何もしない
--- @param opts table|nil プラグイン設定（opts.debounce で補完遅延を指定）
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
  cmp.setup.filetype('cvg', {
    preselect = cmp.PreselectMode.None,
    mapping = cmp.mapping.preset.insert({
      ['<CR>'] = cmp.mapping.confirm({ select = false }),
    }),
    performance = {
      debounce = debounce,
    },
    sources = {
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

return M
