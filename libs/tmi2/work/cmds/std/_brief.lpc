/*
// The "brief" command.
// toggle your verbosity.
// Part of the TMI mudlib, of course!
// Written by Buddha(2-19-92)
*/

#include <mudlib.h>

inherit DAEMON ;

int cmd_brief() {
   int brief;
   brief = (int)previous_object()->query("brief");
   if(brief) {
      write("Verbose mode.\n");
      this_player()->set("brief", 0);
   } else {
      write("Brief mode.\n");
      this_player()->set("brief", 1);
   }
   return 1;
}

string help() {
	return(@HELP
Syntax: brief

The brief command toggles your verbosity setting. If you are in verbose
mode you will see the long description of a room when you enter it, or
look in it. In breif mode, you will see the short description, which is
shorter but less detailed. Typing breif will change your mode and tell
you the new mode.
HELP
  );
}
