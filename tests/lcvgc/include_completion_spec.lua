describe("lcvgc.completion include", function()
  local completion

  before_each(function()
    clear_notifications()
    completion = reload_module("lcvgc.completion")
  end)

  describe("is_include_context", function()
    it("include + スペースの行は true", function()
      assert.is_true(completion.is_include_context("include "))
    end)

    it("include + パスの行は true", function()
      assert.is_true(completion.is_include_context("include lib/bass.cvg"))
    end)

    it("先頭スペース付き include は true", function()
      assert.is_true(completion.is_include_context("  include "))
    end)

    it("include のみ（末尾スペースなし）は false", function()
      assert.is_false(completion.is_include_context("include"))
    end)

    it("空行は false", function()
      assert.is_false(completion.is_include_context(""))
    end)

    it("他のキーワードは false", function()
      assert.is_false(completion.is_include_context("device test"))
    end)

    it("行中の include は false", function()
      assert.is_false(completion.is_include_context("// include foo.cvg"))
    end)
  end)

  describe("get_include_partial", function()
    it("include の後のテキストを返す", function()
      assert.equals("lib/bass.cvg", completion.get_include_partial("include lib/bass.cvg"))
    end)

    it("include + スペースのみの場合は空文字を返す", function()
      assert.equals("", completion.get_include_partial("include "))
    end)

    it("先頭スペース付きでも正しくパースする", function()
      assert.equals("foo.cvg", completion.get_include_partial("  include foo.cvg"))
    end)

    it("include なしの行は空文字を返す", function()
      assert.equals("", completion.get_include_partial("device test"))
    end)
  end)

  describe("list_include_candidates", function()
    local saved_readdir, saved_isdirectory

    before_each(function()
      saved_readdir = vim.fn.readdir
      saved_isdirectory = vim.fn.isdirectory
    end)

    after_each(function()
      vim.fn.readdir = saved_readdir
      vim.fn.isdirectory = saved_isdirectory
    end)

    it("cvg ファイルとディレクトリを返す", function()
      vim.fn.readdir = function(path)
        if path == "/project" then
          return { "bass.cvg", "drums.cvg", "lib", "README.md" }
        end
        return {}
      end
      vim.fn.isdirectory = function(path)
        if path == "/project/lib" then return 1 end
        return 0
      end

      local candidates = completion.list_include_candidates("/project", "")

      assert.equals(3, #candidates)
      -- cvg ファイル
      assert.equals("bass.cvg", candidates[1].label)
      assert.equals(17, candidates[1].kind) -- File
      assert.equals("drums.cvg", candidates[2].label)
      assert.equals(17, candidates[2].kind)
      -- ディレクトリ
      assert.equals("lib/", candidates[3].label)
      assert.equals(19, candidates[3].kind) -- Folder
    end)

    it("サブディレクトリ内のファイルを返す", function()
      vim.fn.readdir = function(path)
        if path == "/project/lib" or path == "/project/lib/" then
          return { "common.cvg", "utils.cvg" }
        end
        return {}
      end
      vim.fn.isdirectory = function() return 0 end

      local candidates = completion.list_include_candidates("/project", "lib/")

      assert.equals(2, #candidates)
      assert.equals("lib/common.cvg", candidates[1].label)
      assert.equals("lib/utils.cvg", candidates[2].label)
    end)

    it("ドットファイルを除外する", function()
      vim.fn.readdir = function()
        return { ".hidden", ".git", "main.cvg" }
      end
      vim.fn.isdirectory = function() return 0 end

      local candidates = completion.list_include_candidates("/project", "")

      assert.equals(1, #candidates)
      assert.equals("main.cvg", candidates[1].label)
    end)

    it("cvg/lcvgc 以外のファイルを除外する", function()
      vim.fn.readdir = function()
        return { "main.cvg", "config.lcvgc", "notes.txt", "README.md" }
      end
      vim.fn.isdirectory = function() return 0 end

      local candidates = completion.list_include_candidates("/project", "")

      assert.equals(2, #candidates)
      assert.equals("main.cvg", candidates[1].label)
      assert.equals("config.lcvgc", candidates[2].label)
    end)

    it("存在しないディレクトリでは空リストを返す", function()
      vim.fn.readdir = function()
        error("no such directory")
      end

      local candidates = completion.list_include_candidates("/nonexistent", "")

      assert.equals(0, #candidates)
    end)

    it("空ディレクトリでは空リストを返す", function()
      vim.fn.readdir = function() return {} end
      vim.fn.isdirectory = function() return 0 end

      local candidates = completion.list_include_candidates("/project", "")

      assert.equals(0, #candidates)
    end)
  end)
end)
