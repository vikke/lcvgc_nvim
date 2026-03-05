require('tests.helpers.vim_mock')

describe('lcvgc.lsp.completion', function()
  local completion
  local last_payload

  before_each(function()
    -- モジュールキャッシュをクリア
    package.loaded['lcvgc.lsp.completion'] = nil
    package.loaded['lcvgc.connection'] = nil
    last_payload = nil
  end)

  describe('is_available', function()
    it('vim.bo.filetype == "cvg" の時 true を返す', function()
      package.loaded['lcvgc.connection'] = {
        is_connected = function() return false end,
        request = function() end,
      }
      completion = require('lcvgc.lsp.completion')
      local src = completion.new()

      vim.bo.filetype = 'cvg'
      assert.is_true(src:is_available())
    end)

    it('vim.bo.filetype が "cvg" 以外の時 false を返す', function()
      package.loaded['lcvgc.connection'] = {
        is_connected = function() return false end,
        request = function() end,
      }
      completion = require('lcvgc.lsp.completion')
      local src = completion.new()

      vim.bo.filetype = 'lua'
      assert.is_false(src:is_available())
    end)
  end)

  describe('get_debug_name', function()
    it('"lcvgc_lsp" を返す', function()
      package.loaded['lcvgc.connection'] = {
        is_connected = function() return false end,
        request = function() end,
      }
      completion = require('lcvgc.lsp.completion')
      local src = completion.new()

      assert.are.equal('lcvgc_lsp', src:get_debug_name())
    end)
  end)

  describe('complete', function()
    it('未接続時は callback が呼ばれない', function()
      package.loaded['lcvgc.connection'] = {
        is_connected = function() return false end,
        request = function() end,
      }
      completion = require('lcvgc.lsp.completion')
      local src = completion.new()

      local called = false
      src:complete({}, function()
        called = true
      end)

      assert.is_false(called)
    end)

    it('正常レスポンスで callback が正しいアイテムで呼ばれる', function()
      package.loaded['lcvgc.connection'] = {
        is_connected = function() return true end,
        request = function(payload, handler)
          last_payload = payload
          handler({
            success = true,
            lsp = {
              type = 'completion',
              items = {
                { label = 'note_on', detail = 'MIDI note on', kind = 'Keyword' },
                { label = 'C4', detail = '音名', kind = 'NoteName' },
              },
            },
          })
          return true
        end,
      }
      completion = require('lcvgc.lsp.completion')
      local src = completion.new()

      local result = nil
      src:complete({}, function(r)
        result = r
      end)

      assert.is_not_nil(result)
      assert.is_false(result.isIncomplete)
      assert.are.equal(2, #result.items)

      -- 1つ目のアイテム: Keyword → 14
      assert.are.equal('note_on', result.items[1].label)
      assert.are.equal('MIDI note on', result.items[1].detail)
      assert.are.equal(14, result.items[1].kind)

      -- 2つ目のアイテム: NoteName → 12
      assert.are.equal('C4', result.items[2].label)
      assert.are.equal('音名', result.items[2].detail)
      assert.are.equal(12, result.items[2].kind)

      -- ペイロードの検証
      assert.are.equal('lsp_completion', last_payload.type)
    end)

    it('空アイテムの場合、空の items で callback が呼ばれる', function()
      package.loaded['lcvgc.connection'] = {
        is_connected = function() return true end,
        request = function(payload, handler)
          last_payload = payload
          handler({
            success = true,
            lsp = {
              type = 'completion',
              items = {},
            },
          })
          return true
        end,
      }
      completion = require('lcvgc.lsp.completion')
      local src = completion.new()

      local result = nil
      src:complete({}, function(r)
        result = r
      end)

      assert.is_not_nil(result)
      assert.is_false(result.isIncomplete)
      assert.are.equal(0, #result.items)
    end)

    it('msg.lsp.type が "completion" でない場合、handler は false を返す', function()
      local handler_result = nil
      package.loaded['lcvgc.connection'] = {
        is_connected = function() return true end,
        request = function(payload, handler)
          handler_result = handler({
            success = true,
            lsp = {
              type = 'hover',
              content = 'some hover info',
            },
          })
          return true
        end,
      }
      completion = require('lcvgc.lsp.completion')
      local src = completion.new()

      local called = false
      src:complete({}, function()
        called = true
      end)

      assert.is_false(called)
      assert.is_false(handler_result)
    end)
  end)
end)
