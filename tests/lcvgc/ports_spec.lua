describe("lcvgc.ports", function()
  local ports

  before_each(function()
    clear_notifications()
    ports = reload_module("lcvgc.ports")
  end)

  describe("_handle_response", function()
    it("ports フィールドがあればキャッシュして true を返す", function()
      local result = ports._handle_response({
        ports = {
          { name = "IAC Driver Bus 1", direction = "out" },
          { name = "MIDI In", direction = "in" },
        },
      })
      assert.is_true(result)
    end)

    it("ports フィールドがなければ false を返す", function()
      local result = ports._handle_response({ type = "status" })
      assert.is_false(result)
    end)
  end)

  describe("get_output_ports", function()
    it("キャッシュが空の場合は空テーブルを返す", function()
      assert.same({}, ports.get_output_ports())
    end)

    it("direction=out のポートのみ返す", function()
      ports._handle_response({
        ports = {
          { name = "IAC Driver Bus 1", direction = "out" },
          { name = "MIDI In", direction = "in" },
          { name = "Virtual Port", direction = "out" },
        },
      })
      local result = ports.get_output_ports()
      assert.same({ "IAC Driver Bus 1", "Virtual Port" }, result)
    end)

    it("direction=out がない場合は空テーブルを返す", function()
      ports._handle_response({
        ports = {
          { name = "MIDI In", direction = "in" },
        },
      })
      assert.same({}, ports.get_output_ports())
    end)
  end)

  describe("clear_cache", function()
    it("キャッシュをクリアする", function()
      ports._handle_response({
        ports = {
          { name = "IAC Driver Bus 1", direction = "out" },
        },
      })
      assert.equals(1, #ports.get_output_ports())

      ports.clear_cache()
      assert.same({}, ports.get_output_ports())
    end)
  end)

  describe("fetch", function()
    it("未接続時は何もしない", function()
      -- connection.is_connected() は false を返す（デフォルト）
      ports.fetch()
      -- エラーが発生しないことを確認
      assert.same({}, ports.get_output_ports())
    end)

    it("接続中は list_ports リクエストを送信する", function()
      local connection = reload_module("lcvgc.connection")
      local sent = {}
      vim.fn.sockconnect = function() return 42 end
      connection.connect(5555, function() end)

      -- request をモニター
      local orig_request = connection.request
      connection.request = function(payload, handler)
        table.insert(sent, payload)
        return orig_request(payload, handler)
      end

      ports.fetch()
      assert.equals(1, #sent)
      assert.equals("list_ports", sent[1].type)

      vim.fn.sockconnect = function() return 0 end
    end)
  end)
end)
