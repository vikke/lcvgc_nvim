local M = {}

function M.setup()
  vim.api.nvim_create_autocmd('FileType', {
    pattern = 'cvg',
    group = vim.api.nvim_create_augroup('lcvgc_lsp', { clear = true }),
    callback = function()
      vim.lsp.start({
        name = 'lcvgc-lsp',
        cmd = { 'lcvgc-lsp' },
        root_dir = vim.fn.getcwd(),
      })
    end,
  })
end

return M
