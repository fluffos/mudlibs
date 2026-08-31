/**
 * lpml.c (LPML implementation)
 *
 * LPML (LPC Markup Language) - A human-friendly config format for MUDs
 * Based on JSON5 with LPC-specific extensions
 *
 * Features supported:
 * - Single and multi-line comments (// and \/* *\/)
 * - Unquoted object keys (identifiers)
 * - Single-quoted strings ('string')
 * - Multiline strings with automatic folding (real newlines → spaces)
 * - String concatenation: adjacent strings auto-join with smart spacing
 * - Trailing commas in objects and arrays
 * - Hexadecimal numbers (0xFF, 0XFF)
 * - Octal numbers (0o77, 0O77)
 * - Binary numbers (0b1010, 0B1010)
 * - Leading/trailing decimal points (.5, 5.)
 * - Plus sign on numbers (+5)
 * - undefined keyword (maps to ([])[0] like null)
 * - MAX_INT and MAX_FLOAT constants (with optional +/- sign)
 * - File includes with "#path" syntax (use \# to escape literal #)
 *
 * mixed lpml_decode(string text, string base_path)
 *     Deserializes LPML into an LPC value.
 *     base_path is optional, used for resolving relative includes.
 *
 * string lpml_encode(mixed value)
 *     Serializes an LPC value into JSON text.
 *
 * @created 2025-11-09 - Gesslar
 * @version 1.0.0
 * @see /doc/lpml-spec.md for full specification
 */

#ifndef __STD_LPML_H
#define __STD_LPML_H

#define to_string(x)                ("" + (x))

#define LPML_DECODE_PARSE_TEXT      0
#define LPML_DECODE_PARSE_POS       1
#define LPML_DECODE_PARSE_LINE      2
#define LPML_DECODE_PARSE_CHAR      3
#define LPML_DECODE_PARSE_FIELDS    4

private mixed lpml_decode_parse_value(mixed* parse);
private varargs mixed lpml_decode_parse_string(mixed* parse, int quote_char);
private string lpml_decode_parse_identifier(mixed* parse);
private string lpml_decode_parse_spacey_key(mixed* parse);
private varargs void lpml_decode_parse_error(mixed* parse, string msg, int ch);

// If at or below the relative path. We do not do multi-cross-traversal.
// examples:
//
// good: ./file.txt
//       ./subdir/file.txt
//       ../file.txt
//       ../../somedir/file.txt
// bad:  ./../what/no.txt
//       ../.././stop/it.c
private string resolve_relative_path(string relative_path, string relative_to) {
  string *relative_path_parts;
  string *relative_to_parts;

  // If we don't have a valid string, the relative path is absolute, or
  // we don't even have enough to work with, yeet it back. Similar tests
  // for the relative_to.
  if(!stringp(relative_path) ||
     !strlen(relative_path) ||
     relative_path[0] == '/' ||

     !stringp(relative_to) ||
     !strlen(relative_to) ||
      relative_to[0] != '/'
    )

    return relative_path;

  relative_path_parts = explode(relative_path, "/");
  relative_path_parts = map(relative_path_parts, (: trim :));
  relative_path_parts = filter(relative_path_parts, (: strlen :));

  relative_to_parts = explode(relative_to, "/");
  relative_to_parts = map(relative_to_parts, (: trim :));
  relative_to_parts = filter(relative_to_parts, (: strlen :));

  if(relative_path_parts[0] == "..") {
    while(relative_path_parts[0] == "..") {

      if(!sizeof(relative_to_parts))
        error(
          "Invalid path relative resolution to '"+relative_path+"' "
          "from '"+relative_to+"'"
        );

      relative_path_parts = relative_path_parts[1..];
      relative_to_parts = relative_to_parts[0..<2];
    }

    return sprintf("/%s/%s",
      implode(relative_to_parts, "/"),
      implode(relative_path_parts, "/")
    );
  }

  if(relative_path_parts[0] == ".")
    relative_path_parts = relative_path_parts[1..];

  return sprintf("/%s/%s",
    implode(relative_to_parts, "/"),
    implode(relative_path_parts, "/")
  );
}

/**
 * Advances the parse position by one character.
 */
private void lpml_decode_parse_next_char(mixed* parse) {
  parse[LPML_DECODE_PARSE_POS]++;
  parse[LPML_DECODE_PARSE_CHAR]++;
}

/**
 * Advances the parse position by the specified number of characters.
 */
private void lpml_decode_parse_next_chars(mixed* parse, int num) {
  parse[LPML_DECODE_PARSE_POS] += num;
  parse[LPML_DECODE_PARSE_CHAR] += num;
}

/**
 * Advances the parse position to the next line.
 */
private void lpml_decode_parse_next_line(mixed* parse) {
  parse[LPML_DECODE_PARSE_POS]++;
  parse[LPML_DECODE_PARSE_LINE]++;
  parse[LPML_DECODE_PARSE_CHAR] = 1;
}

/**
 * Skips whitespace and comments
 */
private void lpml_decode_skip_whitespace_and_comments(mixed* parse) {
  int ch, next_ch;

  while(parse[LPML_DECODE_PARSE_POS] < sizeof(parse[LPML_DECODE_PARSE_TEXT])) {
    ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

    // Whitespace
    if(ch == ' ' || ch == '\t' || ch == '\r') {
      lpml_decode_parse_next_char(parse);
      continue;
    }

    if(ch == '\n' || ch == 0x0c) {
      lpml_decode_parse_next_line(parse);
      continue;
    }

    // Comments
    if(ch == '/') {
      next_ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS] + 1];

      // Single-line comment
      if(next_ch == '/') {
        while(parse[LPML_DECODE_PARSE_POS] < sizeof(parse[LPML_DECODE_PARSE_TEXT]) &&
              parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]] != '\n') {
          lpml_decode_parse_next_char(parse);
        }
        continue;
      }

      // Multi-line comment
      if(next_ch == '*') {
        lpml_decode_parse_next_char(parse);  // Skip /
        lpml_decode_parse_next_char(parse);  // Skip *

        {
          int found_end = 0;

          while(parse[LPML_DECODE_PARSE_POS] + 1 < sizeof(parse[LPML_DECODE_PARSE_TEXT])) {
            ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];
            next_ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS] + 1];

            if(ch == '*' && next_ch == '/') {
              lpml_decode_parse_next_char(parse);  // Skip *
              lpml_decode_parse_next_char(parse);  // Skip /
              found_end = 1;
              break;
            }

            if(ch == '\n') {
              lpml_decode_parse_next_line(parse);
            } else {
              lpml_decode_parse_next_char(parse);
            }
          }

          if(!found_end)
            lpml_decode_parse_error(parse, "Unterminated multi-line comment");
        }

        continue;
      }
    }

    // Not whitespace or comment
    break;
  }
}

/**
 * Converts a hexadecimal character to its integer value.
 */
private int lpml_decode_hexdigit(int ch) {
  if(ch >= '0' && ch <= '9') return ch - '0';
  if(ch >= 'a' && ch <= 'f') return ch - 'a' + 10;
  if(ch >= 'A' && ch <= 'F') return ch - 'A' + 10;
  return -1;
}

/**
 * Checks if the parse position matches the specified token.
 */
private varargs int lpml_decode_parse_at_token(mixed* parse, string token, int start) {
  int i, j, remaining;

  j = strlen(token);
  remaining = sizeof(parse[LPML_DECODE_PARSE_TEXT]) - parse[LPML_DECODE_PARSE_POS];

  if(j - start > remaining)
    return 0;

  for(i = start; i < j; i++)
    if(parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS] + i] != token[i])
      return 0;

  return 1;
}

/**
 * Raises a parse error with the specified message and character.
 */
private varargs void lpml_decode_parse_error(mixed* parse, string msg, int ch) {
  if(!nullp(ch))
    msg = sprintf("%s, '%c'", msg, ch);

  msg = sprintf("%s @ line %d char %d\n'%s'\n",
    msg,
    parse[LPML_DECODE_PARSE_LINE],
    parse[LPML_DECODE_PARSE_CHAR],
    string_decode(parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]..parse[LPML_DECODE_PARSE_POS]+20], "utf8")
  );

  error(msg);
}

/**
 * Check if character is valid identifier start (letter, $, _)
 */
private int lpml_is_identifier_start(int ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_' || ch == '$';
}

/**
 * Check if character is valid identifier continuation (letter, digit, $, _)
 */
private int lpml_is_identifier_char(int ch) {
  return lpml_is_identifier_start(ch) || (ch >= '0' && ch <= '9');
}

/**
 * Parse an identifier (unquoted key)
 */
private string lpml_decode_parse_identifier(mixed* parse) {
  int from, to;
  string out;

  from = parse[LPML_DECODE_PARSE_POS];

  if(!lpml_is_identifier_start(parse[LPML_DECODE_PARSE_TEXT][from]))
    lpml_decode_parse_error(parse, "Invalid identifier start");

  lpml_decode_parse_next_char(parse);

  while(parse[LPML_DECODE_PARSE_POS] < sizeof(parse[LPML_DECODE_PARSE_TEXT]) &&
        lpml_is_identifier_char(parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]])) {
    lpml_decode_parse_next_char(parse);
  }

  to = parse[LPML_DECODE_PARSE_POS] - 1;
  out = string_decode(parse[LPML_DECODE_PARSE_TEXT][from .. to], "utf-8");

  return out;
}

/**
 * Parse a YAML-style spacey key (reads until ':')
 */
private string lpml_decode_parse_spacey_key(mixed* parse) {
  int from, to;
  string out;
  int ch;

  from = parse[LPML_DECODE_PARSE_POS];

  // Read until we hit ':'
  while(parse[LPML_DECODE_PARSE_POS] < sizeof(parse[LPML_DECODE_PARSE_TEXT])) {
    ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

    if(ch == 0)
      lpml_decode_parse_error(parse, "Unexpected end of data in spacey key");

    if(ch == ':')
      break;  // Found the key separator

    if(ch == '\n')
      lpml_decode_parse_next_line(parse);
    else
      lpml_decode_parse_next_char(parse);
  }

  to = parse[LPML_DECODE_PARSE_POS] - 1;
  out = string_decode(parse[LPML_DECODE_PARSE_TEXT][from .. to], "utf-8");

  // Trim leading/trailing whitespace
  out = trim(out);

  if(strlen(out) == 0)
    lpml_decode_parse_error(parse, "Empty spacey key");

  return out;
}

/**
 * Parses a LPML object from the given parse state.
 */
private mixed lpml_decode_parse_object(mixed* parse) {
  mapping out = ([]);
  int done = 0;
  mixed key, value;
  int ch;

  lpml_decode_parse_next_char(parse);  // Skip {
  lpml_decode_skip_whitespace_and_comments(parse);

  ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];
  if(ch == '}') {
    lpml_decode_parse_next_char(parse);
    return out;
  }

  while(!done) {
    lpml_decode_skip_whitespace_and_comments(parse);
    ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

    if(ch == 0)
      lpml_decode_parse_error(parse, "Unexpected end of data");

    // Parse key (quoted string, single-quoted string, identifier, or spacey key)
    if(ch == '"') {
      key = lpml_decode_parse_string(parse, '"');
    } else if(ch == '\'') {
      key = lpml_decode_parse_string(parse, '\'');
    } else if(lpml_is_identifier_start(ch)) {
      // Could be a plain identifier or the start of a spacey key. Try the
      // fast path (plain identifier) first, remembering where we started.
      int key_pos  = parse[LPML_DECODE_PARSE_POS];
      int key_char = parse[LPML_DECODE_PARSE_CHAR];
      int key_line = parse[LPML_DECODE_PARSE_LINE];

      key = lpml_decode_parse_identifier(parse);

      // Check if next non-whitespace is ':' or if there's more (spacey key)
      lpml_decode_skip_whitespace_and_comments(parse);
      ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

      if(ch != ':') {
        // Not a plain identifier (e.g. it contains '-' or other non-ident
        // characters, or interior spaces). Rewind to the start of the key and
        // let the spacey-key reader consume it verbatim, so punctuation is
        // preserved and only the ends are trimmed.
        parse[LPML_DECODE_PARSE_POS]  = key_pos;
        parse[LPML_DECODE_PARSE_CHAR] = key_char;
        parse[LPML_DECODE_PARSE_LINE] = key_line;
        key = lpml_decode_parse_spacey_key(parse);
      }
    } else {
      // YAML-style spacey key - read until ':'
      key = lpml_decode_parse_spacey_key(parse);
    }

    // Find colon
    lpml_decode_skip_whitespace_and_comments(parse);
    ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

    if(ch != ':')
      lpml_decode_parse_error(parse, "Expected ':'", ch);

    lpml_decode_parse_next_char(parse);

    // Parse value
    lpml_decode_skip_whitespace_and_comments(parse);
    value = lpml_decode_parse_value(parse);
    out[key] = value;

    // Check for comma or closing brace
    lpml_decode_skip_whitespace_and_comments(parse);
    ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

    if(ch == ',') {
      lpml_decode_parse_next_char(parse);
      lpml_decode_skip_whitespace_and_comments(parse);
      ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];
      // Trailing comma - check for closing brace
      if(ch == '}') {
        done = 1;
        lpml_decode_parse_next_char(parse);
      }
    } else if(ch == '}') {
      done = 1;
      lpml_decode_parse_next_char(parse);
    } else {
      lpml_decode_parse_error(parse, "Expected ',' or '}'", ch);
    }
  }

  return out;
}

/**
 * Parses a LPML array from the given parse state.
 */
private mixed lpml_decode_parse_array(mixed* parse) {
  mixed* out = ({});
  int done = 0;
  int ch;
  mixed value;

  lpml_decode_parse_next_char(parse);  // Skip [
  lpml_decode_skip_whitespace_and_comments(parse);

  ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

  if(ch == ']') {
    lpml_decode_parse_next_char(parse);
    return out;
  }

  while(!done) {
    lpml_decode_skip_whitespace_and_comments(parse);
    value = lpml_decode_parse_value(parse);
    out += ({ value });

    // Check for comma or closing bracket
    lpml_decode_skip_whitespace_and_comments(parse);
    ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

    if(ch == ',') {
      lpml_decode_parse_next_char(parse);
      lpml_decode_skip_whitespace_and_comments(parse);
      ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

      // Trailing comma - check for closing bracket
      if(ch == ']') {
        done = 1;
        lpml_decode_parse_next_char(parse);
      }
    } else if(ch == ']') {
      done = 1;
      lpml_decode_parse_next_char(parse);
    } else {
      lpml_decode_parse_error(parse, "Expected ',' or ']'", ch);
    }
  }

  return out;
}

/**
 * Parses a LPML string from the given parse state.
 * Supports double quotes and single quotes (both allow multiline).
 * Adjacent strings are automatically concatenated:
 *   "foo" "bar"   → "foo bar" (space added)
 *   "foo\n" "bar" → "foo\nbar" (no space if ends with \n)
 */
private varargs mixed lpml_decode_parse_string(mixed* parse, int quote_char) {
  int from, to, esc_state, esc_active;
  string out;
  int ch;
  int has_real_newlines = 0;
  string next_str;
  int needs_space;

  if(!quote_char) {
    ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

    if(ch == '"')
      quote_char = '"';
    else if(ch == '\'')
      quote_char = '\'';
    else
      lpml_decode_parse_error(parse, "Expected string", ch);
  }

  lpml_decode_parse_next_char(parse);  // Skip opening quote
  from = parse[LPML_DECODE_PARSE_POS];
  to = -1;
  esc_state = 0;
  esc_active = 0;
  has_real_newlines = 0;  // Track if string spans multiple lines in source

  while(to == -1) {
    ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

    if(ch == 0)
      lpml_decode_parse_error(parse, "Unexpected end of data in string");

    // Allow newlines in strings
    if(ch == '\n') {
      has_real_newlines = 1;  // String spans multiple lines in source
      lpml_decode_parse_next_line(parse);
      continue;
    }

    if(ch == '\\') {
      esc_state = !esc_state;
      // A completed backslash pair (\\) is itself an escape that needs
      // collapsing, so flag it the same way other escapes are flagged.
      if(!esc_state)
        esc_active++;
    } else if(ch == quote_char) {
      if(esc_state) {
        esc_state = 0;
        esc_active++;
      } else {
        to = parse[LPML_DECODE_PARSE_POS] - 1;
      }
    } else {
      if(esc_state) {
        esc_state = 0;
        esc_active++;
      }
    }

    lpml_decode_parse_next_char(parse);
  }

  out = string_decode(parse[LPML_DECODE_PARSE_TEXT][from .. to], "utf-8");

  // Fold source newlines BEFORE escape processing so that \n escapes survive.
  // Real newlines in the source (from pressing Enter) become spaces,
  // while escape sequences like \n are preserved as-is for later processing.
  if(has_real_newlines && strsrch(out, "\n") != -1) {
    string* lines;
    int i, sz;

    lines = explode(out, "\n");
    out = "";

    for(i = 0, sz = sizeof(lines); i < sz; i++) {
      string line = trim(lines[i]);

      if(strlen(line) == 0) {
        // Blank line becomes paragraph break
        if(strlen(out) > 0 && out[<1] != '\n')
          out += "\n";
      } else {
        // Add space before line if needed
        if(strlen(out) > 0 && out[<1] != '\n' && out[<1] != ' ')
          out += " ";
        out += line;
      }
    }

    out = trim(out);
  }

  // Process escape sequences
  // IMPORTANT: Process \\\\ first, then other escapes
  if(esc_active) {
    string quote_str = sprintf("%c", quote_char);

    // First, convert \\\\ to a placeholder to avoid double-processing
    string backslash_placeholder = "\x01BACKSLASH\x01";
    if(member_array('\\', out) != -1)
      out = replace_string(out, "\\\\", backslash_placeholder);

    // Now process other escape sequences
    if(member_array(quote_char, out) != -1)
      out = replace_string(out, "\\" + quote_str, quote_str);
    if(strsrch(out, "\\b") != -1)
      out = replace_string(out, "\\b", "\b");
    if(strsrch(out, "\\f") != -1)
      out = replace_string(out, "\\f", "\x0c");
    if(strsrch(out, "\\n") != -1)
      out = replace_string(out, "\\n", "\n");
    if(strsrch(out, "\\r") != -1)
      out = replace_string(out, "\\r", "\r");
    if(strsrch(out, "\\t") != -1)
      out = replace_string(out, "\\t", "\t");
    if(member_array('/', out) != -1)
      out = replace_string(out, "\\/", "/");

    // Unicode escape sequences: \uXXXX
    if(strsrch(out, "\\u") != -1) {
      string uout = "";
      int ui, usz;

      for(ui = 0, usz = strlen(out); ui < usz; ui++) {
        if(out[ui] == '\\' && ui + 5 < usz && out[ui+1] == 'u') {
          int h0, h1, h2, h3, codepoint;

          h0 = lpml_decode_hexdigit(out[ui+2]);
          h1 = lpml_decode_hexdigit(out[ui+3]);
          h2 = lpml_decode_hexdigit(out[ui+4]);
          h3 = lpml_decode_hexdigit(out[ui+5]);

          if(h0 != -1 && h1 != -1 && h2 != -1 && h3 != -1) {
            codepoint = (h0 << 12) | (h1 << 8) | (h2 << 4) | h3;

            // out is a codepoint string (string_decode'd above), and "%c"
            // already UTF-8-encodes the codepoint on output. Emit the
            // codepoint directly; splitting it into bytes here would
            // double-encode (é -> "Ã©").
            uout += sprintf("%c", codepoint);

            ui += 5;  // skip past \uXXXX (loop will increment once more)
            continue;
          }
        }

        uout += sprintf("%c", out[ui]);
      }

      out = uout;
    }

    // Finally, convert placeholder back to single backslash
    if(strsrch(out, backslash_placeholder) != -1)
      out = replace_string(out, backslash_placeholder, "\\");
  }

  // String concatenation: check if next non-whitespace token is another string
  lpml_decode_skip_whitespace_and_comments(parse);
  ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

  if(ch == '"' || ch == '\'') {
    // Another string follows - concatenate!
    needs_space = 1;

    // Check if current string ends with newline
    if(strlen(out) > 0 && out[<1] == '\n')
      needs_space = 0;

    // Recursively parse the next string
    next_str = lpml_decode_parse_string(parse, ch);

    // Concatenate with or without space
    if(needs_space)
      out = out + " " + next_str;
    else
      out = out + next_str;
  }

  return out;
}

/**
 * Parses a LPML number from the given parse state.
 * Supports hex (0xFF), octal (0o77), binary (0b1010),
 * leading/trailing decimals (.5, 5.), plus sign (+5)
 */
private mixed lpml_decode_parse_number(mixed* parse) {
  int from, to, dot, exp, ch, next_ch;
  string number;
  int is_negative = 0;
  int result;

  from = parse[LPML_DECODE_PARSE_POS];
  to = -1;
  dot = -1;
  exp = -1;

  ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

  // Handle sign
  if(ch == '-' || ch == '+') {
    if(ch == '-')
      is_negative = 1;

    lpml_decode_parse_next_char(parse);
    ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

    // Check for MAX_INT or MAX_FLOAT after sign
    if(ch == 'M') {
      if(lpml_decode_parse_at_token(parse, "MAX_INT", 0)) {
        lpml_decode_parse_next_chars(parse, 7);
        return is_negative ? -MAX_INT : MAX_INT;
      }
      if(lpml_decode_parse_at_token(parse, "MAX_FLOAT", 0)) {
        lpml_decode_parse_next_chars(parse, 9);
        return is_negative ? -MAX_FLOAT : MAX_FLOAT;
      }
    }

    // Check for Infinity after sign (e.g. -Infinity, +Infinity)
    if(ch == 'I' && lpml_decode_parse_at_token(parse, "Infinity", 0)) {
      lpml_decode_parse_next_chars(parse, 8);
      return ([])[0];  // undefined - LPC has no Infinity
    }
  }

  // Check for special number formats (hex, octal, binary)
  if(ch == '0') {
    next_ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS] + 1];

    // Hexadecimal: 0xFF or 0XFF
    if(next_ch == 'x' || next_ch == 'X') {
      lpml_decode_parse_next_char(parse);  // Skip 0
      lpml_decode_parse_next_char(parse);  // Skip x/X

      from = parse[LPML_DECODE_PARSE_POS];
      while(parse[LPML_DECODE_PARSE_POS] < sizeof(parse[LPML_DECODE_PARSE_TEXT])) {
        ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];
        if(lpml_decode_hexdigit(ch) == -1) break;
        lpml_decode_parse_next_char(parse);
      }
      to = parse[LPML_DECODE_PARSE_POS] - 1;
      number = string_decode(parse[LPML_DECODE_PARSE_TEXT][from .. to], "utf-8");
      sscanf(number, "%x", result);

      return is_negative ? -result : result;
    }

    // Octal: 0o77 or 0O77
    if(next_ch == 'o' || next_ch == 'O') {
      lpml_decode_parse_next_char(parse);  // Skip 0
      lpml_decode_parse_next_char(parse);  // Skip o/O

      from = parse[LPML_DECODE_PARSE_POS];
      result = 0;
      while(parse[LPML_DECODE_PARSE_POS] < sizeof(parse[LPML_DECODE_PARSE_TEXT])) {
        ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];
        if(ch < '0' || ch > '7') break;
        result = (result * 8) + (ch - '0');
        lpml_decode_parse_next_char(parse);
      }

      return is_negative ? -result : result;
    }

    // Binary: 0b1010 or 0B1010
    if(next_ch == 'b' || next_ch == 'B') {
      lpml_decode_parse_next_char(parse);  // Skip 0
      lpml_decode_parse_next_char(parse);  // Skip b/B

      from = parse[LPML_DECODE_PARSE_POS];
      result = 0;
      while(parse[LPML_DECODE_PARSE_POS] < sizeof(parse[LPML_DECODE_PARSE_TEXT])) {
        ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];
        if(ch != '0' && ch != '1') break;
        result = (result << 1) + (ch - '0');
        lpml_decode_parse_next_char(parse);
      }

      return is_negative ? -result : result;
    }
  }

  // Leading decimal point
  if(ch == '.') {
    dot = parse[LPML_DECODE_PARSE_POS];
    lpml_decode_parse_next_char(parse);
  }

  // Parse number
  while(to == -1 && parse[LPML_DECODE_PARSE_POS] < sizeof(parse[LPML_DECODE_PARSE_TEXT])) {
    ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

    if(ch >= '0' && ch <= '9') {
      lpml_decode_parse_next_char(parse);
    } else if(ch == '.' && dot == -1 && exp == -1) {
      dot = parse[LPML_DECODE_PARSE_POS];
      lpml_decode_parse_next_char(parse);
    } else if((ch == 'e' || ch == 'E') && exp == -1) {
      exp = parse[LPML_DECODE_PARSE_POS];
      lpml_decode_parse_next_char(parse);
      // Handle exponent sign
      ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];
      if(ch == '+' || ch == '-')
        lpml_decode_parse_next_char(parse);
    } else {
      to = parse[LPML_DECODE_PARSE_POS] - 1;
    }
  }

  if(to == -1)
    to = parse[LPML_DECODE_PARSE_POS] - 1;

  number = string_decode(parse[LPML_DECODE_PARSE_TEXT][from .. to], "utf-8");

  if(dot != -1 || exp != -1)
    return to_float(number);
  else
    return to_int(number);
}

/**
 * Parses a LPML value from the given parse state.
 */
private mixed lpml_decode_parse_value(mixed* parse) {
  int ch;

  lpml_decode_skip_whitespace_and_comments(parse);
  ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

  if(ch == 0)
    lpml_decode_parse_error(parse, "Unexpected end of data");

  // Object
  if(ch == '{')
    return lpml_decode_parse_object(parse);

  // Array
  if(ch == '[')
    return lpml_decode_parse_array(parse);

  // String (double or single quoted, both support multiline)
  if(ch == '"' || ch == '\'')
    return lpml_decode_parse_string(parse, ch);

  // Number (including +, leading ., hex)
  if(ch == '-' || ch == '+' || ch == '.' || (ch >= '0' && ch <= '9'))
    return lpml_decode_parse_number(parse);

  // true
  if(ch == 't' && lpml_decode_parse_at_token(parse, "true", 0)) {
    lpml_decode_parse_next_chars(parse, 4);
    return 1;
  }

  // false
  if(ch == 'f' && lpml_decode_parse_at_token(parse, "false", 0)) {
    lpml_decode_parse_next_chars(parse, 5);
    return 0;
  }

  // null
  if(ch == 'n' && lpml_decode_parse_at_token(parse, "null", 0)) {
    lpml_decode_parse_next_chars(parse, 4);
    return ([])[0];  // undefined
  }

  // undefined
  if(ch == 'u' && lpml_decode_parse_at_token(parse, "undefined", 0)) {
    lpml_decode_parse_next_chars(parse, 9);
    return ([])[0];  // undefined
  }

  // Infinity (maps to undefined per spec - LPC has no Infinity)
  if(ch == 'I' && lpml_decode_parse_at_token(parse, "Infinity", 0)) {
    lpml_decode_parse_next_chars(parse, 8);
    return ([])[0];  // undefined
  }

  // NaN (maps to undefined per spec - LPC has no NaN)
  if(ch == 'N' && lpml_decode_parse_at_token(parse, "NaN", 0)) {
    lpml_decode_parse_next_chars(parse, 3);
    return ([])[0];  // undefined
  }

  // MAX_INT
  if(ch == 'M' && lpml_decode_parse_at_token(parse, "MAX_INT", 0)) {
    lpml_decode_parse_next_chars(parse, 7);
    return MAX_INT;
  }

  // MAX_FLOAT
  if(ch == 'M' && lpml_decode_parse_at_token(parse, "MAX_FLOAT", 0)) {
    lpml_decode_parse_next_chars(parse, 9);
    return MAX_FLOAT;
  }

  lpml_decode_parse_error(parse, "Unexpected character", ch);

  return 0;
}

/**
 * Main parse function
 */
private mixed lpml_decode_parse(mixed* parse) {
  mixed out;
  int ch;

  out = lpml_decode_parse_value(parse);

  lpml_decode_skip_whitespace_and_comments(parse);
  ch = parse[LPML_DECODE_PARSE_TEXT][parse[LPML_DECODE_PARSE_POS]];

  if(ch != 0)
    lpml_decode_parse_error(parse, "Unexpected character after value", ch);

  return out;
}

// File interpolation pattern: "#path"

/**
 * Preprocesses LPML text to handle "#path" includes
 *
 * @param {string} text - The LPML string to preprocess
 * @param {string} base_path - Base directory for relative paths
 * @returns {string} Preprocessed LPML text
 *
 * Looks for "#path" pattern and replaces with file contents.
 * Use \# to escape literal # (per LPML spec).
 */
private string lpml_decode_preprocess(string text, string base_path) {
  string source;
  string result, file_path, file_text, include_base;
  int start, end;

  result = "";
  source = text;

  while(strlen(source) > 0) {
    int dq_start, sq_start, dq_esc_start, sq_esc_start;
    int is_single_quote = 0;
    int is_escaped = 0;

    // Look for "# or '# or "\# or '\# patterns
    dq_start = strsrch(source, "\"#");
    sq_start = strsrch(source, "'#");
    dq_esc_start = strsrch(source, "\"\\#");
    sq_esc_start = strsrch(source, "'\\#");

    // Find the earliest match
    start = -1;

    if(dq_start != -1 && (start == -1 || dq_start < start)) {
      start = dq_start;
      is_single_quote = 0;
      is_escaped = 0;
    }
    if(sq_start != -1 && (start == -1 || sq_start < start)) {
      start = sq_start;
      is_single_quote = 1;
      is_escaped = 0;
    }
    if(dq_esc_start != -1 && (start == -1 || dq_esc_start < start)) {
      start = dq_esc_start;
      is_single_quote = 0;
      is_escaped = 1;
    }
    if(sq_esc_start != -1 && (start == -1 || sq_esc_start < start)) {
      start = sq_esc_start;
      is_single_quote = 1;
      is_escaped = 1;
    }

    if(start == -1) {
      // No more includes or escapes
      result += source;
      break;
    }

    // If escaped, strip the backslash and skip
    if(is_escaped) {
      // Add everything before the escape, then quote+#
      result += source[0..start-1];
      if(is_single_quote)
        result += "'#";
      else
        result += "\"#";
      source = source[start+3..];
      continue;
    }

    // Add text before the include (including the opening quote)
    if(start > 0)
      result += source[0..start-1];

    // Find closing quote after the #
    {
      string remainder = source[start+2..];  // Skip quote + #
      string close_quote = is_single_quote ? "'" : "\"";
      int close_pos = strsrch(remainder, close_quote);
      int i;

      // Make sure the " isn't escaped
      while(close_pos != -1) {
        // Count preceding backslashes
        int backslashes = 0;
        i = close_pos - 1;

        while(i >= 0 && remainder[i] == '\\') {
          backslashes++;
          i--;
        }

        // If odd number of backslashes, the " is escaped
        if(backslashes % 2 == 0) {
          // Not escaped - this is our closing quote
          break;
        }

        // Escaped - keep looking
        close_pos = strsrch(remainder, close_quote, close_pos + 1);
      }

      if(close_pos == -1) {
        // No closing quote - keep the \"# and continue
        result += source[start..start+1];
        source = source[start+2..];
        continue;
      }

      end = start + 2 + close_pos;  // Position of closing "
    }

    // Extract file path (between # and ")
    file_path = source[start+2..end-1];

    // Handle relative paths
    file_path = resolve_relative_path(file_path, base_path);

    // Try to read the file
    if(!file_exists(file_path)) {
      // File not found - keep the original string and continue
      result += source[start..end];
      source = source[end+1..];
      continue;
    }

    file_text = read_file(file_path);
    if(!file_text) {
      // Could not read - keep the original string and continue
      result += source[start..end];
      source = source[end+1..];
      continue;
    }

    // Trim trailing newline from read_file
    if(file_text[<1] == '\n')
      file_text = file_text[0..<2];

    // Recursively preprocess (in case included file has includes)
    include_base = strsrch(file_path, "/") != -1
      ? file_path[0..strsrch(file_path, "/", -1)-1]
      : "";

    file_text = lpml_decode_preprocess(file_text, include_base);

    // Insert the file content (no quotes around it)
    result += file_text;

    // Consume the processed part of source (skip the closing ")
    source = source[end+1..];
  }

  // Final pass: strip \# escapes that weren't includes
  result = replace_string(result, "\\#", "#");

  return result;
}

/**
 * Deserializes a LPML string into an LPC value.
 *
 * @param {string} text - The LPML string to deserialize.
 * @param {string} base_path - Optional base directory for relative includes
 * @returns {mixed} The deserialized LPC value.
 */
varargs mixed lpml_decode(string text, string base_path) {
  mixed* parse;
  buffer endl;

  if(!text)
    return 0;

  // Preprocess includes
  text = lpml_decode_preprocess(text, base_path);

  endl = allocate_buffer(1);
  endl[0] = 0;

  parse = allocate(LPML_DECODE_PARSE_FIELDS);
  parse[LPML_DECODE_PARSE_TEXT] = string_encode(text, "utf-8") + endl;
  parse[LPML_DECODE_PARSE_POS] = 0;
  parse[LPML_DECODE_PARSE_CHAR] = 1;
  parse[LPML_DECODE_PARSE_LINE] = 1;

  return lpml_decode_parse(parse);
}

/**
 * Serializes an LPC value into JSON text.
 *
 * @param {mixed} value - The LPC value to serialize.
 * @returns {string} The JSON string representation.
 *
 * Note: Encoding produces standard JSON
 */
varargs string lpml_encode(mixed value, mixed* pointers) {
  // Use standard JSON encoding - LPML is primarily for parsing
  // For now, delegate to json_encode if available, or implement basic encoding

  if(undefinedp(value))
    return "null";
  if(intp(value) || floatp(value))
    return to_string(value);
  if(stringp(value)) {
    value = replace_string(value, "\\", "\\\\");
    value = replace_string(value, "\"", "\\\"");
    value = replace_string(value, "\n", "\\n");
    value = replace_string(value, "\r", "\\r");
    value = replace_string(value, "\t", "\\t");
    return sprintf("\"%s\"", value);
  }

  if(mapp(value)) {
    string out;
    int ix = 0;

    if(pointers && member_array(value, pointers) != -1)
        return "null";

    pointers = pointers ? pointers + ({ value }) : ({ value });

    foreach(mixed k, mixed v in value) {
      if(!stringp(k))
        continue;

      if(ix++)
        out = sprintf("%s,%s:%s", out, lpml_encode(k, pointers), lpml_encode(v, pointers));
      else
        out = sprintf("%s:%s", lpml_encode(k, pointers), lpml_encode(v, pointers));
    }

    return sprintf("{%s}", out || "");
  }

  if(pointerp(value)) {
    string out;
    int ix = 0;

    if(sizeof(value) == 0)
      return "[]";

    if(pointers && member_array(value, pointers) != -1)
      return "null";

    pointers = pointers ? pointers + ({ value }) : ({ value });

    foreach(mixed v in value) {
      if(ix++)
        out = sprintf("%s,%s", out, lpml_encode(v, pointers));
      else
        out = lpml_encode(v, pointers);
    }

    return sprintf("[%s]", out);
  }

  return "null";
}

#endif /* __STD_LPML_H */
