describe("lcvgc.connection", function()
  local connection

  before_each(function()
    clear_notifications()
    connection = reload_module("lcvgc.connection")
  end)

  describe("is_connected", function()
    it("初期状態は未接続", function()
      assert.is_false(connection.is_connected())
    end)
  end)

  describe("send", function()
    it("未接続時は false を返す", function()
      assert.is_false(connection.send({ type = "eval", source = "test" }))
    end)

    it("未接続時に警告通知を出す", function()
      connection.send({ type = "eval" })
      assert.equals(1, #vim._notifications)
      assert.equals(vim.log.levels.WARN, vim._notifications[1].level)
    end)
  end)

  describe("_on_data", function()
    it("改行区切りの JSON を1件パースしてコールバックを呼ぶ", function()
      local received = {}
      connection = reload_module("lcvgc.connection")
      -- on_message_cb を設定するため connect 経由ではなく直接テスト
      -- _on_data は on_message_cb が nil なら何もしない
      -- まず on_message_cb をセットするため、connect のモックを調整
      vim.fn.sockconnect = function() return 42 end
      connection.connect(5555, function(msg) table.insert(received, msg) end)

      connection._on_data({ '{"type":"status","tempo":120}\n' })
      assert.equals(1, #received)
      assert.equals("status", received[1].type)
      assert.equals(120, received[1].tempo)

      -- リストア
      vim.fn.sockconnect = function() return 0 end
    end)

    it("複数行を一度に処理する", function()
      local received = {}
      vim.fn.sockconnect = function() return 42 end
      connection = reload_module("lcvgc.connection")
      connection.connect(5555, function(msg) table.insert(received, msg) end)

      connection._on_data({ '{"type":"a"}\n{"type":"b"}\n' })
      assert.equals(2, #received)
      assert.equals("a", received[1].type)
      assert.equals("b", received[2].type)

      vim.fn.sockconnect = function() return 0 end
    end)

    it("分割されたデータをバッファリングする", function()
      local received = {}
      vim.fn.sockconnect = function() return 42 end
      connection = reload_module("lcvgc.connection")
      connection.connect(5555, function(msg) table.insert(received, msg) end)

      connection._on_data({ '{"type":' })
      assert.equals(0, #received)

      connection._on_data({ '"ok"}\n' })
      assert.equals(1, #received)
      assert.equals("ok", received[1].type)

      vim.fn.sockconnect = function() return 0 end
    end)

    it("空行は無視する", function()
      local received = {}
      vim.fn.sockconnect = function() return 42 end
      connection = reload_module("lcvgc.connection")
      connection.connect(5555, function(msg) table.insert(received, msg) end)

      connection._on_data({ '\n\n{"type":"x"}\n\n' })
      assert.equals(1, #received)

      vim.fn.sockconnect = function() return 0 end
    end)

    it("不正な JSON はスキップする", function()
      local received = {}
      vim.fn.sockconnect = function() return 42 end
      connection = reload_module("lcvgc.connection")
      connection.connect(5555, function(msg) table.insert(received, msg) end)

      connection._on_data({ 'not json\n{"type":"valid"}\n' })
      assert.equals(1, #received)
      assert.equals("valid", received[1].type)

      vim.fn.sockconnect = function() return 0 end
    end)
  end)

  describe("disconnect", function()
    it("接続中なら切断して状態をリセットする", function()
      vim.fn.sockconnect = function() return 42 end
      connection = reload_module("lcvgc.connection")
      connection.connect(5555, function() end)
      assert.is_true(connection.is_connected())

      connection.disconnect()
      assert.is_false(connection.is_connected())

      vim.fn.sockconnect = function() return 0 end
    end)

    it("未接続時は何もしない", function()
      clear_notifications()
      connection.disconnect()
      assert.equals(0, #vim._notifications)
    end)
  end)
end)
