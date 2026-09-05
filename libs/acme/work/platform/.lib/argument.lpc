/**
 * Utility library for parsing command arguments.
 *
 * @author devo@eotl
 * @alias ArgumentLib
 */
#pragma no_clone
#include <argument.h>

private inherit StringLib;
private inherit ArrayLib;

protected varargs string *explode_args(string arg, int preserve_quotes);
private int _find_close_char(string str, int start, string open,
                             string close, int len, int style, string both);
protected varargs int find_close_char(string str, int start,
                                      string open, string close);
protected string *explode_unescaped(string str, string delim);
protected varargs string *explode_nested(string str, string delim,
                                         string open, string close);

/**
 * Separate space-deliniated arguments, but keep quoted strings together.
 *
 * @param  arg             the string containing quoted arguments
 * @param  preserve_quotes set to 1 if the quote characters should be
 *                         preserved in the resulting argument strings
 * @return                 an array of space-deliniated arguments, with the
 *                         quoted strings returned as a single argument
 */
protected varargs string *explode_args(string arg, int preserve_quotes) {
  string *args = ({ });
  if (!arg) { return args; }

  int pos = 0;
  int len = strlen(arg);
  while (pos < len) {
    pos = find_nonws(arg, pos);
    int newpos = match_quote(arg, pos);
    if (preserve_quotes) {
      args += ({ arg[pos..newpos] });
    } else {
      args += ({ unescape(unquote(arg[pos..newpos])) });
    }
    pos = newpos + 1;
  }
  return args;
}

/**
 * The recursive part of the find_char_char() process. Note: the validity
 * of len, style, and both is not checked.
 *
 * @param  str   the string to search through
 * @param  start the position of the open char
 * @param  open  a string of OPEN characters
 * @param  close a string of CLOSE characters
 * @param  len   strlen(str)
 * @param  style position of str[0] in open: (member(open, str[0]))
 * @param  both  open + close
 * @return       a positive number indicates the position of the matching
 *               char in str; a zero/negative result indicates a failure to
 *               match the open char at str[-result]
 */
private int _find_close_char(string str, int start, string open,
                             string close, int len, int style, string both) {
  int cursor = start + 1;
  while (cursor < len) {
    int first = searcha_any(str, both, cursor);

    if (first == -1)  {
      // Close not found.
      return -start;
    }

    if (str[first] == close[style]) {
      // It's what we've been looking for
      return first;
    }

    if (member(open, str[first]) == -1)  {
      // It's not an OPEN char
      // Trying to close something that isn't open
      return -start;
    }

    // Must be an OPEN char.  Recurse.
    int tmp = _find_close_char(str, first, open, close, len,
                               member(open, str[first]), both);
    if (tmp < 0) {
      return tmp;
    }

    // Move past the closing char of the subexpression
    cursor = tmp + 1;

  }

  // Got to the end of the string and didn't find a match.
  // This would happen for "[..(..)"
  return -start;
}


/**
 * Find closing brace/paren/bracket/quote in a string that matches a
 * specified set of open characters. The open and close strings must be the
 * same legnth and in the correct order so that open[i] matches close[i].
 *
 * @param  str    the string to search
 * @param  start  the position of the open brace/paran/bracket/quote
 * @param  open   a string of OPEN characters; defaults to "\"([{"
 * @param  close  a string of CLOSE characters; defaults to "\")]}"
 * @return        ret > 0: the position of the matching char in str
 *                ret ==0: error: str[start] was not an OPEN char
 *                ret < 0: error: failed to match open char at str[-ret - 1]
 */
protected varargs int find_close_char(string str, int start,
                                      string open, string close) {
  // If you explicitly specify 0 for open, you will get errors.
  if (!stringp(close)) {
    open  = "\"([{";
    close = "\")]}";
  }

  // Must be an OPEN char.
  int style = member(open, str[start]);
  if (style == -1) {
    return 0;
  }

  int result = _find_close_char(str, start, open, close, strlen(str), style,
                                open + close);

  if (result <= 0) {
    return result - 1;
  }

  return result;
}

/**
 * Explode a string into substrings by a delimter, ignoring any escaped
 * delimters in the string when performing the separation. See is_escaped().
 *
 * @param  str   the string to explode
 * @param  delim the string delimiting the substrings
 * @return       an array of strings separated by the delimiter
 */
protected string *explode_unescaped(string str, string delim) {
  int delim_len = strlen(delim);
  if (delim_len == 0) {
    return explode(str, delim);
  }

  string *result = ({ });
  int max = strlen(str) - delim_len;

  int cursor = 0;
  int start = 0;
  while (cursor <= max) {
    cursor = strstr(str, delim, cursor);
    if (cursor == -1) {
      break;
    }
    if (is_escaped(str, cursor)) {
      cursor++;
    } else {
      result += ({ str[start..(cursor - 1)] });
      cursor = cursor + delim_len;
      start = cursor;
    }
  }

  result += ({ str[start..] });

  return result;
}

/**
 * Explode a string into substrings by a delimiter, ignoring any escaped
 * delimiters, and delimiters nested within open/close characters. See
 * explode_nested().
 *
 * @param  str    the string to explode
 * @param  delim  the string delimiting the substrings
 * @param  open   a string of OPEN characters; defaults to "\"([{"
 * @param  close  a string of CLOSE characters; defaults to "\")]}"
 * @return        an array of strings separated by the delimiter
 */
protected varargs string *explode_nested(string str, string delim,
                                         string open, string close) {
  int delim_len = strlen(delim);
  if (delim_len == 0) {
    return explode(str, delim);
  }

  // If you explicitly specify 0 for open, you will get errors.
  if (!stringp(close)) {
    open  = DEFAULT_OPEN;
    close = DEFAULT_CLOSE;
  }

  string *result = ({ });
  int max = strlen(str) - delim_len;
  int cursor = 0;
  int start = 0;
  int next_open = 0;
  while (cursor <= max) {
    int next_delim = strstr(str, delim, cursor);
    if (next_delim == -1) {
      break;
    }
    if (is_escaped(str, next_delim)) {
      cursor = next_delim + 1;
    } else {
      if (((next_open > cursor) // The last one we found is still ahead
           || ((next_open = searcha_any(str, open, cursor)) != -1))
          && (next_open < next_delim)) {
        // Skip over the matching close char
        cursor = 1 + find_close_char(str, next_open, open, close);
        if (cursor <= 1) {
          // Something went wrong
          return 0;
        }
      } else {
        result += ({ str[start..(next_delim - 1)] });
        cursor = next_delim + delim_len;
        start = cursor;
      }
    }
  }

  result += ({ str[start..] });

  return result;
}
