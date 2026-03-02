local M = {}

function M.setup()
  local ok, parsers = pcall(require, 'nvim-treesitter.parsers')
  if not ok then
    return
  end

  local parser_configs = parsers.get_parser_configs()
  parser_configs.cvg = {
    install_info = {
      url = 'https://github.com/vikke/tree-sitter-cvg',
      files = { 'src/parser.c', 'src/scanner.c' },
      branch = 'main',
      generate_requires_npm = false,
      requires_generate_from_grammar = false,
    },
    filetype = { 'cvg' },
  }

  -- nvim-treesitterのクエリファイルキャッシュをクリア
  -- 遅延読み込みではnvim-treesitter初期化時にcvgのqueries/が未検出のため
  -- キャッシュにfalseが入りhighlightモジュールのattachが失敗する
  local ts_query_ok, ts_query = pcall(require, 'nvim-treesitter.query')
  if ts_query_ok and ts_query.invalidate_query_cache then
    ts_query.invalidate_query_cache('cvg')
  end
end

return M
