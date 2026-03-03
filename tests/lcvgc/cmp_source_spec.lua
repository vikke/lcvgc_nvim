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
    it('{ \'"\' } を返す', function()
      local source = cmp_source.new()
      local chars = source:get_trigger_characters()
      assert.same({ '"' }, chars)
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
          '  port "',
        }
        return { lines[start + 1] }
      end

      local source = cmp_source.new()
      local callback_result = nil
      local params = {
        context = {
          cursor_before_line = '  port "',
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
      assert.equals('IAC Driver Bus 1"', callback_result.items[1].insertText)
      assert.equals("[MIDI Port]", callback_result.items[1].detail)
      assert.is_false(callback_result.isIncomplete)
    end)

    it("ポートコンテキスト外 → callback 未呼出", function()
      local source = cmp_source.new()
      local callback_called = false
      local params = {
        context = {
          cursor_before_line = "  note c4",
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
          '  port "',
        }
        return { lines[start + 1] }
      end

      local source = cmp_source.new()
      local callback_called = false
      local params = {
        context = {
          cursor_before_line = '  port "',
          bufnr = 1,
        },
      }

      source:complete(params, function()
        callback_called = true
      end)

      assert.is_false(callback_called)
    end)

    it("ポートキャッシュ空 → callback 未呼出", function()
      local ports = reload_module("lcvgc.ports")
      ports.clear_cache()

      vim.api.nvim_win_get_cursor = function() return { 2, 8 } end
      vim.api.nvim_get_current_buf = function() return 1 end
      vim.api.nvim_buf_get_lines = function(_, start, _, _)
        local lines = {
          'device synth {',
          '  port "',
        }
        return { lines[start + 1] }
      end

      local source = cmp_source.new()
      local callback_called = false
      local params = {
        context = {
          cursor_before_line = '  port "',
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

      cmp_source.setup()

      assert.equals(1, #cmp_mock.register_source_calls)
      assert.equals("lcvgc", cmp_mock.register_source_calls[1].name)

      assert.equals(1, #cmp_mock.filetype_calls)
      assert.equals("cvg", cmp_mock.filetype_calls[1].ft)
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
