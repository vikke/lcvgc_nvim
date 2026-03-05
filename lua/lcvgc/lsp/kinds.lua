--- LSPレスポンスの文字列定数をNeovimの定数値に変換するモジュール
--- デーモンがTCP JSON経由で返すCompletionKind/DiagnosticSeverity/SymbolKind文字列を
--- Neovimが期待する数値定数に変換する
local M = {}

--- CompletionKind文字列からNeovim数値への変換テーブル
--- @type table<string, number>
local completion_kind_map = {
  Keyword = 14, -- CompletionItemKind.Keyword
  NoteName = 12, -- CompletionItemKind.Value
  ChordName = 12, -- CompletionItemKind.Value
  CcAlias = 6, -- CompletionItemKind.Variable
  Identifier = 6, -- CompletionItemKind.Variable
}

--- DiagnosticSeverity文字列からNeovim数値への変換テーブル
--- @type table<string, number>
local diagnostic_severity_map = {
  Error = 1, -- vim.diagnostic.severity.ERROR
  Warning = 2, -- vim.diagnostic.severity.WARN
}

--- SymbolKind文字列からNeovim数値への変換テーブル
--- @type table<string, number>
local symbol_kind_map = {
  Device = 5, -- SymbolKind.Class
  Instrument = 23, -- SymbolKind.Struct
  Kit = 23, -- SymbolKind.Struct
  Clip = 12, -- SymbolKind.Function
  Scene = 2, -- SymbolKind.Module
  Session = 2, -- SymbolKind.Module
  Tempo = 14, -- SymbolKind.Constant
  Scale = 14, -- SymbolKind.Constant
  Variable = 13, -- SymbolKind.Variable
  Include = 17, -- SymbolKind.File
  Play = 24, -- SymbolKind.Event
  Stop = 24, -- SymbolKind.Event
}

--- CompletionKind文字列をNeovimのCompletionItemKind数値に変換する
--- @param kind string デーモンが返すCompletionKind文字列
--- @return number CompletionItemKind数値（不明な場合はText=1）
function M.completion_kind(kind)
  return completion_kind_map[kind] or 1
end

--- DiagnosticSeverity文字列をNeovimのdiagnostic severity数値に変換する
--- @param severity string デーモンが返すDiagnosticSeverity文字列
--- @return number diagnostic severity数値（不明な場合はHINT=4）
function M.diagnostic_severity(severity)
  return diagnostic_severity_map[severity] or 4
end

--- SymbolKind文字列をNeovimのSymbolKind数値に変換する
--- @param kind string デーモンが返すSymbolKind文字列
--- @return number SymbolKind数値（不明な場合はFile=1）
function M.symbol_kind(kind)
  return symbol_kind_map[kind] or 1
end

return M
