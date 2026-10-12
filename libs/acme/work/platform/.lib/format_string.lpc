/**
 * Utility library for parsing format strings into runnable lambda closures.
 *
 * @author devo
 * @alias FormatStringLib
 */
#include <sys/debug_info.h>
#include <format_string.h>

private inherit ArgumentLib;
private inherit ArrayLib;
private inherit StringLib;
private inherit ClosureLib;

protected closure parse_format(string format, mapping infomap, symbol *args);
protected varargs string *explode_format(string str, string delim,
                                         string open, string close);
/**
 * Compile a format string into a formatter closure with the given format
 * specifiers and args. Format strings may contain tokens of the format "%c"
 * where 'c' is some alphabetic character. They may also take arguments in
 * the format of "%c{arg}". For every format specifier found, the returned
 * closure will run the closure found for the character in infomap (the
 * character is the key) and replace the format specifier with the result of
 * the evaluated closure. Closures may reference the optional arg value with
 * the symbol 'arg. They may also reference any arguments passed to the
 * closure at runtime with the symbols defined in the args parameter. (Values
 * for these arguments must be supplied by the caller at runtime!) References
 * to the closure arguments in infomap must be double quoted even though
 * they are single quoted in the args parameter.
 *
 * Invoking the result of this function will return the format string with
 * all constituent format specifiers replaced by the result of their closure
 * calls. Example:
 *
 * closure formatter =
 *   parse_format_string(
 *     "name: %N",        // format string
 *     ([ 'N' : ({ 0,     // default value for 'arg
 *                 "%s",  // sprintf() format string of result
 *                 ({     // array of closures to call
 *                        // results will be passed as args to sprintf()
 *                    ({ #'call_other, ''who, "query_name" })
 *                 })
 *              })
 *     ]),
 *     ({ 'who })         // formatter will take one arg named 'who
 *   );
 * // this should write "devo"
 * write(funcall(formatter, FINDP("devo")));
 *
 * @param  format  the format string to parse
 * @param  infomap a map of format specifiers to the info array of how to
 *                 replace the specifier
 * @param  args    optional args that will be passed to the formatter
 *                 (single quoted)
 * @return         a formatter closure that takes specified args and will
 *                 produce formatted strings according to infomap
 */
protected closure parse_format(string format, mapping infomap, symbol *args) {
  object logger = LoggerFactory->get_logger(THISO);
  string output_fmt = "";
  mixed *output_args = ({ });

  string *parts = explode_format(format, "%");
  int size = sizeof(parts);

  output_fmt += parts[0]; // first part is always leading text (could be "")
  for (int i = 1; i < size; i++) {
    string part = unescape(parts[i]);
    if (!strlen(part)) { continue; } // most likely %% in the string
    int spec = part[0];

    if (!member(infomap, spec)) {
      logger->warn("Unknown format specifier: %c", spec);
      continue;
    }
    mixed *info = infomap[spec];

    string arg = info[DEFAULT_ARG];
    string extra = part[1..];
    if (strlen(part) > 1) {
      int pos = find_close_char(part, 1, ARG_OPEN, ARG_CLOSE);
      if (pos > 0) {
        arg = part[2..(pos - 1)];
        extra = part[(pos + 1)..];
      } else if (pos < 0) {
        logger->warn("Unmatched '%c': %%%s", part[1], part);
      }
    }

    output_fmt = sprintf("%s%s%s", output_fmt, info[SPRINTF_FMT], extra);
    output_args += funcall(
      reconstruct_lambda(({ 'arg }), info[FMT_LAMBDA]),
      arg); //'
  }

  return lambda(args, ({ #'sprintf, output_fmt }) + output_args); //'
}


/**
 * Explode a string into substrings by a delimiter, ignoring any escaped
 * delimiters, and delimiters nested within format parameters. See
 * explode_nested().
 *
 * @param  str    the string to explode
 * @param  delim  the string delimiting the substrings
 * @param  open   a string of OPEN characters; defaults to "\"([{"
 * @param  close  a string of CLOSE characters; defaults to "\")]}"
 * @return        an array of strings separated by the delimiter
 */
protected varargs string *explode_format(string str, string delim,
                                         string open, string close) {
  int delim_len = strlen(delim);
  if (delim_len == 0) {
    return explode(str, delim);
  }

  // If you explicitly specify 0 for open, you will get errors.
  if (!stringp(close)) {
    open  = ARG_OPEN;
    close = ARG_CLOSE;
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
      int tmp = 0;
      if (next_open > cursor) {
        tmp = 1;
      } else {
        next_open = cursor - 1;
        while ((next_open = searcha_any(str, open, next_open + 1)) != -1) {
          if ((next_open > delim_len) 
            && (str[(next_open - (delim_len + 1))..(next_open - 2)] 
                == delim)) {
            tmp = 1;
            break;
          }
        }
      }
      if (tmp && (next_open < next_delim)) {
        // Skip over the matching close char
        cursor = 1 + find_close_char(str, next_open, open, close);
        if( cursor <= 1 ) {
          // Something went wrong
          return 0;
        } 
      } else {
        result += ({ str[start..next_delim - 1] });
        cursor = next_delim + delim_len;
        start = cursor;
      }
    }
  }

  result += ({ str[start..] });

  return result;
}
