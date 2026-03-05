require('tests.helpers.vim_mock')

-- vim.diagnostic モック
local diagnostic_sets = {}
vim.diagnostic = {
  severity = { ERROR = 1, WARN = 2, INFO = 3, HINT = 4 },
  set = function(ns_id, buf, diagnostics)
    table.insert(diagnostic_sets, { ns = ns_id, bufnr = buf, items = diagnostics })
  end,
}

describe('lcvgc.lsp.diagnostics', function()
  local diagnostics

  --- connection モックの初期設定用
  --- @param is_connected boolean 接続状態
  --- @param request_handler function|nil request呼び出し時のハンドラ
  local function setup_connection_mock(is_connected, request_handler)
    package.loaded['lcvgc.connection'] = {
      is_connected = function() return is_connected end,
      request = request_handler or function() return true end,
    }
  end

  --- 標準的な診断レスポンスを返すrequest関数を生成する
  --- @param items table[] 診断アイテムのリスト
  --- @return function request関数
  local function make_request_with_items(items)
    return function(payload, handler)
      handler({
        success = true,
        lsp = {
          type = 'diagnostics',
          items = items,
        },
      })
      return true
    end
  end

  before_each(function()
    diagnostic_sets = {}
    -- request モジュールのモック（offsetなしでペイロード構築）
    package.loaded['lcvgc.lsp.request'] = {
      build = function(type_name, bufnr, opts)
        return { type = type_name, bufnr = bufnr, offset = opts and opts.offset }
      end,
    }
  end)

  after_each(function()
    package.loaded['lcvgc.lsp.diagnostics'] = nil
    package.loaded['lcvgc.connection'] = nil
    package.loaded['lcvgc.lsp.request'] = nil
  end)

  describe('未接続時', function()
    it('vim.diagnostic.set が呼ばれない', function()
      setup_connection_mock(false)
      diagnostics = reload_module('lcvgc.lsp.diagnostics')

      diagnostics.update(1)

      assert.are.equal(0, #diagnostic_sets)
    end)
  end)

  describe('正常レスポンス', function()
    it('2つの診断アイテムが正しい形式でvim.diagnostic.setに渡される', function()
      setup_connection_mock(true, make_request_with_items({
        { start_line = 0, start_col = 0, end_line = 0, end_col = 5, message = '未定義の変数', severity = 'Error' },
        { start_line = 3, start_col = 2, end_line = 3, end_col = 10, message = '非推奨の構文', severity = 'Warning' },
      }))
      diagnostics = reload_module('lcvgc.lsp.diagnostics')

      diagnostics.update(1)

      assert.are.equal(1, #diagnostic_sets)
      local result = diagnostic_sets[1]
      assert.are.equal(diagnostics.get_namespace(), result.ns)
      assert.are.equal(1, result.bufnr)
      assert.are.equal(2, #result.items)

      -- 1つ目: Error → severity 1
      local item1 = result.items[1]
      assert.are.equal(0, item1.lnum)
      assert.are.equal(0, item1.col)
      assert.are.equal(0, item1.end_lnum)
      assert.are.equal(5, item1.end_col)
      assert.are.equal('未定義の変数', item1.message)
      assert.are.equal(1, item1.severity)
      assert.are.equal('lcvgc', item1.source)

      -- 2つ目: Warning → severity 2
      local item2 = result.items[2]
      assert.are.equal(3, item2.lnum)
      assert.are.equal(2, item2.col)
      assert.are.equal(3, item2.end_lnum)
      assert.are.equal(10, item2.end_col)
      assert.are.equal('非推奨の構文', item2.message)
      assert.are.equal(2, item2.severity)
      assert.are.equal('lcvgc', item2.source)
    end)
  end)

  describe('空アイテム', function()
    it('空の diagnostics で vim.diagnostic.set が呼ばれる（クリア）', function()
      setup_connection_mock(true, make_request_with_items({}))
      diagnostics = reload_module('lcvgc.lsp.diagnostics')

      diagnostics.update(1)

      assert.are.equal(1, #diagnostic_sets)
      assert.are.equal(0, #diagnostic_sets[1].items)
    end)
  end)

  describe('重複リクエスト排除', function()
    it('pending中にupdateを呼ぶと2回目はスキップされる', function()
      local call_count = 0
      setup_connection_mock(true, function(_payload, _handler)
        -- handlerを呼ばない（pendingのまま）
        call_count = call_count + 1
        return true
      end)
      diagnostics = reload_module('lcvgc.lsp.diagnostics')

      diagnostics.update(1)
      diagnostics.update(1)

      assert.are.equal(1, call_count)
    end)
  end)

  describe('get_namespace', function()
    it('namespace IDを返す', function()
      setup_connection_mock(true)
      diagnostics = reload_module('lcvgc.lsp.diagnostics')

      local ns = diagnostics.get_namespace()
      assert.is_number(ns)
    end)
  end)
end)
