// (??-??-96) Written by Chronos for wizards' convenience.
// (04-05-98) Touched up by Chronos to fit the new lib.

#include <mudlib.h>

inherit DAEMON ;

int cmd_showpath() {
  int x;
  x = this_player()->query("display_path");
  if (x == 0) {
    this_player()->set("display_path", 1);
    write("Now showing full pathnames.\n");
  }
  else {
    this_player()->set("display_path", 0);
    write("No longer showing pathnames.\n");
  }
  return 1;
}

int help() {
  write(@ENDTEXT
Usage: showpath

This command toggles the displaying off pathnames while you are
moving about rooms.

ENDTEXT
  );
  return 1 ;
}
