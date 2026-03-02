--- lcvgc テンプレートモジュール
--- 新規 .cvg ファイル作成時に、DSLの全記法を網羅したサンプルコードを自動挿入する。
--- LANG環境変数に応じて日本語/英語のテンプレートを切り替える。
local M = {}

--- LANG環境変数を取得する（テスト時に差し替え可能）
--- @return string|nil LANG環境変数の値
function M._get_lang()
  return os.getenv("LANG")
end

--- LANG環境変数が日本語ロケールかどうかを判定する
--- @return boolean LANG が "ja" で始まる場合 true
function M.is_ja()
  local lang = M._get_lang()
  if not lang then
    return false
  end
  return lang:sub(1, 2) == "ja"
end

--- 日本語テンプレートの行テーブルを返す
--- @return string[] テンプレートの各行
local function template_ja()
  return {
    "// ============================================================",
    "// lcvgc DSL サンプルテンプレート",
    "// このファイルは新規作成時に自動挿入されます。",
    "// 不要な部分は自由に削除してください。",
    "// ============================================================",
    "",
    "// --- コメント ---",
    "// 行コメント: スラッシュ2つ",
    "",
    "/* ブロックコメント: スラッシュとアスタリスクで囲む */",
    "",
    "/*",
    "  複数行のブロックコメント",
    "  /* ネストも可能 */",
    "*/",
    "",
    "// --- インクルード ---",
    '// include "path/to/file.cvg"',
    "",
    "// --- テンポ・スケール ---",
    "tempo 120",
    "scale c minor",
    "",
    "// --- デバイス定義 ---",
    "// MIDIポートに名前を付ける",
    "device my_synth {",
    '  port "IAC Driver"',
    "}",
    "",
    "// --- インストゥルメント定義 ---",
    "// デバイスのチャンネルに名前を付ける",
    "instrument bass {",
    "  device my_synth",
    "  channel 1",
    "}",
    "",
    "// --- キット定義 ---",
    "// ドラムキットなど、複数ノートをまとめる",
    "kit tr808 {",
    "  device my_synth",
    "  kick {",
    "    channel 10",
    "    note c2",
    "  }",
    "  snare {",
    "    channel 10",
    "    note d2",
    "  }",
    "  hihat {",
    "    channel 10",
    "    note f#2",
    "  }",
    "}",
    "",
    "// --- クリップ定義 ---",
    "// ドラムパターン（キット使用）",
    "clip drums_a [bars 2] {",
    "  use tr808",
    "  resolution 16",
    "  kick  x...x...x...x...",
    "  snare ....x.......x...",
    "  hihat x.x.x.x.x.x.x.x.",
    "}",
    "",
    "// メロディパターン",
    "// 記法: ノート:オクターブ:音価  例) c:3:8 = C3の8分音符",
    "// アーティキュレーション: ' (スタッカート), gN (ゲート長指定)",
    "// 休符: r:音価  和音: [c e g]:3:4  コード名: cmaj7:3:4",
    "// アルペジオ: arp(up, 16)  グループ繰り返し: (c:3:8 d:3:8)*2",
    "// 小節ジャンプ: >2 (2小節目へ移動)",
    "clip bass_a [bars 1] [scale c minor] {",
    "  bass c:3:8 c:3:8 eb:3:8 f:3:4 r:8",
    "}",
    "",
    "// --- シーン定義 ---",
    "// 複数クリップの同時再生、テンポ変更",
    "scene verse {",
    "  drums_a",
    "  bass_a",
    "  tempo +5",
    "}",
    "",
    "// --- セッション定義 ---",
    "// シーンの再生順を定義",
    "session my_song {",
    "  verse [repeat 4]",
    "}",
    "",
    "// --- 再生制御 ---",
    "play verse",
    "// play session my_song [repeat 2]",
    "stop",
    "// stop verse",
  }
end

--- 英語テンプレートの行テーブルを返す
--- @return string[] テンプレートの各行
local function template_en()
  return {
    "// ============================================================",
    "// lcvgc DSL Sample Template",
    "// This file is auto-inserted when creating a new .cvg file.",
    "// Feel free to delete any parts you don't need.",
    "// ============================================================",
    "",
    "// --- Comments ---",
    "// Line comment: two slashes",
    "",
    "/* Block comment: enclosed with slash-asterisk */",
    "",
    "/*",
    "  Multi-line block comment",
    "  /* Nesting is supported */",
    "*/",
    "",
    "// --- Include ---",
    '// include "path/to/file.cvg"',
    "",
    "// --- Tempo & Scale ---",
    "tempo 120",
    "scale c minor",
    "",
    "// --- Device Definition ---",
    "// Give a name to a MIDI port",
    "device my_synth {",
    '  port "IAC Driver"',
    "}",
    "",
    "// --- Instrument Definition ---",
    "// Give a name to a device channel",
    "instrument bass {",
    "  device my_synth",
    "  channel 1",
    "}",
    "",
    "// --- Kit Definition ---",
    "// Group multiple notes (e.g. drum kit)",
    "kit tr808 {",
    "  device my_synth",
    "  kick {",
    "    channel 10",
    "    note c2",
    "  }",
    "  snare {",
    "    channel 10",
    "    note d2",
    "  }",
    "  hihat {",
    "    channel 10",
    "    note f#2",
    "  }",
    "}",
    "",
    "// --- Clip Definition ---",
    "// Drum pattern (using a kit)",
    "clip drums_a [bars 2] {",
    "  use tr808",
    "  resolution 16",
    "  kick  x...x...x...x...",
    "  snare ....x.......x...",
    "  hihat x.x.x.x.x.x.x.x.",
    "}",
    "",
    "// Melody pattern",
    "// Syntax: note:octave:duration  e.g. c:3:8 = C3 eighth note",
    "// Articulation: ' (staccato), gN (gate length)",
    "// Rest: r:duration  Chord: [c e g]:3:4  Chord name: cmaj7:3:4",
    "// Arpeggio: arp(up, 16)  Group repeat: (c:3:8 d:3:8)*2",
    "// Bar jump: >2 (jump to bar 2)",
    "clip bass_a [bars 1] [scale c minor] {",
    "  bass c:3:8 c:3:8 eb:3:8 f:3:4 r:8",
    "}",
    "",
    "// --- Scene Definition ---",
    "// Play multiple clips simultaneously, change tempo",
    "scene verse {",
    "  drums_a",
    "  bass_a",
    "  tempo +5",
    "}",
    "",
    "// --- Session Definition ---",
    "// Define playback order of scenes",
    "session my_song {",
    "  verse [repeat 4]",
    "}",
    "",
    "// --- Playback Control ---",
    "play verse",
    "// play session my_song [repeat 2]",
    "stop",
    "// stop verse",
  }
end

--- テンプレートの行テーブルを返す（LANGに応じて日英切り替え）
--- @return string[] テンプレートの各行
function M.get_lines()
  if M.is_ja() then
    return template_ja()
  else
    return template_en()
  end
end

return M
