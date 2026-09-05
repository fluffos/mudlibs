/*
 * /basic/coloured_string.c
 *
 * This is a basic class for handling coloured strings.
 */

#pragma strong_types

#include <regexps.h>
#include <libs.h>

/*
 * this applies `changer' on all parts of the given coloured_string
 * which are not a colour token and returns the result.
 */
string apply_on_coloured_string(string coloured_string,closure changer) {
  mixed h;
  int i;
  h = regexplode(coloured_string,REGEXP_TERMINAL_COLOUR_TOKEN);
  for (i=0; i<sizeof(h); i+=2)  // pick the non-tokens
    h[i] = funcall(changer,h[i]);
  return implode(h,"");
}

/*
 * this removes all colour tokens from the given coloured_string and
 * returns the result; thus it produces a verbatim string.
 */
string to_verbatim(string coloured_string) {
  return terminal_colour(coloured_string,(: "" :));
}

/*
 * this returns the visible string length of a coloured string
 */
int strlen_visible(string coloured_string) {
  return strlen(terminal_colour(coloured_string,(: "" :)));
}

private void find_pos(string *parts,
                      int pos,status pos_from_back,
                      int real_part,int real_pos,
                      status as_start) {
  if (pos_from_back) {
    if (pos < 0) {
      real_part = sizeof(parts) - 1;
      real_pos = strlen(parts[<1]);
    } else {
      pos = strlen_visible(implode(parts,"")) - pos;
      find_pos(parts,pos,0,&real_part,&real_pos,as_start);
    }
  } else {  // from front
    // skip all parts which are too short:
    for (real_part = real_pos = 0;
         real_part < sizeof(parts) && (as_start?
                                       pos > strlen(parts[real_part]) :
                                       pos >= strlen(parts[real_part]));
         real_pos += strlen(parts[real_part]),
         pos -= strlen(parts[real_part]),
         real_part += 2)
      ;
    if (real_part >= sizeof(parts)) {  // too long?
      real_part = sizeof(parts) - 1;
      real_pos = strlen(parts[<1]);
    } else
      real_pos = pos;
  }
}

/*
 * this returns a substring of the given coloured string;
 */
varargs string substring(string coloured_string,
                         int start,             int stop,
                         status start_from_back,status stop_from_back) {
  string *parts;
  int *real_pos, *vis_pos;
  int i;
  int real_start_pos,real_stop_pos;
  int real_start_part,real_stop_part;
  parts = regexplode(coloured_string,REGEXP_TERMINAL_COLOUR_TOKEN);
  find_pos(parts,start,start_from_back,&real_start_part,&real_start_pos,1);
  find_pos(parts, stop, stop_from_back, &real_stop_part, &real_stop_pos,0);
  if (real_start_part > real_stop_part)
    return "";
  if (real_start_part == real_stop_part)
    parts[real_start_part] =
      parts[real_start_part][real_start_pos..real_stop_pos];
  else {
    parts[real_start_part] = parts[real_start_part][real_start_pos..];
    parts[real_stop_part]  = parts[real_stop_part][..real_stop_pos];
  }
  return implode(parts[real_start_part..real_stop_part],"");
}

/* this version of sprintf() is meant _only_ for string arguments (%s) which
 * are using widths given via an asterisk (%*s), e.g.
 *   coloured_sprintf("bla %-*s foo %*s bar",20,"bf",10,"fb")
 * and it then works properly even if the arguments "bf" and "fb" contain
 * colourization tokens (e.g. "%^GREEN%^")
 */
varargs string coloured_sprintf(string format,varargs mixed *args) {
  int i;
  int strlen_diff;
  for (i=0; i<sizeof(args); i+=2)
    if (stringp(args[i+1])) {
      strlen_diff = strlen(args[i+1]) - strlen_visible(args[i+1]);
      if (args[i] < 0)
        args[i] -= strlen_diff;
      else
        args[i] += strlen_diff;
    }
  return apply(#'sprintf,format,args);
}

varargs string* wrap_coloured_line(string line, int column, int indent,
                                   int first_line) {
  string verbatim_line, *wrapped_lines, *result_lines;
  int li, ri, j;

  verbatim_line = to_verbatim(line);
  li = 0; ri = 0;
  wrapped_lines = explode(break_string(verbatim_line, column-indent),
                          "\n") - ({ "" });
  result_lines = ({ });
  for (j = 0; j < sizeof(wrapped_lines); j++) {
    li = strstr(verbatim_line, wrapped_lines[j], 0);
    ri = li + strlen(wrapped_lines[j]) - 1;
    if (!sizeof(result_lines) && !!first_line) {  // handle special first line
      result_lines += ({ subcoloured_string(line, li, ri) });
    } else {
      result_lines += ({ (indent > 0 ? indent * " " : "") +
                                   subcoloured_string(line, li, ri) });
    }
  }
  // search through the last line from behind for the first newline
  // to cut it, thus preventing an empty line between long and exits
  ri = sizeof(result_lines) && (strlen(result_lines[<1]) - 1);
  while (ri > 0) {
    if (!strlen_visible(result_lines[<1][ri..ri])) {
      ri--;
      continue;
    }
    if (result_lines[<1][ri] == '\n') {
      if (ri > 0)
        result_lines[<1] = result_lines[<1][0..ri-1] + result_lines[<1][ri+1..];
      else
        result_lines[<1] =                             result_lines[<1][ri+1..];
      break;
    }
    ri--;
  }
  return result_lines;
}


