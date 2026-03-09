describe("lcvgc.cmp_source", function()
  local cmp_source
  local cmp_mock

  -- nvim-cmp モックを構築
  local function setup_cmp_mock()
    cmp_mock = {
      register_source_calls = {},
      filetype_calls = {},
      register_source = function(name, source)
        table.insert(cmp_mock.register_source_calls, { name = name, source = source })
      end,
      setup = {
        filetype = function(ft, opts)
          table.insert(cmp_mock.filetype_calls, { ft = ft, opts = opts })
        end,
      },
      PreselectMode = { None = 'none', Item = 'item' },
      mapping = {
        preset = {
          insert = function(overrides) return overrides end,
        },
        confirm = function(opts) return { confirm = true, select = opts.select } end,
      },
    }
    package.loaded["cmp"] = cmp_mock
  end

  -- nvim-cmp モックを削除
  local function teardown_cmp_mock()
    package.loaded["cmp"] = nil
  end

  before_each(function()
    clear_notifications()
    vim._bo_data = {}
    setup_cmp_mock()
    cmp_source = reload_module("lcvgc.cmp_source")
  end)

  after_each(function()
    teardown_cmp_mock()
  end)

  describe("is_available", function()
    it("filetype が cvg なら true", function()
      vim.bo.filetype = "cvg"
      local source = cmp_source.new()
      assert.is_true(source:is_available())
    end)

    it("filetype が lua なら false", function()
      vim.bo.filetype = "lua"
      local source = cmp_source.new()
      assert.is_false(source:is_available())
    end)

    it("filetype 未設定なら false", function()
      local source = cmp_source.new()
      assert.is_false(source:is_available())
    end)
  end)

  describe("get_debug_name", function()
    it("'lcvgc' を返す", function()
      local source = cmp_source.new()
      assert.equals("lcvgc", source:get_debug_name())
    end)
  end)

  describe("get_trigger_characters", function()
    it("{ ' ' } を返す", function()
      local source = cmp_source.new()
      local chars = source:get_trigger_characters()
      assert.same({ ' ' }, chars)
    end)
  end)

  describe("complete", function()
    local saved_fns

    before_each(function()
      -- 元の関数を保存
      saved_fns = {
        nvim_win_get_cursor = vim.api.nvim_win_get_cursor,
        nvim_get_current_buf = vim.api.nvim_get_current_buf,
        nvim_buf_get_lines = vim.api.nvim_buf_get_lines,
      }
    end)

    after_each(function()
      -- リストア
      vim.api.nvim_win_get_cursor = saved_fns.nvim_win_get_cursor
      vim.api.nvim_get_current_buf = saved_fns.nvim_get_current_buf
      vim.api.nvim_buf_get_lines = saved_fns.nvim_buf_get_lines
      -- ポートキャッシュクリア
      local ports = require("lcvgc.ports")
      ports.clear_cache()
    end)

    it("ポートコンテキスト + device ブロック内 → callback 呼出", function()
      -- ポートデータを設定
      local ports = reload_module("lcvgc.ports")
      ports._handle_response({
        ports = {
          { name = "IAC Driver Bus 1", direction = "out" },
          { name = "MIDI Input", direction = "in" },
        },
      })

      -- カーソル位置: 2行目
      vim.api.nvim_win_get_cursor = function() return { 2, 8 } end
      vim.api.nvim_get_current_buf = function() return 1 end
      -- バッファ内容: device ブロック内の port 行
      vim.api.nvim_buf_get_lines = function(_, start, _, _)
        local lines = {
          'device synth {',
          '  port ',
        }
        return { lines[start + 1] }
      end

      local source = cmp_source.new()
      local callback_result = nil
      local params = {
        context = {
          cursor_before_line = '  port I',
          bufnr = 1,
        },
      }

      source:complete(params, function(result)
        callback_result = result
      end)

      assert.is_not_nil(callback_result)
      assert.is_not_nil(callback_result.items)
      assert.equals(1, #callback_result.items)  -- out ポートのみ
      assert.equals("IAC Driver Bus 1", callback_result.items[1].label)
      assert.equals('IAC Driver Bus 1', callback_result.items[1].insertText)
      assert.equals("[MIDI Port]", callback_result.items[1].detail)
      assert.is_false(callback_result.isIncomplete)
    end)

    it("ポートコンテキスト外 → callback 未呼出", function()
      local source = cmp_source.new()
      local callback_called = false
      local params = {
        context = {
          cursor_before_line = "  note c4 ",
          bufnr = 1,
        },
      }

      source:complete(params, function()
        callback_called = true
      end)

      assert.is_false(callback_called)
    end)

    it("device ブロック外 → callback 未呼出", function()
      -- ポートデータを設定
      local ports = reload_module("lcvgc.ports")
      ports._handle_response({
        ports = {
          { name = "IAC Driver Bus 1", direction = "out" },
        },
      })

      -- カーソル位置: 2行目
      vim.api.nvim_win_get_cursor = function() return { 2, 8 } end
      vim.api.nvim_get_current_buf = function() return 1 end
      -- バッファ内容: device ブロック外
      vim.api.nvim_buf_get_lines = function(_, start, _, _)
        local lines = {
          'instrument bass {',
          '  port ',
        }
        return { lines[start + 1] }
      end

      local source = cmp_source.new()
      local callback_called = false
      local params = {
        context = {
          cursor_before_line = '  port ',
          bufnr = 1,
        },
      }

      source:complete(params, function()
        callback_called = true
      end)

      assert.is_false(callback_called)
    end)

    it("include コンテキスト → cvg ファイル候補を返す", function()
      local saved_readdir = vim.fn.readdir
      local saved_isdirectory = vim.fn.isdirectory
      local saved_buf_get_name = vim.api.nvim_buf_get_name

      vim.api.nvim_buf_get_name = function() return "/project/main.cvg" end
      vim.fn.readdir = function(path)
        if path == "/project" then
          return { "bass.cvg", "drums.cvg", "lib" }
        end
        return {}
      end
      vim.fn.isdirectory = function(path)
        if path == "/project/lib" then return 1 end
        return 0
      end

      local include_source = cmp_source.new_include()
      local callback_result = nil
      local params = {
        context = {
          cursor_before_line = 'include ',
          bufnr = 1,
        },
      }

      include_source:complete(params, function(result)
        callback_result = result
      end)

      assert.is_not_nil(callback_result)
      assert.equals(3, #callback_result.items)
      assert.equals("bass.cvg", callback_result.items[1].label)
      assert.equals("drums.cvg", callback_result.items[2].label)
      assert.equals("lib/", callback_result.items[3].label)
      assert.is_true(callback_result.isIncomplete)

      vim.fn.readdir = saved_readdir
      vim.fn.isdirectory = saved_isdirectory
      vim.api.nvim_buf_get_name = saved_buf_get_name
    end)

    it("include コンテキスト + バッファ名なし → callback 未呼出", function()
      local saved_buf_get_name = vim.api.nvim_buf_get_name
      vim.api.nvim_buf_get_name = function() return "" end

      local include_source = cmp_source.new_include()
      local callback_called = false
      local params = {
        context = {
          cursor_before_line = 'include ',
          bufnr = 1,
        },
      }

      include_source:complete(params, function()
        callback_called = true
      end)

      assert.is_false(callback_called)

      vim.api.nvim_buf_get_name = saved_buf_get_name
    end)

    it("include ソースの trigger characters に '/' を含む", function()
      local include_source = cmp_source.new_include()
      local chars = include_source:get_trigger_characters()
      assert.is_true(vim.tbl_contains(chars, '/'))
      assert.is_true(vim.tbl_contains(chars, ' '))
    end)

    it("include ソースの debug name は 'lcvgc_include'", function()
      local include_source = cmp_source.new_include()
      assert.equals("lcvgc_include", include_source:get_debug_name())
    end)

    it("ポートキャッシュ空 → callback 未呼出", function()
      local ports = reload_module("lcvgc.ports")
      ports.clear_cache()

      vim.api.nvim_win_get_cursor = function() return { 2, 8 } end
      vim.api.nvim_get_current_buf = function() return 1 end
      vim.api.nvim_buf_get_lines = function(_, start, _, _)
        local lines = {
          'device synth {',
          '  port ',
        }
        return { lines[start + 1] }
      end

      local source = cmp_source.new()
      local callback_called = false
      local params = {
        context = {
          cursor_before_line = '  port ',
          bufnr = 1,
        },
      }

      source:complete(params, function()
        callback_called = true
      end)

      assert.is_false(callback_called)
    end)
  end)

  describe("setup", function()
    it("cmp.register_source と cmp.setup.filetype が呼ばれる", function()
      cmp_mock.register_source_calls = {}
      cmp_mock.filetype_calls = {}

      cmp_source.setup({ debounce = 200 })

      assert.equals(3, #cmp_mock.register_source_calls)
      assert.equals("lcvgc", cmp_mock.register_source_calls[1].name)
      assert.equals("lcvgc_lsp", cmp_mock.register_source_calls[2].name)
      assert.equals("lcvgc_include", cmp_mock.register_source_calls[3].name)

      assert.equals(1, #cmp_mock.filetype_calls)
      assert.equals("cvg", cmp_mock.filetype_calls[1].ft)
      assert.equals(200, cmp_mock.filetype_calls[1].opts.performance.debounce)
    end)

    it("preselect = None が設定される", function()
      cmp_mock.filetype_calls = {}

      cmp_source.setup()

      assert.equals("none", cmp_mock.filetype_calls[1].opts.preselect)
    end)

    it("CR マッピングが select = false で設定される", function()
      cmp_mock.filetype_calls = {}

      cmp_source.setup()

      local cr_mapping = cmp_mock.filetype_calls[1].opts.mapping['<CR>']
      assert.is_not_nil(cr_mapping)
      assert.is_false(cr_mapping.select)
    end)

    it("opts 未指定時はデフォルト 150ms", function()
      cmp_mock.filetype_calls = {}

      cmp_source.setup()

      assert.equals(150, cmp_mock.filetype_calls[1].opts.performance.debounce)
    end)

    it("cmp なしでもエラーにならない", function()
      teardown_cmp_mock()
      package.loaded["lcvgc.cmp_source"] = nil

      assert.has_no.errors(function()
        local mod = require("lcvgc.cmp_source")
        mod.setup()
      end)
    end)
  end)
end)
