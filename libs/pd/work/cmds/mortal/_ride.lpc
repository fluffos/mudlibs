#include <std.h>

inherit DAEMON;

void help() { message("help", "See \"help mount\".", this_player() ); }

int cmd_ride(string str) {
  int ret;
  ret = load_object("/cmds/mortal/_mount")->cmd_mount(str);
  return ret;
}
