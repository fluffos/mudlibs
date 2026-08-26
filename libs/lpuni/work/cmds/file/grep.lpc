/*
 * Copyright 2006 Doug Swarin (Zac@StarMUD)
 *   http://www.starmud.com/
 *   telnet://home.starmud.com:4000
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *
 * Simple 'grep' command for LPUni, ported from StarMUD's grep.
 *
 * Also includes the following functions which would make useful simuls:
 *   abs()
 *   getopt()
 *   glob_array()
 *
 */

#define GETOPT_NOQUOTES         (1 << 0)
#define GETOPT_KEEPQUOTES       (1 << 1)
#define GETOPT_KEEPSPACES       (1 << 2)

mixed abs (mixed val) {
  if (val < 0)
    return -val;
  return val;
}

varargs mixed *getopt (string str, string opts, int flags) {
  int i, j, k, optslen, elemlen, quote = 0, parse = 1;
  string elem, into, quoted, *list;
  mapping opt = ([ ]);
  mixed *ret = ({ opt });

  if (!stringp(str) || str == "")
    return ret;

  if (!(flags & GETOPT_NOQUOTES)) {
    str = replace_string(str, "\t", " ");
    str = replace_string(str, "\n", " ");
  }

  if (!stringp(opts))
    opts = "";

  optslen = strlen(opts);
  into    = 0;
  list    = explode(str, " ");

  for (i = 0; i < sizeof(list); i++) {
    elem    = list[i];
    elemlen = strlen(elem);

    if (parse && !into && elem[0] == '-') {
      if (elem == "--") {
        parse = 0;
        continue;
      }

      for (j = 1; j < elemlen; j++) {
        if (elem[j] == ':' || (k = strsrch(opts, elem[j])) < 0) {
          opt["?"] = 1;
          return ret + list[i..];
        }

        if (k < optslen && opts[k + 1] == ':') {
          if (j < elemlen - 1) {
            opt["?"] = 1;
            return ret + list[i..];
          }

          into = elem[j..j];
        } else
          opt[elem[j..j]] = 1;
      }

      continue;
    }

    if (parse && !into)
      parse = 0;

    if (quote) {
      if (elemlen > 1 && elem[<1] == quote && elem[<2] == '\\') {
        quoted += " " + elem[0..<3] + elem[<1..];
        continue;
      } else if (elem[<1] == quote) {
        if (into) {
          if (flags & GETOPT_KEEPQUOTES)
            opt[into] = quoted + " " + elem;
          else
            opt[into] = quoted + " " + elem[0..<2];

          into = 0;
        } else {
          if (flags & GETOPT_KEEPQUOTES)
            ret += ({ quoted + " " + elem });
          else
            ret += ({ quoted + " " + elem[0..<2] });
        }

        quote = 0;
        continue;
      }

      quoted += " " + elem;
    } else {
      if (!(flags & GETOPT_NOQUOTES) && (elem[0] == '\'' || elem[0] == '"' || elem[0] == '`')) {
        if (elemlen < 2 || elem[<1] != elem[0] || elem[<2] == '\\') {
          quote = elem[0];

          if (flags & GETOPT_KEEPQUOTES)
            quoted = elem;
          else
            quoted = elem[1..];

          continue;
        }

        if (!(flags & GETOPT_KEEPQUOTES))
          elem = elem[1..<2];
      }

      if (into) {
        opt[into] = elem;
        into = 0;
      } else if (elem != "" || (flags & GETOPT_KEEPSPACES))
        ret += ({ elem });
    }
  }

  if (quote) {
    if (into)
      opt[into] = quoted;
    else
      ret += ({ quoted });
  }

  return ret;
}

varargs string *glob_array (string *paths, string cwd) {
  int i;
  string root, *path, *globbed;

  if (!stringp(cwd))
    cwd = "/";

  paths = map(paths - ({ "" }), (: resolve_path($2, $1) :), cwd);

  for (i = 0; i < sizeof(paths); i++) {
    if (sizeof(path = explode(paths[i], "/") - ({ "" })) < 1) {
      paths[i] = "/";
      continue;
    }

    if (strsrch(path[<1], "?") >= 0 || strsrch(path[<1], "*") >= 0) {
      if (pointerp(globbed = get_dir("/" + implode(path, "/"))))
        globbed -= ({ ".", ".." });
      else
        globbed = ({ });

      root = replace_string("/" + implode(path[0..<2], "/") + "/", "//", "/");

      paths = paths[0..(i - 1)] +
              map(globbed, (: $2 + $1 :), root) +
              paths[(i + 1)..];

      i += sizeof(globbed) - 1;
    }
  }

  return paths;
}

private string grep_file (mapping opt, string pat, string file) {
  int i, j, match, color = 0;
  string line;
  mixed lines, *assoc;
  mapping matches;

  if (!stringp(lines = read_file(file)) || !strlen(lines))
    return "";

  color   = !opt["x"] && !opt["v"] && (strsrch(pat, "%^") < 0);

  lines   = explode(lines, "\n");
  lines   = map(lines, (: replace_string($1, "%^", "%%^^") :));
  matches = ([ ]);

  if (lines[<1] == "")
    lines = lines[0..<2];

  for (i = 0; i < sizeof(lines); i++) {
    line = lines[i];

    if (opt["i"])
      line = lower_case(line);

    if (opt["x"])
      match = (line == pat);
    else if (opt["F"])
      match = strsrch(line, pat) >= 0;
    else
      match = regexp(line, pat);

    if (opt["v"])
      match = !match;

    if (!match)
      continue;

    if (opt["a"]) {
      for (j = (i + 1); j <= (i + opt["a"]); j++) {
        if (j >= sizeof(lines))
          break;
        if (matches[j])
          continue;

        matches[j] = lines[j];
      }
    }

    if (opt["b"]) {
      for (j = (i - opt["b"]); j < i; j++) {
        if (j < 0)
          continue;
        if (matches[j])
          continue;

        matches[j] = lines[j];
      }
    }

    if (color) {
      if (opt["F"]) {
        line = replace_string(lines[i], pat, "%^B_WHITE%^%^BLACK%^" + pat + "%^RESET%^");
      } else {
        assoc = reg_assoc(lines[i], ({ pat }), ({ 1 }), 0);

        for (j = 0; j < sizeof(assoc[0]); j++) {
          if (assoc[1][j])
            assoc[0][j] = "%^B_WHITE%^%^BLACK%^" + assoc[0][j] + "%^RESET%^";
        }

        line = implode(assoc[0], "");
      }
    } else
      line = lines[i];

    matches[i] = line;

    if (opt["l"] || opt["L"])
      break;
  }

  if (sizeof(matches) > 0) {
    if (opt["l"])
      return file;
    else if (opt["L"])
      return "";
    else if (opt["c"])
      return sprintf("%d matching lines found in %s", sizeof(matches), file);

    lines = sort_array(keys(matches), 0);

    for (i = 0; i < sizeof(lines); i++) {
      line = matches[lines[i]];

      if (opt["n"])
        line = "%^BOLD%^" + sprintf("%4d", lines[i] + 1) + "%^RESET%^  " + line;

      lines[i] = line;
    }

    return implode(lines, "\n");
  } else if (opt["L"]) {
    return file;
  }

  return "";
}

int main (string str) {
  int i;
  mixed *opt;
  string out, *files;

  if (sizeof(opt = getopt(str, "a:b:cilmnvxEFLMR:")) < 2 || opt[0]["?"])
    return notify_fail("Type 'help grep' for information on how to use this command.\n");

  if (sizeof(opt) < 3) {
    if (opt[0]["R"])
      str = this_player()->query("cwd");
    else
      str = this_player()->query("cwf");

    if (!stringp(str))
      return notify_fail("Type 'help grep' for information on how to use this command.\n");

    opt += ({ str });
  }

  if (opt[0]["E"])
    opt[0]["F"] = 0;
  if (opt[0]["M"])
    opt[0]["m"] = 0;

  if (opt[0]["a"])
    opt[0]["a"] = abs(to_int(opt[0]["a"]));
  if (opt[0]["b"])
    opt[0]["b"] = abs(to_int(opt[0]["b"]));

  if (opt[0]["i"])
    opt[1] = lower_case(opt[1]);

  if (opt[0]["R"]) {
    string dir, *r;

    r     = ({ });
    files = filter(glob_array(opt[2..], this_player()->query("cwd")),
      (: file_size($1) == -2 :));

    while (sizeof(files) > 0) {
      dir   = files[0];
      files = files[1..];

      r     = r + filter(glob_array(({ dir + "/" + opt[0]["R"] }), "/"), (: file_size($1) >= 0 :));
      files = filter(glob_array(({ dir + "/*" }), "/"), (: file_size($1) == -2 :)) + files;
    }

    files = r;
  } else {
    files = glob_array(opt[2..], this_player()->query("cwd"));

    if (sizeof(files) == 1 && file_size(files[0]) == -2)
      files = glob_array(({ files[1] + (files[1][<1] == '/' ? "*" : "/*") }),
        this_player()->query("cwd"));

    files = filter(files, (: file_size($1) >= 0 :));
  }

  if (sizeof(files) < 1) {
    write("No files found.\n");
    return 1;
  }

  if (!opt[0]["F"] && (str = catch(regexp("", opt[1])))) {
    write("Invalid regular expression: " + str);
    return 1;
  }

  out = "";

  for (i = 0; i < sizeof(files); i++) {
    str = grep_file(opt[0], opt[1], files[i]);

    if (str != "") {
      if (opt[0]["c"] || opt[0]["l"] || opt[0]["L"]) {
        out = out + str + "\n";
      } else {
        if (out != "")
          out = out + "\n";

        out = out + "[" + files[i] + "]\n" + str + "\n";
      }
    }
  }

  if (opt[0]["m"] && strlen(out) < __LARGEST_PRINTABLE_STRING__) {
    write(out + "\n");
  } else {
    object pager;

    pager = clone_object("/obj/mudlib/pager/pager");
    pager->page(out, "grep " + opt[1] + " (in " + implode(opt[2..], " ") + ")");
  }

  return 1;
}

string help () {
  return "\
Usage: grep [-cilmnvxEFLM] [-a after] [-b before] [-R glob] 'pattern' <files>
  -i  Search case-insensitively
  -n  Display the line number before each matched line
  -v  Search for lines that do not have the specified pattern
  -x  Search only for lines that exactly match the specified pattern

  -c  Display a count of matching lines rather than matching lines
  -l  Display file names that have the matching pattern
  -L  Display file names that do not have the matching pattern
" "
  -a  Display the specified number of lines after each match
  -b  Display the specified number of lines before each match

  -E  Search using regular expressions (default; overrides -F)
  -F  Search using straight text search

  -R  Recurse into directories using the specified glob

  -m  Do not pause after each screen of text
  -M  Pause after each screen of text (default; overrides -m)
" "
The 'grep' command searches for text in one or more files. By default, it
searches using regular expressions (type 'man regexp' for information on
these).
";
}
