require('tests.helpers.vim_mock')

describe('lcvgc.lsp.goto_definition', function()
  local cursor_set = {}

  before_each(function()
    cursor_set = {}
    vim.api.nvim_win_set_cursor = function(win, pos)
      table.insert(cursor_set, { win = win, pos = pos })
    end
    clear_notifications()
    package.loaded['lcvgc.connection'] = nil
    package.loaded['lcvgc.lsp.goto_definition'] = nil
  end)

  it('未接続時は何も起きない', function()
    package.loaded['lcvgc.connection'] = {
      is_connected = function() return false end,
      request = function() error('should not be called') end,
    }
    local goto_def = require('lcvgc.lsp.goto_definition')

    goto_def.goto_def(1)

    assert.are.equal(0, #cursor_set)
    assert.are.equal(0, #vim._notifications)
  end)

  it('location が null の場合、定義未発見を通知する', function()
    package.loaded['lcvgc.connection'] = {
      is_connected = function() return true end,
      request = function(payload, handler)
        handler({
          success = true,
          lsp = {
            type = 'goto_definition',
            location = nil,
          },
        })
        return true
      end,
    }
    local goto_def = require('lcvgc.lsp.goto_definition')

    goto_def.goto_def(1)

    assert.are.equal(0, #cursor_set)
    assert.are.equal(1, #vim._notifications)
    assert.are.equal('Definition not found', vim._notifications[1].msg)
    assert.are.equal(vim.log.levels.INFO, vim._notifications[1].level)
  end)

  it('正常レスポンスでカーソルが移動する（0始まり→1始まり変換）', function()
    package.loaded['lcvgc.connection'] = {
      is_connected = function() return true end,
      request = function(payload, handler)
        handler({
          success = true,
          lsp = {
            type = 'goto_definition',
            location = { start_line = 5, start_col = 0, end_line = 5, end_col = 8 },
          },
        })
        return true
      end,
    }
    local goto_def = require('lcvgc.lsp.goto_definition')

    goto_def.goto_def(1)

    assert.are.equal(1, #cursor_set)
    assert.are.equal(0, cursor_set[1].win)
    assert.are.same({ 6, 0 }, cursor_set[1].pos)
  end)

  it('関係ないメッセージに対してhandlerがfalseを返す', function()
    package.loaded['lcvgc.connection'] = {
      is_connected = function() return true end,
      request = function(payload, handler)
        local result = handler({
          success = true,
          some_other = 'data',
        })
        assert.is_false(result)
        return true
      end,
    }
    local goto_def = require('lcvgc.lsp.goto_definition')

    goto_def.goto_def(1)

    assert.are.equal(0, #cursor_set)
    assert.are.equal(0, #vim._notifications)
  end)
end)
