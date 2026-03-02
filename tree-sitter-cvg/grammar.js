/// <reference types="tree-sitter-cli/dsl" />

module.exports = grammar({
  name: 'cvg',

  externals: $ => [$.block_comment],

  extras: $ => [/\s/, $.comment, $.block_comment],

  word: $ => $.identifier,

  rules: {
    source_file: $ => repeat($._top_level),

    _top_level: $ => choice(
      $.device_def,
      $.instrument_def,
      $.kit_def,
      $.clip_def,
      $.scene_def,
      $.session_def,
      $.include_stmt,
      $.tempo_stmt,
      $.scale_stmt,
      $.play_stmt,
      $.stop_stmt,
    ),

    // ── device ──
    device_def: $ => seq(
      'device',
      field('name', $.identifier),
      '{',
      repeat($.device_property),
      '}',
    ),

    device_property: $ => seq(
      'port',
      $.string,
    ),

    // ── instrument ──
    instrument_def: $ => seq(
      'instrument',
      field('name', $.identifier),
      '{',
      repeat($.instrument_property),
      '}',
    ),

    instrument_property: $ => choice(
      seq('device', $.identifier),
      seq('channel', $.number),
      seq('note', $.note_literal),
      seq('gate_normal', $.number),
      seq('gate_staccato', $.number),
    ),

    // ── kit ──
    kit_def: $ => seq(
      'kit',
      field('name', $.identifier),
      '{',
      repeat($._kit_member),
      '}',
    ),

    _kit_member: $ => choice(
      seq('device', $.identifier),
      $.kit_instrument,
    ),

    kit_instrument: $ => seq(
      field('name', $.identifier),
      '{',
      repeat($.kit_instrument_property),
      '}',
    ),

    kit_instrument_property: $ => choice(
      seq('channel', $.number),
      seq('note', $.note_literal),
      seq('gate_normal', $.number),
      seq('gate_staccato', $.number),
    ),

    // note_literal: c2, eb3, f#5 etc (note name + octave number)
    note_literal: $ => token(seq(/[a-g][#b]?/, /[0-9]/)),

    // ── clip ──
    clip_def: $ => seq(
      'clip',
      field('name', $.identifier),
      repeat($.clip_header),
      '{',
      repeat($._clip_content),
      '}',
    ),

    clip_header: $ => seq(
      '[',
      $._clip_attr,
      ']',
    ),

    _clip_attr: $ => choice(
      $.bars_attr,
      $.time_attr,
      $.scale_attr,
    ),

    bars_attr: $ => seq('bars', $.number),
    time_attr: $ => seq('time', $.time_signature),
    scale_attr: $ => seq('scale', $.note_name, $.scale_type),

    time_signature: $ => /\d+\/\d+/,

    scale_type: $ => choice(
      'major', 'minor', 'harmonic_minor', 'melodic_minor',
      'dorian', 'phrygian', 'lydian', 'mixolydian', 'locrian',
    ),

    _clip_content: $ => choice(
      $.use_stmt,
      $.resolution_stmt,
      $.drum_line,
      $.melody_line,
    ),

    use_stmt: $ => seq('use', field('kit', $.identifier)),
    resolution_stmt: $ => seq('resolution', $.number),

    // ── drum line ──
    // The step_pattern is a token that captures the entire pattern as one lexeme
    drum_line: $ => prec.left(seq(
      field('instrument', $.identifier),
      $.step_pattern,
    )),

    // Step pattern: contiguous string of step characters (no whitespace)
    step_pattern: $ => token(prec(-1, /[xXo.|\-()>*0-9]+/)),

    // ── melody line ──
    melody_line: $ => prec.right(seq(
      field('instrument', $.identifier),
      repeat1($._melody_element),
    )),

    _melody_element: $ => choice(
      $.pitched_note,
      $.rest,
      $.chord,
      $.chord_name,
      $.melody_group,
      $.bar_jump,
    ),

    bar_jump: $ => seq('>', $.number),

    pitched_note: $ => seq(
      $.note_name,
      optional(seq(':', $.octave)),
      optional(seq(':', $.duration)),
      optional($.articulation),
    ),

    rest: $ => seq('r', optional(seq(':', $.duration))),

    octave: $ => /[0-9]/,

    duration: $ => choice('1', '2', '4', '4.', '8', '8.', '16', '32'),

    articulation: $ => choice(
      "'",
      seq('g', $.number),
    ),

    chord: $ => seq(
      '[',
      repeat1(choice($.note_name, $.rest)),
      ']',
      optional(seq(':', $.octave)),
      optional(seq(':', $.duration)),
      optional($.arp_expr),
    ),

    chord_name: $ => seq(
      $.chord_symbol,
      optional(seq(':', $.octave)),
      optional(seq(':', $.duration)),
      optional($.arp_expr),
    ),

    chord_symbol: $ => token(prec(2, /[a-g][#b]?(?:maj7|m7|7|dim7|aug|m|dim|sus[24]|add9|6|9|11|13)/)),

    arp_expr: $ => seq(
      'arp',
      '(',
      $.arp_direction,
      ',',
      $.number,
      ')',
    ),

    arp_direction: $ => choice('up', 'down', 'updown', 'random'),

    melody_group: $ => seq(
      '(',
      repeat1($._melody_element),
      ')',
      optional(seq('*', $.number)),
    ),

    // ── scene ──
    scene_def: $ => seq(
      'scene',
      field('name', $.identifier),
      '{',
      repeat($._scene_content),
      '}',
    ),

    _scene_content: $ => choice(
      $.scene_slot,
      $.scene_tempo,
    ),

    scene_slot: $ => seq(
      $.identifier,
      optional(choice(
        $.probability,
        $.shuffle_expr,
      )),
    ),

    probability: $ => /[1-9]/,

    shuffle_expr: $ => seq(
      '|',
      $.identifier,
      optional($.weight),
    ),

    weight: $ => seq('*', $.number),

    scene_tempo: $ => seq(
      'tempo',
      choice($.number, $.tempo_delta),
    ),

    tempo_delta: $ => /[+-]\d+/,

    // ── session ──
    session_def: $ => seq(
      'session',
      field('name', $.identifier),
      '{',
      repeat($.session_entry),
      '}',
    ),

    session_entry: $ => seq(
      $.identifier,
      optional($.session_modifier),
    ),

    session_modifier: $ => seq(
      '[',
      choice(
        seq('repeat', $.number),
        'loop',
      ),
      ']',
    ),

    // ── include ──
    include_stmt: $ => seq('include', $.string),

    // ── tempo (top-level) ──
    tempo_stmt: $ => seq('tempo', $.number),

    // ── scale (global) ──
    scale_stmt: $ => seq('scale', $.note_name, $.scale_type),

    // ── play / stop ──
    play_stmt: $ => seq(
      'play',
      optional('session'),
      $.identifier,
      optional($.session_modifier),
    ),

    stop_stmt: $ => seq(
      'stop',
      optional($.identifier),
    ),

    // ── primitives ──
    note_name: $ => token(prec(1, /[a-g][#b]?/)),
    number: $ => /\d+/,
    identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,
    string: $ => /"[^"]*"/,
    comment: $ => /\/\/.*/,
  },
});
