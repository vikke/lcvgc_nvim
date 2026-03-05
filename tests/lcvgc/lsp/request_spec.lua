require('tests.helpers.vim_mock')

describe('lcvgc.lsp.request', function()
  local request

  -- テスト用バッファ行データ
  local mock_lines = { 'device synth1 {', '  port "MIDI Out"', '}' }

  -- nvim_buf_get_lines のモック保存用
  local original_get_lines
  local original_get_cursor

  before_each(function()
    -- オリジナルを保存
    original_get_lines = vim.api.nvim_buf_get_lines
    original_get_cursor = vim.api.nvim_win_get_cursor

    -- nvim_buf_get_lines をモック: バッファ行データを返す
    vim.api.nvim_buf_get_lines = function(_bufnr, start_row, end_row, _strict)
      if end_row == -1 then
        local result = {}
        for i = start_row + 1, #mock_lines do
          table.insert(result, mock_lines[i])
        end
        return result
      end
      local result = {}
      for i = start_row + 1, end_row do
        if i <= #mock_lines then
          table.insert(result, mock_lines[i])
        end
      end
      return result
    end

    -- モジュールをリロード
    request = reload_module('lcvgc.lsp.request')
  end)

  after_each(function()
    -- オリジナルに戻す
    vim.api.nvim_buf_get_lines = original_get_lines
    vim.api.nvim_win_get_cursor = original_get_cursor
  end)

  describe('get_source', function()
    it('モックされたバッファ行から結合文字列を返す', function()
      local source = request.get_source(1)
      assert.are.equal('device synth1 {\n  port "MIDI Out"\n}', source)
    end)
  end)

  describe('get_byte_offset', function()
    it('1行目先頭のオフセットは0', function()
      local offset = request.get_byte_offset(1, 1, 0)
      assert.are.equal(0, offset)
    end)

    it('2行目先頭のオフセットは1行目の長さ+1', function()
      -- 'device synth1 {' は 15文字 + 改行1 = 16
      local offset = request.get_byte_offset(1, 2, 0)
      assert.are.equal(15 + 1, offset)
    end)

    it('3行目の5バイト目のオフセットを正しく計算する', function()
      -- 'device synth1 {' = 15文字 + '\n' = 16
      -- '  port "MIDI Out"' = 17文字 + '\n' = 18
      -- + 5 = 39
      local offset = request.get_byte_offset(1, 3, 5)
      assert.are.equal(15 + 1 + 17 + 1 + 5, offset)
    end)
  end)

  describe('build', function()
    it('offset付きのリクエストペイロードを構築する', function()
      -- カーソル位置をモック: 2行目、5列目
      vim.api.nvim_win_get_cursor = function(_win)
        return { 2, 5 }
      end

      local payload = request.build('lsp_completion', 1)

      assert.are.equal('lsp_completion', payload.type)
      assert.are.equal('device synth1 {\n  port "MIDI Out"\n}', payload.source)
      -- 2行目5バイト目: 15 + 1 + 5 = 21
      assert.are.equal(21, payload.offset)
    end)

    it('opts.offset=false の場合 offset フィールドが含まれない', function()
      local payload = request.build('lsp_diagnostics', 1, { offset = false })

      assert.are.equal('lsp_diagnostics', payload.type)
      assert.are.equal('device synth1 {\n  port "MIDI Out"\n}', payload.source)
      assert.is_nil(payload.offset)
    end)
  end)
end)
