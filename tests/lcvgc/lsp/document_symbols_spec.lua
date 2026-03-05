require('tests.helpers.vim_mock')

describe('lcvgc.lsp.document_symbols', function()
  local document_symbols
  local last_payload
  local last_handler

  -- vim.ui.select のモック
  local ui_select_calls = {}
  vim.ui = {
    select = function(items, opts, on_choice)
      table.insert(ui_select_calls, { items = items, opts = opts, on_choice = on_choice })
      -- テストでは最初のアイテムを自動選択
      if on_choice and #items > 0 then
        on_choice(items[1], 1)
      end
    end,
  }

  -- nvim_win_set_cursor のモック
  local cursor_set = {}
  vim.api.nvim_win_set_cursor = function(win, pos)
    table.insert(cursor_set, { win = win, pos = pos })
  end

  before_each(function()
    clear_notifications()
    ui_select_calls = {}
    cursor_set = {}
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

      document_symbols = reload_module('lcvgc.lsp.document_symbols')
      document_symbols.show(1)

      assert.is_nil(last_payload)
      assert.is_nil(last_handler)
      assert.are.equal(0, #vim._notifications)
      assert.are.equal(0, #ui_select_calls)
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

      document_symbols = reload_module('lcvgc.lsp.document_symbols')
    end)

    it('空シンボルの場合 vim.notify が呼ばれる', function()
      document_symbols.show(1)

      assert.is_not_nil(last_handler)

      -- items が空のレスポンス
      local result = last_handler({
        success = true,
        lsp = { type = 'document_symbols', items = {} },
      })

      assert.is_true(result)
      assert.are.equal(1, #vim._notifications)
      assert.are.equal('No symbols found', vim._notifications[1].msg)
      assert.are.equal(vim.log.levels.INFO, vim._notifications[1].level)
      assert.are.equal(0, #ui_select_calls)
    end)

    it('正常レスポンスで vim.ui.select が正しいラベルで呼ばれる', function()
      document_symbols.show(1)

      assert.is_not_nil(last_handler)

      -- 2つのシンボルを持つ正常レスポンス
      local result = last_handler({
        success = true,
        lsp = {
          type = 'document_symbols',
          items = {
            { name = 'my_clip', kind = 'Clip', start_line = 0, start_col = 0, end_line = 5, end_col = 1 },
            { name = 'main_scene', kind = 'Scene', start_line = 7, start_col = 0, end_line = 12, end_col = 1 },
          },
        },
      })

      assert.is_true(result)
      assert.are.equal(1, #ui_select_calls)

      local call = ui_select_calls[1]
      assert.are.equal(2, #call.items)
      assert.are.equal('[Clip] my_clip (line 1)', call.items[1])
      assert.are.equal('[Scene] main_scene (line 8)', call.items[2])
      assert.are.equal('Document Symbols:', call.opts.prompt)
    end)

    it('選択時にカーソルが正しい位置に移動する', function()
      document_symbols.show(1)

      assert.is_not_nil(last_handler)

      -- モックの vim.ui.select は自動で最初のアイテムを選択する
      last_handler({
        success = true,
        lsp = {
          type = 'document_symbols',
          items = {
            { name = 'my_clip', kind = 'Clip', start_line = 0, start_col = 0, end_line = 5, end_col = 1 },
            { name = 'main_scene', kind = 'Scene', start_line = 7, start_col = 0, end_line = 12, end_col = 1 },
          },
        },
      })

      assert.are.equal(1, #cursor_set)
      assert.are.equal(0, cursor_set[1].win)
      assert.are.same({ 1, 0 }, cursor_set[1].pos)
    end)

    it('関係ないメッセージでは handler が false を返す', function()
      document_symbols.show(1)

      assert.is_not_nil(last_handler)

      -- 関係ないメッセージ
      local result = last_handler({ success = true, some_other = 'data' })

      assert.is_false(result)
      assert.are.equal(0, #vim._notifications)
      assert.are.equal(0, #ui_select_calls)
    end)
  end)
end)
