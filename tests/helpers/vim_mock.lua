-- vim グローバルモック for busted tests
-- プロジェクトの lua/ をパスに追加
package.path = './lua/?.lua;./lua/?/init.lua;' .. package.path

local vim_mock = {}

-- notify の呼び出し記録
vim_mock._notifications = {}

-- schedule: 即時実行
vim_mock.schedule = function(fn) fn() end

-- log levels
vim_mock.log = { levels = { DEBUG = 0, INFO = 1, WARN = 2, ERROR = 3 } }

-- notify
vim_mock.notify = function(msg, level)
  table.insert(vim_mock._notifications, { msg = msg, level = level })
end

-- vim.fn
vim_mock.fn = {
  sockconnect = function() return 0 end,
  chanclose = function() end,
  chansend = function() end,
  jobstart = function() return 1 end,
  jobstop = function() end,
  timer_start = function(_, cb) if cb then cb() end return 1 end,
  timer_stop = function() end,
  fnamemodify = function(path, mods)
    if mods == ':p' then
      -- 簡易的な絶対パス変換（テスト用）
      if path:sub(1, 1) == '/' then return path end
      return '/mock/' .. path
    elseif mods == ':h' then
      -- ディレクトリ部分を返す
      return path:match('(.+)/') or '.'
    end
    return path
  end,
  line = function() return 1 end,
  col = function() return 1 end,
  complete = function() end,
  json_encode = function(v)
    -- 簡易 JSON エンコード (テスト用)
    if type(v) == "table" then
      local parts = {}
      for k, val in pairs(v) do
        local vstr
        if type(val) == "string" then
          vstr = '"' .. val .. '"'
        else
          vstr = tostring(val)
        end
        table.insert(parts, '"' .. k .. '":' .. vstr)
      end
      return "{" .. table.concat(parts, ",") .. "}"
    end
    return tostring(v)
  end,
  json_decode = function(s)
    -- busted 環境では cjson を使用
    local ok, cjson = pcall(require, "cjson")
    if ok then return cjson.decode(s) end
    -- フォールバック: dkjson
    local ok2, dkjson = pcall(require, "dkjson")
    if ok2 then return dkjson.decode(s) end
    error("No JSON decoder available")
  end,
}

-- defer_fn: テスト時は即時実行
vim_mock.defer_fn = function(fn, _timeout) fn() end

-- vim.api
vim_mock.api = {
  nvim_create_namespace = function(_name) return 1 end,
  nvim_buf_clear_namespace = function() end,
  nvim_buf_set_extmark = function() return 1 end,
  nvim_buf_is_valid = function() return false end,
  nvim_create_buf = function() return 1 end,
  nvim_buf_set_name = function() end,
  nvim_buf_set_lines = function() end,
  nvim_buf_get_lines = function() return {} end,
  nvim_buf_line_count = function() return 0 end,
  nvim_win_is_valid = function() return false end,
  nvim_win_get_cursor = function() return {1, 0} end,
  nvim_get_current_buf = function() return 1 end,
  nvim_set_option_value = function() end,
  nvim_create_user_command = function() end,
  nvim_create_autocmd = function() end,
  nvim_create_augroup = function() return 1 end,
  nvim_put = function() end,
  nvim_get_current_line = function() return '' end,
  nvim_list_bufs = function() return {} end,
  nvim_buf_is_loaded = function() return false end,
}

-- vim.bo (buffer options proxy with read/write support)
-- グローバルな buffer option データストア
vim_mock._bo_data = {}
vim_mock.bo = setmetatable({}, {
  -- vim.bo.filetype のような直接アクセス（カレントバッファ）
  __index = function(_, k)
    if type(k) == 'number' then
      -- vim.bo[bufnr] のようなバッファ指定アクセス
      return setmetatable({}, {
        __index = function(_, opt) return vim_mock._bo_data[opt] end,
        __newindex = function(_, opt, v) vim_mock._bo_data[opt] = v end,
      })
    end
    return vim_mock._bo_data[k]
  end,
  -- vim.bo.filetype = 'cvg' のような直接設定
  __newindex = function(_, k, v)
    vim_mock._bo_data[k] = v
  end,
})

-- vim.cmd
vim_mock.cmd = function() end

-- vim.keymap
vim_mock.keymap = { set = function() end }

-- vim.lsp
vim_mock.lsp = {
  util = {
    open_floating_preview = function() end,
  },
}

-- vim.diagnostic
vim_mock.diagnostic = {
  severity = { ERROR = 1, WARN = 2, INFO = 3, HINT = 4 },
  set = function() end,
}

-- vim.ui
vim_mock.ui = {
  select = function() end,
}

-- vim.treesitter
vim_mock.treesitter = { start = function() end }

-- vim.tbl_deep_extend
vim_mock.tbl_deep_extend = function(_behavior, ...)
  local result = {}
  for _, tbl in ipairs({...}) do
    if type(tbl) == "table" then
      for k, v in pairs(tbl) do
        result[k] = v
      end
    end
  end
  return result
end

-- vim.split
vim_mock.split = function(s, sep)
  local parts = {}
  for part in s:gmatch("[^" .. sep .. "]+") do
    table.insert(parts, part)
  end
  return parts
end

-- グローバルに設定
_G.vim = vim_mock

-- テストヘルパー: モジュールリロード
function _G.reload_module(name)
  package.loaded[name] = nil
  return require(name)
end

-- テストヘルパー: notifications クリア
function _G.clear_notifications()
  vim_mock._notifications = {}
end
