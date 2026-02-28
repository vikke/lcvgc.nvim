#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 222
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 128
#define ALIAS_COUNT 0
#define TOKEN_COUNT 71
#define EXTERNAL_TOKEN_COUNT 0
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
  sym_source_file = 71,
  sym__top_level = 72,
  sym_device_def = 73,
  sym_device_property = 74,
  sym_instrument_def = 75,
  sym_instrument_property = 76,
  sym_kit_def = 77,
  sym__kit_member = 78,
  sym_kit_instrument = 79,
  sym_kit_instrument_property = 80,
  sym_clip_def = 81,
  sym_clip_header = 82,
  sym__clip_attr = 83,
  sym_bars_attr = 84,
  sym_time_attr = 85,
  sym_scale_attr = 86,
  sym_scale_type = 87,
  sym__clip_content = 88,
  sym_use_stmt = 89,
  sym_resolution_stmt = 90,
  sym_drum_line = 91,
  sym_melody_line = 92,
  sym__melody_element = 93,
  sym_bar_jump = 94,
  sym_pitched_note = 95,
  sym_duration = 96,
  sym_articulation = 97,
  sym_chord = 98,
  sym_chord_name = 99,
  sym_arp_expr = 100,
  sym_arp_direction = 101,
  sym_melody_group = 102,
  sym_scene_def = 103,
  sym__scene_content = 104,
  sym_scene_slot = 105,
  sym_shuffle_expr = 106,
  sym_weight = 107,
  sym_scene_tempo = 108,
  sym_session_def = 109,
  sym_session_entry = 110,
  sym_session_modifier = 111,
  sym_include_stmt = 112,
  sym_tempo_stmt = 113,
  sym_scale_stmt = 114,
  sym_play_stmt = 115,
  sym_stop_stmt = 116,
  aux_sym_source_file_repeat1 = 117,
  aux_sym_device_def_repeat1 = 118,
  aux_sym_instrument_def_repeat1 = 119,
  aux_sym_kit_def_repeat1 = 120,
  aux_sym_kit_instrument_repeat1 = 121,
  aux_sym_clip_def_repeat1 = 122,
  aux_sym_clip_def_repeat2 = 123,
  aux_sym_melody_line_repeat1 = 124,
  aux_sym_chord_repeat1 = 125,
  aux_sym_scene_def_repeat1 = 126,
  aux_sym_session_def_repeat1 = 127,
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
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 27},
  [2] = {.lex_state = 27},
  [3] = {.lex_state = 27},
  [4] = {.lex_state = 4},
  [5] = {.lex_state = 4},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 3},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 3},
  [10] = {.lex_state = 27},
  [11] = {.lex_state = 27},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 5},
  [14] = {.lex_state = 27},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 4},
  [17] = {.lex_state = 4},
  [18] = {.lex_state = 4},
  [19] = {.lex_state = 27},
  [20] = {.lex_state = 4},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 3},
  [23] = {.lex_state = 3},
  [24] = {.lex_state = 27},
  [25] = {.lex_state = 27},
  [26] = {.lex_state = 27},
  [27] = {.lex_state = 27},
  [28] = {.lex_state = 27},
  [29] = {.lex_state = 27},
  [30] = {.lex_state = 27},
  [31] = {.lex_state = 27},
  [32] = {.lex_state = 4},
  [33] = {.lex_state = 27},
  [34] = {.lex_state = 27},
  [35] = {.lex_state = 4},
  [36] = {.lex_state = 27},
  [37] = {.lex_state = 27},
  [38] = {.lex_state = 27},
  [39] = {.lex_state = 27},
  [40] = {.lex_state = 27},
  [41] = {.lex_state = 27},
  [42] = {.lex_state = 27},
  [43] = {.lex_state = 4},
  [44] = {.lex_state = 27},
  [45] = {.lex_state = 27},
  [46] = {.lex_state = 27},
  [47] = {.lex_state = 4},
  [48] = {.lex_state = 3},
  [49] = {.lex_state = 27},
  [50] = {.lex_state = 4},
  [51] = {.lex_state = 4},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 2},
  [54] = {.lex_state = 4},
  [55] = {.lex_state = 4},
  [56] = {.lex_state = 4},
  [57] = {.lex_state = 4},
  [58] = {.lex_state = 27},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 27},
  [61] = {.lex_state = 2},
  [62] = {.lex_state = 27},
  [63] = {.lex_state = 4},
  [64] = {.lex_state = 4},
  [65] = {.lex_state = 4},
  [66] = {.lex_state = 27},
  [67] = {.lex_state = 27},
  [68] = {.lex_state = 4},
  [69] = {.lex_state = 4},
  [70] = {.lex_state = 4},
  [71] = {.lex_state = 4},
  [72] = {.lex_state = 4},
  [73] = {.lex_state = 4},
  [74] = {.lex_state = 4},
  [75] = {.lex_state = 27},
  [76] = {.lex_state = 27},
  [77] = {.lex_state = 4},
  [78] = {.lex_state = 4},
  [79] = {.lex_state = 27},
  [80] = {.lex_state = 4},
  [81] = {.lex_state = 3},
  [82] = {.lex_state = 27},
  [83] = {.lex_state = 27},
  [84] = {.lex_state = 27},
  [85] = {.lex_state = 27},
  [86] = {.lex_state = 27},
  [87] = {.lex_state = 4},
  [88] = {.lex_state = 4},
  [89] = {.lex_state = 4},
  [90] = {.lex_state = 4},
  [91] = {.lex_state = 27},
  [92] = {.lex_state = 27},
  [93] = {.lex_state = 27},
  [94] = {.lex_state = 27},
  [95] = {.lex_state = 4},
  [96] = {.lex_state = 27},
  [97] = {.lex_state = 27},
  [98] = {.lex_state = 27},
  [99] = {.lex_state = 27},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 27},
  [102] = {.lex_state = 27},
  [103] = {.lex_state = 27},
  [104] = {.lex_state = 27},
  [105] = {.lex_state = 2},
  [106] = {.lex_state = 2},
  [107] = {.lex_state = 2},
  [108] = {.lex_state = 2},
  [109] = {.lex_state = 2},
  [110] = {.lex_state = 2},
  [111] = {.lex_state = 27},
  [112] = {.lex_state = 2},
  [113] = {.lex_state = 2},
  [114] = {.lex_state = 2},
  [115] = {.lex_state = 27},
  [116] = {.lex_state = 2},
  [117] = {.lex_state = 27},
  [118] = {.lex_state = 2},
  [119] = {.lex_state = 2},
  [120] = {.lex_state = 2},
  [121] = {.lex_state = 27},
  [122] = {.lex_state = 2},
  [123] = {.lex_state = 7},
  [124] = {.lex_state = 27},
  [125] = {.lex_state = 27},
  [126] = {.lex_state = 27},
  [127] = {.lex_state = 27},
  [128] = {.lex_state = 27},
  [129] = {.lex_state = 27},
  [130] = {.lex_state = 27},
  [131] = {.lex_state = 27},
  [132] = {.lex_state = 27},
  [133] = {.lex_state = 27},
  [134] = {.lex_state = 27},
  [135] = {.lex_state = 27},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 27},
  [138] = {.lex_state = 6},
  [139] = {.lex_state = 27},
  [140] = {.lex_state = 27},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 6},
  [143] = {.lex_state = 27},
  [144] = {.lex_state = 27},
  [145] = {.lex_state = 27},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 6},
  [148] = {.lex_state = 27},
  [149] = {.lex_state = 27},
  [150] = {.lex_state = 6},
  [151] = {.lex_state = 27},
  [152] = {.lex_state = 27},
  [153] = {.lex_state = 27},
  [154] = {.lex_state = 27},
  [155] = {.lex_state = 27},
  [156] = {.lex_state = 6},
  [157] = {.lex_state = 27},
  [158] = {.lex_state = 27},
  [159] = {.lex_state = 27},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 27},
  [162] = {.lex_state = 27},
  [163] = {.lex_state = 27},
  [164] = {.lex_state = 4},
  [165] = {.lex_state = 27},
  [166] = {.lex_state = 4},
  [167] = {.lex_state = 4},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 4},
  [170] = {.lex_state = 4},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 27},
  [173] = {.lex_state = 27},
  [174] = {.lex_state = 0},
  [175] = {.lex_state = 27},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 4},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 4},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 6},
  [183] = {.lex_state = 2},
  [184] = {.lex_state = 4},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 27},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 27},
  [189] = {.lex_state = 8},
  [190] = {.lex_state = 4},
  [191] = {.lex_state = 27},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 4},
  [194] = {.lex_state = 27},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 4},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 4},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 27},
  [207] = {.lex_state = 4},
  [208] = {.lex_state = 27},
  [209] = {.lex_state = 6},
  [210] = {.lex_state = 4},
  [211] = {.lex_state = 4},
  [212] = {.lex_state = 27},
  [213] = {.lex_state = 27},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 4},
  [216] = {.lex_state = 8},
  [217] = {.lex_state = 27},
  [218] = {.lex_state = 4},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 27},
  [221] = {.lex_state = 0},
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
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 14,
    ACTIONS(3), 1,
      sym_comment,
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
  [55] = 14,
    ACTIONS(3), 1,
      sym_comment,
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
  [110] = 10,
    ACTIONS(3), 1,
      sym_comment,
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
  [149] = 10,
    ACTIONS(3), 1,
      sym_comment,
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
  [188] = 9,
    ACTIONS(3), 1,
      sym_comment,
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
    STATE(12), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [222] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(122), 1,
      anon_sym_COLON,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_g,
    STATE(57), 1,
      sym_articulation,
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
  [252] = 9,
    ACTIONS(3), 1,
      sym_comment,
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
    STATE(12), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [286] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_g,
    ACTIONS(134), 1,
      anon_sym_COLON,
    STATE(69), 1,
      sym_articulation,
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
  [316] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(138), 1,
      anon_sym_LBRACK,
    STATE(25), 1,
      sym_session_modifier,
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
  [340] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(138), 1,
      anon_sym_LBRACK,
    STATE(41), 1,
      sym_session_modifier,
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
  [364] = 9,
    ACTIONS(3), 1,
      sym_comment,
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
    STATE(12), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [398] = 9,
    ACTIONS(3), 1,
      sym_comment,
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
    STATE(4), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [432] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(164), 1,
      ts_builtin_sym_end,
    ACTIONS(166), 1,
      sym_identifier,
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
  [455] = 8,
    ACTIONS(3), 1,
      sym_comment,
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
    STATE(8), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [486] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(176), 1,
      anon_sym_COLON,
    ACTIONS(178), 1,
      anon_sym_arp,
    STATE(74), 1,
      sym_arp_expr,
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
  [513] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(178), 1,
      anon_sym_arp,
    ACTIONS(184), 1,
      anon_sym_COLON,
    STATE(55), 1,
      sym_arp_expr,
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
  [540] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(178), 1,
      anon_sym_arp,
    ACTIONS(190), 1,
      anon_sym_COLON,
    STATE(64), 1,
      sym_arp_expr,
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
  [567] = 2,
    ACTIONS(3), 1,
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
  [586] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(178), 1,
      anon_sym_arp,
    ACTIONS(198), 1,
      anon_sym_COLON,
    STATE(77), 1,
      sym_arp_expr,
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
  [613] = 8,
    ACTIONS(3), 1,
      sym_comment,
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
    STATE(6), 7,
      sym__melody_element,
      sym_bar_jump,
      sym_pitched_note,
      sym_chord,
      sym_chord_name,
      sym_melody_group,
      aux_sym_melody_line_repeat1,
  [644] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_g,
    STATE(65), 1,
      sym_articulation,
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
  [671] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_g,
    STATE(57), 1,
      sym_articulation,
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
  [698] = 2,
    ACTIONS(3), 1,
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
  [716] = 2,
    ACTIONS(3), 1,
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
  [734] = 2,
    ACTIONS(3), 1,
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
  [752] = 2,
    ACTIONS(3), 1,
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
  [770] = 2,
    ACTIONS(3), 1,
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
  [788] = 2,
    ACTIONS(3), 1,
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
  [806] = 2,
    ACTIONS(3), 1,
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
  [824] = 2,
    ACTIONS(3), 1,
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
  [842] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(178), 1,
      anon_sym_arp,
    STATE(71), 1,
      sym_arp_expr,
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
  [866] = 2,
    ACTIONS(3), 1,
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
  [884] = 2,
    ACTIONS(3), 1,
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
  [902] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(178), 1,
      anon_sym_arp,
    STATE(63), 1,
      sym_arp_expr,
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
  [926] = 2,
    ACTIONS(3), 1,
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
  [944] = 2,
    ACTIONS(3), 1,
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
  [962] = 2,
    ACTIONS(3), 1,
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
  [980] = 2,
    ACTIONS(3), 1,
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
  [998] = 2,
    ACTIONS(3), 1,
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
  [1016] = 2,
    ACTIONS(3), 1,
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
  [1034] = 2,
    ACTIONS(3), 1,
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
  [1052] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(178), 1,
      anon_sym_arp,
    STATE(74), 1,
      sym_arp_expr,
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
  [1076] = 2,
    ACTIONS(3), 1,
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
  [1094] = 2,
    ACTIONS(3), 1,
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
  [1112] = 2,
    ACTIONS(3), 1,
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
  [1130] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(178), 1,
      anon_sym_arp,
    STATE(64), 1,
      sym_arp_expr,
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
  [1154] = 3,
    ACTIONS(3), 1,
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
  [1174] = 2,
    ACTIONS(3), 1,
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
  [1192] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(262), 1,
      anon_sym_STAR,
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
  [1213] = 3,
    ACTIONS(3), 1,
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
  [1232] = 7,
    ACTIONS(3), 1,
      sym_comment,
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
    ACTIONS(120), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1259] = 7,
    ACTIONS(3), 1,
      sym_comment,
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
    ACTIONS(132), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1286] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(172), 1,
      sym_note_name,
    ACTIONS(272), 1,
      anon_sym_COLON,
    ACTIONS(274), 1,
      anon_sym_arp,
    STATE(112), 1,
      sym_arp_expr,
    ACTIONS(174), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1310] = 3,
    ACTIONS(3), 1,
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
  [1328] = 3,
    ACTIONS(3), 1,
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
  [1346] = 3,
    ACTIONS(3), 1,
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
  [1364] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(288), 1,
      sym_identifier,
    ACTIONS(290), 1,
      anon_sym_RBRACE,
    ACTIONS(292), 1,
      anon_sym_use,
    ACTIONS(294), 1,
      anon_sym_resolution,
    STATE(84), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [1388] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(118), 1,
      sym_note_name,
    ACTIONS(266), 1,
      anon_sym_SQUOTE,
    ACTIONS(268), 1,
      anon_sym_g,
    STATE(118), 1,
      sym_articulation,
    ACTIONS(120), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1412] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(296), 1,
      sym_octave,
    STATE(59), 1,
      sym_duration,
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
  [1434] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(202), 1,
      sym_note_name,
    ACTIONS(266), 1,
      anon_sym_SQUOTE,
    ACTIONS(268), 1,
      anon_sym_g,
    STATE(107), 1,
      sym_articulation,
    ACTIONS(204), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1458] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(288), 1,
      sym_identifier,
    ACTIONS(290), 1,
      anon_sym_RBRACE,
    ACTIONS(292), 1,
      anon_sym_use,
    ACTIONS(294), 1,
      anon_sym_resolution,
    STATE(85), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [1482] = 3,
    ACTIONS(3), 1,
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
  [1500] = 3,
    ACTIONS(3), 1,
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
  [1518] = 3,
    ACTIONS(3), 1,
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
  [1536] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(314), 1,
      sym_octave,
    STATE(90), 1,
      sym_duration,
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
  [1558] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(38), 1,
      sym_scale_type,
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
  [1576] = 3,
    ACTIONS(3), 1,
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
  [1594] = 3,
    ACTIONS(3), 1,
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
  [1612] = 3,
    ACTIONS(3), 1,
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
  [1630] = 3,
    ACTIONS(3), 1,
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
  [1648] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    ACTIONS(334), 1,
      anon_sym_COLON,
    STATE(119), 1,
      sym_arp_expr,
    ACTIONS(188), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1672] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(180), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    ACTIONS(336), 1,
      anon_sym_COLON,
    STATE(120), 1,
      sym_arp_expr,
    ACTIONS(182), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1696] = 3,
    ACTIONS(3), 1,
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
  [1714] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(342), 1,
      sym_octave,
    STATE(47), 1,
      sym_duration,
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
  [1736] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(348), 1,
      sym_octave,
    STATE(23), 1,
      sym_duration,
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
  [1758] = 3,
    ACTIONS(3), 1,
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
  [1776] = 3,
    ACTIONS(3), 1,
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
  [1794] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(362), 1,
      sym_octave,
    STATE(43), 1,
      sym_duration,
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
  [1816] = 3,
    ACTIONS(3), 1,
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
  [1834] = 3,
    ACTIONS(3), 1,
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
  [1852] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(368), 1,
      sym_octave,
    STATE(95), 1,
      sym_duration,
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
  [1874] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(288), 1,
      sym_identifier,
    ACTIONS(292), 1,
      anon_sym_use,
    ACTIONS(294), 1,
      anon_sym_resolution,
    ACTIONS(370), 1,
      anon_sym_RBRACE,
    STATE(58), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [1898] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(372), 1,
      sym_identifier,
    ACTIONS(375), 1,
      anon_sym_RBRACE,
    ACTIONS(377), 1,
      anon_sym_use,
    ACTIONS(380), 1,
      anon_sym_resolution,
    STATE(84), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [1922] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(288), 1,
      sym_identifier,
    ACTIONS(292), 1,
      anon_sym_use,
    ACTIONS(294), 1,
      anon_sym_resolution,
    ACTIONS(383), 1,
      anon_sym_RBRACE,
    STATE(84), 6,
      sym__clip_content,
      sym_use_stmt,
      sym_resolution_stmt,
      sym_drum_line,
      sym_melody_line,
      aux_sym_clip_def_repeat2,
  [1946] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(168), 1,
      sym_scale_type,
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
  [1964] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(194), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    ACTIONS(385), 1,
      anon_sym_COLON,
    STATE(114), 1,
      sym_arp_expr,
    ACTIONS(196), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [1988] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(222), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    STATE(105), 1,
      sym_arp_expr,
    ACTIONS(224), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2009] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(230), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    STATE(109), 1,
      sym_arp_expr,
    ACTIONS(232), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2030] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(172), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    STATE(112), 1,
      sym_arp_expr,
    ACTIONS(174), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2051] = 4,
    ACTIONS(3), 1,
      sym_comment,
    STATE(35), 1,
      sym_duration,
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
  [2070] = 4,
    ACTIONS(3), 1,
      sym_comment,
    STATE(89), 1,
      sym_duration,
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
  [2089] = 4,
    ACTIONS(3), 1,
      sym_comment,
    STATE(32), 1,
      sym_duration,
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
  [2108] = 4,
    ACTIONS(3), 1,
      sym_comment,
    STATE(88), 1,
      sym_duration,
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
  [2127] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 1,
      sym_note_name,
    ACTIONS(274), 1,
      anon_sym_arp,
    STATE(119), 1,
      sym_arp_expr,
    ACTIONS(188), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2148] = 4,
    ACTIONS(3), 1,
      sym_comment,
    STATE(61), 1,
      sym_duration,
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
  [2167] = 4,
    ACTIONS(3), 1,
      sym_comment,
    STATE(22), 1,
      sym_duration,
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
  [2186] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(387), 1,
      anon_sym_device,
    ACTIONS(389), 1,
      anon_sym_RBRACE,
    ACTIONS(393), 1,
      anon_sym_note,
    STATE(101), 2,
      sym_instrument_property,
      aux_sym_instrument_def_repeat1,
    ACTIONS(391), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2208] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(387), 1,
      anon_sym_device,
    ACTIONS(393), 1,
      anon_sym_note,
    ACTIONS(395), 1,
      anon_sym_RBRACE,
    STATE(98), 2,
      sym_instrument_property,
      aux_sym_instrument_def_repeat1,
    ACTIONS(391), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2230] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(258), 1,
      sym_note_name,
    ACTIONS(397), 1,
      anon_sym_STAR,
    ACTIONS(260), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2248] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(399), 1,
      anon_sym_device,
    ACTIONS(402), 1,
      anon_sym_RBRACE,
    ACTIONS(407), 1,
      anon_sym_note,
    STATE(101), 2,
      sym_instrument_property,
      aux_sym_instrument_def_repeat1,
    ACTIONS(404), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2270] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(410), 1,
      sym_identifier,
    ACTIONS(412), 1,
      anon_sym_RBRACE,
    ACTIONS(414), 1,
      anon_sym_tempo,
    STATE(121), 4,
      sym__scene_content,
      sym_scene_slot,
      sym_scene_tempo,
      aux_sym_scene_def_repeat1,
  [2289] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(416), 1,
      anon_sym_RBRACE,
    ACTIONS(421), 1,
      anon_sym_note,
    STATE(103), 2,
      sym_kit_instrument_property,
      aux_sym_kit_instrument_repeat1,
    ACTIONS(418), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2308] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(424), 1,
      sym_identifier,
    ACTIONS(427), 1,
      anon_sym_RBRACE,
    ACTIONS(429), 1,
      anon_sym_tempo,
    STATE(104), 4,
      sym__scene_content,
      sym_scene_slot,
      sym_scene_tempo,
      aux_sym_scene_def_repeat1,
  [2327] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(330), 1,
      sym_note_name,
    ACTIONS(332), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2342] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(318), 1,
      sym_note_name,
    ACTIONS(320), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2357] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(310), 1,
      sym_note_name,
    ACTIONS(312), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2372] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(280), 1,
      sym_note_name,
    ACTIONS(282), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2387] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      sym_note_name,
    ACTIONS(304), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2402] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(326), 1,
      sym_note_name,
    ACTIONS(328), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2417] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(432), 1,
      anon_sym_RBRACE,
    ACTIONS(436), 1,
      anon_sym_note,
    STATE(103), 2,
      sym_kit_instrument_property,
      aux_sym_kit_instrument_repeat1,
    ACTIONS(434), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2436] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(338), 1,
      sym_note_name,
    ACTIONS(340), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2451] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(364), 1,
      sym_note_name,
    ACTIONS(366), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2466] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(354), 1,
      sym_note_name,
    ACTIONS(356), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2481] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(438), 1,
      anon_sym_bars,
    ACTIONS(440), 1,
      anon_sym_time,
    ACTIONS(442), 1,
      anon_sym_scale,
    STATE(181), 4,
      sym__clip_attr,
      sym_bars_attr,
      sym_time_attr,
      sym_scale_attr,
  [2500] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(322), 1,
      sym_note_name,
    ACTIONS(324), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2515] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(436), 1,
      anon_sym_note,
    ACTIONS(444), 1,
      anon_sym_RBRACE,
    STATE(111), 2,
      sym_kit_instrument_property,
      aux_sym_kit_instrument_repeat1,
    ACTIONS(434), 3,
      anon_sym_channel,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2534] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(284), 1,
      sym_note_name,
    ACTIONS(286), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2549] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(306), 1,
      sym_note_name,
    ACTIONS(308), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2564] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(276), 1,
      sym_note_name,
    ACTIONS(278), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2579] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(410), 1,
      sym_identifier,
    ACTIONS(414), 1,
      anon_sym_tempo,
    ACTIONS(446), 1,
      anon_sym_RBRACE,
    STATE(104), 4,
      sym__scene_content,
      sym_scene_slot,
      sym_scene_tempo,
      aux_sym_scene_def_repeat1,
  [2598] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(358), 1,
      sym_note_name,
    ACTIONS(360), 6,
      anon_sym_LBRACK,
      anon_sym_GT,
      sym_rest,
      sym_chord_symbol,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [2613] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(450), 1,
      anon_sym_RBRACE,
    ACTIONS(452), 1,
      sym_probability,
    ACTIONS(454), 1,
      anon_sym_PIPE,
    STATE(154), 1,
      sym_shuffle_expr,
    ACTIONS(448), 2,
      anon_sym_tempo,
      sym_identifier,
  [2633] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(456), 1,
      sym_identifier,
    ACTIONS(459), 1,
      anon_sym_device,
    ACTIONS(462), 1,
      anon_sym_RBRACE,
    STATE(124), 3,
      sym__kit_member,
      sym_kit_instrument,
      aux_sym_kit_def_repeat1,
  [2651] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(464), 1,
      sym_identifier,
    ACTIONS(466), 1,
      anon_sym_device,
    ACTIONS(468), 1,
      anon_sym_RBRACE,
    STATE(127), 3,
      sym__kit_member,
      sym_kit_instrument,
      aux_sym_kit_def_repeat1,
  [2669] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(470), 6,
      anon_sym_device,
      anon_sym_RBRACE,
      anon_sym_channel,
      anon_sym_note,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2681] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(464), 1,
      sym_identifier,
    ACTIONS(466), 1,
      anon_sym_device,
    ACTIONS(472), 1,
      anon_sym_RBRACE,
    STATE(124), 3,
      sym__kit_member,
      sym_kit_instrument,
      aux_sym_kit_def_repeat1,
  [2699] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(474), 5,
      anon_sym_RBRACE,
      anon_sym_channel,
      anon_sym_note,
      anon_sym_gate_normal,
      anon_sym_gate_staccato,
  [2710] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(478), 1,
      anon_sym_RBRACE,
    ACTIONS(480), 1,
      anon_sym_STAR,
    STATE(152), 1,
      sym_weight,
    ACTIONS(476), 2,
      anon_sym_tempo,
      sym_identifier,
  [2727] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(482), 1,
      anon_sym_up,
    STATE(219), 1,
      sym_arp_direction,
    ACTIONS(484), 3,
      anon_sym_down,
      anon_sym_updown,
      anon_sym_random,
  [2742] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(482), 1,
      anon_sym_up,
    STATE(185), 1,
      sym_arp_direction,
    ACTIONS(484), 3,
      anon_sym_down,
      anon_sym_updown,
      anon_sym_random,
  [2757] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(486), 1,
      sym_identifier,
    ACTIONS(488), 1,
      anon_sym_RBRACE,
    STATE(134), 2,
      sym_session_entry,
      aux_sym_session_def_repeat1,
  [2771] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(492), 1,
      anon_sym_LBRACK,
    STATE(165), 1,
      sym_session_modifier,
    ACTIONS(490), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [2785] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(486), 1,
      sym_identifier,
    ACTIONS(494), 1,
      anon_sym_RBRACE,
    STATE(144), 2,
      sym_session_entry,
      aux_sym_session_def_repeat1,
  [2799] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(496), 1,
      anon_sym_RBRACE,
    ACTIONS(498), 1,
      anon_sym_port,
    STATE(137), 2,
      sym_device_property,
      aux_sym_device_def_repeat1,
  [2813] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(500), 1,
      anon_sym_LBRACE,
    ACTIONS(502), 1,
      anon_sym_LBRACK,
    STATE(146), 2,
      sym_clip_header,
      aux_sym_clip_def_repeat1,
  [2827] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(504), 1,
      anon_sym_RBRACE,
    ACTIONS(506), 1,
      anon_sym_port,
    STATE(137), 2,
      sym_device_property,
      aux_sym_device_def_repeat1,
  [2841] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(509), 1,
      anon_sym_RBRACK,
    STATE(138), 1,
      aux_sym_chord_repeat1,
    ACTIONS(511), 2,
      sym_rest,
      sym_note_name,
  [2855] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(498), 1,
      anon_sym_port,
    ACTIONS(514), 1,
      anon_sym_RBRACE,
    STATE(135), 2,
      sym_device_property,
      aux_sym_device_def_repeat1,
  [2869] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(518), 1,
      anon_sym_RBRACE,
    ACTIONS(516), 3,
      anon_sym_use,
      anon_sym_resolution,
      sym_identifier,
  [2881] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(502), 1,
      anon_sym_LBRACK,
    ACTIONS(520), 1,
      anon_sym_LBRACE,
    STATE(136), 2,
      sym_clip_header,
      aux_sym_clip_def_repeat1,
  [2895] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(522), 1,
      anon_sym_RBRACK,
    STATE(138), 1,
      aux_sym_chord_repeat1,
    ACTIONS(524), 2,
      sym_rest,
      sym_note_name,
  [2909] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(528), 1,
      anon_sym_RBRACE,
    ACTIONS(526), 3,
      anon_sym_use,
      anon_sym_resolution,
      sym_identifier,
  [2921] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(530), 1,
      sym_identifier,
    ACTIONS(533), 1,
      anon_sym_RBRACE,
    STATE(144), 2,
      sym_session_entry,
      aux_sym_session_def_repeat1,
  [2935] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(537), 1,
      anon_sym_RBRACE,
    ACTIONS(535), 3,
      anon_sym_use,
      anon_sym_resolution,
      sym_identifier,
  [2947] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(539), 1,
      anon_sym_LBRACE,
    ACTIONS(541), 1,
      anon_sym_LBRACK,
    STATE(146), 2,
      sym_clip_header,
      aux_sym_clip_def_repeat1,
  [2961] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(544), 1,
      anon_sym_RBRACK,
    STATE(138), 1,
      aux_sym_chord_repeat1,
    ACTIONS(524), 2,
      sym_rest,
      sym_note_name,
  [2975] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(548), 1,
      anon_sym_RBRACE,
    ACTIONS(546), 2,
      anon_sym_device,
      sym_identifier,
  [2986] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(552), 1,
      anon_sym_RBRACE,
    ACTIONS(550), 2,
      anon_sym_device,
      sym_identifier,
  [2997] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(147), 1,
      aux_sym_chord_repeat1,
    ACTIONS(554), 2,
      sym_rest,
      sym_note_name,
  [3008] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(558), 1,
      anon_sym_RBRACE,
    ACTIONS(556), 2,
      anon_sym_tempo,
      sym_identifier,
  [3019] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(562), 1,
      anon_sym_RBRACE,
    ACTIONS(560), 2,
      anon_sym_tempo,
      sym_identifier,
  [3030] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(566), 1,
      anon_sym_RBRACE,
    ACTIONS(564), 2,
      anon_sym_device,
      sym_identifier,
  [3041] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(570), 1,
      anon_sym_RBRACE,
    ACTIONS(568), 2,
      anon_sym_tempo,
      sym_identifier,
  [3052] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(574), 1,
      anon_sym_RBRACE,
    ACTIONS(572), 2,
      anon_sym_tempo,
      sym_identifier,
  [3063] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(142), 1,
      aux_sym_chord_repeat1,
    ACTIONS(576), 2,
      sym_rest,
      sym_note_name,
  [3074] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(578), 1,
      anon_sym_repeat,
    ACTIONS(580), 1,
      anon_sym_loop,
  [3084] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(582), 1,
      sym_identifier,
    ACTIONS(584), 1,
      anon_sym_session,
  [3094] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(586), 1,
      anon_sym_repeat,
    ACTIONS(588), 1,
      anon_sym_loop,
  [3104] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(590), 2,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
  [3112] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(210), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [3120] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(240), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [3128] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(592), 2,
      anon_sym_RBRACE,
      anon_sym_port,
  [3136] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(594), 2,
      sym_tempo_delta,
      sym_number,
  [3144] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(596), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [3152] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(598), 1,
      sym_number,
  [3159] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(600), 1,
      sym_number,
  [3166] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(602), 1,
      anon_sym_RBRACK,
  [3173] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(604), 1,
      sym_number,
  [3180] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(606), 1,
      sym_number,
  [3187] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(608), 1,
      anon_sym_COMMA,
  [3194] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(610), 1,
      sym_identifier,
  [3201] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(612), 1,
      anon_sym_RPAREN,
  [3208] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(614), 1,
      anon_sym_RBRACK,
  [3215] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(616), 1,
      sym_identifier,
  [3222] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(618), 1,
      anon_sym_RBRACK,
  [3229] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(620), 1,
      anon_sym_RBRACK,
  [3236] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(622), 1,
      sym_number,
  [3243] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(624), 1,
      anon_sym_RBRACK,
  [3250] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(626), 1,
      sym_number,
  [3257] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(628), 1,
      anon_sym_RBRACK,
  [3264] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(630), 1,
      sym_note_name,
  [3271] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(632), 1,
      sym_time_signature,
  [3278] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(634), 1,
      sym_number,
  [3285] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(636), 1,
      anon_sym_COMMA,
  [3292] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(638), 1,
      sym_identifier,
  [3299] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(640), 1,
      anon_sym_LBRACE,
  [3306] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(642), 1,
      sym_identifier,
  [3313] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(644), 1,
      sym_note_literal,
  [3320] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(644), 1,
      sym_number,
  [3327] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(644), 1,
      sym_identifier,
  [3334] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(646), 1,
      sym_string,
  [3341] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(648), 1,
      sym_number,
  [3348] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(650), 1,
      sym_identifier,
  [3355] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(652), 1,
      anon_sym_LBRACE,
  [3362] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(654), 1,
      anon_sym_LBRACE,
  [3369] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(656), 1,
      anon_sym_LBRACE,
  [3376] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(658), 1,
      anon_sym_LBRACE,
  [3383] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(660), 1,
      anon_sym_LBRACE,
  [3390] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(662), 1,
      ts_builtin_sym_end,
  [3397] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(664), 1,
      sym_number,
  [3404] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(666), 1,
      sym_string,
  [3411] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(668), 1,
      anon_sym_RBRACK,
  [3418] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(670), 1,
      sym_number,
  [3425] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(672), 1,
      anon_sym_RBRACK,
  [3432] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(674), 1,
      sym_identifier,
  [3439] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(676), 1,
      sym_number,
  [3446] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(678), 1,
      sym_identifier,
  [3453] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(680), 1,
      sym_note_name,
  [3460] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(682), 1,
      sym_number,
  [3467] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(684), 1,
      sym_number,
  [3474] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(686), 1,
      sym_identifier,
  [3481] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(688), 1,
      anon_sym_RPAREN,
  [3488] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(690), 1,
      anon_sym_LPAREN,
  [3495] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(692), 1,
      sym_number,
  [3502] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(604), 1,
      sym_note_literal,
  [3509] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(694), 1,
      sym_identifier,
  [3516] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(696), 1,
      sym_number,
  [3523] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(698), 1,
      anon_sym_COMMA,
  [3530] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(700), 1,
      sym_identifier,
  [3537] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(702), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 55,
  [SMALL_STATE(4)] = 110,
  [SMALL_STATE(5)] = 149,
  [SMALL_STATE(6)] = 188,
  [SMALL_STATE(7)] = 222,
  [SMALL_STATE(8)] = 252,
  [SMALL_STATE(9)] = 286,
  [SMALL_STATE(10)] = 316,
  [SMALL_STATE(11)] = 340,
  [SMALL_STATE(12)] = 364,
  [SMALL_STATE(13)] = 398,
  [SMALL_STATE(14)] = 432,
  [SMALL_STATE(15)] = 455,
  [SMALL_STATE(16)] = 486,
  [SMALL_STATE(17)] = 513,
  [SMALL_STATE(18)] = 540,
  [SMALL_STATE(19)] = 567,
  [SMALL_STATE(20)] = 586,
  [SMALL_STATE(21)] = 613,
  [SMALL_STATE(22)] = 644,
  [SMALL_STATE(23)] = 671,
  [SMALL_STATE(24)] = 698,
  [SMALL_STATE(25)] = 716,
  [SMALL_STATE(26)] = 734,
  [SMALL_STATE(27)] = 752,
  [SMALL_STATE(28)] = 770,
  [SMALL_STATE(29)] = 788,
  [SMALL_STATE(30)] = 806,
  [SMALL_STATE(31)] = 824,
  [SMALL_STATE(32)] = 842,
  [SMALL_STATE(33)] = 866,
  [SMALL_STATE(34)] = 884,
  [SMALL_STATE(35)] = 902,
  [SMALL_STATE(36)] = 926,
  [SMALL_STATE(37)] = 944,
  [SMALL_STATE(38)] = 962,
  [SMALL_STATE(39)] = 980,
  [SMALL_STATE(40)] = 998,
  [SMALL_STATE(41)] = 1016,
  [SMALL_STATE(42)] = 1034,
  [SMALL_STATE(43)] = 1052,
  [SMALL_STATE(44)] = 1076,
  [SMALL_STATE(45)] = 1094,
  [SMALL_STATE(46)] = 1112,
  [SMALL_STATE(47)] = 1130,
  [SMALL_STATE(48)] = 1154,
  [SMALL_STATE(49)] = 1174,
  [SMALL_STATE(50)] = 1192,
  [SMALL_STATE(51)] = 1213,
  [SMALL_STATE(52)] = 1232,
  [SMALL_STATE(53)] = 1259,
  [SMALL_STATE(54)] = 1286,
  [SMALL_STATE(55)] = 1310,
  [SMALL_STATE(56)] = 1328,
  [SMALL_STATE(57)] = 1346,
  [SMALL_STATE(58)] = 1364,
  [SMALL_STATE(59)] = 1388,
  [SMALL_STATE(60)] = 1412,
  [SMALL_STATE(61)] = 1434,
  [SMALL_STATE(62)] = 1458,
  [SMALL_STATE(63)] = 1482,
  [SMALL_STATE(64)] = 1500,
  [SMALL_STATE(65)] = 1518,
  [SMALL_STATE(66)] = 1536,
  [SMALL_STATE(67)] = 1558,
  [SMALL_STATE(68)] = 1576,
  [SMALL_STATE(69)] = 1594,
  [SMALL_STATE(70)] = 1612,
  [SMALL_STATE(71)] = 1630,
  [SMALL_STATE(72)] = 1648,
  [SMALL_STATE(73)] = 1672,
  [SMALL_STATE(74)] = 1696,
  [SMALL_STATE(75)] = 1714,
  [SMALL_STATE(76)] = 1736,
  [SMALL_STATE(77)] = 1758,
  [SMALL_STATE(78)] = 1776,
  [SMALL_STATE(79)] = 1794,
  [SMALL_STATE(80)] = 1816,
  [SMALL_STATE(81)] = 1834,
  [SMALL_STATE(82)] = 1852,
  [SMALL_STATE(83)] = 1874,
  [SMALL_STATE(84)] = 1898,
  [SMALL_STATE(85)] = 1922,
  [SMALL_STATE(86)] = 1946,
  [SMALL_STATE(87)] = 1964,
  [SMALL_STATE(88)] = 1988,
  [SMALL_STATE(89)] = 2009,
  [SMALL_STATE(90)] = 2030,
  [SMALL_STATE(91)] = 2051,
  [SMALL_STATE(92)] = 2070,
  [SMALL_STATE(93)] = 2089,
  [SMALL_STATE(94)] = 2108,
  [SMALL_STATE(95)] = 2127,
  [SMALL_STATE(96)] = 2148,
  [SMALL_STATE(97)] = 2167,
  [SMALL_STATE(98)] = 2186,
  [SMALL_STATE(99)] = 2208,
  [SMALL_STATE(100)] = 2230,
  [SMALL_STATE(101)] = 2248,
  [SMALL_STATE(102)] = 2270,
  [SMALL_STATE(103)] = 2289,
  [SMALL_STATE(104)] = 2308,
  [SMALL_STATE(105)] = 2327,
  [SMALL_STATE(106)] = 2342,
  [SMALL_STATE(107)] = 2357,
  [SMALL_STATE(108)] = 2372,
  [SMALL_STATE(109)] = 2387,
  [SMALL_STATE(110)] = 2402,
  [SMALL_STATE(111)] = 2417,
  [SMALL_STATE(112)] = 2436,
  [SMALL_STATE(113)] = 2451,
  [SMALL_STATE(114)] = 2466,
  [SMALL_STATE(115)] = 2481,
  [SMALL_STATE(116)] = 2500,
  [SMALL_STATE(117)] = 2515,
  [SMALL_STATE(118)] = 2534,
  [SMALL_STATE(119)] = 2549,
  [SMALL_STATE(120)] = 2564,
  [SMALL_STATE(121)] = 2579,
  [SMALL_STATE(122)] = 2598,
  [SMALL_STATE(123)] = 2613,
  [SMALL_STATE(124)] = 2633,
  [SMALL_STATE(125)] = 2651,
  [SMALL_STATE(126)] = 2669,
  [SMALL_STATE(127)] = 2681,
  [SMALL_STATE(128)] = 2699,
  [SMALL_STATE(129)] = 2710,
  [SMALL_STATE(130)] = 2727,
  [SMALL_STATE(131)] = 2742,
  [SMALL_STATE(132)] = 2757,
  [SMALL_STATE(133)] = 2771,
  [SMALL_STATE(134)] = 2785,
  [SMALL_STATE(135)] = 2799,
  [SMALL_STATE(136)] = 2813,
  [SMALL_STATE(137)] = 2827,
  [SMALL_STATE(138)] = 2841,
  [SMALL_STATE(139)] = 2855,
  [SMALL_STATE(140)] = 2869,
  [SMALL_STATE(141)] = 2881,
  [SMALL_STATE(142)] = 2895,
  [SMALL_STATE(143)] = 2909,
  [SMALL_STATE(144)] = 2921,
  [SMALL_STATE(145)] = 2935,
  [SMALL_STATE(146)] = 2947,
  [SMALL_STATE(147)] = 2961,
  [SMALL_STATE(148)] = 2975,
  [SMALL_STATE(149)] = 2986,
  [SMALL_STATE(150)] = 2997,
  [SMALL_STATE(151)] = 3008,
  [SMALL_STATE(152)] = 3019,
  [SMALL_STATE(153)] = 3030,
  [SMALL_STATE(154)] = 3041,
  [SMALL_STATE(155)] = 3052,
  [SMALL_STATE(156)] = 3063,
  [SMALL_STATE(157)] = 3074,
  [SMALL_STATE(158)] = 3084,
  [SMALL_STATE(159)] = 3094,
  [SMALL_STATE(160)] = 3104,
  [SMALL_STATE(161)] = 3112,
  [SMALL_STATE(162)] = 3120,
  [SMALL_STATE(163)] = 3128,
  [SMALL_STATE(164)] = 3136,
  [SMALL_STATE(165)] = 3144,
  [SMALL_STATE(166)] = 3152,
  [SMALL_STATE(167)] = 3159,
  [SMALL_STATE(168)] = 3166,
  [SMALL_STATE(169)] = 3173,
  [SMALL_STATE(170)] = 3180,
  [SMALL_STATE(171)] = 3187,
  [SMALL_STATE(172)] = 3194,
  [SMALL_STATE(173)] = 3201,
  [SMALL_STATE(174)] = 3208,
  [SMALL_STATE(175)] = 3215,
  [SMALL_STATE(176)] = 3222,
  [SMALL_STATE(177)] = 3229,
  [SMALL_STATE(178)] = 3236,
  [SMALL_STATE(179)] = 3243,
  [SMALL_STATE(180)] = 3250,
  [SMALL_STATE(181)] = 3257,
  [SMALL_STATE(182)] = 3264,
  [SMALL_STATE(183)] = 3271,
  [SMALL_STATE(184)] = 3278,
  [SMALL_STATE(185)] = 3285,
  [SMALL_STATE(186)] = 3292,
  [SMALL_STATE(187)] = 3299,
  [SMALL_STATE(188)] = 3306,
  [SMALL_STATE(189)] = 3313,
  [SMALL_STATE(190)] = 3320,
  [SMALL_STATE(191)] = 3327,
  [SMALL_STATE(192)] = 3334,
  [SMALL_STATE(193)] = 3341,
  [SMALL_STATE(194)] = 3348,
  [SMALL_STATE(195)] = 3355,
  [SMALL_STATE(196)] = 3362,
  [SMALL_STATE(197)] = 3369,
  [SMALL_STATE(198)] = 3376,
  [SMALL_STATE(199)] = 3383,
  [SMALL_STATE(200)] = 3390,
  [SMALL_STATE(201)] = 3397,
  [SMALL_STATE(202)] = 3404,
  [SMALL_STATE(203)] = 3411,
  [SMALL_STATE(204)] = 3418,
  [SMALL_STATE(205)] = 3425,
  [SMALL_STATE(206)] = 3432,
  [SMALL_STATE(207)] = 3439,
  [SMALL_STATE(208)] = 3446,
  [SMALL_STATE(209)] = 3453,
  [SMALL_STATE(210)] = 3460,
  [SMALL_STATE(211)] = 3467,
  [SMALL_STATE(212)] = 3474,
  [SMALL_STATE(213)] = 3481,
  [SMALL_STATE(214)] = 3488,
  [SMALL_STATE(215)] = 3495,
  [SMALL_STATE(216)] = 3502,
  [SMALL_STATE(217)] = 3509,
  [SMALL_STATE(218)] = 3516,
  [SMALL_STATE(219)] = 3523,
  [SMALL_STATE(220)] = 3530,
  [SMALL_STATE(221)] = 3537,
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

#ifdef __cplusplus
extern "C" {
#endif
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
