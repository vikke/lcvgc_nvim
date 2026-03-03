local M = {}

--- プラグインバージョン
M.version = '0.4.0'

local defaults = {
  port = 9876,
  log_path = '/tmp/lcvgc.log',
  auto_connect = false,
  auto_layout = false,
}

function M.setup(opts)
  opts = vim.tbl_deep_extend('force', defaults, opts or {})
  M.opts = opts

  require('lcvgc.treesitter').setup()
  require('lcvgc.colors').setup()
  require('lcvgc.commands').setup(opts)
  require('lcvgc.lsp').setup()

  require('lcvgc.completion').setup()
  require('lcvgc.cmp_source').setup()

  if opts.auto_connect then
    local connection = require('lcvgc.connection')
    local display = require('lcvgc.display')
    local ok = connection.connect(opts.port, display.on_message)
    if ok then
      require('lcvgc.ports').fetch()
    end
  end

  -- 新規 .cvg ファイル作成時にサンプルテンプレートを自動挿入
  vim.api.nvim_create_autocmd('BufNewFile', {
    pattern = '*.cvg',
    group = vim.api.nvim_create_augroup('lcvgc_template', { clear = true }),
    callback = function(ev)
      local lines = require('lcvgc.template').get_lines()
      vim.api.nvim_buf_set_lines(ev.buf, 0, -1, false, lines)
      vim.bo[ev.buf].modified = false
    end,
  })

  if opts.auto_layout then
    vim.api.nvim_create_autocmd('BufRead', {
      pattern = '*.cvg',
      group = vim.api.nvim_create_augroup('lcvgc_auto_layout', { clear = true }),
      once = true,
      callback = function()
        require('lcvgc.layout').setup({ log_path = opts.log_path })
      end,
    })
  end
end

return M
