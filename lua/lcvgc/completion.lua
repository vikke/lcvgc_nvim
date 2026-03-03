local M = {}

function M.is_port_context(line)
  return line:match('^%s*port%s+"') ~= nil
end

function M.is_in_device_block(bufnr, row)
  for i = row - 1, 1, -1 do
    local prev = vim.api.nvim_buf_get_lines(bufnr, i - 1, i, false)[1]
    if prev:match('^%s*device%s+%S+%s*{') then
      return true
    end
    if prev:match('^%s*}') then
      return false
    end
  end
  return false
end

function M.trigger_port_completion()
  local ports = require('lcvgc.ports')
  local names = ports.get_output_ports()
  if #names == 0 then
    return
  end

  local line = vim.api.nvim_get_current_line()
  local col = vim.fn.col('.')
  local before = line:sub(1, col - 1)
  local start = before:find('"[^"]*$')
  if not start then
    return
  end

  local items = {}
  for _, name in ipairs(names) do
    table.insert(items, {
      word = name .. '"',
      abbr = name,
      menu = '[MIDI Port]',
    })
  end

  vim.fn.complete(start + 1, items)
end

--- 補完セットアップ
--- nvim-cmp がある場合は cmp_source.lua に委譲し、TextChangedI autocmd を登録しない
function M.setup()
  local has_cmp = pcall(require, 'cmp')
  if has_cmp then
    return
  end

  -- cmp 未インストール時のフォールバック: TextChangedI による直接補完
  vim.api.nvim_create_autocmd('TextChangedI', {
    pattern = '*.cvg',
    group = vim.api.nvim_create_augroup('lcvgc_port_completion', { clear = true }),
    callback = function()
      local line = vim.api.nvim_get_current_line()
      local col = vim.fn.col('.')
      local before = line:sub(1, col - 1)

      if not M.is_port_context(before) then
        return
      end

      local bufnr = vim.api.nvim_get_current_buf()
      local row = vim.api.nvim_win_get_cursor(0)[1]
      if not M.is_in_device_block(bufnr, row) then
        return
      end

      M.trigger_port_completion()
    end,
  })
end

return M
