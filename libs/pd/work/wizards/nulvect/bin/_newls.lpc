
#include <std.h>

inherit DAEMON;

class FileEntry {
  string name;
  string fullpath;
  string ext;
  string color;
  int type;
  int size;
  int accesstime;
  int loadtime;
};

mapping filetypes = ([
  "none" : 0,
  "dir" : 1,
  "exec" : 2,
  "hidden" : 4,
]);

mapping type_colors = ([
  1 : "%^BOLD%^%^BLUE%^", // dir
  2 : "%^ORANGE%^", // exec
  4 : "%^BOLD%^%^BLACK%^", // hidden
]);

mapping extension_colors = ([
  "c" : "%^CYAN%^",
  "h" : "%^BOLD%^%^CYAN%^",
  "bak" : "%^GREEN%^",
]);

mapping options = ([
  "l" : 1,
  "b" : 2,
  "a" : 4,
]);

void parse_args(string, int ref, string ref *);
class FileEntry *get_file_list(object, string, string *);

// this function does a lot, including removing nonexistant filenames from
//   the list and spitting out errors for them
class FileEntry get_entry_info(
  class FileEntry, int, string *, int ref, int ref, string *
);
void set_entry_type(class FileEntry, string *);
string get_entry_color(class FileEntry);
string get_entry_output(class FileEntry, int, int);
string *resolve_wildcards(object tp, string cwd, string filename);

int cmd_newls(string str) {
  object tp = this_player();
  class FileEntry *files;
  string cwd;
  string *filenames;
  string *searchpaths;
  string *errors = ({});
  int opts = 0;
  int screen;
  int cols;
  int colwidth;
  int colheight;
  int longest;
  int totalsize;
  string out = "";
  string finishtext;

  cwd = tp->get_path();
  searchpaths = tp->query_search_path();
  screen = to_int(tp->query_env("SCREEN"));
  if (!screen)
    screen = 80;
  screen -= 1;

  // split the argument string into command options and filenames to list
  parse_args(str, ref opts, ref filenames);

  // populate the file list (names only), sort it as well
  files = get_file_list(tp, cwd, filenames);

  // get all the info needed for each entry and put it in the "output" section
  // also calculates the longest output entry and total file size
  files = map(files, (: get_entry_info($1, $2, $3, $4, $5, $6) :),
    opts, searchpaths, ref longest, ref totalsize, errors);
  files = filter(files, (: $1 :) );

  /*
  for (int i = 0; i < sizeof(files); i++)
    files[i] = get_entry_info(files[i], opts, cwd, searchpaths, ref longest, ref totalsize);
  */

  // only one column for long listings
  if (opts & options["l"]) {
    colwidth = screen - 2;
    cols = 1;
    colheight = sizeof(files);
  }
  else {
    colwidth = longest+8;
    cols = screen / colwidth;
    colheight = sizeof(files) / cols;
    if (sizeof(files) % cols)
      colheight += 1;
  }

  // print every COLth entry so it looks like we're printing in columns downward
  for (int i = 0; i < colheight; i++) {
    for (int j = 0; j < cols; j++) {
      int which = i + (colheight * j);
      if (which < sizeof(files)) {
	out += get_entry_output(files[which], colwidth, opts);
      }
    }
    out += "\n";
  }

  /*
  for (int i = 0; i < sizeof(files)+cols+1; i += cols) {
    if (i = sizeof(files)) {
      i = i - sizeof(files);
      out += "\n";
      // spit it all out periodically to avoid the max printable string limit
      if (sizeof(out) > 2048) {
        message("system", out, tp);
        out = "";
      }
    }
    out += arrange_string("  "+get_entry_output(files[i], colwidth, opts) );
  }
  */

  out += implode(errors, "\n");
  out +=
    "A total of "+add_commas(totalsize)+" bytes in "+
    sizeof(filter(files, (: !($1->type & $2["dir"]) :), filetypes))+" files and "+
    sizeof(filter(files, (: $1->type & $2["dir"] :), filetypes))+" directories.";

  tp->more(explode(out, "\n"), "system");

  return 1;
}

void parse_args(string args, int ref opts, string ref *filenames) {
  opts = 0;
  filenames = ({});

  while (sizeof(args)) {
    int space;
    string word;

    space = strsrch(args, " ");
    if (space == -1) {
      word = args;
      args = 0;
    }
    else {
      word = args[0 .. space-1];
      args = args[space+1 .. <1];
    }

    if (word[0..0] == "-") {
      foreach (string k, int v in options) {
        if (strsrch(word, k) != -1) {
          opts |= v;
        }
      }
    }

    else {
      filenames += ({ word });
    }
  }
}

class FileEntry *get_file_list(object tp, string cwd, string *filenames) {
  class FileEntry *files = ({});

  if (!sizeof(filenames)) {
    if (cwd == "/")
      filenames = ({ "/*" });
    else
      filenames = ({ "*" });
  }

  // nested loops are bad, optimize this later
  // done this way so that dirs typed specifically on the command line
  // will have their contents listed instead of just showing the dir's entry
  foreach (string fn in filenames) {
    string *resolved;
    if (fn == "/")
      fn = "/*";
    resolved = resolve_wildcards(tp, cwd, fn);
    foreach (string re in resolved) {
      string *path = path_file(re);
      class FileEntry f = new(class FileEntry);
      if (file_size(re) == -2) {
	if (re[<1..<1] != "/") re += "/*";
	else re += "*";
      }
      printf("debug: re = %O\n", re);
      f->fullpath = re;
      f->size = file_size(re);
      if (f->size == -2) {
	int slash = strsrch(f->fullpath, "/", -1);
	if (slash == strlen(f->fullpath)-1)
	  slash = strsrch(f->fullpath[0..<2], "/", -1);
	f->name = f->fullpath[slash+1 .. <1] + "/";
      }
      else
	f->name = path[1];
      f->type = 0;
      files += ({ f });
    }
  }

  return files;
}

// code intended to be used as a simulefun
string *resolve_wildcards(object tp, string cwd, string filename) {
  string *ret = ({});

  if (!tp || !filename || !sizeof(filename))
    return 0;

  // TODO:
  // resolve wildcards and special entries here
  // see /adm/simul_efun/resolv_path.c and
  // /std/user/wildcard.c and basically combine them

  return tp->wild_card(filename);

}

class FileEntry get_entry_info(
class FileEntry entry, int opts, string *searchpaths,
int ref longest, int ref totalsize, string *errors) {

  int len;
  
  // at this point, name and size are set, and type is 0 ("none")

  if (entry->size == -1) {
    errors += ({ entry->fullpath+": no such file or directory" });
    return 0;
  }

  set_entry_type(entry, searchpaths);

  if (!(opts & options["a"]) && entry->type & filetypes["hidden"])
    return 0;

  if (entry->type & filetypes["dir"]) {
    mixed *dir_stat;
    if (entry->fullpath[<1..<1] != "/")
      entry->fullpath += "/";
    // have to stat it without a / on the end!
    dir_stat = get_dir(entry->fullpath[0..<2], -1);
    entry->accesstime = dir_stat[0][2];
  }

  else {
    int *stat_info = stat(entry->fullpath);
    entry->accesstime = stat_info[1];
    entry->loadtime = stat_info[2];
  }

  entry->color = get_entry_color(entry);

  if (entry->size > 0)
    totalsize = totalsize + entry->size;

  len = strlen(entry->name);
  if (len > longest)
    longest = len;

  return entry;
}

string get_entry_output(class FileEntry entry, int width, int opts) {

  string d, r, w, x, loaded, time;
  int size, pad;
  string *path;
  string output;

  if (entry->loadtime)
    loaded = "*";
  else
    loaded = " ";

  if (opts & options["b"]) {
    size = entry->size;
  }
  else {
    size = entry->size / 1024;
    if (size == 0)
      size = 1;
  }

  if (opts & options["l"]) {
    if (entry->type & filetypes["dir"])
      d = "d";
    else
      d = "-";
    if (master()->valid_read(entry->fullpath, this_player(), ""))
      r = "r";
    else
      r = "-";
    if (master()->valid_write(entry->fullpath, this_player(), ""))
      w = "w";
    else
      w = "-";
    if (entry->type & filetypes["exec"])
      x = "x";
    else
      x = "-";
    time = ctime(entry->accesstime);

    pad = width - (strlen(d+r+w+x+loaded+time+entry->name) + 8);

    output = sprintf(
      "%s%s%s%s  %s  %*d  %s  %s%s%s",
      d, r, w, x, loaded, pad, size, time, entry->color, entry->name, "%^RESET%^"
    );
  }
  else {

    // put a space in front and in back
    pad = width - (strlen(loaded+entry->name)+1+2+1+1);

    output = sprintf(
      " %s%2d %s%s%-*s",
      loaded, size, entry->color, entry->name, pad, "%^RESET%^"
    );
  }

  return output;
}

void set_entry_type(class FileEntry entry, string *searchpaths) {
  int dot = strsrch(entry->name, ".", -1);
  string path;
  string ext;
  
  if (dot != -1) {
    ext = entry->name[dot+1 .. <1];
    if (ext[<1..<1] == "/")
      ext = ext[0..<2];
    entry->ext = ext;
  }

  if (entry->size == -2)
    entry->type |= filetypes["dir"];

  path = entry->fullpath[0 .. <(strlen(entry->name)+2)];
  if (member_array(path, searchpaths) != -1 && ext == "c" && entry->name[0..0] == "_")
    entry->type |= filetypes["exec"];

  if (entry->name[0..0] == ".")
    entry->type |= filetypes["hidden"];

}

string get_entry_color(class FileEntry entry) {
  string ret = "";
  if (entry->ext && extension_colors[entry->ext])
    ret += extension_colors[entry->ext];
  foreach (int type, string col in type_colors)
    if (entry->type & type)
      ret += col;
  return ret;
}
