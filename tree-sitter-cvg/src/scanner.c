/*
 * External scanner for nested block comments in the cvg grammar.
 *
 * Uses tree-sitter's external scanner mechanism to parse block comments
 * that support nesting. A depth counter tracks nested opening and closing
 * delimiters. The token completes when the counter reaches zero.
 * Returns false if EOF is reached before all comments are closed.
 */

#include "tree_sitter/parser.h"

/* Token types matching the externals array index in grammar.js. */
enum TokenType {
  BLOCK_COMMENT /* Nested block comment token */
};

/* Create scanner instance. Stateless, so returns NULL. */
void *tree_sitter_cvg_external_scanner_create(void) { return NULL; }

/* Destroy scanner instance. No-op since stateless. */
void tree_sitter_cvg_external_scanner_destroy(void *payload) {}

/* Serialize scanner state. Returns 0 since stateless. */
unsigned tree_sitter_cvg_external_scanner_serialize(void *payload,
                                                    char *buffer) {
  return 0;
}

/* Deserialize scanner state. No-op since stateless. */
void tree_sitter_cvg_external_scanner_deserialize(void *payload,
                                                  const char *buffer,
                                                  unsigned length) {}

/*
 * Scan for a nested block comment.
 *
 * Detects the opening delimiter, then uses a depth counter:
 * increments on nested opening delimiters, decrements on closing ones.
 * Returns true when depth reaches 0, false on EOF (unclosed comment).
 */
bool tree_sitter_cvg_external_scanner_scan(void *payload, TSLexer *lexer,
                                           const bool *valid_symbols) {
  if (!valid_symbols[BLOCK_COMMENT]) {
    return false;
  }

  /* Skip leading whitespace */
  while (lexer->lookahead == ' ' || lexer->lookahead == '\t' ||
         lexer->lookahead == '\r' || lexer->lookahead == '\n') {
    lexer->advance(lexer, true);
  }

  /* Detect opening delimiter */
  if (lexer->lookahead != '/') {
    return false;
  }
  lexer->advance(lexer, false);
  if (lexer->lookahead != '*') {
    return false;
  }
  lexer->advance(lexer, false);

  /* Parse block comment body with nesting support */
  int depth = 1;
  while (depth > 0 && !lexer->eof(lexer)) {
    if (lexer->lookahead == '/') {
      lexer->advance(lexer, false);
      if (!lexer->eof(lexer) && lexer->lookahead == '*') {
        depth++;
        lexer->advance(lexer, false);
      }
    } else if (lexer->lookahead == '*') {
      lexer->advance(lexer, false);
      if (!lexer->eof(lexer) && lexer->lookahead == '/') {
        depth--;
        lexer->advance(lexer, false);
      }
    } else {
      lexer->advance(lexer, false);
    }
  }

  lexer->result_symbol = BLOCK_COMMENT;
  return depth == 0;
}
