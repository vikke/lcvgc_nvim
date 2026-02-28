describe("lcvgc.eval", function()
  local eval
  local sent_messages

  before_each(function()
    clear_notifications()
    sent_messages = {}

    -- connection.send モック
    package.loaded["lcvgc.connection"] = {
      send = function(msg)
        table.insert(sent_messages, msg)
      end,
      is_connected = function() return true end,
    }

    eval = reload_module("lcvgc.eval")
  end)

  describe("read_file", function()
    it("存在するファイルを読み込む", function()
      -- テスト用一時ファイル作成
      local tmpfile = os.tmpname()
      local f = io.open(tmpfile, "w")
      f:write("line1\nline2\nline3")
      f:close()

      local lines, err = eval.read_file(tmpfile)
      assert.is_nil(err)
      assert.equals(3, #lines)
      assert.equals("line1", lines[1])
      assert.equals("line2", lines[2])
      assert.equals("line3", lines[3])

      os.remove(tmpfile)
    end)

    it("存在しないファイルはエラーを返す", function()
      local lines, err = eval.read_file("/nonexistent/path/file.cvg")
      assert.is_nil(lines)
      assert.is_truthy(err)
      assert.is_truthy(err:match("Cannot read"))
    end)
  end)

  describe("expand_includes", function()
    local tmpdir

    before_each(function()
      tmpdir = os.tmpname()
      os.remove(tmpdir)
      os.execute("mkdir -p " .. tmpdir)
    end)

    after_each(function()
      os.execute("rm -rf " .. tmpdir)
    end)

    local function write_tmp(name, content)
      local path = tmpdir .. "/" .. name
      local dir = path:match("(.+)/")
      if dir then os.execute("mkdir -p " .. dir) end
      local f = io.open(path, "w")
      f:write(content)
      f:close()
      return path
    end

    it("includeなしの行をそのまま返す", function()
      local lines = { "tempo 120", "clip drums" }
      local result, source_map = eval.expand_includes(lines, "test.cvg", tmpdir, {})
      assert.same({ "tempo 120", "clip drums" }, result)
      assert.equals(2, #source_map)
      assert.equals("test.cvg", source_map[1].file)
      assert.equals(1, source_map[1].line)
    end)

    it("include文を展開する", function()
      write_tmp("header.cvg", "tempo 120\nscale C major")
      local lines = { 'include "header.cvg"', "clip drums" }
      local result, source_map = eval.expand_includes(lines, "main.cvg", tmpdir, {})
      assert.equals(3, #result)
      assert.equals("tempo 120", result[1])
      assert.equals("scale C major", result[2])
      assert.equals("clip drums", result[3])
      -- ソースマップ: 展開された行はheader.cvgを指す
      assert.equals("header.cvg", source_map[1].file:match("[^/]+$"))
      assert.equals(1, source_map[1].line)
      assert.equals("header.cvg", source_map[2].file:match("[^/]+$"))
      assert.equals(2, source_map[2].line)
      assert.equals("main.cvg", source_map[3].file)
      assert.equals(2, source_map[3].line)
    end)

    it("再帰的にincludeを展開する", function()
      write_tmp("a.cvg", 'include "b.cvg"\nline_a')
      write_tmp("b.cvg", "line_b")
      local lines = { 'include "a.cvg"', "line_main" }
      local result, source_map = eval.expand_includes(lines, "main.cvg", tmpdir, {})
      assert.equals(3, #result)
      assert.equals("line_b", result[1])
      assert.equals("line_a", result[2])
      assert.equals("line_main", result[3])
      -- line_bはb.cvg由来
      assert.equals("b.cvg", source_map[1].file:match("[^/]+$"))
    end)

    it("重複includeをスキップする", function()
      write_tmp("shared.cvg", "shared_line")
      local lines = { 'include "shared.cvg"', 'include "shared.cvg"', "main_line" }
      local result, _ = eval.expand_includes(lines, "main.cvg", tmpdir, {})
      -- sharedは1回だけ展開される
      assert.equals(2, #result)
      assert.equals("shared_line", result[1])
      assert.equals("main_line", result[2])
    end)

    it("存在しないファイルのincludeでエラーを返す", function()
      local lines = { 'include "nonexistent.cvg"' }
      local result, source_map, err = eval.expand_includes(lines, "main.cvg", tmpdir, {})
      assert.is_truthy(err)
      assert.is_truthy(err:match("Cannot read"))
    end)
  end)
end)
