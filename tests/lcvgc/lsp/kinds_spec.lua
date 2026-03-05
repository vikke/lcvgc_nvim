require('tests.helpers.vim_mock')
local kinds = require('lcvgc.lsp.kinds')

describe("lcvgc.lsp.kinds", function()
  describe("completion_kind", function()
    it("Keyword → 14 (Keyword)", function()
      assert.are.equal(14, kinds.completion_kind("Keyword"))
    end)

    it("NoteName → 12 (Value)", function()
      assert.are.equal(12, kinds.completion_kind("NoteName"))
    end)

    it("ChordName → 12 (Value)", function()
      assert.are.equal(12, kinds.completion_kind("ChordName"))
    end)

    it("CcAlias → 6 (Variable)", function()
      assert.are.equal(6, kinds.completion_kind("CcAlias"))
    end)

    it("Identifier → 6 (Variable)", function()
      assert.are.equal(6, kinds.completion_kind("Identifier"))
    end)

    it("不明な値はデフォルト 1 (Text) を返す", function()
      assert.are.equal(1, kinds.completion_kind("Unknown"))
    end)
  end)

  describe("diagnostic_severity", function()
    it("Error → 1 (ERROR)", function()
      assert.are.equal(1, kinds.diagnostic_severity("Error"))
    end)

    it("Warning → 2 (WARN)", function()
      assert.are.equal(2, kinds.diagnostic_severity("Warning"))
    end)

    it("不明な値はデフォルト 4 (HINT) を返す", function()
      assert.are.equal(4, kinds.diagnostic_severity("Unknown"))
    end)
  end)

  describe("symbol_kind", function()
    it("Device → 5 (Class)", function()
      assert.are.equal(5, kinds.symbol_kind("Device"))
    end)

    it("Instrument → 23 (Struct)", function()
      assert.are.equal(23, kinds.symbol_kind("Instrument"))
    end)

    it("Kit → 23 (Struct)", function()
      assert.are.equal(23, kinds.symbol_kind("Kit"))
    end)

    it("Clip → 12 (Function)", function()
      assert.are.equal(12, kinds.symbol_kind("Clip"))
    end)

    it("Scene → 2 (Module)", function()
      assert.are.equal(2, kinds.symbol_kind("Scene"))
    end)

    it("Session → 2 (Module)", function()
      assert.are.equal(2, kinds.symbol_kind("Session"))
    end)

    it("Tempo → 14 (Constant)", function()
      assert.are.equal(14, kinds.symbol_kind("Tempo"))
    end)

    it("Scale → 14 (Constant)", function()
      assert.are.equal(14, kinds.symbol_kind("Scale"))
    end)

    it("Variable → 13 (Variable)", function()
      assert.are.equal(13, kinds.symbol_kind("Variable"))
    end)

    it("Include → 17 (File)", function()
      assert.are.equal(17, kinds.symbol_kind("Include"))
    end)

    it("Play → 24 (Event)", function()
      assert.are.equal(24, kinds.symbol_kind("Play"))
    end)

    it("Stop → 24 (Event)", function()
      assert.are.equal(24, kinds.symbol_kind("Stop"))
    end)

    it("不明な値はデフォルト 1 (File) を返す", function()
      assert.are.equal(1, kinds.symbol_kind("Unknown"))
    end)
  end)
end)
