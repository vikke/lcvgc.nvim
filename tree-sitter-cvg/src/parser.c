#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 222
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 129
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
  sym_rest = 34,
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
  sym_duration = 97,
  sym_articulation = 98,
  sym_chord = 99,
  sym_chord_name = 100,
  sym_arp_expr = 101,
  sym_arp_direction = 102,
  sym_melody_group = 103,
  sym_scene_def = 104,
  sym__scene_content = 105,
  sym_scene_slot = 106,
  sym_shuffle_expr = 107,
  sym_weight = 108,
  sym_scene_tempo = 109,
  sym_session_def = 110,
  sym_session_entry = 111,
  sym_session_modifier = 112,
  sym_include_stmt = 113,
  sym_tempo_stmt = 114,
  sym_scale_stmt = 115,
  sym_play_stmt = 116,
  sym_stop_stmt = 117,
  aux_sym_source_file_repeat1 = 118,
  aux_sym_device_def_repeat1 = 119,
  aux_sym_instrument_def_repeat1 = 120,
  aux_sym_kit_def_repeat1 = 121,
  aux_sym_kit_instrument_repeat1 = 122,
  aux_sym_clip_def_repeat1 = 123,
  aux_sym_clip_def_repeat2 = 124,
  aux_sym_melody_line_repeat1 = 125,
  aux_sym_chord_repeat1 = 126,
  aux_sym_scene_def_repeat1 = 127,
  aux_sym_session_def_repeat1 = 128,
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
  [sym_rest] = "rest",
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
  [sym_rest] = sym_rest,
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
  [sym_rest] = {
    .visible = true,
    .named = true,
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
  [8] = 6,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 5,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 15,
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
  [50] = 50,
  [51] = 48,
  [52] = 7,
  [53] = 9,
  [54] = 16,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 23,
  [60] = 60,
  [61] = 22,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 18,
  [73] = 17,
  [74] = 74,
  [75] = 75,
  [76] = 60,
  [77] = 77,
  [78] = 78,
  [79] = 66,
  [80] = 80,
  [81] = 48,
  [82] = 75,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 20,
  [88] = 32,
  [89] = 35,
  [90] = 43,
  [91] = 91,
  [92] = 91,
  [93] = 93,
  [94] = 93,
  [95] = 47,
  [96] = 96,
  [97] = 96,
  [98] = 98,
  [99] = 99,
  [100] = 50,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 71,
  [106] = 68,
  [107] = 65,
  [108] = 56,
  [109] = 63,
  [110] = 70,
  [111] = 111,
  [112] = 74,
  [113] = 80,
  [114] = 77,
  [115] = 115,
  [116] = 69,
  [117] = 117,
  [118] = 57,
  [119] = 64,
  [120] = 55,
  [121] = 121,
  [122] = 78,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 130,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 142,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 150,
  [157] = 157,
  [158] = 158,
  [159] = 157,
  [160] = 160,
  [161] = 26,
  [162] = 39,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 167,
  [168] = 168,
  [169] = 169,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 173,
  [174] = 174,
  [175] = 175,
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
  [203] = 179,
  [204] = 178,
  [205] = 174,
  [206] = 206,
  [207] = 207,
  [208] = 208,
  [209] = 209,
  [210] = 170,
  [211] = 167,
  [212] = 212,
  [213] = 173,
  [214] = 214,
  [215] = 180,
  [216] = 216,
  [217] = 217,
  [218] = 193,
  [219] = 185,
  [220] = 220,
  [221] = 214,
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
      ACCEPT_TOKEN(sym_rest);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_rest);
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
  [6] = {.lex_state = 2, .external_lex_state = 1},
  [7] = {.lex_state = 3, .external_lex_state = 1},
  [8] = {.lex_state = 2, .external_lex_state = 1},
  [9] = {.lex_state = 3, .external_lex_state = 1},
  [10] = {.lex_state = 27, .external_lex_state = 1},
  [11] = {.lex_state = 27, .external_lex_state = 1},
  [12] = {.lex_state = 2, .external_lex_state = 1},
  [13] = {.lex_state = 5, .external_lex_state = 1},
  [14] = {.lex_state = 27, .external_lex_state = 1},
  [15] = {.lex_state = 2, .external_lex_state = 1},
  [16] = {.lex_state = 4, .external_lex_state = 1},
  [17] = {.lex_state = 4, .external_lex_state = 1},
  [18] = {.lex_state = 4, .external_lex_state = 1},
  [19] = {.lex_state = 27, .external_lex_state = 1},
  [20] = {.lex_state = 4, .external_lex_state = 1},
  [21] = {.lex_state = 2, .external_lex_state = 1},
  [22] = {.lex_state = 3, .external_lex_state = 1},
  [23] = {.lex_state = 3, .external_lex_state = 1},
  [24] = {.lex_state = 27, .external_lex_state = 1},
  [25] = {.lex_state = 27, .external_lex_state = 1},
  [26] = {.lex_state = 27, .external_lex_state = 1},
  [27] = {.lex_state = 27, .external_lex_state = 1},
  [28] = {.lex_state = 27, .external_lex_state = 1},
  [29] = {.lex_state = 27, .external_lex_state = 1},
  [30] = {.lex_state = 27, .external_lex_state = 1},
  [31] = {.lex_state = 27, .external_lex_state = 1},
  [32] = {.lex_state = 4, .external_lex_state = 1},
  [33] = {.lex_state = 27, .external_lex_state = 1},
  [34] = {.lex_state = 27, .external_lex_state = 1},
  [35] = {.lex_state = 4, .external_lex_state = 1},
  [36] = {.lex_state = 27, .external_lex_state = 1},
  [37] = {.lex_state = 27, .external_lex_state = 1},
  [38] = {.lex_state = 27, .external_lex_state = 1},
  [39] = {.lex_state = 27, .external_lex_state = 1},
  [40] = {.lex_state = 27, .external_lex_state = 1},
  [41] = {.lex_state = 27, .external_lex_state = 1},
  [42] = {.lex_state = 27, .external_lex_state = 1},
  [43] = {.lex_state = 4, .external_lex_state = 1},
  [44] = {.lex_state = 27, .external_lex_state = 1},
  [45] = {.lex_state = 27, .external_lex_state = 1},
  [46] = {.lex_state = 27, .external_lex_state = 1},
  [47] = {.lex_state = 4, .external_lex_state = 1},
  [48] = {.lex_state = 3, .external_lex_state = 1},
  [49] = {.lex_state = 27, .external_lex_state = 1},
  [50] = {.lex_state = 4, .external_lex_state = 1},
  [51] = {.lex_state = 4, .external_lex_state = 1},
  [52] = {.lex_state = 2, .external_lex_state = 1},
  [53] = {.lex_state = 2, .external_lex_state = 1},
  [54] = {.lex_state = 4, .external_lex_state = 1},
  [55] = {.lex_state = 4, .external_lex_state = 1},
  [56] = {.lex_state = 4, .external_lex_state = 1},
  [57] = {.lex_state = 4, .external_lex_state = 1},
  [58] = {.lex_state = 27, .external_lex_state = 1},
  [59] = {.lex_state = 2, .external_lex_state = 1},
  [60] = {.lex_state = 27, .external_lex_state = 1},
  [61] = {.lex_state = 2, .external_lex_state = 1},
  [62] = {.lex_state = 27, .external_lex_state = 1},
  [63] = {.lex_state = 4, .external_lex_state = 1},
  [64] = {.lex_state = 4, .external_lex_state = 1},
  [65] = {.lex_state = 4, .external_lex_state = 1},
  [66] = {.lex_state = 27, .external_lex_state = 1},
  [67] = {.lex_state = 27, .external_lex_state = 1},
  [68] = {.lex_state = 4, .external_lex_state = 1},
  [69] = {.lex_state = 4, .external_lex_state = 1},
  [70] = {.lex_state = 4, .external_lex_state = 1},
  [71] = {.lex_state = 4, .external_lex_state = 1},
  [72] = {.lex_state = 4, .external_lex_state = 1},
  [73] = {.lex_state = 4, .external_lex_state = 1},
  [74] = {.lex_state = 4, .external_lex_state = 1},
  [75] = {.lex_state = 27, .external_lex_state = 1},
  [76] = {.lex_state = 27, .external_lex_state = 1},
  [77] = {.lex_state = 4, .external_lex_state = 1},
  [78] = {.lex_state = 4, .external_lex_state = 1},
  [79] = {.lex_state = 27, .external_lex_state = 1},
  [80] = {.lex_state = 4, .external_lex_state = 1},
  [81] = {.lex_state = 3, .external_lex_state = 1},
  [82] = {.lex_state = 27, .external_lex_state = 1},
  [83] = {.lex_state = 27, .external_lex_state = 1},
  [84] = {.lex_state = 27, .external_lex_state = 1},
  [85] = {.lex_state = 27, .external_lex_state = 1},
  [86] = {.lex_state = 27, .external_lex_state = 1},
  [87] = {.lex_state = 4, .external_lex_state = 1},
  [88] = {.lex_state = 4, .external_lex_state = 1},
  [89] = {.lex_state = 4, .external_lex_state = 1},
  [90] = {.lex_state = 4, .external_lex_state = 1},
  [91] = {.lex_state = 27, .external_lex_state = 1},
  [92] = {.lex_state = 27, .external_lex_state = 1},
  [93] = {.lex_state = 27, .external_lex_state = 1},
  [94] = {.lex_state = 27, .external_lex_state = 1},
  [95] = {.lex_state = 4, .external_lex_state = 1},
  [96] = {.lex_state = 27, .external_lex_state = 1},
  [97] = {.lex_state = 27, .external_lex_state = 1},
  [98] = {.lex_state = 27, .external_lex_state = 1},
  [99] = {.lex_state = 27, .external_lex_state = 1},
  [100] = {.lex_state = 2, .external_lex_state = 1},
  [101] = {.lex_state = 27, .external_lex_state = 1},
  [102] = {.lex_state = 27, .external_lex_state = 1},
  [103] = {.lex_state = 27, .external_lex_state = 1},
  [104] = {.lex_state = 27, .external_lex_state = 1},
  [105] = {.lex_state = 2, .external_lex_state = 1},
  [106] = {.lex_state = 2, .external_lex_state = 1},
  [107] = {.lex_state = 2, .external_lex_state = 1},
  [108] = {.lex_state = 2, .external_lex_state = 1},
  [109] = {.lex_state = 2, .external_lex_state = 1},
  [110] = {.lex_state = 2, .external_lex_state = 1},
  [111] = {.lex_state = 27, .external_lex_state = 1},
  [112] = {.lex_state = 2, .external_lex_state = 1},
  [113] = {.lex_state = 2, .external_lex_state = 1},
  [114] = {.lex_state = 2, .external_lex_state = 1},
  [115] = {.lex_state = 27, .external_lex_state = 1},
  [116] = {.lex_state = 2, .external_lex_state = 1},
  [117] = {.lex_state = 27, .external_lex_state = 1},
  [118] = {.lex_state = 2, .external_lex_state = 1},
  [119] = {.lex_state = 2, .external_lex_state = 1},
  [120] = {.lex_state = 2, .external_lex_state = 1},
  [121] = {.lex_state = 27, .external_lex_state = 1},
  [122] = {.lex_state = 2, .external_lex_state = 1},
  [123] = {.lex_state = 7, .external_lex_state = 1},
  [124] = {.lex_state = 27, .external_lex_state = 1},
  [125] = {.lex_state = 27, .external_lex_state = 1},
  [126] = {.lex_state = 27, .external_lex_state = 1},
  [127] = {.lex_state = 27, .external_lex_state = 1},
  [128] = {.lex_state = 27, .external_lex_state = 1},
  [129] = {.lex_state = 27, .external_lex_state = 1},
  [130] = {.lex_state = 27, .external_lex_state = 1},
  [131] = {.lex_state = 27, .external_lex_state = 1},
  [132] = {.lex_state = 27, .external_lex_state = 1},
  [133] = {.lex_state = 27, .external_lex_state = 1},
  [134] = {.lex_state = 27, .external_lex_state = 1},
  [135] = {.lex_state = 27, .external_lex_state = 1},
  [136] = {.lex_state = 0, .external_lex_state = 1},
  [137] = {.lex_state = 27, .external_lex_state = 1},
  [138] = {.lex_state = 6, .external_lex_state = 1},
  [139] = {.lex_state = 27, .external_lex_state = 1},
  [140] = {.lex_state = 27, .external_lex_state = 1},
  [141] = {.lex_state = 0, .external_lex_state = 1},
  [142] = {.lex_state = 6, .external_lex_state = 1},
  [143] = {.lex_state = 27, .external_lex_state = 1},
  [144] = {.lex_state = 27, .external_lex_state = 1},
  [145] = {.lex_state = 27, .external_lex_state = 1},
  [146] = {.lex_state = 0, .external_lex_state = 1},
  [147] = {.lex_state = 6, .external_lex_state = 1},
  [148] = {.lex_state = 27, .external_lex_state = 1},
  [149] = {.lex_state = 27, .external_lex_state = 1},
  [150] = {.lex_state = 6, .external_lex_state = 1},
  [151] = {.lex_state = 27, .external_lex_state = 1},
  [152] = {.lex_state = 27, .external_lex_state = 1},
  [153] = {.lex_state = 27, .external_lex_state = 1},
  [154] = {.lex_state = 27, .external_lex_state = 1},
  [155] = {.lex_state = 27, .external_lex_state = 1},
  [156] = {.lex_state = 6, .external_lex_state = 1},
  [157] = {.lex_state = 27, .external_lex_state = 1},
  [158] = {.lex_state = 27, .external_lex_state = 1},
  [159] = {.lex_state = 27, .external_lex_state = 1},
  [160] = {.lex_state = 0, .external_lex_state = 1},
  [161] = {.lex_state = 27, .external_lex_state = 1},
  [162] = {.lex_state = 27, .external_lex_state = 1},
  [163] = {.lex_state = 27, .external_lex_state = 1},
  [164] = {.lex_state = 4, .external_lex_state = 1},
  [165] = {.lex_state = 27, .external_lex_state = 1},
  [166] = {.lex_state = 4, .external_lex_state = 1},
  [167] = {.lex_state = 4, .external_lex_state = 1},
  [168] = {.lex_state = 0, .external_lex_state = 1},
  [169] = {.lex_state = 4, .external_lex_state = 1},
  [170] = {.lex_state = 4, .external_lex_state = 1},
  [171] = {.lex_state = 0, .external_lex_state = 1},
  [172] = {.lex_state = 27, .external_lex_state = 1},
  [173] = {.lex_state = 27, .external_lex_state = 1},
  [174] = {.lex_state = 0, .external_lex_state = 1},
  [175] = {.lex_state = 27, .external_lex_state = 1},
  [176] = {.lex_state = 0, .external_lex_state = 1},
  [177] = {.lex_state = 0, .external_lex_state = 1},
  [178] = {.lex_state = 4, .external_lex_state = 1},
  [179] = {.lex_state = 0, .external_lex_state = 1},
  [180] = {.lex_state = 4, .external_lex_state = 1},
  [181] = {.lex_state = 0, .external_lex_state = 1},
  [182] = {.lex_state = 6, .external_lex_state = 1},
  [183] = {.lex_state = 2, .external_lex_state = 1},
  [184] = {.lex_state = 4, .external_lex_state = 1},
  [185] = {.lex_state = 0, .external_lex_state = 1},
  [186] = {.lex_state = 27, .external_lex_state = 1},
  [187] = {.lex_state = 0, .external_lex_state = 1},
  [188] = {.lex_state = 27, .external_lex_state = 1},
  [189] = {.lex_state = 8, .external_lex_state = 1},
  [190] = {.lex_state = 4, .external_lex_state = 1},
  [191] = {.lex_state = 27, .external_lex_state = 1},
  [192] = {.lex_state = 0, .external_lex_state = 1},
  [193] = {.lex_state = 4, .external_lex_state = 1},
  [194] = {.lex_state = 27, .external_lex_state = 1},
  [195] = {.lex_state = 0, .external_lex_state = 1},
  [196] = {.lex_state = 0, .external_lex_state = 1},
  [197] = {.lex_state = 0, .external_lex_state = 1},
  [198] = {.lex_state = 0, .external_lex_state = 1},
  [199] = {.lex_state = 0, .external_lex_state = 1},
  [200] = {.lex_state = 0, .external_lex_state = 1},
  [201] = {.lex_state = 4, .external_lex_state = 1},
  [202] = {.lex_state = 0, .external_lex_state = 1},
  [203] = {.lex_state = 0, .external_lex_state = 1},
  [204] = {.lex_state = 4, .external_lex_state = 1},
  [205] = {.lex_state = 0, .external_lex_state = 1},
  [206] = {.lex_state = 27, .external_lex_state = 1},
  [207] = {.lex_state = 4, .external_lex_state = 1},
  [208] = {.lex_state = 27, .external_lex_state = 1},
  [209] = {.lex_state = 6, .external_lex_state = 1},
  [210] = {.lex_state = 4, .external_lex_state = 1},
  [211] = {.lex_state = 4, .external_lex_state = 1},
  [212] = {.lex_state = 27, .external_lex_state = 1},
  [213] = {.lex_state = 27, .external_lex_state = 1},
  [214] = {.lex_state = 0, .external_lex_state = 1},
  [215] = {.lex_state = 4, .external_lex_state = 1},
  [216] = {.lex_state = 8, .external_lex_state = 1},
  [217] = {.lex_state = 27, .external_lex_state = 1},
  [218] = {.lex_state = 4, .external_lex_state = 1},
  [219] = {.lex_state = 0, .external_lex_state = 1},
  [220] = {.lex_state = 27, .external_lex_state = 1},
  [221] = {.lex_state = 0, .external_lex_state = 1},
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
    [sym_rest] = ACTIONS(1),
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
    [sym_source_file] = STATE(200),
    [sym__top_level] = STATE(2),
    [sym_device_def] = STATE(2),
    [sym_instrument_def] = STATE(2),
    [sym_kit_def] = STATE(2),
    [sym_clip_def] = STATE(2),
    [sym_scene_def] = STATE(2),
    [sym_session_def] = STATE(2),
    [sym_include_stmt] = STATE(2),
    [sym_tempo_stmt] = STATE(2),
    [sym_scale_stmt] = STATE(2),
    [sym_play_stmt] = STATE(2),
    [sym_stop_stmt] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
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
    ACTIONS(29), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(3), 13,
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
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 1,
      anon_sym_device,
    ACTIONS(36), 1,
      anon_sym_instrument,
    ACTIONS(39), 1,
      anon_sym_kit,
    ACTIONS(42), 1,
      anon_sym_clip,
    ACTIONS(45), 1,
      anon_sym_scale,
    ACTIONS(48), 1,
      anon_sym_scene,
    ACTIONS(51), 1,
      anon_sym_tempo,
    ACTIONS(54), 1,
      anon_sym_session,
    ACTIONS(57), 1,
      anon_sym_include,
    ACTIONS(60), 1,
      anon_sym_play,
    ACTIONS(63), 1,
      anon_sym_stop,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(3), 13,
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
    ACTIONS(72), 1,
      anon_sym_GT,
    ACTIONS(74), 1,
      sym_rest,
    ACTIONS(76), 1,
      sym_chord_symbol,
    ACTIONS(78), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(66), 3,
      anon_sym_use,
      anon_sym_resolution,
      sym_identifier,
    STATE(5), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [152] = 10,
    ACTIONS(84), 1,
      anon_sym_RBRACE,
    ACTIONS(86), 1,
      anon_sym_LBRACK,
    ACTIONS(89), 1,
      anon_sym_GT,
    ACTIONS(92), 1,
      sym_rest,
    ACTIONS(95), 1,
      sym_chord_symbol,
    ACTIONS(98), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(82), 3,
      anon_sym_use,
      anon_sym_resolution,
      sym_identifier,
    STATE(5), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [192] = 9,
    ACTIONS(104), 1,
      anon_sym_LBRACK,
    ACTIONS(106), 1,
      anon_sym_GT,
    ACTIONS(108), 1,
      sym_rest,
    ACTIONS(110), 1,
      sym_chord_symbol,
    ACTIONS(112), 1,
      anon_sym_LPAREN,
    ACTIONS(114), 1,
      anon_sym_RPAREN,
    ACTIONS(116), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(12), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [227] = 7,
    ACTIONS(122), 1,
      anon_sym_COLON,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_g,
    STATE(57), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(118), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(120), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [258] = 9,
    ACTIONS(104), 1,
      anon_sym_LBRACK,
    ACTIONS(106), 1,
      anon_sym_GT,
    ACTIONS(108), 1,
      sym_rest,
    ACTIONS(110), 1,
      sym_chord_symbol,
    ACTIONS(112), 1,
      anon_sym_LPAREN,
    ACTIONS(116), 1,
      sym_note_name,
    ACTIONS(128), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(12), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [293] = 7,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_g,
    ACTIONS(134), 1,
      anon_sym_COLON,
    STATE(69), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(130), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(132), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [324] = 4,
    ACTIONS(138), 1,
      anon_sym_LBRACK,
    STATE(25), 1,
      sym_session_modifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(136), 12,
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
  [349] = 4,
    ACTIONS(138), 1,
      anon_sym_LBRACK,
    STATE(41), 1,
      sym_session_modifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(140), 12,
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
  [374] = 9,
    ACTIONS(84), 1,
      anon_sym_RPAREN,
    ACTIONS(142), 1,
      anon_sym_LBRACK,
    ACTIONS(145), 1,
      anon_sym_GT,
    ACTIONS(148), 1,
      sym_rest,
    ACTIONS(151), 1,
      sym_chord_symbol,
    ACTIONS(154), 1,
      anon_sym_LPAREN,
    ACTIONS(157), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(12), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [409] = 9,
    ACTIONS(70), 1,
      anon_sym_LBRACK,
    ACTIONS(72), 1,
      anon_sym_GT,
    ACTIONS(76), 1,
      sym_chord_symbol,
    ACTIONS(78), 1,
      anon_sym_LPAREN,
    ACTIONS(80), 1,
      sym_note_name,
    ACTIONS(160), 1,
      sym_step_pattern,
    ACTIONS(162), 1,
      sym_rest,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(4), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [444] = 4,
    ACTIONS(164), 1,
      ts_builtin_sym_end,
    ACTIONS(166), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(168), 11,
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
  [468] = 8,
    ACTIONS(104), 1,
      anon_sym_LBRACK,
    ACTIONS(106), 1,
      anon_sym_GT,
    ACTIONS(110), 1,
      sym_chord_symbol,
    ACTIONS(112), 1,
      anon_sym_LPAREN,
    ACTIONS(116), 1,
      sym_note_name,
    ACTIONS(170), 1,
      sym_rest,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(8), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [500] = 6,
    ACTIONS(176), 1,
      anon_sym_COLON,
    ACTIONS(178), 1,
      anon_sym_arp,
    STATE(74), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(172), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(174), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [528] = 6,
    ACTIONS(178), 1,
      anon_sym_arp,
    ACTIONS(184), 1,
      anon_sym_COLON,
    STATE(55), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(180), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(182), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [556] = 6,
    ACTIONS(178), 1,
      anon_sym_arp,
    ACTIONS(190), 1,
      anon_sym_COLON,
    STATE(64), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(186), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(188), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [584] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(192), 13,
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
  [604] = 6,
    ACTIONS(178), 1,
      anon_sym_arp,
    ACTIONS(198), 1,
      anon_sym_COLON,
    STATE(77), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(194), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(196), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [632] = 8,
    ACTIONS(104), 1,
      anon_sym_LBRACK,
    ACTIONS(106), 1,
      anon_sym_GT,
    ACTIONS(110), 1,
      sym_chord_symbol,
    ACTIONS(112), 1,
      anon_sym_LPAREN,
    ACTIONS(116), 1,
      sym_note_name,
    ACTIONS(200), 1,
      sym_rest,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(6), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [664] = 6,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_g,
    STATE(65), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(202), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(204), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [692] = 6,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_g,
    STATE(57), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(118), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(120), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [720] = 2,
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
  [739] = 2,
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
  [758] = 2,
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
  [777] = 2,
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
  [796] = 2,
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
  [815] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(216), 12,
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
  [834] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(218), 12,
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
  [853] = 2,
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
  [872] = 5,
    ACTIONS(178), 1,
      anon_sym_arp,
    STATE(71), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(222), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(224), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [897] = 2,
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
  [916] = 2,
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
  [935] = 5,
    ACTIONS(178), 1,
      anon_sym_arp,
    STATE(63), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(230), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(232), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [960] = 2,
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
  [979] = 2,
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
  [998] = 2,
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
  [1017] = 2,
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
  [1036] = 2,
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
  [1055] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(136), 12,
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
  [1074] = 2,
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
  [1093] = 5,
    ACTIONS(178), 1,
      anon_sym_arp,
    STATE(74), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(172), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(174), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1118] = 2,
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
  [1137] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(248), 12,
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
  [1156] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(250), 12,
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
  [1175] = 5,
    ACTIONS(178), 1,
      anon_sym_arp,
    STATE(64), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(186), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(188), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1200] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(252), 6,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      anon_sym_g,
      sym_note_name,
      sym_identifier,
    ACTIONS(254), 6,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      anon_sym_SQUOTE,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1221] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(256), 12,
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
  [1240] = 4,
    ACTIONS(262), 1,
      anon_sym_STAR,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(258), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(260), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1262] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(254), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
    ACTIONS(252), 6,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      anon_sym_arp,
      sym_note_name,
      sym_identifier,
  [1282] = 7,
    ACTIONS(118), 1,
      sym_note_name,
    ACTIONS(264), 1,
      anon_sym_COLON,
    ACTIONS(266), 1,
      anon_sym_SQUOTE,
    ACTIONS(268), 1,
      anon_sym_g,
    STATE(118), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(120), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1310] = 7,
    ACTIONS(130), 1,
      sym_note_name,
    ACTIONS(266), 1,
      anon_sym_SQUOTE,
    ACTIONS(268), 1,
      anon_sym_g,
    ACTIONS(270), 1,
      anon_sym_COLON,
    STATE(116), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(132), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1338] = 6,
    ACTIONS(172), 1,
      sym_note_name,
    ACTIONS(272), 1,
      anon_sym_COLON,
    ACTIONS(274), 1,
      anon_sym_arp,
    STATE(112), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(174), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1363] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(276), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(278), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1382] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(280), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(282), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1401] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(284), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(286), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1420] = 6,
    ACTIONS(288), 1,
      sym_identifier,
    ACTIONS(290), 1,
      anon_sym_RBRACE,
    ACTIONS(292), 1,
      anon_sym_use,
    ACTIONS(294), 1,
      anon_sym_resolution,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(84), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [1445] = 6,
    ACTIONS(118), 1,
      sym_note_name,
    ACTIONS(266), 1,
      anon_sym_SQUOTE,
    ACTIONS(268), 1,
      anon_sym_g,
    STATE(118), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(120), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1470] = 5,
    ACTIONS(296), 1,
      sym_octave,
    STATE(59), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(298), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(300), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [1493] = 6,
    ACTIONS(202), 1,
      sym_note_name,
    ACTIONS(266), 1,
      anon_sym_SQUOTE,
    ACTIONS(268), 1,
      anon_sym_g,
    STATE(107), 1,
      sym_articulation,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(204), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1518] = 6,
    ACTIONS(288), 1,
      sym_identifier,
    ACTIONS(290), 1,
      anon_sym_RBRACE,
    ACTIONS(292), 1,
      anon_sym_use,
    ACTIONS(294), 1,
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
  [1543] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(302), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(304), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1562] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(306), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(308), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1581] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(310), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(312), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1600] = 5,
    ACTIONS(314), 1,
      sym_octave,
    STATE(90), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(298), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(300), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [1623] = 3,
    STATE(38), 1,
      sym_scale_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(316), 9,
      anon_sym_major,
      anon_sym_minor,
      anon_sym_harmonic_minor,
      anon_sym_melodic_minor,
      anon_sym_dorian,
      anon_sym_phrygian,
      anon_sym_lydian,
      anon_sym_mixolydian,
      anon_sym_locrian,
  [1642] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(318), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(320), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1661] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(322), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(324), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1680] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(326), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(328), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1699] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(330), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(332), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1718] = 6,
    ACTIONS(186), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    ACTIONS(334), 1,
      anon_sym_COLON,
    STATE(119), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(188), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1743] = 6,
    ACTIONS(180), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    ACTIONS(336), 1,
      anon_sym_COLON,
    STATE(120), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(182), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1768] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(338), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(340), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1787] = 5,
    ACTIONS(342), 1,
      sym_octave,
    STATE(47), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(344), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(346), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [1810] = 5,
    ACTIONS(348), 1,
      sym_octave,
    STATE(23), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(350), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(352), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [1833] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(354), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(356), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1852] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(358), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(360), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1871] = 5,
    ACTIONS(362), 1,
      sym_octave,
    STATE(43), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(344), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(346), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [1894] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(364), 5,
      anon_sym_use,
      anon_sym_resolution,
      sym_rest,
      sym_note_name,
      sym_identifier,
    ACTIONS(366), 5,
      anon_sym_RBRACE,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_chord_symbol,
      anon_sym_LPAREN,
  [1913] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(252), 3,
      anon_sym_g,
      anon_sym_arp,
      sym_note_name,
    ACTIONS(254), 7,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      anon_sym_SQUOTE,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1932] = 5,
    ACTIONS(368), 1,
      sym_octave,
    STATE(95), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(298), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(300), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [1955] = 6,
    ACTIONS(288), 1,
      sym_identifier,
    ACTIONS(292), 1,
      anon_sym_use,
    ACTIONS(294), 1,
      anon_sym_resolution,
    ACTIONS(370), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(58), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [1980] = 6,
    ACTIONS(372), 1,
      sym_identifier,
    ACTIONS(375), 1,
      anon_sym_RBRACE,
    ACTIONS(377), 1,
      anon_sym_use,
    ACTIONS(380), 1,
      anon_sym_resolution,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(84), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [2005] = 6,
    ACTIONS(288), 1,
      sym_identifier,
    ACTIONS(292), 1,
      anon_sym_use,
    ACTIONS(294), 1,
      anon_sym_resolution,
    ACTIONS(383), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(84), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [2030] = 3,
    STATE(168), 1,
      sym_scale_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(316), 9,
      anon_sym_major,
      anon_sym_minor,
      anon_sym_harmonic_minor,
      anon_sym_melodic_minor,
      anon_sym_dorian,
      anon_sym_phrygian,
      anon_sym_lydian,
      anon_sym_mixolydian,
      anon_sym_locrian,
  [2049] = 6,
    ACTIONS(194), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    ACTIONS(385), 1,
      anon_sym_COLON,
    STATE(114), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(196), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2074] = 5,
    ACTIONS(222), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    STATE(105), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(224), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2096] = 5,
    ACTIONS(230), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    STATE(109), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(232), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2118] = 5,
    ACTIONS(172), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    STATE(112), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(174), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2140] = 4,
    STATE(35), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(344), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(346), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2160] = 4,
    STATE(89), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(298), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(300), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2180] = 4,
    STATE(32), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(344), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(346), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2200] = 4,
    STATE(88), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(298), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(300), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2220] = 5,
    ACTIONS(186), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    STATE(119), 1,
      sym_arp_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(188), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2242] = 4,
    STATE(61), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(298), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(300), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2262] = 4,
    STATE(22), 1,
      sym_duration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(350), 3,
      anon_sym_1,
      anon_sym_4,
      anon_sym_8,
    ACTIONS(352), 5,
      anon_sym_2,
      anon_sym_4_DOT,
      anon_sym_8_DOT,
      anon_sym_16,
      anon_sym_32,
  [2282] = 6,
    ACTIONS(387), 1,
      anon_sym_device,
    ACTIONS(389), 1,
      anon_sym_RBRACE,
    ACTIONS(393), 1,
      anon_sym_note,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(101), 2,
      sym_instrument_property,
      aux_sym_instrument_def_repeat1,
    ACTIONS(391), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2305] = 6,
    ACTIONS(387), 1,
      anon_sym_device,
    ACTIONS(393), 1,
      anon_sym_note,
    ACTIONS(395), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(98), 2,
      sym_instrument_property,
      aux_sym_instrument_def_repeat1,
    ACTIONS(391), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2328] = 4,
    ACTIONS(258), 1,
      sym_note_name,
    ACTIONS(397), 1,
      anon_sym_STAR,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(260), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2347] = 6,
    ACTIONS(399), 1,
      anon_sym_device,
    ACTIONS(402), 1,
      anon_sym_RBRACE,
    ACTIONS(407), 1,
      anon_sym_note,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(101), 2,
      sym_instrument_property,
      aux_sym_instrument_def_repeat1,
    ACTIONS(404), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2370] = 5,
    ACTIONS(410), 1,
      sym_identifier,
    ACTIONS(412), 1,
      anon_sym_RBRACE,
    ACTIONS(414), 1,
      anon_sym_tempo,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(121), 4,
      sym__scene_content,
      sym_scene_slot,
      sym_scene_tempo,
      aux_sym_scene_def_repeat1,
  [2390] = 5,
    ACTIONS(416), 1,
      anon_sym_RBRACE,
    ACTIONS(421), 1,
      anon_sym_note,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(103), 2,
      sym_kit_instrument_property,
      aux_sym_kit_instrument_repeat1,
    ACTIONS(418), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2410] = 5,
    ACTIONS(424), 1,
      sym_identifier,
    ACTIONS(427), 1,
      anon_sym_RBRACE,
    ACTIONS(429), 1,
      anon_sym_tempo,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(104), 4,
      sym__scene_content,
      sym_scene_slot,
      sym_scene_tempo,
      aux_sym_scene_def_repeat1,
  [2430] = 3,
    ACTIONS(330), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(332), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2446] = 3,
    ACTIONS(318), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(320), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2462] = 3,
    ACTIONS(310), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(312), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2478] = 3,
    ACTIONS(280), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(282), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2494] = 3,
    ACTIONS(302), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(304), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2510] = 3,
    ACTIONS(326), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(328), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2526] = 5,
    ACTIONS(432), 1,
      anon_sym_RBRACE,
    ACTIONS(436), 1,
      anon_sym_note,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(103), 2,
      sym_kit_instrument_property,
      aux_sym_kit_instrument_repeat1,
    ACTIONS(434), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2546] = 3,
    ACTIONS(338), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(340), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2562] = 3,
    ACTIONS(364), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(366), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2578] = 3,
    ACTIONS(354), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(356), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2594] = 5,
    ACTIONS(438), 1,
      anon_sym_bars,
    ACTIONS(440), 1,
      anon_sym_time,
    ACTIONS(442), 1,
      anon_sym_scale,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(181), 4,
      sym__clip_attr,
      sym_bars_attr,
      sym_time_attr,
      sym_scale_attr,
  [2614] = 3,
    ACTIONS(322), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(324), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2630] = 5,
    ACTIONS(436), 1,
      anon_sym_note,
    ACTIONS(444), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(111), 2,
      sym_kit_instrument_property,
      aux_sym_kit_instrument_repeat1,
    ACTIONS(434), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2650] = 3,
    ACTIONS(284), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(286), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2666] = 3,
    ACTIONS(306), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(308), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2682] = 3,
    ACTIONS(276), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(278), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2698] = 5,
    ACTIONS(410), 1,
      sym_identifier,
    ACTIONS(414), 1,
      anon_sym_tempo,
    ACTIONS(446), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(104), 4,
      sym__scene_content,
      sym_scene_slot,
      sym_scene_tempo,
      aux_sym_scene_def_repeat1,
  [2718] = 3,
    ACTIONS(358), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(360), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2734] = 6,
    ACTIONS(450), 1,
      anon_sym_RBRACE,
    ACTIONS(452), 1,
      sym_probability,
    ACTIONS(454), 1,
      anon_sym_PIPE,
    STATE(154), 1,
      sym_shuffle_expr,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(448), 2,
      anon_sym_tempo,
      sym_identifier,
  [2755] = 5,
    ACTIONS(456), 1,
      sym_identifier,
    ACTIONS(459), 1,
      anon_sym_device,
    ACTIONS(462), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(124), 3,
      sym__kit_member,
      sym_kit_instrument,
      aux_sym_kit_def_repeat1,
  [2774] = 5,
    ACTIONS(464), 1,
      sym_identifier,
    ACTIONS(466), 1,
      anon_sym_device,
    ACTIONS(468), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(127), 3,
      sym__kit_member,
      sym_kit_instrument,
      aux_sym_kit_def_repeat1,
  [2793] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(470), 6,
      anon_sym_device,
      anon_sym_RBRACE,
      anon_sym_channel,
      anon_sym_note,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2806] = 5,
    ACTIONS(464), 1,
      sym_identifier,
    ACTIONS(466), 1,
      anon_sym_device,
    ACTIONS(472), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(124), 3,
      sym__kit_member,
      sym_kit_instrument,
      aux_sym_kit_def_repeat1,
  [2825] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(474), 5,
      anon_sym_RBRACE,
      anon_sym_channel,
      anon_sym_note,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2837] = 5,
    ACTIONS(478), 1,
      anon_sym_RBRACE,
    ACTIONS(480), 1,
      anon_sym_STAR,
    STATE(152), 1,
      sym_weight,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(476), 2,
      anon_sym_tempo,
      sym_identifier,
  [2855] = 4,
    ACTIONS(482), 1,
      anon_sym_up,
    STATE(219), 1,
      sym_arp_direction,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(484), 3,
      anon_sym_down,
      anon_sym_updown,
      anon_sym_random,
  [2871] = 4,
    ACTIONS(482), 1,
      anon_sym_up,
    STATE(185), 1,
      sym_arp_direction,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(484), 3,
      anon_sym_down,
      anon_sym_updown,
      anon_sym_random,
  [2887] = 4,
    ACTIONS(486), 1,
      sym_identifier,
    ACTIONS(488), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(134), 2,
      sym_session_entry,
      aux_sym_session_def_repeat1,
  [2902] = 4,
    ACTIONS(492), 1,
      anon_sym_LBRACK,
    STATE(165), 1,
      sym_session_modifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(490), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [2917] = 4,
    ACTIONS(486), 1,
      sym_identifier,
    ACTIONS(494), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(144), 2,
      sym_session_entry,
      aux_sym_session_def_repeat1,
  [2932] = 4,
    ACTIONS(496), 1,
      anon_sym_RBRACE,
    ACTIONS(498), 1,
      anon_sym_port,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(137), 2,
      sym_device_property,
      aux_sym_device_def_repeat1,
  [2947] = 4,
    ACTIONS(500), 1,
      anon_sym_LBRACE,
    ACTIONS(502), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(146), 2,
      sym_clip_header,
      aux_sym_clip_def_repeat1,
  [2962] = 4,
    ACTIONS(504), 1,
      anon_sym_RBRACE,
    ACTIONS(506), 1,
      anon_sym_port,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(137), 2,
      sym_device_property,
      aux_sym_device_def_repeat1,
  [2977] = 4,
    ACTIONS(509), 1,
      anon_sym_RBRACK,
    STATE(138), 1,
      aux_sym_chord_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(511), 2,
      sym_rest,
      sym_note_name,
  [2992] = 4,
    ACTIONS(498), 1,
      anon_sym_port,
    ACTIONS(514), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(135), 2,
      sym_device_property,
      aux_sym_device_def_repeat1,
  [3007] = 3,
    ACTIONS(518), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(516), 3,
      anon_sym_use,
      anon_sym_resolution,
      sym_identifier,
  [3020] = 4,
    ACTIONS(502), 1,
      anon_sym_LBRACK,
    ACTIONS(520), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(136), 2,
      sym_clip_header,
      aux_sym_clip_def_repeat1,
  [3035] = 4,
    ACTIONS(522), 1,
      anon_sym_RBRACK,
    STATE(138), 1,
      aux_sym_chord_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(524), 2,
      sym_rest,
      sym_note_name,
  [3050] = 3,
    ACTIONS(528), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(526), 3,
      anon_sym_use,
      anon_sym_resolution,
      sym_identifier,
  [3063] = 4,
    ACTIONS(530), 1,
      sym_identifier,
    ACTIONS(533), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(144), 2,
      sym_session_entry,
      aux_sym_session_def_repeat1,
  [3078] = 3,
    ACTIONS(537), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(535), 3,
      anon_sym_use,
      anon_sym_resolution,
      sym_identifier,
  [3091] = 4,
    ACTIONS(539), 1,
      anon_sym_LBRACE,
    ACTIONS(541), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(146), 2,
      sym_clip_header,
      aux_sym_clip_def_repeat1,
  [3106] = 4,
    ACTIONS(544), 1,
      anon_sym_RBRACK,
    STATE(138), 1,
      aux_sym_chord_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(524), 2,
      sym_rest,
      sym_note_name,
  [3121] = 3,
    ACTIONS(548), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(546), 2,
      anon_sym_device,
      sym_identifier,
  [3133] = 3,
    ACTIONS(552), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(550), 2,
      anon_sym_device,
      sym_identifier,
  [3145] = 3,
    STATE(147), 1,
      aux_sym_chord_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(554), 2,
      sym_rest,
      sym_note_name,
  [3157] = 3,
    ACTIONS(558), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(556), 2,
      anon_sym_tempo,
      sym_identifier,
  [3169] = 3,
    ACTIONS(562), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(560), 2,
      anon_sym_tempo,
      sym_identifier,
  [3181] = 3,
    ACTIONS(566), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(564), 2,
      anon_sym_device,
      sym_identifier,
  [3193] = 3,
    ACTIONS(570), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(568), 2,
      anon_sym_tempo,
      sym_identifier,
  [3205] = 3,
    ACTIONS(574), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(572), 2,
      anon_sym_tempo,
      sym_identifier,
  [3217] = 3,
    STATE(142), 1,
      aux_sym_chord_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(576), 2,
      sym_rest,
      sym_note_name,
  [3229] = 3,
    ACTIONS(578), 1,
      anon_sym_repeat,
    ACTIONS(580), 1,
      anon_sym_loop,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3240] = 3,
    ACTIONS(582), 1,
      sym_identifier,
    ACTIONS(584), 1,
      anon_sym_session,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3251] = 3,
    ACTIONS(586), 1,
      anon_sym_repeat,
    ACTIONS(588), 1,
      anon_sym_loop,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3262] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(590), 2,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
  [3271] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(210), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [3280] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(240), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [3289] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(592), 2,
      anon_sym_RBRACE,
      anon_sym_port,
  [3298] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(594), 2,
      sym_tempo_delta,
      sym_number,
  [3307] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(596), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [3316] = 2,
    ACTIONS(598), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3324] = 2,
    ACTIONS(600), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3332] = 2,
    ACTIONS(602), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3340] = 2,
    ACTIONS(604), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3348] = 2,
    ACTIONS(606), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3356] = 2,
    ACTIONS(608), 1,
      anon_sym_COMMA,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3364] = 2,
    ACTIONS(610), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3372] = 2,
    ACTIONS(612), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3380] = 2,
    ACTIONS(614), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3388] = 2,
    ACTIONS(616), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3396] = 2,
    ACTIONS(618), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3404] = 2,
    ACTIONS(620), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3412] = 2,
    ACTIONS(622), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3420] = 2,
    ACTIONS(624), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3428] = 2,
    ACTIONS(626), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3436] = 2,
    ACTIONS(628), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3444] = 2,
    ACTIONS(630), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3452] = 2,
    ACTIONS(632), 1,
      sym_time_signature,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3460] = 2,
    ACTIONS(634), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3468] = 2,
    ACTIONS(636), 1,
      anon_sym_COMMA,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3476] = 2,
    ACTIONS(638), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3484] = 2,
    ACTIONS(640), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3492] = 2,
    ACTIONS(642), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3500] = 2,
    ACTIONS(644), 1,
      sym_note_literal,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3508] = 2,
    ACTIONS(644), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3516] = 2,
    ACTIONS(644), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3524] = 2,
    ACTIONS(646), 1,
      sym_string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3532] = 2,
    ACTIONS(648), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3540] = 2,
    ACTIONS(650), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3548] = 2,
    ACTIONS(652), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3556] = 2,
    ACTIONS(654), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3564] = 2,
    ACTIONS(656), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3572] = 2,
    ACTIONS(658), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3580] = 2,
    ACTIONS(660), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3588] = 2,
    ACTIONS(662), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3596] = 2,
    ACTIONS(664), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3604] = 2,
    ACTIONS(666), 1,
      sym_string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3612] = 2,
    ACTIONS(668), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3620] = 2,
    ACTIONS(670), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3628] = 2,
    ACTIONS(672), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3636] = 2,
    ACTIONS(674), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3644] = 2,
    ACTIONS(676), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3652] = 2,
    ACTIONS(678), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3660] = 2,
    ACTIONS(680), 1,
      sym_note_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3668] = 2,
    ACTIONS(682), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3676] = 2,
    ACTIONS(684), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3684] = 2,
    ACTIONS(686), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3692] = 2,
    ACTIONS(688), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3700] = 2,
    ACTIONS(690), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3708] = 2,
    ACTIONS(692), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3716] = 2,
    ACTIONS(604), 1,
      sym_note_literal,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3724] = 2,
    ACTIONS(694), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3732] = 2,
    ACTIONS(696), 1,
      sym_number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3740] = 2,
    ACTIONS(698), 1,
      anon_sym_COMMA,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3748] = 2,
    ACTIONS(700), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3756] = 2,
    ACTIONS(702), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 56,
  [SMALL_STATE(4)] = 112,
  [SMALL_STATE(5)] = 152,
  [SMALL_STATE(6)] = 192,
  [SMALL_STATE(7)] = 227,
  [SMALL_STATE(8)] = 258,
  [SMALL_STATE(9)] = 293,
  [SMALL_STATE(10)] = 324,
  [SMALL_STATE(11)] = 349,
  [SMALL_STATE(12)] = 374,
  [SMALL_STATE(13)] = 409,
  [SMALL_STATE(14)] = 444,
  [SMALL_STATE(15)] = 468,
  [SMALL_STATE(16)] = 500,
  [SMALL_STATE(17)] = 528,
  [SMALL_STATE(18)] = 556,
  [SMALL_STATE(19)] = 584,
  [SMALL_STATE(20)] = 604,
  [SMALL_STATE(21)] = 632,
  [SMALL_STATE(22)] = 664,
  [SMALL_STATE(23)] = 692,
  [SMALL_STATE(24)] = 720,
  [SMALL_STATE(25)] = 739,
  [SMALL_STATE(26)] = 758,
  [SMALL_STATE(27)] = 777,
  [SMALL_STATE(28)] = 796,
  [SMALL_STATE(29)] = 815,
  [SMALL_STATE(30)] = 834,
  [SMALL_STATE(31)] = 853,
  [SMALL_STATE(32)] = 872,
  [SMALL_STATE(33)] = 897,
  [SMALL_STATE(34)] = 916,
  [SMALL_STATE(35)] = 935,
  [SMALL_STATE(36)] = 960,
  [SMALL_STATE(37)] = 979,
  [SMALL_STATE(38)] = 998,
  [SMALL_STATE(39)] = 1017,
  [SMALL_STATE(40)] = 1036,
  [SMALL_STATE(41)] = 1055,
  [SMALL_STATE(42)] = 1074,
  [SMALL_STATE(43)] = 1093,
  [SMALL_STATE(44)] = 1118,
  [SMALL_STATE(45)] = 1137,
  [SMALL_STATE(46)] = 1156,
  [SMALL_STATE(47)] = 1175,
  [SMALL_STATE(48)] = 1200,
  [SMALL_STATE(49)] = 1221,
  [SMALL_STATE(50)] = 1240,
  [SMALL_STATE(51)] = 1262,
  [SMALL_STATE(52)] = 1282,
  [SMALL_STATE(53)] = 1310,
  [SMALL_STATE(54)] = 1338,
  [SMALL_STATE(55)] = 1363,
  [SMALL_STATE(56)] = 1382,
  [SMALL_STATE(57)] = 1401,
  [SMALL_STATE(58)] = 1420,
  [SMALL_STATE(59)] = 1445,
  [SMALL_STATE(60)] = 1470,
  [SMALL_STATE(61)] = 1493,
  [SMALL_STATE(62)] = 1518,
  [SMALL_STATE(63)] = 1543,
  [SMALL_STATE(64)] = 1562,
  [SMALL_STATE(65)] = 1581,
  [SMALL_STATE(66)] = 1600,
  [SMALL_STATE(67)] = 1623,
  [SMALL_STATE(68)] = 1642,
  [SMALL_STATE(69)] = 1661,
  [SMALL_STATE(70)] = 1680,
  [SMALL_STATE(71)] = 1699,
  [SMALL_STATE(72)] = 1718,
  [SMALL_STATE(73)] = 1743,
  [SMALL_STATE(74)] = 1768,
  [SMALL_STATE(75)] = 1787,
  [SMALL_STATE(76)] = 1810,
  [SMALL_STATE(77)] = 1833,
  [SMALL_STATE(78)] = 1852,
  [SMALL_STATE(79)] = 1871,
  [SMALL_STATE(80)] = 1894,
  [SMALL_STATE(81)] = 1913,
  [SMALL_STATE(82)] = 1932,
  [SMALL_STATE(83)] = 1955,
  [SMALL_STATE(84)] = 1980,
  [SMALL_STATE(85)] = 2005,
  [SMALL_STATE(86)] = 2030,
  [SMALL_STATE(87)] = 2049,
  [SMALL_STATE(88)] = 2074,
  [SMALL_STATE(89)] = 2096,
  [SMALL_STATE(90)] = 2118,
  [SMALL_STATE(91)] = 2140,
  [SMALL_STATE(92)] = 2160,
  [SMALL_STATE(93)] = 2180,
  [SMALL_STATE(94)] = 2200,
  [SMALL_STATE(95)] = 2220,
  [SMALL_STATE(96)] = 2242,
  [SMALL_STATE(97)] = 2262,
  [SMALL_STATE(98)] = 2282,
  [SMALL_STATE(99)] = 2305,
  [SMALL_STATE(100)] = 2328,
  [SMALL_STATE(101)] = 2347,
  [SMALL_STATE(102)] = 2370,
  [SMALL_STATE(103)] = 2390,
  [SMALL_STATE(104)] = 2410,
  [SMALL_STATE(105)] = 2430,
  [SMALL_STATE(106)] = 2446,
  [SMALL_STATE(107)] = 2462,
  [SMALL_STATE(108)] = 2478,
  [SMALL_STATE(109)] = 2494,
  [SMALL_STATE(110)] = 2510,
  [SMALL_STATE(111)] = 2526,
  [SMALL_STATE(112)] = 2546,
  [SMALL_STATE(113)] = 2562,
  [SMALL_STATE(114)] = 2578,
  [SMALL_STATE(115)] = 2594,
  [SMALL_STATE(116)] = 2614,
  [SMALL_STATE(117)] = 2630,
  [SMALL_STATE(118)] = 2650,
  [SMALL_STATE(119)] = 2666,
  [SMALL_STATE(120)] = 2682,
  [SMALL_STATE(121)] = 2698,
  [SMALL_STATE(122)] = 2718,
  [SMALL_STATE(123)] = 2734,
  [SMALL_STATE(124)] = 2755,
  [SMALL_STATE(125)] = 2774,
  [SMALL_STATE(126)] = 2793,
  [SMALL_STATE(127)] = 2806,
  [SMALL_STATE(128)] = 2825,
  [SMALL_STATE(129)] = 2837,
  [SMALL_STATE(130)] = 2855,
  [SMALL_STATE(131)] = 2871,
  [SMALL_STATE(132)] = 2887,
  [SMALL_STATE(133)] = 2902,
  [SMALL_STATE(134)] = 2917,
  [SMALL_STATE(135)] = 2932,
  [SMALL_STATE(136)] = 2947,
  [SMALL_STATE(137)] = 2962,
  [SMALL_STATE(138)] = 2977,
  [SMALL_STATE(139)] = 2992,
  [SMALL_STATE(140)] = 3007,
  [SMALL_STATE(141)] = 3020,
  [SMALL_STATE(142)] = 3035,
  [SMALL_STATE(143)] = 3050,
  [SMALL_STATE(144)] = 3063,
  [SMALL_STATE(145)] = 3078,
  [SMALL_STATE(146)] = 3091,
  [SMALL_STATE(147)] = 3106,
  [SMALL_STATE(148)] = 3121,
  [SMALL_STATE(149)] = 3133,
  [SMALL_STATE(150)] = 3145,
  [SMALL_STATE(151)] = 3157,
  [SMALL_STATE(152)] = 3169,
  [SMALL_STATE(153)] = 3181,
  [SMALL_STATE(154)] = 3193,
  [SMALL_STATE(155)] = 3205,
  [SMALL_STATE(156)] = 3217,
  [SMALL_STATE(157)] = 3229,
  [SMALL_STATE(158)] = 3240,
  [SMALL_STATE(159)] = 3251,
  [SMALL_STATE(160)] = 3262,
  [SMALL_STATE(161)] = 3271,
  [SMALL_STATE(162)] = 3280,
  [SMALL_STATE(163)] = 3289,
  [SMALL_STATE(164)] = 3298,
  [SMALL_STATE(165)] = 3307,
  [SMALL_STATE(166)] = 3316,
  [SMALL_STATE(167)] = 3324,
  [SMALL_STATE(168)] = 3332,
  [SMALL_STATE(169)] = 3340,
  [SMALL_STATE(170)] = 3348,
  [SMALL_STATE(171)] = 3356,
  [SMALL_STATE(172)] = 3364,
  [SMALL_STATE(173)] = 3372,
  [SMALL_STATE(174)] = 3380,
  [SMALL_STATE(175)] = 3388,
  [SMALL_STATE(176)] = 3396,
  [SMALL_STATE(177)] = 3404,
  [SMALL_STATE(178)] = 3412,
  [SMALL_STATE(179)] = 3420,
  [SMALL_STATE(180)] = 3428,
  [SMALL_STATE(181)] = 3436,
  [SMALL_STATE(182)] = 3444,
  [SMALL_STATE(183)] = 3452,
  [SMALL_STATE(184)] = 3460,
  [SMALL_STATE(185)] = 3468,
  [SMALL_STATE(186)] = 3476,
  [SMALL_STATE(187)] = 3484,
  [SMALL_STATE(188)] = 3492,
  [SMALL_STATE(189)] = 3500,
  [SMALL_STATE(190)] = 3508,
  [SMALL_STATE(191)] = 3516,
  [SMALL_STATE(192)] = 3524,
  [SMALL_STATE(193)] = 3532,
  [SMALL_STATE(194)] = 3540,
  [SMALL_STATE(195)] = 3548,
  [SMALL_STATE(196)] = 3556,
  [SMALL_STATE(197)] = 3564,
  [SMALL_STATE(198)] = 3572,
  [SMALL_STATE(199)] = 3580,
  [SMALL_STATE(200)] = 3588,
  [SMALL_STATE(201)] = 3596,
  [SMALL_STATE(202)] = 3604,
  [SMALL_STATE(203)] = 3612,
  [SMALL_STATE(204)] = 3620,
  [SMALL_STATE(205)] = 3628,
  [SMALL_STATE(206)] = 3636,
  [SMALL_STATE(207)] = 3644,
  [SMALL_STATE(208)] = 3652,
  [SMALL_STATE(209)] = 3660,
  [SMALL_STATE(210)] = 3668,
  [SMALL_STATE(211)] = 3676,
  [SMALL_STATE(212)] = 3684,
  [SMALL_STATE(213)] = 3692,
  [SMALL_STATE(214)] = 3700,
  [SMALL_STATE(215)] = 3708,
  [SMALL_STATE(216)] = 3716,
  [SMALL_STATE(217)] = 3724,
  [SMALL_STATE(218)] = 3732,
  [SMALL_STATE(219)] = 3740,
  [SMALL_STATE(220)] = 3748,
  [SMALL_STATE(221)] = 3756,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [33] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(172),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(220),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(217),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(212),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(209),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(208),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(207),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(206),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(202),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(158),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [66] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_melody_line, 2, 0, 3),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_melody_line, 2, 0, 3),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [80] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(156),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(178),
  [92] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(20),
  [98] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [101] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitched_note, 3, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitched_note, 3, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(170),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitched_note, 1, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitched_note, 1, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_play_stmt, 3, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_play_stmt, 2, 0, 0),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(150),
  [145] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(204),
  [148] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [151] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(87),
  [154] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [157] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_melody_line_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [160] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stop_stmt, 1, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_stop_stmt, 1, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 5, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 5, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(214),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord_name, 3, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord_name, 3, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scale_type, 1, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord_name, 1, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord_name, 1, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitched_note, 5, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitched_note, 5, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_device_def, 5, 0, 1),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_play_stmt, 4, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_session_modifier, 3, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tempo_stmt, 2, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_session_def, 5, 0, 1),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_stmt, 2, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_def, 5, 0, 1),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stop_stmt, 2, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 7, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 7, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_clip_def, 4, 0, 1),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_clip_def, 5, 0, 1),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord_name, 5, 0, 0),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord_name, 5, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kit_def, 5, 0, 1),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instrument_def, 5, 0, 1),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scale_stmt, 3, 0, 0),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_session_modifier, 4, 0, 0),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_session_def, 4, 0, 1),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_device_def, 4, 0, 1),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_clip_def, 6, 0, 1),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instrument_def, 4, 0, 1),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kit_def, 4, 0, 1),
  [252] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_duration, 1, 0, 0),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 1, 0, 0),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_def, 4, 0, 1),
  [258] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_melody_group, 3, 0, 0),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_melody_group, 3, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [268] = {.entry = {.count = 1, .reusable = false}}, SHIFT(210),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [274] = {.entry = {.count = 1, .reusable = false}}, SHIFT(221),
  [276] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, 0, 0),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, 0, 0),
  [280] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bar_jump, 2, 0, 0),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bar_jump, 2, 0, 0),
  [284] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitched_note, 4, 0, 0),
  [286] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitched_note, 4, 0, 0),
  [288] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [292] = {.entry = {.count = 1, .reusable = false}}, SHIFT(186),
  [294] = {.entry = {.count = 1, .reusable = false}}, SHIFT(166),
  [296] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [298] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [302] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord_name, 6, 0, 0),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord_name, 6, 0, 0),
  [306] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord_name, 4, 0, 0),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord_name, 4, 0, 0),
  [310] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitched_note, 6, 0, 0),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitched_note, 6, 0, 0),
  [314] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [318] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arp_expr, 6, 0, 0),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arp_expr, 6, 0, 0),
  [322] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitched_note, 2, 0, 0),
  [324] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitched_note, 2, 0, 0),
  [326] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_articulation, 1, 0, 0),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_articulation, 1, 0, 0),
  [330] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 8, 0, 0),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 8, 0, 0),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [338] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 6, 0, 0),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 6, 0, 0),
  [342] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [344] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [348] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [350] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [354] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord_name, 2, 0, 0),
  [356] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord_name, 2, 0, 0),
  [358] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_articulation, 2, 0, 0),
  [360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_articulation, 2, 0, 0),
  [362] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [364] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_melody_group, 5, 0, 0),
  [366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_melody_group, 5, 0, 0),
  [368] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [372] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_clip_def_repeat2, 2, 0, 0), SHIFT_REPEAT(13),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_clip_def_repeat2, 2, 0, 0),
  [377] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_clip_def_repeat2, 2, 0, 0), SHIFT_REPEAT(186),
  [380] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_clip_def_repeat2, 2, 0, 0), SHIFT_REPEAT(166),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [399] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_instrument_def_repeat1, 2, 0, 0), SHIFT_REPEAT(191),
  [402] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_instrument_def_repeat1, 2, 0, 0),
  [404] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_instrument_def_repeat1, 2, 0, 0), SHIFT_REPEAT(190),
  [407] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_instrument_def_repeat1, 2, 0, 0), SHIFT_REPEAT(189),
  [410] = {.entry = {.count = 1, .reusable = false}}, SHIFT(123),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [414] = {.entry = {.count = 1, .reusable = false}}, SHIFT(164),
  [416] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_kit_instrument_repeat1, 2, 0, 0),
  [418] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_kit_instrument_repeat1, 2, 0, 0), SHIFT_REPEAT(169),
  [421] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_kit_instrument_repeat1, 2, 0, 0), SHIFT_REPEAT(216),
  [424] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_scene_def_repeat1, 2, 0, 0), SHIFT_REPEAT(123),
  [427] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_scene_def_repeat1, 2, 0, 0),
  [429] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_scene_def_repeat1, 2, 0, 0), SHIFT_REPEAT(164),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [448] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_slot, 1, 0, 0),
  [450] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_slot, 1, 0, 0),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [456] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_kit_def_repeat1, 2, 0, 0), SHIFT_REPEAT(187),
  [459] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_kit_def_repeat1, 2, 0, 0), SHIFT_REPEAT(188),
  [462] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_kit_def_repeat1, 2, 0, 0),
  [464] = {.entry = {.count = 1, .reusable = false}}, SHIFT(187),
  [466] = {.entry = {.count = 1, .reusable = false}}, SHIFT(188),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instrument_property, 2, 0, 0),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [474] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kit_instrument_property, 2, 0, 0),
  [476] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_shuffle_expr, 2, 0, 0),
  [478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shuffle_expr, 2, 0, 0),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [482] = {.entry = {.count = 1, .reusable = false}}, SHIFT(171),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [490] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_session_entry, 1, 0, 0),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [504] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_device_def_repeat1, 2, 0, 0),
  [506] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_device_def_repeat1, 2, 0, 0), SHIFT_REPEAT(192),
  [509] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_chord_repeat1, 2, 0, 0),
  [511] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_chord_repeat1, 2, 0, 0), SHIFT_REPEAT(138),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [516] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_drum_line, 2, 0, 3),
  [518] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_drum_line, 2, 0, 3),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [526] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_resolution_stmt, 2, 0, 0),
  [528] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_resolution_stmt, 2, 0, 0),
  [530] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_session_def_repeat1, 2, 0, 0), SHIFT_REPEAT(133),
  [533] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_session_def_repeat1, 2, 0, 0),
  [535] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_use_stmt, 2, 0, 2),
  [537] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_use_stmt, 2, 0, 2),
  [539] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_clip_def_repeat1, 2, 0, 0),
  [541] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_clip_def_repeat1, 2, 0, 0), SHIFT_REPEAT(115),
  [544] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [546] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_kit_instrument, 3, 0, 4),
  [548] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kit_instrument, 3, 0, 4),
  [550] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__kit_member, 2, 0, 0),
  [552] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__kit_member, 2, 0, 0),
  [554] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [556] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_weight, 2, 0, 0),
  [558] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_weight, 2, 0, 0),
  [560] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_shuffle_expr, 3, 0, 0),
  [562] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_shuffle_expr, 3, 0, 0),
  [564] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_kit_instrument, 4, 0, 4),
  [566] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kit_instrument, 4, 0, 4),
  [568] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_slot, 2, 0, 0),
  [570] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_slot, 2, 0, 0),
  [572] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_tempo, 2, 0, 0),
  [574] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_tempo, 2, 0, 0),
  [576] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [578] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [580] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [582] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [584] = {.entry = {.count = 1, .reusable = false}}, SHIFT(194),
  [586] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [588] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [590] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_clip_header, 3, 0, 0),
  [592] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_device_property, 2, 0, 0),
  [594] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [596] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_session_entry, 2, 0, 0),
  [598] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [600] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [602] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scale_attr, 3, 0, 0),
  [604] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [608] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arp_direction, 1, 0, 0),
  [610] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [612] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [614] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [616] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [618] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time_attr, 2, 0, 0),
  [620] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bars_attr, 2, 0, 0),
  [622] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [624] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [626] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [628] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [630] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [632] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [634] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [636] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [638] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [640] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [642] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [644] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [646] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [648] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [650] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [652] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [654] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [656] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [658] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [660] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [662] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [664] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [666] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [668] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [670] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [672] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [674] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [676] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [678] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [680] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [682] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [684] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [686] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [688] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [690] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [692] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [694] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [696] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [698] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [700] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [702] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
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
