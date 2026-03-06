local connection = require('lcvgc.connection')
local eval = require('lcvgc.eval')
local layout = require('lcvgc.layout')
local display = require('lcvgc.display')

local M = {}

local mic_job = nil

local function get_clip_scale()
  local bufnr = vim.api.nvim_get_current_buf()
  local row = vim.api.nvim_win_get_cursor(0)[1]
  for i = row, 1, -1 do
    local line = vim.api.nvim_buf_get_lines(bufnr, i - 1, i, false)[1]
    local root, scale_type = line:match('%[scale%s+(%S+)%s+(%S+)%]')
    if root and scale_type then
      return { root = root, type = scale_type }
    end
    if line:match('^%s*clip%s') or line:match('^%s*scene%s') or line:match('^%s*session%s') then
      break
    end
  end
  for i = 1, vim.api.nvim_buf_line_count(bufnr) do
    local line = vim.api.nvim_buf_get_lines(bufnr, i - 1, i, false)[1]
    local root, scale_type = line:match('^%s*scale%s+(%S+)%s+(%S+)')
    if root and scale_type then
      return { root = root, type = scale_type }
    end
  end
  return nil
end

function M.setup(opts)
  opts = opts or {}

  vim.api.nvim_create_user_command('LcvgcConnect', function(cmd)
    local port = tonumber(cmd.args) or opts.port or 5555
    local ok = connection.connect(port, display.on_message)
    if ok then
      require('lcvgc.ports').fetch()
    end
  end, { nargs = '?' })

  vim.api.nvim_create_user_command('LcvgcDisconnect', function()
    connection.disconnect()
  end, {})

  vim.api.nvim_create_user_command('LcvgcStatus', function()
    if not connection.is_connected() then
      vim.notify('lcvgc not connected', vim.log.levels.WARN)
      return
    end
    local status = display.get_last_status()
    if not status then
      vim.notify('No status received yet', vim.log.levels.INFO)
      return
    end
    local lines = {
      'tempo: ' .. (status.tempo or '?'),
      'scene: ' .. (status.scene or '?'),
      'playing: ' .. table.concat(status.playing_clips or {}, ', '),
    }
    if status.position then
      table.insert(lines, 'position: bar ' .. (status.position.bar or '?') .. ' beat ' .. (status.position.beat or '?'))
    end
    vim.notify(table.concat(lines, '\n'), vim.log.levels.INFO)
  end, {})

  vim.api.nvim_create_user_command('LcvgcEvalFile', function()
    eval.eval_file()
  end, {})

  vim.api.nvim_create_user_command('LcvgcStop', function()
    connection.send({ type = 'eval', source = 'stop' })
  end, {})

  vim.api.nvim_create_user_command('LcvgcLayout', function()
    layout.setup({ log_path = opts.log_path })
  end, {})

  vim.api.nvim_create_user_command('LcvgcListPorts', function()
    local ports = require('lcvgc.ports')
    local names = ports.get_output_ports()
    if #names == 0 then
      vim.notify('No MIDI ports available (connected?)', vim.log.levels.WARN)
      return
    end
    vim.notify('MIDI output ports:\n' .. table.concat(names, '\n'), vim.log.levels.INFO)
  end, {})

  vim.api.nvim_create_user_command('LcvgcMicStart', function(cmd)
    if mic_job then
      vim.notify('lcvgc-mic already running', vim.log.levels.WARN)
      return
    end
    local args = { 'lcvgc-mic' }
    for _, arg in ipairs(vim.split(cmd.args, ' ')) do
      if arg ~= '' then table.insert(args, arg) end
    end
    if not cmd.args:match('%-%-key') then
      local scale = get_clip_scale()
      if scale then
        table.insert(args, '--key')
        table.insert(args, scale.root)
        table.insert(args, '--scale')
        table.insert(args, scale.type)
      end
    end
    mic_job = vim.fn.jobstart(args, {
      on_stdout = function(_, data, _)
        local text = table.concat(data, ' '):gsub('%s+$', '')
        if text ~= '' then
          vim.schedule(function()
            vim.api.nvim_put({ text }, 'c', true, true)
          end)
        end
      end,
      on_stderr = function(_, data, _)
        local msg = table.concat(data, '')
        if msg ~= '' then
          vim.notify('lcvgc-mic: ' .. msg, vim.log.levels.WARN)
        end
      end,
      on_exit = function()
        mic_job = nil
      end,
    })
  end, { nargs = '*' })

  vim.api.nvim_create_user_command('LcvgcMicStop', function()
    if mic_job then
      vim.fn.jobstop(mic_job)
      mic_job = nil
    end
  end, {})

  -- キーマップ
  vim.keymap.set('v', '<C-e>', function()
    eval.eval_selection()
  end, { desc = 'lcvgc: eval selection' })

  vim.keymap.set('n', '<C-e>', function()
    eval.eval_paragraph()
  end, { desc = 'lcvgc: eval paragraph' })

  vim.keymap.set('n', '<C-S-e>', function()
    eval.eval_file()
  end, { desc = 'lcvgc: eval file (with include expansion)' })
end

return M
