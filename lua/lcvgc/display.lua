local M = {}

local eval_buf = nil
local eval_win = nil
local last_status = nil

function M.get_eval_buf()
  if eval_buf and vim.api.nvim_buf_is_valid(eval_buf) then
    return eval_buf
  end
  eval_buf = vim.api.nvim_create_buf(false, true)
  vim.bo[eval_buf].buftype = 'nofile'
  vim.bo[eval_buf].bufhidden = 'hide'
  vim.bo[eval_buf].swapfile = false
  vim.api.nvim_buf_set_name(eval_buf, '[lcvgc-eval]')
  return eval_buf
end

function M.set_eval_win(win)
  eval_win = win
end

function M.get_last_status()
  return last_status
end

function M.on_message(msg)
  if msg.type == 'status' then
    last_status = msg
    return
  end

  local buf = M.get_eval_buf()
  local lines = {}
  local is_error = msg.type == 'error'

  if is_error then
    local eval = require('lcvgc.eval')
    local sm = eval._last_source_map
    local err_line = msg.line
    if sm and err_line and sm[err_line] then
      local entry = sm[err_line]
      table.insert(lines, 'ERR ' .. entry.file .. ':' .. entry.line .. ': ' .. (msg.message or ''))
    else
      table.insert(lines, 'ERR line ' .. (err_line or '?') .. ': ' .. (msg.message or ''))
    end
  else
    table.insert(lines, 'OK ' .. (msg.block or '') .. ':' .. (msg.name or ''))
    if msg.warnings then
      for _, w in ipairs(msg.warnings) do
        table.insert(lines, '  WARN: ' .. w)
      end
    end
    if msg.playing_in and #msg.playing_in > 0 then
      table.insert(lines, '  playing in: ' .. table.concat(msg.playing_in, ', '))
    end
  end

  vim.api.nvim_buf_set_lines(buf, 0, -1, false, lines)

  if eval_win and vim.api.nvim_win_is_valid(eval_win) then
    local hl = is_error and 'ErrorMsg' or 'DiffAdd'
    vim.api.nvim_set_option_value('winhighlight', 'Normal:' .. hl, { win = eval_win })
  end
end

return M
