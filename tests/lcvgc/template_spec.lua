describe("lcvgc.template", function()
  local template

  before_each(function()
    package.loaded["lcvgc.template"] = nil
    template = require("lcvgc.template")
  end)

  describe("is_ja", function()
    local orig_lang

    before_each(function()
      orig_lang = os.getenv("LANG")
    end)

    -- NOTE: os.getenvは直接設定できないため、内部関数を差し替えてテスト
    it("LANG=ja_JP.UTF-8 のとき true を返す", function()
      template._get_lang = function() return "ja_JP.UTF-8" end
      assert.is_true(template.is_ja())
    end)

    it("LANG=ja のとき true を返す", function()
      template._get_lang = function() return "ja" end
      assert.is_true(template.is_ja())
    end)

    it("LANG=en_US.UTF-8 のとき false を返す", function()
      template._get_lang = function() return "en_US.UTF-8" end
      assert.is_false(template.is_ja())
    end)

    it("LANG=nil のとき false を返す", function()
      template._get_lang = function() return nil end
      assert.is_false(template.is_ja())
    end)
  end)

  describe("get_lines", function()
    it("テーブルを返す", function()
      local lines = template.get_lines()
      assert.is_table(lines)
      assert.is_true(#lines > 0)
    end)

    it("日本語テンプレートに主要キーワードが含まれる", function()
      template._get_lang = function() return "ja_JP.UTF-8" end
      local lines = template.get_lines()
      local text = table.concat(lines, "\n")

      -- DSLの全主要キーワードが含まれることを検証
      local keywords = {
        "device", "instrument", "kit", "clip", "scene",
        "session", "play", "stop", "tempo", "scale", "include",
      }
      for _, kw in ipairs(keywords) do
        assert.is_truthy(
          text:find(kw),
          "キーワード '" .. kw .. "' がテンプレートに含まれていません"
        )
      end
    end)

    it("英語テンプレートに主要キーワードが含まれる", function()
      template._get_lang = function() return "en_US.UTF-8" end
      local lines = template.get_lines()
      local text = table.concat(lines, "\n")

      local keywords = {
        "device", "instrument", "kit", "clip", "scene",
        "session", "play", "stop", "tempo", "scale", "include",
      }
      for _, kw in ipairs(keywords) do
        assert.is_truthy(
          text:find(kw),
          "Keyword '" .. kw .. "' is missing from template"
        )
      end
    end)

    it("日本語テンプレートにコメント記法が含まれる", function()
      template._get_lang = function() return "ja_JP.UTF-8" end
      local lines = template.get_lines()
      local text = table.concat(lines, "\n")

      -- 行コメントとブロックコメント
      assert.is_truthy(text:find("//"), "行コメント '//' が含まれていません")
      assert.is_truthy(text:find("/%*"), "ブロックコメント '/*' が含まれていません")
      assert.is_truthy(text:find("%*/"), "ブロックコメント '*/' が含まれていません")
    end)

    it("英語テンプレートにコメント記法が含まれる", function()
      template._get_lang = function() return "en_US.UTF-8" end
      local lines = template.get_lines()
      local text = table.concat(lines, "\n")

      assert.is_truthy(text:find("//"), "Line comment '//' missing")
      assert.is_truthy(text:find("/%*"), "Block comment '/*' missing")
      assert.is_truthy(text:find("%*/"), "Block comment '*/' missing")
    end)

    it("テンプレートにmelody要素が含まれる", function()
      local lines = template.get_lines()
      local text = table.concat(lines, "\n")

      -- melody記法の要素
      assert.is_truthy(text:find("resolution"), "resolution が含まれていません")
      assert.is_truthy(text:find("use "), "'use' が含まれていません")
      assert.is_truthy(text:find("bars"), "'bars' が含まれていません")
    end)
  end)
end)
