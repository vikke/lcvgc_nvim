local M = {}

function M.setup()
  local ok, parsers = pcall(require, 'nvim-treesitter.parsers')
  if not ok then
    return
  end

  local parser_configs = parsers.get_parser_configs()
  parser_configs.cvg = {
    install_info = {
      url = 'https://github.com/vikke/tree-sitter-cvg',
      files = { 'src/parser.c', 'src/scanner.c' },
      branch = 'main',
      generate_requires_npm = false,
      requires_generate_from_grammar = false,
    },
    filetype = { 'cvg' },
  }

  -- cvgバッファのtreesitterハイライトを有効化
  -- nvim-treesitterの遅延読み込みでhighlight moduleが自動アタッチしないため手動で起動
  local function enable_highlight(buf)
    pcall(vim.treesitter.start, buf, 'cvg')
  end

  -- 既に開かれているcvgバッファ
  for _, buf in ipairs(vim.api.nvim_list_bufs()) do
    if vim.api.nvim_buf_is_loaded(buf) and vim.bo[buf].filetype == 'cvg' then
      enable_highlight(buf)
    end
  end

  -- 今後開かれるcvgバッファ
  vim.api.nvim_create_autocmd('FileType', {
    pattern = 'cvg',
    group = vim.api.nvim_create_augroup('lcvgc_treesitter_highlight', { clear = true }),
    callback = function(ev)
      enable_highlight(ev.buf)
    end,
  })
end

return M
