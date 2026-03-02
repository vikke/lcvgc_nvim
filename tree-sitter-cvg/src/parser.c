#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 232
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 130
#define ALIAS_COUNT 0
#define TOKEN_COUNT 72
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 5

enum ts_symbol_identifiers {
  sym_identifier = 1,
  anon_sym_device = 2,
  anon_sym_LBRACE = 3,
  anon_sym_RBRACE = 4,
  anon_sym_port = 5,
  anon_sym_instrument = 6,
  anon_sym_channel = 7,
  anon_sym_note = 8,
  anon_sym_gate_normal = 9,
  anon_sym_gate_staccato = 10,
  anon_sym_kit = 11,
  sym_note_literal = 12,
  anon_sym_clip = 13,
  anon_sym_LBRACK = 14,
  anon_sym_RBRACK = 15,
  anon_sym_bars = 16,
  anon_sym_time = 17,
  anon_sym_scale = 18,
  sym_time_signature = 19,
  anon_sym_major = 20,
  anon_sym_minor = 21,
  anon_sym_harmonic_minor = 22,
  anon_sym_melodic_minor = 23,
  anon_sym_dorian = 24,
  anon_sym_phrygian = 25,
  anon_sym_lydian = 26,
  anon_sym_mixolydian = 27,
  anon_sym_locrian = 28,
  anon_sym_use = 29,
  anon_sym_resolution = 30,
  sym_step_pattern = 31,
  anon_sym_GT = 32,
  anon_sym_COLON = 33,
  anon_sym_r = 34,
  sym_octave = 35,
  anon_sym_1 = 36,
  anon_sym_2 = 37,
  anon_sym_4 = 38,
  anon_sym_4_DOT = 39,
  anon_sym_8 = 40,
  anon_sym_8_DOT = 41,
  anon_sym_16 = 42,
  anon_sym_32 = 43,
  anon_sym_SQUOTE = 44,
  anon_sym_g = 45,
  sym_chord_symbol = 46,
  anon_sym_arp = 47,
  anon_sym_LPAREN = 48,
  anon_sym_COMMA = 49,
  anon_sym_RPAREN = 50,
  anon_sym_up = 51,
  anon_sym_down = 52,
  anon_sym_updown = 53,
  anon_sym_random = 54,
  anon_sym_STAR = 55,
  anon_sym_scene = 56,
  sym_probability = 57,
  anon_sym_PIPE = 58,
  anon_sym_tempo = 59,
  sym_tempo_delta = 60,
  anon_sym_session = 61,
  anon_sym_repeat = 62,
  anon_sym_loop = 63,
  anon_sym_include = 64,
  anon_sym_play = 65,
  anon_sym_stop = 66,
  sym_note_name = 67,
  sym_number = 68,
  sym_string = 69,
  sym_comment = 70,
  sym_block_comment = 71,
  sym_source_file = 72,
  sym__top_level = 73,
  sym_device_def = 74,
  sym_device_property = 75,
  sym_instrument_def = 76,
  sym_instrument_property = 77,
  sym_kit_def = 78,
  sym__kit_member = 79,
  sym_kit_instrument = 80,
  sym_kit_instrument_property = 81,
  sym_clip_def = 82,
  sym_clip_header = 83,
  sym__clip_attr = 84,
  sym_bars_attr = 85,
  sym_time_attr = 86,
  sym_scale_attr = 87,
  sym_scale_type = 88,
  sym__clip_content = 89,
  sym_use_stmt = 90,
  sym_resolution_stmt = 91,
  sym_drum_line = 92,
  sym_melody_line = 93,
  sym__melody_element = 94,
  sym_bar_jump = 95,
  sym_pitched_note = 96,
  sym_rest = 97,
  sym_duration = 98,
  sym_articulation = 99,
  sym_chord = 100,
  sym_chord_name = 101,
  sym_arp_expr = 102,
  sym_arp_direction = 103,
  sym_melody_group = 104,
  sym_scene_def = 105,
  sym__scene_content = 106,
  sym_scene_slot = 107,
  sym_shuffle_expr = 108,
  sym_weight = 109,
  sym_scene_tempo = 110,
  sym_session_def = 111,
  sym_session_entry = 112,
  sym_session_modifier = 113,
  sym_include_stmt = 114,
  sym_tempo_stmt = 115,
  sym_scale_stmt = 116,
  sym_play_stmt = 117,
  sym_stop_stmt = 118,
  aux_sym_source_file_repeat1 = 119,
  aux_sym_device_def_repeat1 = 120,
  aux_sym_instrument_def_repeat1 = 121,
  aux_sym_kit_def_repeat1 = 122,
  aux_sym_kit_instrument_repeat1 = 123,
  aux_sym_clip_def_repeat1 = 124,
  aux_sym_clip_def_repeat2 = 125,
  aux_sym_melody_line_repeat1 = 126,
  aux_sym_chord_repeat1 = 127,
  aux_sym_scene_def_repeat1 = 128,
  aux_sym_session_def_repeat1 = 129,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_device] = "device",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_port] = "port",
  [anon_sym_instrument] = "instrument",
  [anon_sym_channel] = "channel",
  [anon_sym_note] = "note",
  [anon_sym_gate_normal] = "gate_normal",
  [anon_sym_gate_staccato] = "gate_staccato",
  [anon_sym_kit] = "kit",
  [sym_note_literal] = "note_literal",
  [anon_sym_clip] = "clip",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_bars] = "bars",
  [anon_sym_time] = "time",
  [anon_sym_scale] = "scale",
  [sym_time_signature] = "time_signature",
  [anon_sym_major] = "major",
  [anon_sym_minor] = "minor",
  [anon_sym_harmonic_minor] = "harmonic_minor",
  [anon_sym_melodic_minor] = "melodic_minor",
  [anon_sym_dorian] = "dorian",
  [anon_sym_phrygian] = "phrygian",
  [anon_sym_lydian] = "lydian",
  [anon_sym_mixolydian] = "mixolydian",
  [anon_sym_locrian] = "locrian",
  [anon_sym_use] = "use",
  [anon_sym_resolution] = "resolution",
  [sym_step_pattern] = "step_pattern",
  [anon_sym_GT] = ">",
  [anon_sym_COLON] = ":",
  [anon_sym_r] = "r",
  [sym_octave] = "octave",
  [anon_sym_1] = "1",
  [anon_sym_2] = "2",
  [anon_sym_4] = "4",
  [anon_sym_4_DOT] = "4.",
  [anon_sym_8] = "8",
  [anon_sym_8_DOT] = "8.",
  [anon_sym_16] = "16",
  [anon_sym_32] = "32",
  [anon_sym_SQUOTE] = "'",
  [anon_sym_g] = "g",
  [sym_chord_symbol] = "chord_symbol",
  [anon_sym_arp] = "arp",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_up] = "up",
  [anon_sym_down] = "down",
  [anon_sym_updown] = "updown",
  [anon_sym_random] = "random",
  [anon_sym_STAR] = "*",
  [anon_sym_scene] = "scene",
  [sym_probability] = "probability",
  [anon_sym_PIPE] = "|",
  [anon_sym_tempo] = "tempo",
  [sym_tempo_delta] = "tempo_delta",
  [anon_sym_session] = "session",
  [anon_sym_repeat] = "repeat",
  [anon_sym_loop] = "loop",
  [anon_sym_include] = "include",
  [anon_sym_play] = "play",
  [anon_sym_stop] = "stop",
  [sym_note_name] = "note_name",
  [sym_number] = "number",
  [sym_string] = "string",
  [sym_comment] = "comment",
  [sym_block_comment] = "block_comment",
  [sym_source_file] = "source_file",
  [sym__top_level] = "_top_level",
  [sym_device_def] = "device_def",
  [sym_device_property] = "device_property",
  [sym_instrument_def] = "instrument_def",
  [sym_instrument_property] = "instrument_property",
  [sym_kit_def] = "kit_def",
  [sym__kit_member] = "_kit_member",
  [sym_kit_instrument] = "kit_instrument",
  [sym_kit_instrument_property] = "kit_instrument_property",
  [sym_clip_def] = "clip_def",
  [sym_clip_header] = "clip_header",
  [sym__clip_attr] = "_clip_attr",
  [sym_bars_attr] = "bars_attr",
  [sym_time_attr] = "time_attr",
  [sym_scale_attr] = "scale_attr",
  [sym_scale_type] = "scale_type",
  [sym__clip_content] = "_clip_content",
  [sym_use_stmt] = "use_stmt",
  [sym_resolution_stmt] = "resolution_stmt",
  [sym_drum_line] = "drum_line",
  [sym_melody_line] = "melody_line",
  [sym__melody_element] = "_melody_element",
  [sym_bar_jump] = "bar_jump",
  [sym_pitched_note] = "pitched_note",
  [sym_rest] = "rest",
  [sym_duration] = "duration",
  [sym_articulation] = "articulation",
  [sym_chord] = "chord",
  [sym_chord_name] = "chord_name",
  [sym_arp_expr] = "arp_expr",
  [sym_arp_direction] = "arp_direction",
  [sym_melody_group] = "melody_group",
  [sym_scene_def] = "scene_def",
  [sym__scene_content] = "_scene_content",
  [sym_scene_slot] = "scene_slot",
  [sym_shuffle_expr] = "shuffle_expr",
  [sym_weight] = "weight",
  [sym_scene_tempo] = "scene_tempo",
  [sym_session_def] = "session_def",
  [sym_session_entry] = "session_entry",
  [sym_session_modifier] = "session_modifier",
  [sym_include_stmt] = "include_stmt",
  [sym_tempo_stmt] = "tempo_stmt",
  [sym_scale_stmt] = "scale_stmt",
  [sym_play_stmt] = "play_stmt",
  [sym_stop_stmt] = "stop_stmt",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_device_def_repeat1] = "device_def_repeat1",
  [aux_sym_instrument_def_repeat1] = "instrument_def_repeat1",
  [aux_sym_kit_def_repeat1] = "kit_def_repeat1",
  [aux_sym_kit_instrument_repeat1] = "kit_instrument_repeat1",
  [aux_sym_clip_def_repeat1] = "clip_def_repeat1",
  [aux_sym_clip_def_repeat2] = "clip_def_repeat2",
  [aux_sym_melody_line_repeat1] = "melody_line_repeat1",
  [aux_sym_chord_repeat1] = "chord_repeat1",
  [aux_sym_scene_def_repeat1] = "scene_def_repeat1",
  [aux_sym_session_def_repeat1] = "session_def_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_device] = anon_sym_device,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_port] = anon_sym_port,
  [anon_sym_instrument] = anon_sym_instrument,
  [anon_sym_channel] = anon_sym_channel,
  [anon_sym_note] = anon_sym_note,
  [anon_sym_gate_normal] = anon_sym_gate_normal,
  [anon_sym_gate_staccato] = anon_sym_gate_staccato,
  [anon_sym_kit] = anon_sym_kit,
  [sym_note_literal] = sym_note_literal,
  [anon_sym_clip] = anon_sym_clip,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_bars] = anon_sym_bars,
  [anon_sym_time] = anon_sym_time,
  [anon_sym_scale] = anon_sym_scale,
  [sym_time_signature] = sym_time_signature,
  [anon_sym_major] = anon_sym_major,
  [anon_sym_minor] = anon_sym_minor,
  [anon_sym_harmonic_minor] = anon_sym_harmonic_minor,
  [anon_sym_melodic_minor] = anon_sym_melodic_minor,
  [anon_sym_dorian] = anon_sym_dorian,
  [anon_sym_phrygian] = anon_sym_phrygian,
  [anon_sym_lydian] = anon_sym_lydian,
  [anon_sym_mixolydian] = anon_sym_mixolydian,
  [anon_sym_locrian] = anon_sym_locrian,
  [anon_sym_use] = anon_sym_use,
  [anon_sym_resolution] = anon_sym_resolution,
  [sym_step_pattern] = sym_step_pattern,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_r] = anon_sym_r,
  [sym_octave] = sym_octave,
  [anon_sym_1] = anon_sym_1,
  [anon_sym_2] = anon_sym_2,
  [anon_sym_4] = anon_sym_4,
  [anon_sym_4_DOT] = anon_sym_4_DOT,
  [anon_sym_8] = anon_sym_8,
  [anon_sym_8_DOT] = anon_sym_8_DOT,
  [anon_sym_16] = anon_sym_16,
  [anon_sym_32] = anon_sym_32,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [anon_sym_g] = anon_sym_g,
  [sym_chord_symbol] = sym_chord_symbol,
  [anon_sym_arp] = anon_sym_arp,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_up] = anon_sym_up,
  [anon_sym_down] = anon_sym_down,
  [anon_sym_updown] = anon_sym_updown,
  [anon_sym_random] = anon_sym_random,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_scene] = anon_sym_scene,
  [sym_probability] = sym_probability,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_tempo] = anon_sym_tempo,
  [sym_tempo_delta] = sym_tempo_delta,
  [anon_sym_session] = anon_sym_session,
  [anon_sym_repeat] = anon_sym_repeat,
  [anon_sym_loop] = anon_sym_loop,
  [anon_sym_include] = anon_sym_include,
  [anon_sym_play] = anon_sym_play,
  [anon_sym_stop] = anon_sym_stop,
  [sym_note_name] = sym_note_name,
  [sym_number] = sym_number,
  [sym_string] = sym_string,
  [sym_comment] = sym_comment,
  [sym_block_comment] = sym_block_comment,
  [sym_source_file] = sym_source_file,
  [sym__top_level] = sym__top_level,
  [sym_device_def] = sym_device_def,
  [sym_device_property] = sym_device_property,
  [sym_instrument_def] = sym_instrument_def,
  [sym_instrument_property] = sym_instrument_property,
  [sym_kit_def] = sym_kit_def,
  [sym__kit_member] = sym__kit_member,
  [sym_kit_instrument] = sym_kit_instrument,
  [sym_kit_instrument_property] = sym_kit_instrument_property,
  [sym_clip_def] = sym_clip_def,
  [sym_clip_header] = sym_clip_header,
  [sym__clip_attr] = sym__clip_attr,
  [sym_bars_attr] = sym_bars_attr,
  [sym_time_attr] = sym_time_attr,
  [sym_scale_attr] = sym_scale_attr,
  [sym_scale_type] = sym_scale_type,
  [sym__clip_content] = sym__clip_content,
  [sym_use_stmt] = sym_use_stmt,
  [sym_resolution_stmt] = sym_resolution_stmt,
  [sym_drum_line] = sym_drum_line,
  [sym_melody_line] = sym_melody_line,
  [sym__melody_element] = sym__melody_element,
  [sym_bar_jump] = sym_bar_jump,
  [sym_pitched_note] = sym_pitched_note,
  [sym_rest] = sym_rest,
  [sym_duration] = sym_duration,
  [sym_articulation] = sym_articulation,
  [sym_chord] = sym_chord,
  [sym_chord_name] = sym_chord_name,
  [sym_arp_expr] = sym_arp_expr,
  [sym_arp_direction] = sym_arp_direction,
  [sym_melody_group] = sym_melody_group,
  [sym_scene_def] = sym_scene_def,
  [sym__scene_content] = sym__scene_content,
  [sym_scene_slot] = sym_scene_slot,
  [sym_shuffle_expr] = sym_shuffle_expr,
  [sym_weight] = sym_weight,
  [sym_scene_tempo] = sym_scene_tempo,
  [sym_session_def] = sym_session_def,
  [sym_session_entry] = sym_session_entry,
  [sym_session_modifier] = sym_session_modifier,
  [sym_include_stmt] = sym_include_stmt,
  [sym_tempo_stmt] = sym_tempo_stmt,
  [sym_scale_stmt] = sym_scale_stmt,
  [sym_play_stmt] = sym_play_stmt,
  [sym_stop_stmt] = sym_stop_stmt,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_device_def_repeat1] = aux_sym_device_def_repeat1,
  [aux_sym_instrument_def_repeat1] = aux_sym_instrument_def_repeat1,
  [aux_sym_kit_def_repeat1] = aux_sym_kit_def_repeat1,
  [aux_sym_kit_instrument_repeat1] = aux_sym_kit_instrument_repeat1,
  [aux_sym_clip_def_repeat1] = aux_sym_clip_def_repeat1,
  [aux_sym_clip_def_repeat2] = aux_sym_clip_def_repeat2,
  [aux_sym_melody_line_repeat1] = aux_sym_melody_line_repeat1,
  [aux_sym_chord_repeat1] = aux_sym_chord_repeat1,
  [aux_sym_scene_def_repeat1] = aux_sym_scene_def_repeat1,
  [aux_sym_session_def_repeat1] = aux_sym_session_def_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_device] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_port] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_instrument] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_channel] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_note] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_gate_normal] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_gate_staccato] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_kit] = {
    .visible = true,
    .named = false,
  },
  [sym_note_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_clip] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bars] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_time] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_scale] = {
    .visible = true,
    .named = false,
  },
  [sym_time_signature] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_major] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_minor] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_harmonic_minor] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_melodic_minor] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_dorian] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_phrygian] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_lydian] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mixolydian] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_locrian] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_use] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_resolution] = {
    .visible = true,
    .named = false,
  },
  [sym_step_pattern] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_r] = {
    .visible = true,
    .named = false,
  },
  [sym_octave] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_4] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_4_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_8_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_g] = {
    .visible = true,
    .named = false,
  },
  [sym_chord_symbol] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_arp] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_up] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_down] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_updown] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_random] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_scene] = {
    .visible = true,
    .named = false,
  },
  [sym_probability] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_tempo] = {
    .visible = true,
    .named = false,
  },
  [sym_tempo_delta] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_session] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_repeat] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_loop] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_include] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_play] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_stop] = {
    .visible = true,
    .named = false,
  },
  [sym_note_name] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_block_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__top_level] = {
    .visible = false,
    .named = true,
  },
  [sym_device_def] = {
    .visible = true,
    .named = true,
  },
  [sym_device_property] = {
    .visible = true,
    .named = true,
  },
  [sym_instrument_def] = {
    .visible = true,
    .named = true,
  },
  [sym_instrument_property] = {
    .visible = true,
    .named = true,
  },
  [sym_kit_def] = {
    .visible = true,
    .named = true,
  },
  [sym__kit_member] = {
    .visible = false,
    .named = true,
  },
  [sym_kit_instrument] = {
    .visible = true,
    .named = true,
  },
  [sym_kit_instrument_property] = {
    .visible = true,
    .named = true,
  },
  [sym_clip_def] = {
    .visible = true,
    .named = true,
  },
  [sym_clip_header] = {
    .visible = true,
    .named = true,
  },
  [sym__clip_attr] = {
    .visible = false,
    .named = true,
  },
  [sym_bars_attr] = {
    .visible = true,
    .named = true,
  },
  [sym_time_attr] = {
    .visible = true,
    .named = true,
  },
  [sym_scale_attr] = {
    .visible = true,
    .named = true,
  },
  [sym_scale_type] = {
    .visible = true,
    .named = true,
  },
  [sym__clip_content] = {
    .visible = false,
    .named = true,
  },
  [sym_use_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_resolution_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_drum_line] = {
    .visible = true,
    .named = true,
  },
  [sym_melody_line] = {
    .visible = true,
    .named = true,
  },
  [sym__melody_element] = {
    .visible = false,
    .named = true,
  },
  [sym_bar_jump] = {
    .visible = true,
    .named = true,
  },
  [sym_pitched_note] = {
    .visible = true,
    .named = true,
  },
  [sym_rest] = {
    .visible = true,
    .named = true,
  },
  [sym_duration] = {
    .visible = true,
    .named = true,
  },
  [sym_articulation] = {
    .visible = true,
    .named = true,
  },
  [sym_chord] = {
    .visible = true,
    .named = true,
  },
  [sym_chord_name] = {
    .visible = true,
    .named = true,
  },
  [sym_arp_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_arp_direction] = {
    .visible = true,
    .named = true,
  },
  [sym_melody_group] = {
    .visible = true,
    .named = true,
  },
  [sym_scene_def] = {
    .visible = true,
    .named = true,
  },
  [sym__scene_content] = {
    .visible = false,
    .named = true,
  },
  [sym_scene_slot] = {
    .visible = true,
    .named = true,
  },
  [sym_shuffle_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_weight] = {
    .visible = true,
    .named = true,
  },
  [sym_scene_tempo] = {
    .visible = true,
    .named = true,
  },
  [sym_session_def] = {
    .visible = true,
    .named = true,
  },
  [sym_session_entry] = {
    .visible = true,
    .named = true,
  },
  [sym_session_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym_include_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_tempo_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_scale_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_play_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_stop_stmt] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_device_def_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_instrument_def_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_kit_def_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_kit_instrument_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_clip_def_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_clip_def_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_melody_line_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_chord_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_scene_def_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_session_def_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_instrument = 1,
  field_kit = 2,
  field_name = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_instrument] = "instrument",
  [field_kit] = "kit",
  [field_name] = "name",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_kit, 1},
  [2] =
    {field_instrument, 0},
  [3] =
    {field_name, 0},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 4,
  [9] = 7,
  [10] = 10,
  [11] = 11,
  [12] = 10,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 11,
  [51] = 51,
  [52] = 52,
  [53] = 15,
  [54] = 39,
  [55] = 16,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 21,
  [62] = 62,
  [63] = 63,
  [64] = 20,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 58,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 22,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 17,
  [83] = 83,
  [84] = 18,
  [85] = 85,
  [86] = 74,
  [87] = 87,
  [88] = 66,
  [89] = 39,
  [90] = 90,
  [91] = 24,
  [92] = 48,
  [93] = 93,
  [94] = 33,
  [95] = 95,
  [96] = 96,
  [97] = 95,
  [98] = 96,
  [99] = 32,
  [100] = 90,
  [101] = 90,
  [102] = 93,
  [103] = 51,
  [104] = 52,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 59,
  [109] = 71,
  [110] = 56,
  [111] = 79,
  [112] = 68,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 83,
  [120] = 73,
  [121] = 57,
  [122] = 122,
  [123] = 70,
  [124] = 67,
  [125] = 78,
  [126] = 77,
  [127] = 62,
  [128] = 81,
  [129] = 65,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 135,
  [137] = 137,
  [138] = 138,
  [139] = 137,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 52,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 147,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 39,
  [161] = 161,
  [162] = 83,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 35,
  [168] = 168,
  [169] = 169,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 40,
  [174] = 174,
  [175] = 171,
  [176] = 176,
  [177] = 177,
  [178] = 178,
  [179] = 179,
  [180] = 180,
  [181] = 181,
  [182] = 182,
  [183] = 183,
  [184] = 184,
  [185] = 185,
  [186] = 186,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 190,
  [191] = 191,
  [192] = 192,
  [193] = 193,
  [194] = 194,
  [195] = 195,
  [196] = 196,
  [197] = 197,
  [198] = 198,
  [199] = 199,
  [200] = 200,
  [201] = 201,
  [202] = 202,
  [203] = 203,
  [204] = 204,
  [205] = 205,
  [206] = 206,
  [207] = 207,
  [208] = 208,
  [209] = 209,
  [210] = 210,
  [211] = 201,
  [212] = 203,
  [213] = 181,
  [214] = 214,
  [215] = 215,
  [216] = 216,
  [217] = 217,
  [218] = 218,
  [219] = 208,
  [220] = 193,
  [221] = 221,
  [222] = 183,
  [223] = 223,
  [224] = 224,
  [225] = 198,
  [226] = 226,
  [227] = 227,
  [228] = 189,
  [229] = 194,
  [230] = 230,
  [231] = 214,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(28);
      ADVANCE_MAP(
        '"', 1,
        '\'', 59,
        '(', 64,
        ')', 66,
        '*', 67,
        '+', 24,
        ',', 65,
        '-', 35,
        '.', 36,
        '/', 9,
        '0', 44,
        '1', 45,
        '2', 48,
        '3', 42,
        '4', 50,
        '8', 53,
        ':', 38,
        '>', 37,
        '[', 32,
        ']', 33,
        'g', 72,
        'r', 40,
        '{', 29,
        '|', 69,
        '}', 30,
        'X', 90,
        'o', 90,
        'x', 90,
      );
      if (('5' <= lookahead && lookahead <= '9')) ADVANCE(44);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(72);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('h' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(92);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '\'', 59,
        '(', 64,
        ')', 66,
        '*', 67,
        '/', 9,
        ':', 38,
        '>', 37,
        '[', 32,
        'g', 74,
        'r', 39,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(74);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        '\'', 59,
        '(', 64,
        ')', 66,
        '/', 9,
        ':', 38,
        '>', 37,
        '[', 32,
        'g', 72,
        'r', 40,
        '}', 30,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('a' <= lookahead && lookahead <= 'f')) ADVANCE(72);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('h' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '(', 64,
        ')', 66,
        '*', 67,
        '/', 9,
        ':', 38,
        '>', 37,
        '[', 32,
        'r', 40,
        '}', 30,
        '+', 24,
        '-', 24,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('a' <= lookahead && lookahead <= 'g')) ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('h' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 5:
      if (lookahead == '(') ADVANCE(64);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '>') ADVANCE(37);
      if (lookahead == '[') ADVANCE(32);
      if (lookahead == 'r') ADVANCE(39);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('a' <= lookahead && lookahead <= 'g')) ADVANCE(74);
      if (lookahead == ')' ||
          lookahead == '*' ||
          ('-' <= lookahead && lookahead <= '9') ||
          lookahead == 'X' ||
          lookahead == 'o' ||
          lookahead == 'x' ||
          lookahead == '|') ADVANCE(36);
      END_STATE();
    case 6:
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == ':') ADVANCE(38);
      if (lookahead == ']') ADVANCE(33);
      if (lookahead == 'r') ADVANCE(39);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('a' <= lookahead && lookahead <= 'g')) ADVANCE(76);
      END_STATE();
    case 7:
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '|') ADVANCE(69);
      if (lookahead == '}') ADVANCE(30);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(68);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 8:
      if (lookahead == '/') ADVANCE(9);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('a' <= lookahead && lookahead <= 'g')) ADVANCE(21);
      END_STATE();
    case 9:
      if (lookahead == '/') ADVANCE(93);
      END_STATE();
    case 10:
      if (lookahead == '/') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '7') ADVANCE(60);
      END_STATE();
    case 12:
      if (lookahead == '9') ADVANCE(60);
      END_STATE();
    case 13:
      if (lookahead == 'd') ADVANCE(14);
      if (lookahead == 'u') ADVANCE(15);
      END_STATE();
    case 14:
      if (lookahead == 'd') ADVANCE(12);
      END_STATE();
    case 15:
      if (lookahead == 'g') ADVANCE(60);
      END_STATE();
    case 16:
      if (lookahead == 'i') ADVANCE(18);
      END_STATE();
    case 17:
      if (lookahead == 'j') ADVANCE(11);
      END_STATE();
    case 18:
      if (lookahead == 'm') ADVANCE(61);
      END_STATE();
    case 19:
      if (lookahead == 's') ADVANCE(23);
      END_STATE();
    case 20:
      if (lookahead == 'u') ADVANCE(19);
      END_STATE();
    case 21:
      if (lookahead == '#' ||
          lookahead == 'b') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 22:
      if (lookahead == '1' ||
          lookahead == '3') ADVANCE(60);
      END_STATE();
    case 23:
      if (lookahead == '2' ||
          lookahead == '4') ADVANCE(60);
      END_STATE();
    case 24:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);
      END_STATE();
    case 25:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(34);
      END_STATE();
    case 26:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 27:
      if (eof) ADVANCE(28);
      ADVANCE_MAP(
        ')', 66,
        '*', 67,
        '/', 9,
        '1', 46,
        '2', 47,
        '3', 43,
        '4', 49,
        '8', 52,
        '[', 32,
        ']', 33,
        '}', 30,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(27);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_note_literal);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_time_signature);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_step_pattern);
      if (('(' <= lookahead && lookahead <= '*') ||
          lookahead == '-' ||
          lookahead == '.' ||
          lookahead == '>' ||
          lookahead == 'X' ||
          lookahead == 'o' ||
          lookahead == 'x' ||
          lookahead == '|') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_step_pattern);
      if (('(' <= lookahead && lookahead <= '*') ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '>' ||
          lookahead == 'X' ||
          lookahead == 'o' ||
          lookahead == 'x' ||
          lookahead == '|') ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_r);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_r);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_octave);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_octave);
      if (lookahead == '2') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_octave);
      if (lookahead == '2') ADVANCE(57);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_octave);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_1);
      if (lookahead == '6') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_1);
      if (lookahead == '6') ADVANCE(55);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_2);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_4);
      if (lookahead == '.') ADVANCE(51);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_4);
      if (lookahead == '.') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_4_DOT);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_8);
      if (lookahead == '.') ADVANCE(54);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_8);
      if (lookahead == '.') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_8_DOT);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_16);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_16);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_32);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_32);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_chord_symbol);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_chord_symbol);
      if (lookahead == '7') ADVANCE(60);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_chord_symbol);
      if (lookahead == '7') ADVANCE(60);
      if (lookahead == 'a') ADVANCE(84);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_chord_symbol);
      if (lookahead == '7') ADVANCE(60);
      if (lookahead == 'a') ADVANCE(17);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_probability);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_tempo_delta);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_note_name);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_note_name);
      ADVANCE_MAP(
        '#', 75,
        '1', 88,
        'a', 80,
        'b', 73,
        'd', 83,
        'm', 62,
        's', 87,
        '6', 60,
        '7', 60,
        '9', 60,
      );
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_note_name);
      if (lookahead == '1') ADVANCE(88);
      if (lookahead == 'a') ADVANCE(80);
      if (lookahead == 'd') ADVANCE(83);
      if (lookahead == 'm') ADVANCE(62);
      if (lookahead == 's') ADVANCE(87);
      if (lookahead == '6' ||
          lookahead == '7' ||
          lookahead == '9') ADVANCE(60);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_note_name);
      ADVANCE_MAP(
        '1', 22,
        'a', 13,
        'd', 16,
        'm', 63,
        's', 20,
        '#', 75,
        'b', 75,
        '6', 60,
        '7', 60,
        '9', 60,
      );
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_note_name);
      if (lookahead == '1') ADVANCE(22);
      if (lookahead == 'a') ADVANCE(13);
      if (lookahead == 'd') ADVANCE(16);
      if (lookahead == 'm') ADVANCE(63);
      if (lookahead == 's') ADVANCE(20);
      if (lookahead == '6' ||
          lookahead == '7' ||
          lookahead == '9') ADVANCE(60);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_note_name);
      if (lookahead == '#' ||
          lookahead == 'b') ADVANCE(71);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '7') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '9') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '8') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(81);
      if (lookahead == 'u') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'j') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1' ||
          lookahead == '3') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '2' ||
          lookahead == '4') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == 'X' ||
          lookahead == 'o' ||
          lookahead == 'x') ADVANCE(90);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(93);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      ADVANCE_MAP(
        'a', 1,
        'b', 2,
        'c', 3,
        'd', 4,
        'g', 5,
        'h', 6,
        'i', 7,
        'k', 8,
        'l', 9,
        'm', 10,
        'n', 11,
        'p', 12,
        'r', 13,
        's', 14,
        't', 15,
        'u', 16,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == 'r') ADVANCE(17);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(18);
      END_STATE();
    case 3:
      if (lookahead == 'h') ADVANCE(19);
      if (lookahead == 'l') ADVANCE(20);
      END_STATE();
    case 4:
      if (lookahead == 'e') ADVANCE(21);
      if (lookahead == 'o') ADVANCE(22);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(23);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(24);
      END_STATE();
    case 7:
      if (lookahead == 'n') ADVANCE(25);
      END_STATE();
    case 8:
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 9:
      if (lookahead == 'o') ADVANCE(27);
      if (lookahead == 'y') ADVANCE(28);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(29);
      if (lookahead == 'e') ADVANCE(30);
      if (lookahead == 'i') ADVANCE(31);
      END_STATE();
    case 11:
      if (lookahead == 'o') ADVANCE(32);
      END_STATE();
    case 12:
      if (lookahead == 'h') ADVANCE(33);
      if (lookahead == 'l') ADVANCE(34);
      if (lookahead == 'o') ADVANCE(35);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(36);
      if (lookahead == 'e') ADVANCE(37);
      END_STATE();
    case 14:
      if (lookahead == 'c') ADVANCE(38);
      if (lookahead == 'e') ADVANCE(39);
      if (lookahead == 't') ADVANCE(40);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(41);
      if (lookahead == 'i') ADVANCE(42);
      END_STATE();
    case 16:
      if (lookahead == 'p') ADVANCE(43);
      if (lookahead == 's') ADVANCE(44);
      END_STATE();
    case 17:
      if (lookahead == 'p') ADVANCE(45);
      END_STATE();
    case 18:
      if (lookahead == 'r') ADVANCE(46);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(47);
      END_STATE();
    case 20:
      if (lookahead == 'i') ADVANCE(48);
      END_STATE();
    case 21:
      if (lookahead == 'v') ADVANCE(49);
      END_STATE();
    case 22:
      if (lookahead == 'r') ADVANCE(50);
      if (lookahead == 'w') ADVANCE(51);
      END_STATE();
    case 23:
      if (lookahead == 't') ADVANCE(52);
      END_STATE();
    case 24:
      if (lookahead == 'r') ADVANCE(53);
      END_STATE();
    case 25:
      if (lookahead == 'c') ADVANCE(54);
      if (lookahead == 's') ADVANCE(55);
      END_STATE();
    case 26:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 27:
      if (lookahead == 'c') ADVANCE(57);
      if (lookahead == 'o') ADVANCE(58);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(59);
      END_STATE();
    case 29:
      if (lookahead == 'j') ADVANCE(60);
      END_STATE();
    case 30:
      if (lookahead == 'l') ADVANCE(61);
      END_STATE();
    case 31:
      if (lookahead == 'n') ADVANCE(62);
      if (lookahead == 'x') ADVANCE(63);
      END_STATE();
    case 32:
      if (lookahead == 't') ADVANCE(64);
      END_STATE();
    case 33:
      if (lookahead == 'r') ADVANCE(65);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(66);
      END_STATE();
    case 35:
      if (lookahead == 'r') ADVANCE(67);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(68);
      END_STATE();
    case 37:
      if (lookahead == 'p') ADVANCE(69);
      if (lookahead == 's') ADVANCE(70);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(71);
      if (lookahead == 'e') ADVANCE(72);
      END_STATE();
    case 39:
      if (lookahead == 's') ADVANCE(73);
      END_STATE();
    case 40:
      if (lookahead == 'o') ADVANCE(74);
      END_STATE();
    case 41:
      if (lookahead == 'm') ADVANCE(75);
      END_STATE();
    case 42:
      if (lookahead == 'm') ADVANCE(76);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_up);
      if (lookahead == 'd') ADVANCE(77);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(78);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_arp);
      END_STATE();
    case 46:
      if (lookahead == 's') ADVANCE(79);
      END_STATE();
    case 47:
      if (lookahead == 'n') ADVANCE(80);
      END_STATE();
    case 48:
      if (lookahead == 'p') ADVANCE(81);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(82);
      END_STATE();
    case 50:
      if (lookahead == 'i') ADVANCE(83);
      END_STATE();
    case 51:
      if (lookahead == 'n') ADVANCE(84);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(85);
      END_STATE();
    case 53:
      if (lookahead == 'm') ADVANCE(86);
      END_STATE();
    case 54:
      if (lookahead == 'l') ADVANCE(87);
      END_STATE();
    case 55:
      if (lookahead == 't') ADVANCE(88);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_kit);
      END_STATE();
    case 57:
      if (lookahead == 'r') ADVANCE(89);
      END_STATE();
    case 58:
      if (lookahead == 'p') ADVANCE(90);
      END_STATE();
    case 59:
      if (lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 60:
      if (lookahead == 'o') ADVANCE(92);
      END_STATE();
    case 61:
      if (lookahead == 'o') ADVANCE(93);
      END_STATE();
    case 62:
      if (lookahead == 'o') ADVANCE(94);
      END_STATE();
    case 63:
      if (lookahead == 'o') ADVANCE(95);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(96);
      END_STATE();
    case 65:
      if (lookahead == 'y') ADVANCE(97);
      END_STATE();
    case 66:
      if (lookahead == 'y') ADVANCE(98);
      END_STATE();
    case 67:
      if (lookahead == 't') ADVANCE(99);
      END_STATE();
    case 68:
      if (lookahead == 'd') ADVANCE(100);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(101);
      END_STATE();
    case 70:
      if (lookahead == 'o') ADVANCE(102);
      END_STATE();
    case 71:
      if (lookahead == 'l') ADVANCE(103);
      END_STATE();
    case 72:
      if (lookahead == 'n') ADVANCE(104);
      END_STATE();
    case 73:
      if (lookahead == 's') ADVANCE(105);
      END_STATE();
    case 74:
      if (lookahead == 'p') ADVANCE(106);
      END_STATE();
    case 75:
      if (lookahead == 'p') ADVANCE(107);
      END_STATE();
    case 76:
      if (lookahead == 'e') ADVANCE(108);
      END_STATE();
    case 77:
      if (lookahead == 'o') ADVANCE(109);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_use);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_bars);
      END_STATE();
    case 80:
      if (lookahead == 'n') ADVANCE(110);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_clip);
      END_STATE();
    case 82:
      if (lookahead == 'c') ADVANCE(111);
      END_STATE();
    case 83:
      if (lookahead == 'a') ADVANCE(112);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_down);
      END_STATE();
    case 85:
      if (lookahead == '_') ADVANCE(113);
      END_STATE();
    case 86:
      if (lookahead == 'o') ADVANCE(114);
      END_STATE();
    case 87:
      if (lookahead == 'u') ADVANCE(115);
      END_STATE();
    case 88:
      if (lookahead == 'r') ADVANCE(116);
      END_STATE();
    case 89:
      if (lookahead == 'i') ADVANCE(117);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_loop);
      END_STATE();
    case 91:
      if (lookahead == 'a') ADVANCE(118);
      END_STATE();
    case 92:
      if (lookahead == 'r') ADVANCE(119);
      END_STATE();
    case 93:
      if (lookahead == 'd') ADVANCE(120);
      END_STATE();
    case 94:
      if (lookahead == 'r') ADVANCE(121);
      END_STATE();
    case 95:
      if (lookahead == 'l') ADVANCE(122);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_note);
      END_STATE();
    case 97:
      if (lookahead == 'g') ADVANCE(123);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_play);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_port);
      END_STATE();
    case 100:
      if (lookahead == 'o') ADVANCE(124);
      END_STATE();
    case 101:
      if (lookahead == 'a') ADVANCE(125);
      END_STATE();
    case 102:
      if (lookahead == 'l') ADVANCE(126);
      END_STATE();
    case 103:
      if (lookahead == 'e') ADVANCE(127);
      END_STATE();
    case 104:
      if (lookahead == 'e') ADVANCE(128);
      END_STATE();
    case 105:
      if (lookahead == 'i') ADVANCE(129);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_stop);
      END_STATE();
    case 107:
      if (lookahead == 'o') ADVANCE(130);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_time);
      END_STATE();
    case 109:
      if (lookahead == 'w') ADVANCE(131);
      END_STATE();
    case 110:
      if (lookahead == 'e') ADVANCE(132);
      END_STATE();
    case 111:
      if (lookahead == 'e') ADVANCE(133);
      END_STATE();
    case 112:
      if (lookahead == 'n') ADVANCE(134);
      END_STATE();
    case 113:
      if (lookahead == 'n') ADVANCE(135);
      if (lookahead == 's') ADVANCE(136);
      END_STATE();
    case 114:
      if (lookahead == 'n') ADVANCE(137);
      END_STATE();
    case 115:
      if (lookahead == 'd') ADVANCE(138);
      END_STATE();
    case 116:
      if (lookahead == 'u') ADVANCE(139);
      END_STATE();
    case 117:
      if (lookahead == 'a') ADVANCE(140);
      END_STATE();
    case 118:
      if (lookahead == 'n') ADVANCE(141);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_major);
      END_STATE();
    case 120:
      if (lookahead == 'i') ADVANCE(142);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_minor);
      END_STATE();
    case 122:
      if (lookahead == 'y') ADVANCE(143);
      END_STATE();
    case 123:
      if (lookahead == 'i') ADVANCE(144);
      END_STATE();
    case 124:
      if (lookahead == 'm') ADVANCE(145);
      END_STATE();
    case 125:
      if (lookahead == 't') ADVANCE(146);
      END_STATE();
    case 126:
      if (lookahead == 'u') ADVANCE(147);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_scale);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_scene);
      END_STATE();
    case 129:
      if (lookahead == 'o') ADVANCE(148);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_tempo);
      END_STATE();
    case 131:
      if (lookahead == 'n') ADVANCE(149);
      END_STATE();
    case 132:
      if (lookahead == 'l') ADVANCE(150);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_device);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_dorian);
      END_STATE();
    case 135:
      if (lookahead == 'o') ADVANCE(151);
      END_STATE();
    case 136:
      if (lookahead == 't') ADVANCE(152);
      END_STATE();
    case 137:
      if (lookahead == 'i') ADVANCE(153);
      END_STATE();
    case 138:
      if (lookahead == 'e') ADVANCE(154);
      END_STATE();
    case 139:
      if (lookahead == 'm') ADVANCE(155);
      END_STATE();
    case 140:
      if (lookahead == 'n') ADVANCE(156);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_lydian);
      END_STATE();
    case 142:
      if (lookahead == 'c') ADVANCE(157);
      END_STATE();
    case 143:
      if (lookahead == 'd') ADVANCE(158);
      END_STATE();
    case 144:
      if (lookahead == 'a') ADVANCE(159);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_random);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_repeat);
      END_STATE();
    case 147:
      if (lookahead == 't') ADVANCE(160);
      END_STATE();
    case 148:
      if (lookahead == 'n') ADVANCE(161);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_updown);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_channel);
      END_STATE();
    case 151:
      if (lookahead == 'r') ADVANCE(162);
      END_STATE();
    case 152:
      if (lookahead == 'a') ADVANCE(163);
      END_STATE();
    case 153:
      if (lookahead == 'c') ADVANCE(164);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 155:
      if (lookahead == 'e') ADVANCE(165);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_locrian);
      END_STATE();
    case 157:
      if (lookahead == '_') ADVANCE(166);
      END_STATE();
    case 158:
      if (lookahead == 'i') ADVANCE(167);
      END_STATE();
    case 159:
      if (lookahead == 'n') ADVANCE(168);
      END_STATE();
    case 160:
      if (lookahead == 'i') ADVANCE(169);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_session);
      END_STATE();
    case 162:
      if (lookahead == 'm') ADVANCE(170);
      END_STATE();
    case 163:
      if (lookahead == 'c') ADVANCE(171);
      END_STATE();
    case 164:
      if (lookahead == '_') ADVANCE(172);
      END_STATE();
    case 165:
      if (lookahead == 'n') ADVANCE(173);
      END_STATE();
    case 166:
      if (lookahead == 'm') ADVANCE(174);
      END_STATE();
    case 167:
      if (lookahead == 'a') ADVANCE(175);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_phrygian);
      END_STATE();
    case 169:
      if (lookahead == 'o') ADVANCE(176);
      END_STATE();
    case 170:
      if (lookahead == 'a') ADVANCE(177);
      END_STATE();
    case 171:
      if (lookahead == 'c') ADVANCE(178);
      END_STATE();
    case 172:
      if (lookahead == 'm') ADVANCE(179);
      END_STATE();
    case 173:
      if (lookahead == 't') ADVANCE(180);
      END_STATE();
    case 174:
      if (lookahead == 'i') ADVANCE(181);
      END_STATE();
    case 175:
      if (lookahead == 'n') ADVANCE(182);
      END_STATE();
    case 176:
      if (lookahead == 'n') ADVANCE(183);
      END_STATE();
    case 177:
      if (lookahead == 'l') ADVANCE(184);
      END_STATE();
    case 178:
      if (lookahead == 'a') ADVANCE(185);
      END_STATE();
    case 179:
      if (lookahead == 'i') ADVANCE(186);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_instrument);
      END_STATE();
    case 181:
      if (lookahead == 'n') ADVANCE(187);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_mixolydian);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_resolution);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_gate_normal);
      END_STATE();
    case 185:
      if (lookahead == 't') ADVANCE(188);
      END_STATE();
    case 186:
      if (lookahead == 'n') ADVANCE(189);
      END_STATE();
    case 187:
      if (lookahead == 'o') ADVANCE(190);
      END_STATE();
    case 188:
      if (lookahead == 'o') ADVANCE(191);
      END_STATE();
    case 189:
      if (lookahead == 'o') ADVANCE(192);
      END_STATE();
    case 190:
      if (lookahead == 'r') ADVANCE(193);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_gate_staccato);
      END_STATE();
    case 192:
      if (lookahead == 'r') ADVANCE(194);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_melodic_minor);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_harmonic_minor);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 27, .external_lex_state = 1},
  [2] = {.lex_state = 27, .external_lex_state = 1},
  [3] = {.lex_state = 27, .external_lex_state = 1},
  [4] = {.lex_state = 4, .external_lex_state = 1},
  [5] = {.lex_state = 4, .external_lex_state = 1},
  [6] = {.lex_state = 5, .external_lex_state = 1},
  [7] = {.lex_state = 2, .external_lex_state = 1},
  [8] = {.lex_state = 2, .external_lex_state = 1},
  [9] = {.lex_state = 2, .external_lex_state = 1},
  [10] = {.lex_state = 5, .external_lex_state = 1},
  [11] = {.lex_state = 3, .external_lex_state = 1},
  [12] = {.lex_state = 5, .external_lex_state = 1},
  [13] = {.lex_state = 27, .external_lex_state = 1},
  [14] = {.lex_state = 27, .external_lex_state = 1},
  [15] = {.lex_state = 3, .external_lex_state = 1},
  [16] = {.lex_state = 4, .external_lex_state = 1},
  [17] = {.lex_state = 4, .external_lex_state = 1},
  [18] = {.lex_state = 4, .external_lex_state = 1},
  [19] = {.lex_state = 27, .external_lex_state = 1},
  [20] = {.lex_state = 3, .external_lex_state = 1},
  [21] = {.lex_state = 4, .external_lex_state = 1},
  [22] = {.lex_state = 3, .external_lex_state = 1},
  [23] = {.lex_state = 27, .external_lex_state = 1},
  [24] = {.lex_state = 4, .external_lex_state = 1},
  [25] = {.lex_state = 27, .external_lex_state = 1},
  [26] = {.lex_state = 27, .external_lex_state = 1},
  [27] = {.lex_state = 27, .external_lex_state = 1},
  [28] = {.lex_state = 27, .external_lex_state = 1},
  [29] = {.lex_state = 27, .external_lex_state = 1},
  [30] = {.lex_state = 27, .external_lex_state = 1},
  [31] = {.lex_state = 27, .external_lex_state = 1},
  [32] = {.lex_state = 4, .external_lex_state = 1},
  [33] = {.lex_state = 4, .external_lex_state = 1},
  [34] = {.lex_state = 27, .external_lex_state = 1},
  [35] = {.lex_state = 27, .external_lex_state = 1},
  [36] = {.lex_state = 27, .external_lex_state = 1},
  [37] = {.lex_state = 27, .external_lex_state = 1},
  [38] = {.lex_state = 27, .external_lex_state = 1},
  [39] = {.lex_state = 3, .external_lex_state = 1},
  [40] = {.lex_state = 27, .external_lex_state = 1},
  [41] = {.lex_state = 27, .external_lex_state = 1},
  [42] = {.lex_state = 27, .external_lex_state = 1},
  [43] = {.lex_state = 27, .external_lex_state = 1},
  [44] = {.lex_state = 27, .external_lex_state = 1},
  [45] = {.lex_state = 27, .external_lex_state = 1},
  [46] = {.lex_state = 27, .external_lex_state = 1},
  [47] = {.lex_state = 27, .external_lex_state = 1},
  [48] = {.lex_state = 4, .external_lex_state = 1},
  [49] = {.lex_state = 27, .external_lex_state = 1},
  [50] = {.lex_state = 2, .external_lex_state = 1},
  [51] = {.lex_state = 4, .external_lex_state = 1},
  [52] = {.lex_state = 4, .external_lex_state = 1},
  [53] = {.lex_state = 2, .external_lex_state = 1},
  [54] = {.lex_state = 4, .external_lex_state = 1},
  [55] = {.lex_state = 4, .external_lex_state = 1},
  [56] = {.lex_state = 4, .external_lex_state = 1},
  [57] = {.lex_state = 4, .external_lex_state = 1},
  [58] = {.lex_state = 27, .external_lex_state = 1},
  [59] = {.lex_state = 4, .external_lex_state = 1},
  [60] = {.lex_state = 27, .external_lex_state = 1},
  [61] = {.lex_state = 4, .external_lex_state = 1},
  [62] = {.lex_state = 4, .external_lex_state = 1},
  [63] = {.lex_state = 27, .external_lex_state = 1},
  [64] = {.lex_state = 2, .external_lex_state = 1},
  [65] = {.lex_state = 4, .external_lex_state = 1},
  [66] = {.lex_state = 27, .external_lex_state = 1},
  [67] = {.lex_state = 4, .external_lex_state = 1},
  [68] = {.lex_state = 4, .external_lex_state = 1},
  [69] = {.lex_state = 27, .external_lex_state = 1},
  [70] = {.lex_state = 4, .external_lex_state = 1},
  [71] = {.lex_state = 4, .external_lex_state = 1},
  [72] = {.lex_state = 27, .external_lex_state = 1},
  [73] = {.lex_state = 4, .external_lex_state = 1},
  [74] = {.lex_state = 27, .external_lex_state = 1},
  [75] = {.lex_state = 27, .external_lex_state = 1},
  [76] = {.lex_state = 2, .external_lex_state = 1},
  [77] = {.lex_state = 4, .external_lex_state = 1},
  [78] = {.lex_state = 4, .external_lex_state = 1},
  [79] = {.lex_state = 4, .external_lex_state = 1},
  [80] = {.lex_state = 27, .external_lex_state = 1},
  [81] = {.lex_state = 4, .external_lex_state = 1},
  [82] = {.lex_state = 4, .external_lex_state = 1},
  [83] = {.lex_state = 4, .external_lex_state = 1},
  [84] = {.lex_state = 4, .external_lex_state = 1},
  [85] = {.lex_state = 27, .external_lex_state = 1},
  [86] = {.lex_state = 27, .external_lex_state = 1},
  [87] = {.lex_state = 27, .external_lex_state = 1},
  [88] = {.lex_state = 27, .external_lex_state = 1},
  [89] = {.lex_state = 3, .external_lex_state = 1},
  [90] = {.lex_state = 27, .external_lex_state = 1},
  [91] = {.lex_state = 4, .external_lex_state = 1},
  [92] = {.lex_state = 4, .external_lex_state = 1},
  [93] = {.lex_state = 27, .external_lex_state = 1},
  [94] = {.lex_state = 4, .external_lex_state = 1},
  [95] = {.lex_state = 27, .external_lex_state = 1},
  [96] = {.lex_state = 27, .external_lex_state = 1},
  [97] = {.lex_state = 27, .external_lex_state = 1},
  [98] = {.lex_state = 27, .external_lex_state = 1},
  [99] = {.lex_state = 4, .external_lex_state = 1},
  [100] = {.lex_state = 27, .external_lex_state = 1},
  [101] = {.lex_state = 27, .external_lex_state = 1},
  [102] = {.lex_state = 27, .external_lex_state = 1},
  [103] = {.lex_state = 2, .external_lex_state = 1},
  [104] = {.lex_state = 2, .external_lex_state = 1},
  [105] = {.lex_state = 27, .external_lex_state = 1},
  [106] = {.lex_state = 27, .external_lex_state = 1},
  [107] = {.lex_state = 27, .external_lex_state = 1},
  [108] = {.lex_state = 2, .external_lex_state = 1},
  [109] = {.lex_state = 2, .external_lex_state = 1},
  [110] = {.lex_state = 2, .external_lex_state = 1},
  [111] = {.lex_state = 2, .external_lex_state = 1},
  [112] = {.lex_state = 2, .external_lex_state = 1},
  [113] = {.lex_state = 27, .external_lex_state = 1},
  [114] = {.lex_state = 27, .external_lex_state = 1},
  [115] = {.lex_state = 27, .external_lex_state = 1},
  [116] = {.lex_state = 27, .external_lex_state = 1},
  [117] = {.lex_state = 27, .external_lex_state = 1},
  [118] = {.lex_state = 27, .external_lex_state = 1},
  [119] = {.lex_state = 2, .external_lex_state = 1},
  [120] = {.lex_state = 2, .external_lex_state = 1},
  [121] = {.lex_state = 2, .external_lex_state = 1},
  [122] = {.lex_state = 27, .external_lex_state = 1},
  [123] = {.lex_state = 2, .external_lex_state = 1},
  [124] = {.lex_state = 2, .external_lex_state = 1},
  [125] = {.lex_state = 2, .external_lex_state = 1},
  [126] = {.lex_state = 2, .external_lex_state = 1},
  [127] = {.lex_state = 2, .external_lex_state = 1},
  [128] = {.lex_state = 2, .external_lex_state = 1},
  [129] = {.lex_state = 2, .external_lex_state = 1},
  [130] = {.lex_state = 27, .external_lex_state = 1},
  [131] = {.lex_state = 7, .external_lex_state = 1},
  [132] = {.lex_state = 27, .external_lex_state = 1},
  [133] = {.lex_state = 27, .external_lex_state = 1},
  [134] = {.lex_state = 27, .external_lex_state = 1},
  [135] = {.lex_state = 27, .external_lex_state = 1},
  [136] = {.lex_state = 27, .external_lex_state = 1},
  [137] = {.lex_state = 6, .external_lex_state = 1},
  [138] = {.lex_state = 6, .external_lex_state = 1},
  [139] = {.lex_state = 6, .external_lex_state = 1},
  [140] = {.lex_state = 27, .external_lex_state = 1},
  [141] = {.lex_state = 27, .external_lex_state = 1},
  [142] = {.lex_state = 27, .external_lex_state = 1},
  [143] = {.lex_state = 27, .external_lex_state = 1},
  [144] = {.lex_state = 27, .external_lex_state = 1},
  [145] = {.lex_state = 6, .external_lex_state = 1},
  [146] = {.lex_state = 0, .external_lex_state = 1},
  [147] = {.lex_state = 6, .external_lex_state = 1},
  [148] = {.lex_state = 0, .external_lex_state = 1},
  [149] = {.lex_state = 27, .external_lex_state = 1},
  [150] = {.lex_state = 27, .external_lex_state = 1},
  [151] = {.lex_state = 27, .external_lex_state = 1},
  [152] = {.lex_state = 6, .external_lex_state = 1},
  [153] = {.lex_state = 27, .external_lex_state = 1},
  [154] = {.lex_state = 27, .external_lex_state = 1},
  [155] = {.lex_state = 27, .external_lex_state = 1},
  [156] = {.lex_state = 0, .external_lex_state = 1},
  [157] = {.lex_state = 27, .external_lex_state = 1},
  [158] = {.lex_state = 27, .external_lex_state = 1},
  [159] = {.lex_state = 27, .external_lex_state = 1},
  [160] = {.lex_state = 6, .external_lex_state = 1},
  [161] = {.lex_state = 27, .external_lex_state = 1},
  [162] = {.lex_state = 6, .external_lex_state = 1},
  [163] = {.lex_state = 27, .external_lex_state = 1},
  [164] = {.lex_state = 27, .external_lex_state = 1},
  [165] = {.lex_state = 27, .external_lex_state = 1},
  [166] = {.lex_state = 27, .external_lex_state = 1},
  [167] = {.lex_state = 27, .external_lex_state = 1},
  [168] = {.lex_state = 27, .external_lex_state = 1},
  [169] = {.lex_state = 4, .external_lex_state = 1},
  [170] = {.lex_state = 0, .external_lex_state = 1},
  [171] = {.lex_state = 27, .external_lex_state = 1},
  [172] = {.lex_state = 27, .external_lex_state = 1},
  [173] = {.lex_state = 27, .external_lex_state = 1},
  [174] = {.lex_state = 27, .external_lex_state = 1},
  [175] = {.lex_state = 27, .external_lex_state = 1},
  [176] = {.lex_state = 27, .external_lex_state = 1},
  [177] = {.lex_state = 8, .external_lex_state = 1},
  [178] = {.lex_state = 4, .external_lex_state = 1},
  [179] = {.lex_state = 0, .external_lex_state = 1},
  [180] = {.lex_state = 27, .external_lex_state = 1},
  [181] = {.lex_state = 0, .external_lex_state = 1},
  [182] = {.lex_state = 0, .external_lex_state = 1},
  [183] = {.lex_state = 27, .external_lex_state = 1},
  [184] = {.lex_state = 27, .external_lex_state = 1},
  [185] = {.lex_state = 4, .external_lex_state = 1},
  [186] = {.lex_state = 4, .external_lex_state = 1},
  [187] = {.lex_state = 2, .external_lex_state = 1},
  [188] = {.lex_state = 6, .external_lex_state = 1},
  [189] = {.lex_state = 4, .external_lex_state = 1},
  [190] = {.lex_state = 27, .external_lex_state = 1},
  [191] = {.lex_state = 0, .external_lex_state = 1},
  [192] = {.lex_state = 0, .external_lex_state = 1},
  [193] = {.lex_state = 4, .external_lex_state = 1},
  [194] = {.lex_state = 0, .external_lex_state = 1},
  [195] = {.lex_state = 0, .external_lex_state = 1},
  [196] = {.lex_state = 0, .external_lex_state = 1},
  [197] = {.lex_state = 0, .external_lex_state = 1},
  [198] = {.lex_state = 4, .external_lex_state = 1},
  [199] = {.lex_state = 0, .external_lex_state = 1},
  [200] = {.lex_state = 0, .external_lex_state = 1},
  [201] = {.lex_state = 0, .external_lex_state = 1},
  [202] = {.lex_state = 4, .external_lex_state = 1},
  [203] = {.lex_state = 4, .external_lex_state = 1},
  [204] = {.lex_state = 0, .external_lex_state = 1},
  [205] = {.lex_state = 0, .external_lex_state = 1},
  [206] = {.lex_state = 0, .external_lex_state = 1},
  [207] = {.lex_state = 0, .external_lex_state = 1},
  [208] = {.lex_state = 4, .external_lex_state = 1},
  [209] = {.lex_state = 27, .external_lex_state = 1},
  [210] = {.lex_state = 0, .external_lex_state = 1},
  [211] = {.lex_state = 0, .external_lex_state = 1},
  [212] = {.lex_state = 4, .external_lex_state = 1},
  [213] = {.lex_state = 0, .external_lex_state = 1},
  [214] = {.lex_state = 0, .external_lex_state = 1},
  [215] = {.lex_state = 27, .external_lex_state = 1},
  [216] = {.lex_state = 4, .external_lex_state = 1},
  [217] = {.lex_state = 27, .external_lex_state = 1},
  [218] = {.lex_state = 6, .external_lex_state = 1},
  [219] = {.lex_state = 4, .external_lex_state = 1},
  [220] = {.lex_state = 4, .external_lex_state = 1},
  [221] = {.lex_state = 27, .external_lex_state = 1},
  [222] = {.lex_state = 27, .external_lex_state = 1},
  [223] = {.lex_state = 27, .external_lex_state = 1},
  [224] = {.lex_state = 27, .external_lex_state = 1},
  [225] = {.lex_state = 4, .external_lex_state = 1},
  [226] = {.lex_state = 8, .external_lex_state = 1},
  [227] = {.lex_state = 27, .external_lex_state = 1},
  [228] = {.lex_state = 4, .external_lex_state = 1},
  [229] = {.lex_state = 0, .external_lex_state = 1},
  [230] = {.lex_state = 4, .external_lex_state = 1},
  [231] = {.lex_state = 0, .external_lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_device] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_port] = ACTIONS(1),
    [anon_sym_instrument] = ACTIONS(1),
    [anon_sym_channel] = ACTIONS(1),
    [anon_sym_note] = ACTIONS(1),
    [anon_sym_gate_normal] = ACTIONS(1),
    [anon_sym_gate_staccato] = ACTIONS(1),
    [anon_sym_kit] = ACTIONS(1),
    [anon_sym_clip] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_bars] = ACTIONS(1),
    [anon_sym_time] = ACTIONS(1),
    [anon_sym_scale] = ACTIONS(1),
    [anon_sym_major] = ACTIONS(1),
    [anon_sym_minor] = ACTIONS(1),
    [anon_sym_harmonic_minor] = ACTIONS(1),
    [anon_sym_melodic_minor] = ACTIONS(1),
    [anon_sym_dorian] = ACTIONS(1),
    [anon_sym_phrygian] = ACTIONS(1),
    [anon_sym_lydian] = ACTIONS(1),
    [anon_sym_mixolydian] = ACTIONS(1),
    [anon_sym_locrian] = ACTIONS(1),
    [anon_sym_use] = ACTIONS(1),
    [anon_sym_resolution] = ACTIONS(1),
    [sym_step_pattern] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_r] = ACTIONS(1),
    [sym_octave] = ACTIONS(1),
    [anon_sym_1] = ACTIONS(1),
    [anon_sym_2] = ACTIONS(1),
    [anon_sym_4] = ACTIONS(1),
    [anon_sym_4_DOT] = ACTIONS(1),
    [anon_sym_8] = ACTIONS(1),
    [anon_sym_8_DOT] = ACTIONS(1),
    [anon_sym_16] = ACTIONS(1),
    [anon_sym_32] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_g] = ACTIONS(1),
    [sym_chord_symbol] = ACTIONS(1),
    [anon_sym_arp] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_up] = ACTIONS(1),
    [anon_sym_down] = ACTIONS(1),
    [anon_sym_updown] = ACTIONS(1),
    [anon_sym_random] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_scene] = ACTIONS(1),
    [sym_probability] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_tempo] = ACTIONS(1),
    [sym_tempo_delta] = ACTIONS(1),
    [anon_sym_session] = ACTIONS(1),
    [anon_sym_repeat] = ACTIONS(1),
    [anon_sym_loop] = ACTIONS(1),
    [anon_sym_include] = ACTIONS(1),
    [anon_sym_play] = ACTIONS(1),
    [anon_sym_stop] = ACTIONS(1),
    [sym_note_name] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(204),
    [sym__top_level] = STATE(3),
    [sym_device_def] = STATE(3),
    [sym_instrument_def] = STATE(3),
    [sym_kit_def] = STATE(3),
    [sym_clip_def] = STATE(3),
    [sym_scene_def] = STATE(3),
    [sym_session_def] = STATE(3),
    [sym_include_stmt] = STATE(3),
    [sym_tempo_stmt] = STATE(3),
    [sym_scale_stmt] = STATE(3),
    [sym_play_stmt] = STATE(3),
    [sym_stop_stmt] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_device] = ACTIONS(7),
    [anon_sym_instrument] = ACTIONS(9),
    [anon_sym_kit] = ACTIONS(11),
    [anon_sym_clip] = ACTIONS(13),
    [anon_sym_scale] = ACTIONS(15),
    [anon_sym_scene] = ACTIONS(17),
    [anon_sym_tempo] = ACTIONS(19),
    [anon_sym_session] = ACTIONS(21),
    [anon_sym_include] = ACTIONS(23),
    [anon_sym_play] = ACTIONS(25),
    [anon_sym_stop] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 14,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
    ACTIONS(31), 1,
      anon_sym_device,
    ACTIONS(34), 1,
      anon_sym_instrument,
    ACTIONS(37), 1,
      anon_sym_kit,
    ACTIONS(40), 1,
      anon_sym_clip,
    ACTIONS(43), 1,
      anon_sym_scale,
    ACTIONS(46), 1,
      anon_sym_scene,
    ACTIONS(49), 1,
      anon_sym_tempo,
    ACTIONS(52), 1,
      anon_sym_session,
    ACTIONS(55), 1,
      anon_sym_include,
    ACTIONS(58), 1,
      anon_sym_play,
    ACTIONS(61), 1,
      anon_sym_stop,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(2), 13,
      sym__top_level,
      sym_device_def,
      sym_instrument_def,
      sym_kit_def,
      sym_clip_def,
      sym_scene_def,
      sym_session_def,
      sym_include_stmt,
      sym_tempo_stmt,
      sym_scale_stmt,
      sym_play_stmt,
      sym_stop_stmt,
      aux_sym_source_file_repeat1,
  [56] = 14,
    ACTIONS(7), 1,
      anon_sym_device,
    ACTIONS(9), 1,
      anon_sym_instrument,
    ACTIONS(11), 1,
      anon_sym_kit,
    ACTIONS(13), 1,
      anon_sym_clip,
    ACTIONS(15), 1,
      anon_sym_scale,
    ACTIONS(17), 1,
      anon_sym_scene,
    ACTIONS(19), 1,
      anon_sym_tempo,
    ACTIONS(21), 1,
      anon_sym_session,
    ACTIONS(23), 1,
      anon_sym_include,
    ACTIONS(25), 1,
      anon_sym_play,
    ACTIONS(27), 1,
      anon_sym_stop,
    ACTIONS(64), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(2), 13,
      sym__top_level,
      sym_device_def,
      sym_instrument_def,
      sym_kit_def,
      sym_clip_def,
      sym_scene_def,
      sym_session_def,
      sym_include_stmt,
      sym_tempo_stmt,
      sym_scale_stmt,
      sym_play_stmt,
      sym_stop_stmt,
      aux_sym_source_file_repeat1,
  [112] = 10,
    ACTIONS(68), 1,
      anon_sym_RBRACE,
    ACTIONS(70), 1,
      anon_sym_LBRACK,
    ACTIONS(73), 1,
      anon_sym_GT,
    ACTIONS(76), 1,
      anon_sym_r,
    ACTIONS(79), 1,
      sym_chord_symbol,
    ACTIONS(82), 1,
      anon_sym_LPAREN,
    ACTIONS(85), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(66), 3,
      anon_sym_use,
      anon_sym_resolution,
      sym_identifier,
    STATE(4), 8,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_rest,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [153] = 10,
    ACTIONS(90), 1,
      anon_sym_RBRACE,
    ACTIONS(92), 1,
      anon_sym_LBRACK,
    ACTIONS(94), 1,
      anon_sym_GT,
    ACTIONS(96), 1,
      anon_sym_r,
    ACTIONS(98), 1,
      sym_chord_symbol,
    ACTIONS(100), 1,
      anon_sym_LPAREN,
    ACTIONS(102), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(88), 3,
      anon_sym_use,
      anon_sym_resolution,
      sym_identifier,
    STATE(4), 8,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_rest,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [194] = 9,
    ACTIONS(92), 1,
      anon_sym_LBRACK,
    ACTIONS(94), 1,
      anon_sym_GT,
    ACTIONS(98), 1,
      sym_chord_symbol,
    ACTIONS(100), 1,
      anon_sym_LPAREN,
    ACTIONS(102), 1,
      sym_note_name,
    ACTIONS(104), 1,
      sym_step_pattern,
    ACTIONS(106), 1,
      anon_sym_r,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(5), 8,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_rest,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [230] = 9,
    ACTIONS(108), 1,
      anon_sym_LBRACK,
    ACTIONS(110), 1,
      anon_sym_GT,
    ACTIONS(112), 1,
      anon_sym_r,
    ACTIONS(114), 1,
      sym_chord_symbol,
    ACTIONS(116), 1,
      anon_sym_LPAREN,
    ACTIONS(118), 1,
      anon_sym_RPAREN,
    ACTIONS(120), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(8), 8,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_rest,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [266] = 9,
    ACTIONS(68), 1,
      anon_sym_RPAREN,
    ACTIONS(122), 1,
      anon_sym_LBRACK,
    ACTIONS(125), 1,
      anon_sym_GT,
    ACTIONS(128), 1,
      anon_sym_r,
    ACTIONS(131), 1,
      sym_chord_symbol,
    ACTIONS(134), 1,
      anon_sym_LPAREN,
    ACTIONS(137), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(8), 8,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_rest,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [302] = 9,
    ACTIONS(108), 1,
      anon_sym_LBRACK,
    ACTIONS(110), 1,
      anon_sym_GT,
    ACTIONS(112), 1,
      anon_sym_r,
    ACTIONS(114), 1,
      sym_chord_symbol,
    ACTIONS(116), 1,
      anon_sym_LPAREN,
    ACTIONS(120), 1,
      sym_note_name,
    ACTIONS(140), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(8), 8,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_rest,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [338] = 8,
    ACTIONS(108), 1,
      anon_sym_LBRACK,
    ACTIONS(110), 1,
      anon_sym_GT,
    ACTIONS(112), 1,
      anon_sym_r,
    ACTIONS(114), 1,
      sym_chord_symbol,
    ACTIONS(116), 1,
      anon_sym_LPAREN,
    ACTIONS(120), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(9), 8,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_rest,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [371] = 7,
    ACTIONS(146), 1,
      anon_sym_COLON,
    ACTIONS(148), 1,
      anon_sym_SQUOTE,
    ACTIONS(150), 1,
      anon_sym_g,
    STATE(65), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(142), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(144), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [402] = 8,
    ACTIONS(108), 1,
      anon_sym_LBRACK,
    ACTIONS(110), 1,
      anon_sym_GT,
    ACTIONS(112), 1,
      anon_sym_r,
    ACTIONS(114), 1,
      sym_chord_symbol,
    ACTIONS(116), 1,
      anon_sym_LPAREN,
    ACTIONS(120), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(7), 8,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_rest,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [435] = 4,
    ACTIONS(154), 1,
      anon_sym_LBRACK,
    STATE(41), 1,
      sym_session_modifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(152), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [460] = 4,
    ACTIONS(154), 1,
      anon_sym_LBRACK,
    STATE(47), 1,
      sym_session_modifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(156), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [485] = 7,
    ACTIONS(148), 1,
      anon_sym_SQUOTE,
    ACTIONS(150), 1,
      anon_sym_g,
    ACTIONS(162), 1,
      anon_sym_COLON,
    STATE(56), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(158), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(160), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [516] = 6,
    ACTIONS(168), 1,
      anon_sym_COLON,
    ACTIONS(170), 1,
      anon_sym_arp,
    STATE(68), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(164), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(166), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [544] = 6,
    ACTIONS(170), 1,
      anon_sym_arp,
    ACTIONS(176), 1,
      anon_sym_COLON,
    STATE(70), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(172), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(174), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [572] = 6,
    ACTIONS(170), 1,
      anon_sym_arp,
    ACTIONS(182), 1,
      anon_sym_COLON,
    STATE(67), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(178), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(180), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [600] = 4,
    ACTIONS(184), 1,
      ts_builtin_sym_end,
    ACTIONS(186), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(188), 11,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [624] = 6,
    ACTIONS(148), 1,
      anon_sym_SQUOTE,
    ACTIONS(150), 1,
      anon_sym_g,
    STATE(65), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(142), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(144), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [652] = 6,
    ACTIONS(170), 1,
      anon_sym_arp,
    ACTIONS(194), 1,
      anon_sym_COLON,
    STATE(57), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(190), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(192), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [680] = 6,
    ACTIONS(148), 1,
      anon_sym_SQUOTE,
    ACTIONS(150), 1,
      anon_sym_g,
    STATE(71), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(196), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(198), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [708] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(200), 13,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_RBRACK,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [728] = 5,
    ACTIONS(170), 1,
      anon_sym_arp,
    STATE(67), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(178), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(180), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [753] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(202), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [772] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(204), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [791] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(206), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [810] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(208), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [829] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(210), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [848] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(212), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [867] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(214), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [886] = 5,
    ACTIONS(170), 1,
      anon_sym_arp,
    STATE(57), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(190), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(192), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [911] = 5,
    ACTIONS(170), 1,
      anon_sym_arp,
    STATE(81), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(216), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(218), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [936] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(220), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [955] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(222), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [974] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(224), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [993] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(226), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [1012] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(228), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [1031] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(230), 6,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      anon_sym_g,
      sym_note_name,
      sym_identifier,
    ACTIONS(232), 6,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_SQUOTE,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1052] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(234), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [1071] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(156), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [1090] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(236), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [1109] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(238), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [1128] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(240), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [1147] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(242), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [1166] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(244), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [1185] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(246), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [1204] = 5,
    ACTIONS(170), 1,
      anon_sym_arp,
    STATE(78), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(248), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(250), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1229] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(252), 12,
      ts_builtin_sym_end,
      anon_sym_device,
      anon_sym_instrument,
      anon_sym_kit,
      anon_sym_clip,
      anon_sym_scale,
      anon_sym_scene,
      anon_sym_tempo,
      anon_sym_session,
      anon_sym_include,
      anon_sym_play,
      anon_sym_stop,
  [1248] = 7,
    ACTIONS(142), 1,
      sym_note_name,
    ACTIONS(254), 1,
      anon_sym_COLON,
    ACTIONS(256), 1,
      anon_sym_SQUOTE,
    ACTIONS(258), 1,
      anon_sym_g,
    STATE(129), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(144), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1276] = 4,
    ACTIONS(264), 1,
      anon_sym_STAR,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(260), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(262), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1298] = 4,
    ACTIONS(270), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(266), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(268), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1320] = 7,
    ACTIONS(158), 1,
      sym_note_name,
    ACTIONS(256), 1,
      anon_sym_SQUOTE,
    ACTIONS(258), 1,
      anon_sym_g,
    ACTIONS(272), 1,
      anon_sym_COLON,
    STATE(110), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(160), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1348] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(232), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
    ACTIONS(230), 6,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      anon_sym_arp,
      sym_note_name,
      sym_identifier,
  [1368] = 6,
    ACTIONS(164), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_COLON,
    ACTIONS(276), 1,
      anon_sym_arp,
    STATE(112), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(166), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1393] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(278), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(280), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1412] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(282), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(284), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1431] = 5,
    ACTIONS(286), 1,
      sym_octave,
    STATE(99), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(288), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(290), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [1454] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(292), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(294), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1473] = 6,
    ACTIONS(296), 1,
      sym_identifier,
    ACTIONS(298), 1,
      anon_sym_RBRACE,
    ACTIONS(300), 1,
      anon_sym_use,
    ACTIONS(302), 1,
      anon_sym_resolution,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(85), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [1498] = 6,
    ACTIONS(190), 1,
      sym_note_name,
    ACTIONS(276), 1,
      anon_sym_arp,
    ACTIONS(304), 1,
      anon_sym_COLON,
    STATE(121), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(192), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1523] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(306), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(308), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1542] = 6,
    ACTIONS(296), 1,
      sym_identifier,
    ACTIONS(298), 1,
      anon_sym_RBRACE,
    ACTIONS(300), 1,
      anon_sym_use,
    ACTIONS(302), 1,
      anon_sym_resolution,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(69), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [1567] = 6,
    ACTIONS(142), 1,
      sym_note_name,
    ACTIONS(256), 1,
      anon_sym_SQUOTE,
    ACTIONS(258), 1,
      anon_sym_g,
    STATE(129), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(144), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1592] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(310), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(312), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1611] = 5,
    ACTIONS(314), 1,
      sym_octave,
    STATE(24), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(316), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(318), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [1634] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(320), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(322), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1653] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(324), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(326), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1672] = 6,
    ACTIONS(296), 1,
      sym_identifier,
    ACTIONS(300), 1,
      anon_sym_use,
    ACTIONS(302), 1,
      anon_sym_resolution,
    ACTIONS(328), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(85), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [1697] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(330), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(332), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1716] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(334), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(336), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1735] = 5,
    ACTIONS(338), 1,
      sym_octave,
    STATE(32), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(316), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(318), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [1758] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(340), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(342), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1777] = 5,
    ACTIONS(344), 1,
      sym_octave,
    STATE(20), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(346), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(348), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [1800] = 3,
    STATE(205), 1,
      sym_scale_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(350), 9,
      anon_sym_major,
      anon_sym_minor,
      anon_sym_harmonic_minor,
      anon_sym_melodic_minor,
      anon_sym_dorian,
      anon_sym_phrygian,
      anon_sym_lydian,
      anon_sym_mixolydian,
      anon_sym_locrian,
  [1819] = 6,
    ACTIONS(196), 1,
      sym_note_name,
    ACTIONS(256), 1,
      anon_sym_SQUOTE,
    ACTIONS(258), 1,
      anon_sym_g,
    STATE(109), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(198), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1844] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(352), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(354), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1863] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(356), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(358), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1882] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(360), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(362), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1901] = 3,
    STATE(38), 1,
      sym_scale_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(350), 9,
      anon_sym_major,
      anon_sym_minor,
      anon_sym_harmonic_minor,
      anon_sym_melodic_minor,
      anon_sym_dorian,
      anon_sym_phrygian,
      anon_sym_lydian,
      anon_sym_mixolydian,
      anon_sym_locrian,
  [1920] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(364), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(366), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1939] = 6,
    ACTIONS(172), 1,
      sym_note_name,
    ACTIONS(276), 1,
      anon_sym_arp,
    ACTIONS(368), 1,
      anon_sym_COLON,
    STATE(123), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(174), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1964] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(370), 5,
      anon_sym_use,
      anon_sym_resolution,
      anon_sym_r,
      sym_note_name,
      sym_identifier,
    ACTIONS(372), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1983] = 6,
    ACTIONS(178), 1,
      sym_note_name,
    ACTIONS(276), 1,
      anon_sym_arp,
    ACTIONS(374), 1,
      anon_sym_COLON,
    STATE(124), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(180), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2008] = 6,
    ACTIONS(376), 1,
      sym_identifier,
    ACTIONS(379), 1,
      anon_sym_RBRACE,
    ACTIONS(381), 1,
      anon_sym_use,
    ACTIONS(384), 1,
      anon_sym_resolution,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(85), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [2033] = 5,
    ACTIONS(387), 1,
      sym_octave,
    STATE(64), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(288), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(290), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2056] = 6,
    ACTIONS(296), 1,
      sym_identifier,
    ACTIONS(300), 1,
      anon_sym_use,
    ACTIONS(302), 1,
      anon_sym_resolution,
    ACTIONS(389), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(60), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [2081] = 5,
    ACTIONS(391), 1,
      sym_octave,
    STATE(91), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(288), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(290), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2104] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(230), 3,
      anon_sym_g,
      anon_sym_arp,
      sym_note_name,
    ACTIONS(232), 7,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      anon_sym_SQUOTE,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2123] = 4,
    STATE(162), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(393), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(395), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2143] = 5,
    ACTIONS(178), 1,
      sym_note_name,
    ACTIONS(276), 1,
      anon_sym_arp,
    STATE(124), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(180), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2165] = 5,
    ACTIONS(248), 1,
      sym_note_name,
    ACTIONS(276), 1,
      anon_sym_arp,
    STATE(125), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(250), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2187] = 4,
    STATE(92), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(288), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(290), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2207] = 5,
    ACTIONS(216), 1,
      sym_note_name,
    ACTIONS(276), 1,
      anon_sym_arp,
    STATE(128), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(218), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2229] = 4,
    STATE(33), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(316), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(318), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2249] = 4,
    STATE(76), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(288), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(290), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2269] = 4,
    STATE(94), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(288), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(290), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2289] = 4,
    STATE(22), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(346), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(348), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2309] = 5,
    ACTIONS(190), 1,
      sym_note_name,
    ACTIONS(276), 1,
      anon_sym_arp,
    STATE(121), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(192), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2331] = 4,
    STATE(83), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(316), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(318), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2351] = 4,
    STATE(119), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(288), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(290), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2371] = 4,
    STATE(48), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(316), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(318), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2391] = 4,
    ACTIONS(260), 1,
      sym_note_name,
    ACTIONS(397), 1,
      anon_sym_STAR,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(262), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2410] = 4,
    ACTIONS(266), 1,
      sym_note_name,
    ACTIONS(399), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(268), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2429] = 6,
    ACTIONS(401), 1,
      anon_sym_device,
    ACTIONS(403), 1,
      anon_sym_RBRACE,
    ACTIONS(407), 1,
      anon_sym_note,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(107), 2,
      sym_instrument_property,
      aux_sym_instrument_def_repeat1,
    ACTIONS(405), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2452] = 6,
    ACTIONS(409), 1,
      anon_sym_device,
    ACTIONS(412), 1,
      anon_sym_RBRACE,
    ACTIONS(417), 1,
      anon_sym_note,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(106), 2,
      sym_instrument_property,
      aux_sym_instrument_def_repeat1,
    ACTIONS(414), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2475] = 6,
    ACTIONS(401), 1,
      anon_sym_device,
    ACTIONS(407), 1,
      anon_sym_note,
    ACTIONS(420), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(106), 2,
      sym_instrument_property,
      aux_sym_instrument_def_repeat1,
    ACTIONS(405), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2498] = 3,
    ACTIONS(292), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(294), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2514] = 3,
    ACTIONS(334), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(336), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2530] = 3,
    ACTIONS(278), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(280), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2546] = 3,
    ACTIONS(360), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(362), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2562] = 3,
    ACTIONS(324), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(326), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2578] = 5,
    ACTIONS(422), 1,
      anon_sym_RBRACE,
    ACTIONS(427), 1,
      anon_sym_note,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(113), 2,
      sym_kit_instrument_property,
      aux_sym_kit_instrument_repeat1,
    ACTIONS(424), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2598] = 5,
    ACTIONS(430), 1,
      anon_sym_RBRACE,
    ACTIONS(434), 1,
      anon_sym_note,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(113), 2,
      sym_kit_instrument_property,
      aux_sym_kit_instrument_repeat1,
    ACTIONS(432), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2618] = 5,
    ACTIONS(436), 1,
      sym_identifier,
    ACTIONS(438), 1,
      anon_sym_RBRACE,
    ACTIONS(440), 1,
      anon_sym_tempo,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(122), 4,
      sym__scene_content,
      sym_scene_slot,
      sym_scene_tempo,
      aux_sym_scene_def_repeat1,
  [2638] = 5,
    ACTIONS(442), 1,
      anon_sym_bars,
    ACTIONS(444), 1,
      anon_sym_time,
    ACTIONS(446), 1,
      anon_sym_scale,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(191), 4,
      sym__clip_attr,
      sym_bars_attr,
      sym_time_attr,
      sym_scale_attr,
  [2658] = 5,
    ACTIONS(434), 1,
      anon_sym_note,
    ACTIONS(448), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(114), 2,
      sym_kit_instrument_property,
      aux_sym_kit_instrument_repeat1,
    ACTIONS(432), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2678] = 5,
    ACTIONS(450), 1,
      sym_identifier,
    ACTIONS(453), 1,
      anon_sym_RBRACE,
    ACTIONS(455), 1,
      anon_sym_tempo,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(118), 4,
      sym__scene_content,
      sym_scene_slot,
      sym_scene_tempo,
      aux_sym_scene_def_repeat1,
  [2698] = 3,
    ACTIONS(370), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(372), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2714] = 3,
    ACTIONS(340), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(342), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2730] = 3,
    ACTIONS(282), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(284), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2746] = 5,
    ACTIONS(436), 1,
      sym_identifier,
    ACTIONS(440), 1,
      anon_sym_tempo,
    ACTIONS(458), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(118), 4,
      sym__scene_content,
      sym_scene_slot,
      sym_scene_tempo,
      aux_sym_scene_def_repeat1,
  [2766] = 3,
    ACTIONS(330), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(332), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2782] = 3,
    ACTIONS(320), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(322), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2798] = 3,
    ACTIONS(356), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(358), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2814] = 3,
    ACTIONS(352), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(354), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2830] = 3,
    ACTIONS(306), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(308), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2846] = 3,
    ACTIONS(364), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(366), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2862] = 3,
    ACTIONS(310), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(312), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_r,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2878] = 5,
    ACTIONS(460), 1,
      sym_identifier,
    ACTIONS(463), 1,
      anon_sym_device,
    ACTIONS(466), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(130), 3,
      sym__kit_member,
      sym_kit_instrument,
      aux_sym_kit_def_repeat1,
  [2897] = 6,
    ACTIONS(470), 1,
      anon_sym_RBRACE,
    ACTIONS(472), 1,
      sym_probability,
    ACTIONS(474), 1,
      anon_sym_PIPE,
    STATE(159), 1,
      sym_shuffle_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(468), 2,
      anon_sym_tempo,
      sym_identifier,
  [2918] = 5,
    ACTIONS(476), 1,
      sym_identifier,
    ACTIONS(478), 1,
      anon_sym_device,
    ACTIONS(480), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(133), 3,
      sym__kit_member,
      sym_kit_instrument,
      aux_sym_kit_def_repeat1,
  [2937] = 5,
    ACTIONS(476), 1,
      sym_identifier,
    ACTIONS(478), 1,
      anon_sym_device,
    ACTIONS(482), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(130), 3,
      sym__kit_member,
      sym_kit_instrument,
      aux_sym_kit_def_repeat1,
  [2956] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(484), 6,
      anon_sym_device,
      anon_sym_RBRACE,
      anon_sym_channel,
      anon_sym_note,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2969] = 4,
    ACTIONS(486), 1,
      anon_sym_up,
    STATE(194), 1,
      sym_arp_direction,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(488), 3,
      anon_sym_down,
      anon_sym_updown,
      anon_sym_random,
  [2985] = 4,
    ACTIONS(486), 1,
      anon_sym_up,
    STATE(229), 1,
      sym_arp_direction,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(488), 3,
      anon_sym_down,
      anon_sym_updown,
      anon_sym_random,
  [3001] = 5,
    ACTIONS(490), 1,
      anon_sym_RBRACK,
    ACTIONS(492), 1,
      anon_sym_r,
    ACTIONS(494), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(138), 2,
      sym_rest,
      aux_sym_chord_repeat1,
  [3019] = 5,
    ACTIONS(496), 1,
      anon_sym_RBRACK,
    ACTIONS(498), 1,
      anon_sym_r,
    ACTIONS(501), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(138), 2,
      sym_rest,
      aux_sym_chord_repeat1,
  [3037] = 5,
    ACTIONS(492), 1,
      anon_sym_r,
    ACTIONS(494), 1,
      sym_note_name,
    ACTIONS(504), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(138), 2,
      sym_rest,
      aux_sym_chord_repeat1,
  [3055] = 5,
    ACTIONS(508), 1,
      anon_sym_RBRACE,
    ACTIONS(510), 1,
      anon_sym_STAR,
    STATE(158), 1,
      sym_weight,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(506), 2,
      anon_sym_tempo,
      sym_identifier,
  [3073] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(512), 5,
      anon_sym_RBRACE,
      anon_sym_channel,
      anon_sym_note,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [3085] = 4,
    ACTIONS(514), 1,
      sym_identifier,
    ACTIONS(517), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(142), 2,
      sym_session_entry,
      aux_sym_session_def_repeat1,
  [3100] = 4,
    ACTIONS(519), 1,
      anon_sym_RBRACE,
    ACTIONS(521), 1,
      anon_sym_port,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(144), 2,
      sym_device_property,
      aux_sym_device_def_repeat1,
  [3115] = 4,
    ACTIONS(523), 1,
      anon_sym_RBRACE,
    ACTIONS(525), 1,
      anon_sym_port,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(144), 2,
      sym_device_property,
      aux_sym_device_def_repeat1,
  [3130] = 3,
    ACTIONS(528), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(268), 3,
      anon_sym_RBRACK,
      anon_sym_r,
      sym_note_name,
  [3143] = 4,
    ACTIONS(530), 1,
      anon_sym_LBRACE,
    ACTIONS(532), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(146), 2,
      sym_clip_header,
      aux_sym_clip_def_repeat1,
  [3158] = 4,
    ACTIONS(492), 1,
      anon_sym_r,
    ACTIONS(535), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(139), 2,
      sym_rest,
      aux_sym_chord_repeat1,
  [3173] = 4,
    ACTIONS(537), 1,
      anon_sym_LBRACE,
    ACTIONS(539), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(156), 2,
      sym_clip_header,
      aux_sym_clip_def_repeat1,
  [3188] = 4,
    ACTIONS(541), 1,
      sym_identifier,
    ACTIONS(543), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(142), 2,
      sym_session_entry,
      aux_sym_session_def_repeat1,
  [3203] = 4,
    ACTIONS(547), 1,
      anon_sym_LBRACK,
    STATE(168), 1,
      sym_session_modifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(545), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [3218] = 3,
    ACTIONS(551), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(549), 3,
      anon_sym_use,
      anon_sym_resolution,
      sym_identifier,
  [3231] = 4,
    ACTIONS(492), 1,
      anon_sym_r,
    ACTIONS(553), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(137), 2,
      sym_rest,
      aux_sym_chord_repeat1,
  [3246] = 3,
    ACTIONS(557), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(555), 3,
      anon_sym_use,
      anon_sym_resolution,
      sym_identifier,
  [3259] = 4,
    ACTIONS(541), 1,
      sym_identifier,
    ACTIONS(559), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(149), 2,
      sym_session_entry,
      aux_sym_session_def_repeat1,
  [3274] = 3,
    ACTIONS(563), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(561), 3,
      anon_sym_use,
      anon_sym_resolution,
      sym_identifier,
  [3287] = 4,
    ACTIONS(539), 1,
      anon_sym_LBRACK,
    ACTIONS(565), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(146), 2,
      sym_clip_header,
      aux_sym_clip_def_repeat1,
  [3302] = 4,
    ACTIONS(521), 1,
      anon_sym_port,
    ACTIONS(567), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(143), 2,
      sym_device_property,
      aux_sym_device_def_repeat1,
  [3317] = 3,
    ACTIONS(571), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(569), 2,
      anon_sym_tempo,
      sym_identifier,
  [3329] = 3,
    ACTIONS(575), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(573), 2,
      anon_sym_tempo,
      sym_identifier,
  [3341] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(232), 3,
      anon_sym_RBRACK,
      anon_sym_r,
      sym_note_name,
  [3351] = 3,
    ACTIONS(579), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(577), 2,
      anon_sym_tempo,
      sym_identifier,
  [3363] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(372), 3,
      anon_sym_RBRACK,
      anon_sym_r,
      sym_note_name,
  [3373] = 3,
    ACTIONS(583), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(581), 2,
      anon_sym_tempo,
      sym_identifier,
  [3385] = 3,
    ACTIONS(587), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(585), 2,
      anon_sym_device,
      sym_identifier,
  [3397] = 3,
    ACTIONS(591), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(589), 2,
      anon_sym_device,
      sym_identifier,
  [3409] = 3,
    ACTIONS(595), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(593), 2,
      anon_sym_device,
      sym_identifier,
  [3421] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(222), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [3430] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(597), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [3439] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(599), 2,
      sym_tempo_delta,
      sym_number,
  [3448] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(601), 2,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
  [3457] = 3,
    ACTIONS(603), 1,
      anon_sym_repeat,
    ACTIONS(605), 1,
      anon_sym_loop,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3468] = 3,
    ACTIONS(607), 1,
      sym_identifier,
    ACTIONS(609), 1,
      anon_sym_session,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3479] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(234), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [3488] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(611), 2,
      anon_sym_RBRACE,
      anon_sym_port,
  [3497] = 3,
    ACTIONS(613), 1,
      anon_sym_repeat,
    ACTIONS(615), 1,
      anon_sym_loop,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3508] = 2,
    ACTIONS(617), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3516] = 2,
    ACTIONS(619), 1,
      sym_note_literal,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3524] = 2,
    ACTIONS(619), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3532] = 2,
    ACTIONS(621), 1,
      sym_string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3540] = 2,
    ACTIONS(619), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3548] = 2,
    ACTIONS(623), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3556] = 2,
    ACTIONS(625), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3564] = 2,
    ACTIONS(627), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3572] = 2,
    ACTIONS(629), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3580] = 2,
    ACTIONS(631), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3588] = 2,
    ACTIONS(633), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3596] = 2,
    ACTIONS(635), 1,
      sym_time_signature,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3604] = 2,
    ACTIONS(637), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3612] = 2,
    ACTIONS(639), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3620] = 2,
    ACTIONS(641), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3628] = 2,
    ACTIONS(643), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3636] = 2,
    ACTIONS(645), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3644] = 2,
    ACTIONS(647), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3652] = 2,
    ACTIONS(649), 1,
      anon_sym_COMMA,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3660] = 2,
    ACTIONS(651), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3668] = 2,
    ACTIONS(653), 1,
      anon_sym_COMMA,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3676] = 2,
    ACTIONS(655), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3684] = 2,
    ACTIONS(657), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3692] = 2,
    ACTIONS(659), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3700] = 2,
    ACTIONS(661), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3708] = 2,
    ACTIONS(663), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3716] = 2,
    ACTIONS(665), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3724] = 2,
    ACTIONS(667), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3732] = 2,
    ACTIONS(669), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3740] = 2,
    ACTIONS(671), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3748] = 2,
    ACTIONS(673), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3756] = 2,
    ACTIONS(675), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3764] = 2,
    ACTIONS(677), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3772] = 2,
    ACTIONS(679), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3780] = 2,
    ACTIONS(681), 1,
      sym_string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3788] = 2,
    ACTIONS(683), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3796] = 2,
    ACTIONS(685), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3804] = 2,
    ACTIONS(687), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3812] = 2,
    ACTIONS(689), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3820] = 2,
    ACTIONS(691), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3828] = 2,
    ACTIONS(693), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3836] = 2,
    ACTIONS(695), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3844] = 2,
    ACTIONS(697), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3852] = 2,
    ACTIONS(699), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3860] = 2,
    ACTIONS(701), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3868] = 2,
    ACTIONS(703), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3876] = 2,
    ACTIONS(705), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3884] = 2,
    ACTIONS(707), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3892] = 2,
    ACTIONS(709), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3900] = 2,
    ACTIONS(711), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3908] = 2,
    ACTIONS(713), 1,
      sym_note_literal,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3916] = 2,
    ACTIONS(715), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3924] = 2,
    ACTIONS(717), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3932] = 2,
    ACTIONS(719), 1,
      anon_sym_COMMA,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3940] = 2,
    ACTIONS(713), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3948] = 2,
    ACTIONS(721), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 56,
  [SMALL_STATE(4)] = 112,
  [SMALL_STATE(5)] = 153,
  [SMALL_STATE(6)] = 194,
  [SMALL_STATE(7)] = 230,
  [SMALL_STATE(8)] = 266,
  [SMALL_STATE(9)] = 302,
  [SMALL_STATE(10)] = 338,
  [SMALL_STATE(11)] = 371,
  [SMALL_STATE(12)] = 402,
  [SMALL_STATE(13)] = 435,
  [SMALL_STATE(14)] = 460,
  [SMALL_STATE(15)] = 485,
  [SMALL_STATE(16)] = 516,
  [SMALL_STATE(17)] = 544,
  [SMALL_STATE(18)] = 572,
  [SMALL_STATE(19)] = 600,
  [SMALL_STATE(20)] = 624,
  [SMALL_STATE(21)] = 652,
  [SMALL_STATE(22)] = 680,
  [SMALL_STATE(23)] = 708,
  [SMALL_STATE(24)] = 728,
  [SMALL_STATE(25)] = 753,
  [SMALL_STATE(26)] = 772,
  [SMALL_STATE(27)] = 791,
  [SMALL_STATE(28)] = 810,
  [SMALL_STATE(29)] = 829,
  [SMALL_STATE(30)] = 848,
  [SMALL_STATE(31)] = 867,
  [SMALL_STATE(32)] = 886,
  [SMALL_STATE(33)] = 911,
  [SMALL_STATE(34)] = 936,
  [SMALL_STATE(35)] = 955,
  [SMALL_STATE(36)] = 974,
  [SMALL_STATE(37)] = 993,
  [SMALL_STATE(38)] = 1012,
  [SMALL_STATE(39)] = 1031,
  [SMALL_STATE(40)] = 1052,
  [SMALL_STATE(41)] = 1071,
  [SMALL_STATE(42)] = 1090,
  [SMALL_STATE(43)] = 1109,
  [SMALL_STATE(44)] = 1128,
  [SMALL_STATE(45)] = 1147,
  [SMALL_STATE(46)] = 1166,
  [SMALL_STATE(47)] = 1185,
  [SMALL_STATE(48)] = 1204,
  [SMALL_STATE(49)] = 1229,
  [SMALL_STATE(50)] = 1248,
  [SMALL_STATE(51)] = 1276,
  [SMALL_STATE(52)] = 1298,
  [SMALL_STATE(53)] = 1320,
  [SMALL_STATE(54)] = 1348,
  [SMALL_STATE(55)] = 1368,
  [SMALL_STATE(56)] = 1393,
  [SMALL_STATE(57)] = 1412,
  [SMALL_STATE(58)] = 1431,
  [SMALL_STATE(59)] = 1454,
  [SMALL_STATE(60)] = 1473,
  [SMALL_STATE(61)] = 1498,
  [SMALL_STATE(62)] = 1523,
  [SMALL_STATE(63)] = 1542,
  [SMALL_STATE(64)] = 1567,
  [SMALL_STATE(65)] = 1592,
  [SMALL_STATE(66)] = 1611,
  [SMALL_STATE(67)] = 1634,
  [SMALL_STATE(68)] = 1653,
  [SMALL_STATE(69)] = 1672,
  [SMALL_STATE(70)] = 1697,
  [SMALL_STATE(71)] = 1716,
  [SMALL_STATE(72)] = 1735,
  [SMALL_STATE(73)] = 1758,
  [SMALL_STATE(74)] = 1777,
  [SMALL_STATE(75)] = 1800,
  [SMALL_STATE(76)] = 1819,
  [SMALL_STATE(77)] = 1844,
  [SMALL_STATE(78)] = 1863,
  [SMALL_STATE(79)] = 1882,
  [SMALL_STATE(80)] = 1901,
  [SMALL_STATE(81)] = 1920,
  [SMALL_STATE(82)] = 1939,
  [SMALL_STATE(83)] = 1964,
  [SMALL_STATE(84)] = 1983,
  [SMALL_STATE(85)] = 2008,
  [SMALL_STATE(86)] = 2033,
  [SMALL_STATE(87)] = 2056,
  [SMALL_STATE(88)] = 2081,
  [SMALL_STATE(89)] = 2104,
  [SMALL_STATE(90)] = 2123,
  [SMALL_STATE(91)] = 2143,
  [SMALL_STATE(92)] = 2165,
  [SMALL_STATE(93)] = 2187,
  [SMALL_STATE(94)] = 2207,
  [SMALL_STATE(95)] = 2229,
  [SMALL_STATE(96)] = 2249,
  [SMALL_STATE(97)] = 2269,
  [SMALL_STATE(98)] = 2289,
  [SMALL_STATE(99)] = 2309,
  [SMALL_STATE(100)] = 2331,
  [SMALL_STATE(101)] = 2351,
  [SMALL_STATE(102)] = 2371,
  [SMALL_STATE(103)] = 2391,
  [SMALL_STATE(104)] = 2410,
  [SMALL_STATE(105)] = 2429,
  [SMALL_STATE(106)] = 2452,
  [SMALL_STATE(107)] = 2475,
  [SMALL_STATE(108)] = 2498,
  [SMALL_STATE(109)] = 2514,
  [SMALL_STATE(110)] = 2530,
  [SMALL_STATE(111)] = 2546,
  [SMALL_STATE(112)] = 2562,
  [SMALL_STATE(113)] = 2578,
  [SMALL_STATE(114)] = 2598,
  [SMALL_STATE(115)] = 2618,
  [SMALL_STATE(116)] = 2638,
  [SMALL_STATE(117)] = 2658,
  [SMALL_STATE(118)] = 2678,
  [SMALL_STATE(119)] = 2698,
  [SMALL_STATE(120)] = 2714,
  [SMALL_STATE(121)] = 2730,
  [SMALL_STATE(122)] = 2746,
  [SMALL_STATE(123)] = 2766,
  [SMALL_STATE(124)] = 2782,
  [SMALL_STATE(125)] = 2798,
  [SMALL_STATE(126)] = 2814,
  [SMALL_STATE(127)] = 2830,
  [SMALL_STATE(128)] = 2846,
  [SMALL_STATE(129)] = 2862,
  [SMALL_STATE(130)] = 2878,
  [SMALL_STATE(131)] = 2897,
  [SMALL_STATE(132)] = 2918,
  [SMALL_STATE(133)] = 2937,
  [SMALL_STATE(134)] = 2956,
  [SMALL_STATE(135)] = 2969,
  [SMALL_STATE(136)] = 2985,
  [SMALL_STATE(137)] = 3001,
  [SMALL_STATE(138)] = 3019,
  [SMALL_STATE(139)] = 3037,
  [SMALL_STATE(140)] = 3055,
  [SMALL_STATE(141)] = 3073,
  [SMALL_STATE(142)] = 3085,
  [SMALL_STATE(143)] = 3100,
  [SMALL_STATE(144)] = 3115,
  [SMALL_STATE(145)] = 3130,
  [SMALL_STATE(146)] = 3143,
  [SMALL_STATE(147)] = 3158,
  [SMALL_STATE(148)] = 3173,
  [SMALL_STATE(149)] = 3188,
  [SMALL_STATE(150)] = 3203,
  [SMALL_STATE(151)] = 3218,
  [SMALL_STATE(152)] = 3231,
  [SMALL_STATE(153)] = 3246,
  [SMALL_STATE(154)] = 3259,
  [SMALL_STATE(155)] = 3274,
  [SMALL_STATE(156)] = 3287,
  [SMALL_STATE(157)] = 3302,
  [SMALL_STATE(158)] = 3317,
  [SMALL_STATE(159)] = 3329,
  [SMALL_STATE(160)] = 3341,
  [SMALL_STATE(161)] = 3351,
  [SMALL_STATE(162)] = 3363,
  [SMALL_STATE(163)] = 3373,
  [SMALL_STATE(164)] = 3385,
  [SMALL_STATE(165)] = 3397,
  [SMALL_STATE(166)] = 3409,
  [SMALL_STATE(167)] = 3421,
  [SMALL_STATE(168)] = 3430,
  [SMALL_STATE(169)] = 3439,
  [SMALL_STATE(170)] = 3448,
  [SMALL_STATE(171)] = 3457,
  [SMALL_STATE(172)] = 3468,
  [SMALL_STATE(173)] = 3479,
  [SMALL_STATE(174)] = 3488,
  [SMALL_STATE(175)] = 3497,
  [SMALL_STATE(176)] = 3508,
  [SMALL_STATE(177)] = 3516,
  [SMALL_STATE(178)] = 3524,
  [SMALL_STATE(179)] = 3532,
  [SMALL_STATE(180)] = 3540,
  [SMALL_STATE(181)] = 3548,
  [SMALL_STATE(182)] = 3556,
  [SMALL_STATE(183)] = 3564,
  [SMALL_STATE(184)] = 3572,
  [SMALL_STATE(185)] = 3580,
  [SMALL_STATE(186)] = 3588,
  [SMALL_STATE(187)] = 3596,
  [SMALL_STATE(188)] = 3604,
  [SMALL_STATE(189)] = 3612,
  [SMALL_STATE(190)] = 3620,
  [SMALL_STATE(191)] = 3628,
  [SMALL_STATE(192)] = 3636,
  [SMALL_STATE(193)] = 3644,
  [SMALL_STATE(194)] = 3652,
  [SMALL_STATE(195)] = 3660,
  [SMALL_STATE(196)] = 3668,
  [SMALL_STATE(197)] = 3676,
  [SMALL_STATE(198)] = 3684,
  [SMALL_STATE(199)] = 3692,
  [SMALL_STATE(200)] = 3700,
  [SMALL_STATE(201)] = 3708,
  [SMALL_STATE(202)] = 3716,
  [SMALL_STATE(203)] = 3724,
  [SMALL_STATE(204)] = 3732,
  [SMALL_STATE(205)] = 3740,
  [SMALL_STATE(206)] = 3748,
  [SMALL_STATE(207)] = 3756,
  [SMALL_STATE(208)] = 3764,
  [SMALL_STATE(209)] = 3772,
  [SMALL_STATE(210)] = 3780,
  [SMALL_STATE(211)] = 3788,
  [SMALL_STATE(212)] = 3796,
  [SMALL_STATE(213)] = 3804,
  [SMALL_STATE(214)] = 3812,
  [SMALL_STATE(215)] = 3820,
  [SMALL_STATE(216)] = 3828,
  [SMALL_STATE(217)] = 3836,
  [SMALL_STATE(218)] = 3844,
  [SMALL_STATE(219)] = 3852,
  [SMALL_STATE(220)] = 3860,
  [SMALL_STATE(221)] = 3868,
  [SMALL_STATE(222)] = 3876,
  [SMALL_STATE(223)] = 3884,
  [SMALL_STATE(224)] = 3892,
  [SMALL_STATE(225)] = 3900,
  [SMALL_STATE(226)] = 3908,
  [SMALL_STATE(227)] = 3916,
  [SMALL_STATE(228)] = 3924,
  [SMALL_STATE(229)] = 3932,
  [SMALL_STATE(230)] = 3940,
  [SMALL_STATE(231)] = 3948,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(224),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(227),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(223),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(221),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(218),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(217),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(216),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(215),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(210),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(172),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [66] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(147),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(203),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(52),
  [79] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [82] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [88] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_melody_line, 2, 0, 3),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_melody_line, 2, 0, 3),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [96] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [102] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(151),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [120] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [122] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(152),
  [125] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(212),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(104),
  [131] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(55),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [137] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitched_note, 3, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitched_note, 3, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(208),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_play_stmt, 2, 0, 0),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_play_stmt, 3, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitched_note, 1, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitched_note, 1, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord_name, 1, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord_name, 1, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [170] = {.entry = {.count = 1, .reusable = false}}, SHIFT(214),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord_name, 3, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord_name, 3, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stop_stmt, 1, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stop_stmt, 1, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 5, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 5, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitched_note, 5, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitched_note, 5, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scale_type, 1, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kit_def, 5, 0, 1),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_session_def, 5, 0, 1),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tempo_stmt, 2, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_def, 5, 0, 1),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_stmt, 2, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_clip_def, 5, 0, 1),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stop_stmt, 2, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord_name, 5, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord_name, 5, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_clip_def, 6, 0, 1),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_session_modifier, 4, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_clip_def, 4, 0, 1),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_session_def, 4, 0, 1),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scale_stmt, 3, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_duration, 1, 0, 0),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 1, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_session_modifier, 3, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_device_def, 4, 0, 1),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_def, 4, 0, 1),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instrument_def, 5, 0, 1),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instrument_def, 4, 0, 1),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_device_def, 5, 0, 1),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_play_stmt, 4, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 7, 0, 0),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 7, 0, 0),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kit_def, 4, 0, 1),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [258] = {.entry = {.count = 1, .reusable = false}}, SHIFT(219),
  [260] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_melody_group, 3, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_melody_group, 3, 0, 0),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [266] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rest, 1, 0, 0),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rest, 1, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [276] = {.entry = {.count = 1, .reusable = false}}, SHIFT(231),
  [278] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitched_note, 2, 0, 0),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitched_note, 2, 0, 0),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 6, 0, 0),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 6, 0, 0),
  [286] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [288] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [292] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bar_jump, 2, 0, 0),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bar_jump, 2, 0, 0),
  [296] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [300] = {.entry = {.count = 1, .reusable = false}}, SHIFT(184),
  [302] = {.entry = {.count = 1, .reusable = false}}, SHIFT(185),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [306] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_melody_group, 5, 0, 0),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_melody_group, 5, 0, 0),
  [310] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitched_note, 4, 0, 0),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitched_note, 4, 0, 0),
  [314] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [316] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [320] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord_name, 4, 0, 0),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord_name, 4, 0, 0),
  [324] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord_name, 2, 0, 0),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord_name, 2, 0, 0),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [330] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, 0, 0),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, 0, 0),
  [334] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitched_note, 6, 0, 0),
  [336] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitched_note, 6, 0, 0),
  [338] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [340] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_articulation, 2, 0, 0),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_articulation, 2, 0, 0),
  [344] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [346] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [352] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arp_expr, 6, 0, 0),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arp_expr, 6, 0, 0),
  [356] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 8, 0, 0),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 8, 0, 0),
  [360] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_articulation, 1, 0, 0),
  [362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_articulation, 1, 0, 0),
  [364] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord_name, 6, 0, 0),
  [366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord_name, 6, 0, 0),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [370] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rest, 3, 0, 0),
  [372] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rest, 3, 0, 0),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [376] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_clip_def_repeat2, 2, 0, 0), SHIFT_REPEAT(6),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_clip_def_repeat2, 2, 0, 0),
  [381] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_clip_def_repeat2, 2, 0, 0), SHIFT_REPEAT(184),
  [384] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_clip_def_repeat2, 2, 0, 0), SHIFT_REPEAT(185),
  [387] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [391] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [393] = {.entry = {.count = 1, .reusable = false}}, SHIFT(160),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [409] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_instrument_def_repeat1, 2, 0, 0), SHIFT_REPEAT(180),
  [412] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_instrument_def_repeat1, 2, 0, 0),
  [414] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_instrument_def_repeat1, 2, 0, 0), SHIFT_REPEAT(178),
  [417] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_instrument_def_repeat1, 2, 0, 0), SHIFT_REPEAT(177),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [422] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_kit_instrument_repeat1, 2, 0, 0),
  [424] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_kit_instrument_repeat1, 2, 0, 0), SHIFT_REPEAT(230),
  [427] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_kit_instrument_repeat1, 2, 0, 0), SHIFT_REPEAT(226),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [436] = {.entry = {.count = 1, .reusable = false}}, SHIFT(131),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [440] = {.entry = {.count = 1, .reusable = false}}, SHIFT(169),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [450] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_scene_def_repeat1, 2, 0, 0), SHIFT_REPEAT(131),
  [453] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_scene_def_repeat1, 2, 0, 0),
  [455] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_scene_def_repeat1, 2, 0, 0), SHIFT_REPEAT(169),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [460] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_kit_def_repeat1, 2, 0, 0), SHIFT_REPEAT(182),
  [463] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_kit_def_repeat1, 2, 0, 0), SHIFT_REPEAT(176),
  [466] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_kit_def_repeat1, 2, 0, 0),
  [468] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_slot, 1, 0, 0),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_slot, 1, 0, 0),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [476] = {.entry = {.count = 1, .reusable = false}}, SHIFT(182),
  [478] = {.entry = {.count = 1, .reusable = false}}, SHIFT(176),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [484] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instrument_property, 2, 0, 0),
  [486] = {.entry = {.count = 1, .reusable = false}}, SHIFT(196),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [496] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_chord_repeat1, 2, 0, 0),
  [498] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_chord_repeat1, 2, 0, 0), SHIFT_REPEAT(145),
  [501] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_chord_repeat1, 2, 0, 0), SHIFT_REPEAT(138),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [506] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_shuffle_expr, 2, 0, 0),
  [508] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shuffle_expr, 2, 0, 0),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [512] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kit_instrument_property, 2, 0, 0),
  [514] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_session_def_repeat1, 2, 0, 0), SHIFT_REPEAT(150),
  [517] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_session_def_repeat1, 2, 0, 0),
  [519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [523] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_device_def_repeat1, 2, 0, 0),
  [525] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_device_def_repeat1, 2, 0, 0), SHIFT_REPEAT(179),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [530] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_clip_def_repeat1, 2, 0, 0),
  [532] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_clip_def_repeat1, 2, 0, 0), SHIFT_REPEAT(116),
  [535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [545] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_session_entry, 1, 0, 0),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [549] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drum_line, 2, 0, 3),
  [551] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drum_line, 2, 0, 3),
  [553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [555] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_use_stmt, 2, 0, 2),
  [557] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_use_stmt, 2, 0, 2),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [561] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_resolution_stmt, 2, 0, 0),
  [563] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_resolution_stmt, 2, 0, 0),
  [565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [569] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_shuffle_expr, 3, 0, 0),
  [571] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shuffle_expr, 3, 0, 0),
  [573] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_slot, 2, 0, 0),
  [575] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_slot, 2, 0, 0),
  [577] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_weight, 2, 0, 0),
  [579] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_weight, 2, 0, 0),
  [581] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_tempo, 2, 0, 0),
  [583] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_tempo, 2, 0, 0),
  [585] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_kit_instrument, 4, 0, 4),
  [587] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kit_instrument, 4, 0, 4),
  [589] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__kit_member, 2, 0, 0),
  [591] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__kit_member, 2, 0, 0),
  [593] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_kit_instrument, 3, 0, 4),
  [595] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kit_instrument, 3, 0, 4),
  [597] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_session_entry, 2, 0, 0),
  [599] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [601] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_clip_header, 3, 0, 0),
  [603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [605] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [607] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [609] = {.entry = {.count = 1, .reusable = false}}, SHIFT(190),
  [611] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_device_property, 2, 0, 0),
  [613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [629] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [631] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [633] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [635] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [637] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [639] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [641] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [643] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [645] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [647] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [649] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [651] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [653] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arp_direction, 1, 0, 0),
  [655] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [657] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [659] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [661] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [663] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [665] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [667] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [669] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [671] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scale_attr, 3, 0, 0),
  [673] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bars_attr, 2, 0, 0),
  [675] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time_attr, 2, 0, 0),
  [677] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [679] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [681] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [683] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [685] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [687] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [689] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [691] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [693] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [695] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [697] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [699] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [705] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [707] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [709] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [711] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [713] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [715] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [717] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [719] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [721] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_block_comment = 0,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_block_comment] = sym_block_comment,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_block_comment] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_cvg_external_scanner_create(void);
void tree_sitter_cvg_external_scanner_destroy(void *);
bool tree_sitter_cvg_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_cvg_external_scanner_serialize(void *, char *);
void tree_sitter_cvg_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_cvg(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_cvg_external_scanner_create,
      tree_sitter_cvg_external_scanner_destroy,
      tree_sitter_cvg_external_scanner_scan,
      tree_sitter_cvg_external_scanner_serialize,
      tree_sitter_cvg_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
