/* printerrors command */

#include <log.h>
#include <board.h>

inherit ERRORS_BASE;

class bugs {
   int bugs;
   string file;
   string *dirs;
}

#define BUGS ((class bugs)print_globvars[player])->bugs
#define FILE ((class bugs)print_globvars[player])->file
#define DIRS ((class bugs)print_globvars[player])->dirs

private nosave mapping print_globvars;

protected string get_bug(string player, int i);
void start_collect(string player, string dir, int recurse);

protected void create() {
  print_globvars = ([]);
}

int cmd(string str) {
  string player, ret;

  if (str) {
    if (str[0] != '/')
      str = this_player()->query_current_path() + "/" + str;
    if (str[<1] == '0')
      str = str[0..<2];
    if (str[<1] == '/')
      str = str[0..<2];
    player = this_player()->query_name();

    if (!print_globvars[player]) {
      print_globvars[player] = new(class bugs);
      DIRS = ({ str });
      FILE = "/w/"+ player +"/print_errors.txt";
      write_file(FILE, "", 1);
    } else {
      DIRS += ({ str });
    }
    if ((ret = init_errors(player, "errors"))) {
      printf("Error connecting to the errors database: %s\n", ret);
      map_delete(print_globvars, player);
      return 1;
    }
    write("%^YELLOW%^Starting to collect bugreports, this may take a "
          "while.%^RESET%^\n");
    call_out("collect_in_one", 1, player, 1);
    return 1;
  } else
    return notify_fail("Usage:\nprinterrors <path>\n note that this will "
                       "overwrite any previous print_errors.txt file\n");
}

void start_collect(object player_ob, string *dirs, int recurse) {
  string player, ret;

  player = player_ob->query_name();

  if (!print_globvars[player]) {
    print_globvars[player] = new(class bugs);
    DIRS = copy(dirs);
    FILE = "/w/"+ player +"/print_errors.txt";
    write_file(FILE, "", 1);
  } else {
    tell_object(player_ob, "Already collecting error reports.\n");
    return;
  }
  if ((ret = init_errors(player, "errors"))) {
    tell_object(player_ob,
                sprintf("Error connecting to the errors database: %s\n", ret));
    map_delete(print_globvars, player);
    return;
  }
  tell_object(player_ob,
              "%^YELLOW%^Starting to collect bugreports, this may take a "
              "while.%^RESET%^\n");
  call_out("collect_in_one", 1, player, recurse);
}

protected void collect_in_one(string player, int recurse) {
  string dir, bug, *dirs;
  mixed ret;
  int i;

  dirs = DIRS;
  if (sizeof(dirs)) {
    dir = dirs[0];
    if (sizeof(dirs) > 0) {
      dirs = dirs[1..];
    } else {
      dirs = ({ });
    }
    DIRS = dirs;
    if (dir[<1] == '/') {
      dir = dir[0..<2];
    }
    if (recurse) {
      ret = sql_query(player, "SELECT Id, EntryDate, Filename, Category, "
                      "Type, Name, Reporter, Report, Runtime FROM errors "
                      "WHERE Directory LIKE '%s%%' AND Status = 'OPEN' "
                      "ORDER BY DirEntryDate;", dir);
    } else {
      ret = get_fields(player, dir, "Id, EntryDate, Filename, Category, Type, "
                       "Name, Reporter, Report, Runtime");
    }
    if (stringp(ret)) {
      tell_object(find_player(player), sprintf("Error fetching reports from "
                                               "%s : %s\n", dir, ret));
      return;
    }
    BUGS = ret;
    i = 1;
    for (i = 1; i <= ret; i++) {
      bug = get_bug(player, i);
      if (bug) {
        write_file(FILE, bug, 0);
      }
    }
    call_out("collect_in_one", 1, player, recurse);
  } else {
    tell_object(find_player(player),
                "%^YELLOW%^Finished printing bugreports.%^RESET%^\n");
    finish_errors(player);
    map_delete(print_globvars, player);
  }
}

protected string get_bug(string player, int i) {
  int rtime;
  string bug, ret, title, filename, name;
  mixed res, forwards, comments;

  if ((BUGS == 0) || (i > BUGS))
    return 0;
  res = get_row(player, i);
  if (stringp(res)) {
    return sprintf("Error getting report %d : %s\n", i, res);
  }
  title = sprintf("%s %s %s", res["Category"], res["Type"], res["Name"]);
  filename = res["Filename"];
  name = res["Reporter"];
  bug = res["Report"];
  if (res["Runtime"] && (res["Runtime"] != "")) {
    bug += "[RUNTIME]\n" + res["Runtime"];
  }
  forwards = get_forwards(player, i);
  if (stringp(forwards)) {
    return sprintf("Error getting forward info for report %d : %s\n", i,
                   forwards);
  }
  comments = get_comments(player, i);
  if (stringp(comments)) {
    return sprintf("Error getting comments for report %d : %s\n", i,
                   comments);
  }
  ret = sprintf("%s\n", title);
  ret += sprintf("%s\n", filename);
  if (sizeof(forwards)) {
    string *fdirs = forwards["OldDirectory"], *fnames = forwards["Forwarder"];
    int size, *ftimes = forwards["ForwardDate"];

    size = sizeof(fdirs);
    for (i = 0; i < size; i++) {
      ret += sprintf("Forwarded by   : %s\n", capitalize(fnames[i]));
      if (fdirs[i] != "") {
        ret += sprintf("from           : %s\n", fdirs[i]);
      }
      ret += sprintf("at             : %s\n", ctime(ftimes[i]));
    }
  }
  ret += sprintf("Made by        : %s\n", capitalize(name));
  rtime = res["EntryDate"];
  ret += sprintf("at             : %s\n\n", ctime(rtime));
  ret += bug;
  if (sizeof(comments)) {
    string *ctexts = comments["Comment"], *cnames = comments["Commenter"];
    int size, *ctimes = comments["CommentDate"];

    size = sizeof(ctexts);
    for (i = 0; i < size; i++) {
      ret += sprintf("\nComment by     : %s\n", capitalize(cnames[i]));
      ret += sprintf("at             : %s\n", ctime(ctimes[i]));
      ret += ctexts[i];
    }
  }
  return ret;
} /* get_bug() */

void dest_me() {
  string user;

  if (sizeof(print_globvars)) {
    foreach(user in values(print_globvars)) {
      finish_errors(user);
    }
  }
  destruct(this_object());
}

mixed *stats() {
  mixed *tmp;
  object key;
  class bugs value;

  tmp = ({ });
  foreach (key, value in print_globvars) {
    if (sizeof(value->dirs))
      tmp += ({ ({ key, sprintf("at %s (%d left)",
                                value->dirs[0], sizeof(value->dirs)) }) });
    else
      tmp += ({ ({ key, "finished" }) });
  }
  if (!sizeof(tmp)) return 0;
  return tmp;
} /* stats() */
