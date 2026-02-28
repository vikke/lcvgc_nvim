local connection = require('lcvgc.connection')

local M = {}

M._last_source_map = nil

function M.read_file(path)
  local f = io.open(path, 'r')
  if not f then
    return nil, 'Cannot read file: ' .. path
  end
  local content = f:read('*a')
  f:close()
  local lines = {}
  for line in (content .. '\n'):gmatch('(.-)\n') do
    table.insert(lines, line)
  end
  -- 末尾の空行を除去（最後の\nで生成される空文字列）
  if #lines > 0 and lines[#lines] == '' then
    table.remove(lines)
  end
  return lines, nil
end

function M.expand_includes(lines, filepath, base_dir, visited)
  visited = visited or {}
  local result = {}
  local source_map = {}

  for i, line in ipairs(lines) do
    local include_path = line:match('^%s*include%s+"([^"]+)"%s*$')
    if include_path then
      local full_path = base_dir .. '/' .. include_path
      -- 正規化（簡易）
      local normalized = vim.fn.fnamemodify(full_path, ':p')

      if visited[normalized] then
        -- 重複include: スキップ
      else
        visited[normalized] = true
        local inc_lines, err = M.read_file(full_path)
        if not inc_lines then
          return nil, nil, err .. ' (included from ' .. filepath .. ':' .. i .. ')'
        end
        local inc_dir = full_path:match('(.+)/') or base_dir
        local expanded, sub_map, sub_err = M.expand_includes(inc_lines, full_path, inc_dir, visited)
        if sub_err then
          return nil, nil, sub_err
        end
        for _, el in ipairs(expanded) do
          table.insert(result, el)
        end
        for _, sm in ipairs(sub_map) do
          table.insert(source_map, sm)
        end
      end
    else
      table.insert(result, line)
      table.insert(source_map, { file = filepath, line = i })
    end
  end

  return result, source_map, nil
end

function M.eval_file()
  local bufnr = vim.api.nvim_get_current_buf()
  local filepath = vim.api.nvim_buf_get_name(bufnr)
  local line_count = vim.api.nvim_buf_line_count(bufnr)
  local lines = vim.api.nvim_buf_get_lines(bufnr, 0, line_count, false)
  local base_dir = vim.fn.fnamemodify(filepath, ':h')

  local expanded, source_map, err = M.expand_includes(lines, filepath, base_dir, {})
  if err then
    vim.notify('lcvgc: ' .. err, vim.log.levels.ERROR)
    return
  end

  M._last_source_map = source_map
  local text = table.concat(expanded, '\n')
  connection.send({ type = 'eval', source = text })
end

function M.eval_selection()
  local start_line = vim.fn.line("'<")
  local end_line = vim.fn.line("'>")
  local lines = vim.api.nvim_buf_get_lines(0, start_line - 1, end_line, false)
  local text = table.concat(lines, '\n')
  connection.send({ type = 'eval', source = text })
end

function M.eval_paragraph()
  local cursor = vim.api.nvim_win_get_cursor(0)
  local row = cursor[1]
  local line_count = vim.api.nvim_buf_line_count(0)

  local start_line = row
  for i = row - 1, 1, -1 do
    local line = vim.api.nvim_buf_get_lines(0, i - 1, i, false)[1]
    if line:match('^%s*$') then
      break
    end
    start_line = i
  end

  local end_line = row
  for i = row + 1, line_count do
    local line = vim.api.nvim_buf_get_lines(0, i - 1, i, false)[1]
    if line:match('^%s*$') then
      break
    end
    end_line = i
  end

  local lines = vim.api.nvim_buf_get_lines(0, start_line - 1, end_line, false)
  local text = table.concat(lines, '\n')
  connection.send({ type = 'eval', source = text })
end

return M
