#include "tree_sitter/parser.h"

enum TokenType {
    TITLE,
    MARKDOWN_BLOCK,
};

void *tree_sitter_octo_external_scanner_create(void) {
    return NULL;
}

void tree_sitter_octo_external_scanner_destroy(void *payload) {
    (void)payload;
}

unsigned tree_sitter_octo_external_scanner_serialize(
  void *payload,
  char *buffer
) {
    (void)payload;
    (void)buffer;
    return 0;
}

void tree_sitter_octo_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
    (void)payload;
    (void)buffer;
    (void)length;
}

bool tree_sitter_octo_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
    (void)payload;
    if (valid_symbols[TITLE]) {
        while (lexer->lookahead != '\n' && !lexer->eof(lexer)) {
            lexer->advance(lexer, false);
        }
        lexer->advance(lexer, false);
        lexer->result_symbol = TITLE;
        return true;
    }
    if (valid_symbols[MARKDOWN_BLOCK]) {
        while (!lexer->eof(lexer)) {
            lexer->advance(lexer, false);
        }
        lexer->result_symbol = MARKDOWN_BLOCK;
        return true;
    }
    return false;
}
