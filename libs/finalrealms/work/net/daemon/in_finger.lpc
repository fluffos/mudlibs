#include "inet.h"
mapping close_up, colour_map;
#define CHAR "/net/daemon/chars/"
#include "term.h"

void create() {
  seteuid(getuid());
  close_up = ([ ]);
  colour_map = ([ ]);
} /* create() */

string fix_string(string bing);

void read_callback(int fd, string mess) {
  string str, rest;
  object ob;

  sscanf(mess, "%s\n%s", mess, rest);
  if (!rest) rest = "";
  rest = replace(rest, ({ "\r", "", "\n", "" }));
  if (mess != "EVERYONE" && mess != "") {
    str = (string)"/secure/finger"->finger_info(mess);
    if (rest != "discworld" && str)
      str = fix_string(str);
    if (!str) {
      previous_object()->write_fd(fd, "No one called "+mess+" has ever "+
                                      "visited "+MUD_NAME+".\n");
    } else {
      previous_object()->write_fd(fd, str);
    }
    previous_object()->close_fd(fd); /* Close once flushed */
    if (find_player(mess)) {
      ob = clone_object(CHAR+"in_finger_demon");
      ob->setup_finger(mess);
    }
  } else {
/*
 * Ok... In here we need to get the long finger list.
 * Which list shall we use?
 * Who list seems appropriate to me.
 */
    str = (string)"/global/player"->who_string(75);
    if (rest != "discworld" && str)
      str = fix_string(str);
    if (!str) {
      previous_object()->write_fd(fd, "Some sort of fun internal error "+
                                      "occured.  You are happy.\n");
    } else {
      previous_object()->write_fd(fd, str);
    }
    previous_object()->close_fd(fd);
  }
} /* read_callback() */

string fix_string(string ret) {
  string *st;
  int i, off, oct;

  if (!stringp(ret) || ret == "")
    return ret;
  if (!colour_map) {
    colour_map = TERM_HANDLER->set_term_type("dumb");
    colour_map["RESET"] = "";
  }
  st = explode(ret, "%^");
  ret = "";
  for (i=0;i<sizeof(st);i++)
    if (stringp(colour_map[st[i]]))
      ret += colour_map[st[i]];
    else
      ret += st[i];
  return ret;
} /* fix_string() */
