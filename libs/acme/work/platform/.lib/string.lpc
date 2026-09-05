/**
 * Utility library for manipulating strings.
 *
 * @author devo
 * @alias StringLib
 */
#pragma no_clone
#include <string.h>

private inherit ArrayLib;

protected varargs int find_nonws(string str, int start);
protected int is_escaped(string str, int index);
protected varargs int search_str_unescaped(string str, int el, int pos, 
                                           int step);
protected varargs int match_quote(string str, int start, string quote_chars);
protected string unescape(string str);
protected varargs string unquote(string str, string quote_chars);
protected string crop_string(string str, int length);

/**
 * Find the first non-space character in a string.
 * Note: functionally equivilent to ArrayLib->anti_search(str, ' ', start),
 * but optimized for speed.
 *
 * @param  str   the string to search
 * @param  start optional start position for search, defaults to 0
 * @return       the index of the first non-space character, or strlen(str)
 *               if the string only contains spaces
 */
protected varargs int find_nonws(string str, int start) {
  for (int size = strlen(str);
       (start < size) && (str[start] == ' ');
       start++);
  return start;
}

/**
 * Test whether a character in string is escaped by a backslash.
 *
 * @param  str   the string containing the potentially escaped char
 * @param  index the index of the character to test
 * @return       true if str[index] is escaped
 */
protected int is_escaped(string str, int index) {
  // It's complicated because backslashes can be escaped too.
  int last_non_bs = anti_searcha(str, '\\', index-1, -1);
  return (index - last_non_bs + 1) % 2;
}

/**
 * Search a string for a character, ignoring escaped characters.
 *
 * @param  str  the string to search
 * @param  el   the character (ascii value) for which to search
 * @param  pos  optional starting position, defaults to 0
 * @param  step optional step size, defaults to 1
 * @return      the index of the first unescaped character, or -1 if
 *              character was not found
 */
protected varargs int search_str_unescaped(string str, int el, int pos, 
                                           int step) {
  step ||= 1;

  for (int size = strlen(str); (pos < size) && (pos >= 0); pos += step) {
    if ((str[pos] == el) && !is_escaped(str, pos)) {
      return pos;
    }
  }
  return -1;
}

/**
 * Find the index of the last character in a possibly quoted string.
 *
 * @param  str         the string to search
 * @param  start       optional start position, defaults to 0
 * @param  quote_chars an optional string containing quote characters,
 *                     defaults to "\"'"
 * @return             the index of the last character in the first quoted
 *                     character sequence, or the index of the last character
 *                     of the first word
 */
protected varargs int match_quote(string str, int start, string quote_chars) {
  int end;

  if (member(quote_chars || QUOTE_CHARS, str[start]) != -1)
    end = search_str_unescaped(str, str[start], start + 1, 1);
  else
    end = search_str_unescaped(str, ' ', start + 1, 1) - 1;
  return (end < 0) ? strlen(str) - 1 : end;
}

/**
 * Unescape all characters in a string by one level.
 * <p>Note: This deals with literal backslashes only.  In the examples, and ind
 * the strings this function is meant to deal with "\a" is meant to represent
 * a string containing the two characters '\\' and 'a', not a string
 * containing a single '\a' character.
 *
 * @param  str the string to unescape
 * @return     the unescaped string
 */
protected string unescape(string str) {
  string copy = "";

  for (int len = strlen(str), int i = 0, int next = 0;
       i < len;
       i = next + 2) {
    next = member(str, '\\', i);
    if (next == -1) { return copy + str[i..len-1]; }
    if (next == len - 1) {
      if(i == next) { return copy; }
      else { return copy + str[i..len-2]; }
    }
    copy += str[i..next-1] + str[next+1..next+1];
  }
  return copy;
}

/**
 * Removes the outer layer of quotes, if there is one.
 *
 * @param  str         the potentially quoted string
 * @param  quote_chars an optional string containing quote characters,
 *                     defaults to "\"'"
 * @return             the unquoted string
 */
protected varargs string unquote(string str, string quote_chars) {
  int len = strlen(str);

  // no room for quotes
  if (len < 2) { return str; }

  if (!quote_chars) {
    quote_chars = UNQUOTE_CHARS;
  }

  if (( (str[0] == '\"') || (str[0] == '\'') ) && (str[0] == str[len-1])) {
    return (len == 2) ? "" : str[1..len-2]; //"
  }
  else {
    return str;
  }
}

/**
 * Crop a string, adding an elipsis if necessary.
 *
 * @param  str    the string to crop
 * @param  length the desired string length
 * @return        the original string, or a truncated string with trailng
 *                elipsis
 */
protected string crop_string(string str, int length) {
  if (strlen(str) > length) {
    return str[0..(length - 4)] + ELIPSIS;
  }
  return str;
}
