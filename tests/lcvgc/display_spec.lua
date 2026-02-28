describe("lcvgc.display", function()
  local display
  local set_lines_calls

  before_each(function()
    clear_notifications()
    set_lines_calls = {}
    vim.api.nvim_buf_set_lines = function(buf, start, stop, strict, lines)
      table.insert(set_lines_calls, { buf = buf, lines = lines })
    end
    vim.api.nvim_buf_is_valid = function() return false end
    display = reload_module("lcvgc.display")
  end)

  describe("on_message - status", function()
    it("status メッセージを last_status に保存する", function()
      local msg = { type = "status", tempo = 120, scene = "main" }
      display.on_message(msg)
      assert.same(msg, display.get_last_status())
    end)

    it("status メッセージはバッファに書き込まない", function()
      display.on_message({ type = "status", tempo = 120 })
      assert.equals(0, #set_lines_calls)
    end)
  end)

  describe("on_message - error", function()
    it("エラー行をフォーマットする", function()
      display.on_message({ type = "error", line = 5, message = "syntax error" })
      assert.equals(1, #set_lines_calls)
      assert.equals("ERR line 5: syntax error", set_lines_calls[1].lines[1])
    end)

    it("line が nil の場合は ? を表示する", function()
      display.on_message({ type = "error", message = "unknown" })
      assert.equals("ERR line ?: unknown", set_lines_calls[1].lines[1])
    end)

    it("ソースマップがある場合はファイル名:行番号で表示する", function()
      local eval = require("lcvgc.eval")
      eval._last_source_map = {
        [1] = { file = "main.cvg", line = 1 },
        [2] = { file = "header.cvg", line = 3 },
        [3] = { file = "main.cvg", line = 2 },
      }
      display.on_message({ type = "error", line = 2, message = "bad note" })
      assert.equals("ERR header.cvg:3: bad note", set_lines_calls[1].lines[1])
      eval._last_source_map = nil
    end)

    it("ソースマップの範囲外の場合は通常フォーマット", function()
      local eval = require("lcvgc.eval")
      eval._last_source_map = {
        [1] = { file = "main.cvg", line = 1 },
      }
      display.on_message({ type = "error", line = 99, message = "oops" })
      assert.equals("ERR line 99: oops", set_lines_calls[1].lines[1])
      eval._last_source_map = nil
    end)
  end)

  describe("on_message - 正常応答", function()
    it("OK 行を生成する", function()
      display.on_message({ type = "result", block = "clip1", name = "melody" })
      assert.equals("OK clip1:melody", set_lines_calls[1].lines[1])
    end)

    it("warnings を表示する", function()
      display.on_message({
        type = "result",
        block = "c",
        name = "n",
        warnings = { "warn1", "warn2" },
      })
      local lines = set_lines_calls[1].lines
      assert.equals(3, #lines)
      assert.equals("  WARN: warn1", lines[2])
      assert.equals("  WARN: warn2", lines[3])
    end)

    it("playing_in を表示する", function()
      display.on_message({
        type = "result",
        block = "c",
        name = "n",
        playing_in = { "ch1", "ch2" },
      })
      local lines = set_lines_calls[1].lines
      assert.equals(2, #lines)
      assert.equals("  playing in: ch1, ch2", lines[2])
    end)

    it("空の playing_in は表示しない", function()
      display.on_message({
        type = "result",
        block = "c",
        name = "n",
        playing_in = {},
      })
      local lines = set_lines_calls[1].lines
      assert.equals(1, #lines)
    end)
  end)
end)
