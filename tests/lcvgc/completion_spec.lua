describe("lcvgc.completion", function()
  local completion

  before_each(function()
    clear_notifications()
    completion = reload_module("lcvgc.completion")
  end)

  describe("is_port_context", function()
    it('port " で始まる行を検出する', function()
      assert.is_true(completion.is_port_context('  port "'))
    end)

    it('port "IAC を検出する', function()
      assert.is_true(completion.is_port_context('  port "IAC'))
    end)

    it("port だけの行は false", function()
      assert.is_false(completion.is_port_context("  port "))
    end)

    it("空行は false", function()
      assert.is_false(completion.is_port_context(""))
    end)

    it("他のキーワードは false", function()
      assert.is_false(completion.is_port_context('  device "test'))
    end)
  end)

  describe("is_in_device_block", function()
    it("device ブロック内なら true", function()
      vim.api.nvim_buf_get_lines = function(_, start, _, _)
        local lines = {
          'device synth {',
          '  port "',
        }
        return { lines[start + 1] }
      end
      assert.is_true(completion.is_in_device_block(1, 2))

      -- リストア
      vim.api.nvim_buf_get_lines = function() return {} end
    end)

    it("device ブロック外なら false", function()
      vim.api.nvim_buf_get_lines = function(_, start, _, _)
        local lines = {
          'instrument bass {',
          '  port "',
        }
        return { lines[start + 1] }
      end
      assert.is_false(completion.is_in_device_block(1, 2))

      vim.api.nvim_buf_get_lines = function() return {} end
    end)

    it("閉じブレースがあれば false", function()
      vim.api.nvim_buf_get_lines = function(_, start, _, _)
        local lines = {
          'device synth {',
          '  port "IAC"',
          '}',
          '  port "',
        }
        return { lines[start + 1] }
      end
      assert.is_false(completion.is_in_device_block(1, 4))

      vim.api.nvim_buf_get_lines = function() return {} end
    end)
  end)

  describe("trigger_port_completion", function()
    it("ポートが空の場合は何もしない", function()
      local ports = reload_module("lcvgc.ports")
      ports.clear_cache()
      local complete_called = false
      vim.fn.complete = function() complete_called = true end

      completion.trigger_port_completion()
      assert.is_false(complete_called)

      vim.fn.complete = function() end
    end)

    it("ポートがある場合に complete を呼ぶ", function()
      local ports = reload_module("lcvgc.ports")
      ports._handle_response({
        ports = {
          { name = "IAC Driver Bus 1", direction = "out" },
        },
      })

      vim.api.nvim_get_current_line = function()
        return '  port "'
      end
      vim.fn.col = function() return 9 end

      local complete_args = nil
      vim.fn.complete = function(start, items)
        complete_args = { start = start, items = items }
      end

      completion.trigger_port_completion()
      assert.is_not_nil(complete_args)
      assert.equals(1, #complete_args.items)
      assert.equals('IAC Driver Bus 1', complete_args.items[1].word)
      assert.equals("IAC Driver Bus 1", complete_args.items[1].abbr)

      -- リストア
      vim.api.nvim_get_current_line = function() return '' end
      vim.fn.col = function() return 1 end
      vim.fn.complete = function() end
    end)
  end)
end)
