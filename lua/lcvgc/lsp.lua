--- LSP機能オーケストレーターモジュール
--- デーモンTCP JSON経由のLSP機能（diagnostics, hover, goto_definition, document_symbols）を
--- autocmd と keymap で Neovim に統合する
local M = {}

--- デバウンスタイマー管理用
local debounce_timer = nil

--- diagnostics 更新をデバウンス付きで実行する
--- @param bufnr number バッファ番号
--- @param delay number デバウンス遅延（ミリ秒）
local function debounced_diagnostics(bufnr, delay)
  if debounce_timer then
    vim.fn.timer_stop(debounce_timer)
    debounce_timer = nil
  end
  debounce_timer = vim.fn.timer_start(delay, function()
    debounce_timer = nil
    local diagnostics = require('lcvgc.lsp.diagnostics')
    diagnostics.update(bufnr)
  end)
end

--- CVGファイル用のautocmdを設定する（diagnostics自動更新）
--- @param group number augroup ID
--- @param delay number デバウンス遅延（ミリ秒）
local function setup_autocmds(group, delay)
  -- diagnostics 自動更新トリガー
  vim.api.nvim_create_autocmd({ 'BufEnter', 'TextChanged', 'InsertLeave' }, {
    pattern = '*.cvg',
    group = group,
    callback = function(ev)
      debounced_diagnostics(ev.buf, delay)
    end,
  })
end

--- CVGファイル用のキーマップを設定する
--- @param group number augroup ID
local function setup_keymaps(group)
  vim.api.nvim_create_autocmd('FileType', {
    pattern = 'cvg',
    group = group,
    callback = function(ev)
      local bufnr = ev.buf
      local opts = { buffer = bufnr, silent = true }

      -- K: ホバー情報表示
      vim.keymap.set('n', 'K', function()
        require('lcvgc.lsp.hover').show(bufnr)
      end, opts)

      -- gd: 定義ジャンプ
      vim.keymap.set('n', 'gd', function()
        require('lcvgc.lsp.goto_definition').goto_def(bufnr)
      end, opts)

      -- <leader>ds: ドキュメントシンボル一覧
      vim.keymap.set('n', '<leader>ds', function()
        require('lcvgc.lsp.document_symbols').show(bufnr)
      end, opts)
    end,
  })
end

--- デーモン経由LSP機能をセットアップする
--- @param opts table|nil プラグイン設定（opts.debounce でdiagnostics更新遅延を指定）
function M.setup(opts)
  local delay = (opts and opts.debounce) or 150

  local group = vim.api.nvim_create_augroup('lcvgc_lsp', { clear = true })

  setup_autocmds(group, delay)
  setup_keymaps(group)
end

return M
