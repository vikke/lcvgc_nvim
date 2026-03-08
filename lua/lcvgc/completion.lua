local M = {}

--- port コンテキスト判定（引用符なし構文）
--- `port ` の後に1文字以上の非空白文字がある行を検出する
--- 行末コメント（//）は無視する
--- @param line string カーソル行のテキスト
--- @return boolean port コンテキストかどうか
function M.is_port_context(line)
  return line:match('^%s*port%s+') ~= nil
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

--- port 補完をトリガーする（引用符なし構文）
--- `port ` の後のテキストを補完候補で置き換える
function M.trigger_port_completion()
  local ports = require('lcvgc.ports')
  local names = ports.get_output_ports()
  if #names == 0 then
    return
  end

  local line = vim.api.nvim_get_current_line()
  local col = vim.fn.col('.')
  local before = line:sub(1, col - 1)
  -- "port " の後の開始位置を見つける
  local start = before:find('port%s+')
  if not start then
    return
  end
  -- "port " の後の文字開始位置
  local value_start = before:find('%S', start + 4)
  if not value_start then
    value_start = col
  end

  local items = {}
  for _, name in ipairs(names) do
    table.insert(items, {
      word = name,
      abbr = name,
      menu = '[MIDI Port]',
    })
  end

  vim.fn.complete(value_start, items)
end

--- include コンテキスト判定
--- `include ` で始まる行を検出する
--- Detects lines starting with `include `
--- @param line string カーソル行のテキスト
--- @return boolean include コンテキストかどうか
function M.is_include_context(line)
  return line:match('^%s*include%s') ~= nil
end

--- include 行からパーシャルパスを取得する
--- Extracts partial path from include line
--- @param line string カーソル行のテキスト
--- @return string パーシャルパス（include の後のテキスト）
function M.get_include_partial(line)
  return line:match('^%s*include%s+(.*)$') or ''
end

--- include候補を列挙する（cvgファイルのディレクトリ基準）
--- Lists include candidates relative to the cvg file's directory
--- @param base_dir string cvgファイルのディレクトリ
--- @param partial string 入力済みのパーシャルパス
--- @return table[] 補完候補のリスト
function M.list_include_candidates(base_dir, partial)
  local dir_part = partial:match('(.*/)') or ''
  local scan_dir = base_dir
  if dir_part ~= '' then
    scan_dir = base_dir .. '/' .. dir_part
  end

  local candidates = {}
  local ok, entries = pcall(vim.fn.readdir, scan_dir)
  if not ok or not entries then
    return candidates
  end

  for _, name in ipairs(entries) do
    if name:sub(1, 1) ~= '.' then
      local full_path = scan_dir .. '/' .. name
      local label = dir_part .. name

      if vim.fn.isdirectory(full_path) == 1 then
        table.insert(candidates, {
          label = label .. '/',
          kind = 19, -- Folder
          detail = '[Directory]',
        })
      elseif name:match('%.cvg$') or name:match('%.lcvgc$') then
        table.insert(candidates, {
          label = label,
          kind = 17, -- File
          detail = '[CVG File]',
        })
      end
    end
  end

  return candidates
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
