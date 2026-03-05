require('tests.helpers.vim_mock')

describe('lcvgc.lsp.hover', function()
  local hover
  local last_payload
  local last_handler

  -- vim.lsp.util のモック
  local floating_preview_calls = {}
  vim.lsp.util = {
    open_floating_preview = function(lines, syntax, opts)
      table.insert(floating_preview_calls, {
        lines = lines,
        syntax = syntax,
        opts = opts,
      })
    end,
  }

  before_each(function()
    clear_notifications()
    floating_preview_calls = {}
    last_payload = nil
    last_handler = nil
  end)

  describe('未接続時', function()
    it('connection.is_connected() が false の場合は何も起きない', function()
      -- 未接続状態のモック
      package.loaded['lcvgc.connection'] = {
        is_connected = function() return false end,
        request = function(payload, handler)
          last_payload = payload
          last_handler = handler
          return true
        end,
      }

      hover = reload_module('lcvgc.lsp.hover')
      hover.show(1)

      assert.is_nil(last_payload)
      assert.is_nil(last_handler)
      assert.are.equal(0, #vim._notifications)
      assert.are.equal(0, #floating_preview_calls)
    end)
  end)

  describe('接続済み', function()
    before_each(function()
      -- 接続状態のモック
      package.loaded['lcvgc.connection'] = {
        is_connected = function() return true end,
        request = function(payload, handler)
          last_payload = payload
          last_handler = handler
          return true
        end,
      }

      hover = reload_module('lcvgc.lsp.hover')
    end)

    it('info が nil の場合 vim.notify が呼ばれる', function()
      hover.show(1)

      assert.is_not_nil(last_handler)

      -- info が nil のレスポンス
      local result = last_handler({
        success = true,
        lsp = { type = 'hover', info = nil },
      })

      assert.is_true(result)
      assert.are.equal(1, #vim._notifications)
      assert.are.equal('No hover information', vim._notifications[1].msg)
      assert.are.equal(vim.log.levels.INFO, vim._notifications[1].level)
      assert.are.equal(0, #floating_preview_calls)
    end)

    it('正常レスポンスで open_floating_preview が正しい引数で呼ばれる', function()
      hover.show(1)

      assert.is_not_nil(last_handler)

      -- content を持つ正常レスポンス
      local result = last_handler({
        success = true,
        lsp = {
          type = 'hover',
          info = { content = '**note_on** `ch pitch vel`\nMIDI note on' },
        },
      })

      assert.is_true(result)
      assert.are.equal(1, #floating_preview_calls)

      local call = floating_preview_calls[1]
      assert.are.same(
        { '**note_on** `ch pitch vel`', 'MIDI note on' },
        call.lines
      )
      assert.are.equal('markdown', call.syntax)
      assert.are.same({ focus = false }, call.opts)
    end)

    it('msg.lsp がないメッセージでは handler が false を返す', function()
      hover.show(1)

      assert.is_not_nil(last_handler)

      -- 関係ないメッセージ
      local result = last_handler({ success = true, some_other = 'data' })

      assert.is_false(result)
      assert.are.equal(0, #vim._notifications)
      assert.are.equal(0, #floating_preview_calls)
    end)
  end)
end)
