//	/cmds/mortal/_hp.c
//      -- seeker

#include <std.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;

int cmd_hp(string str) {
seteuid(UID_FORCE);   
      this_player()->force_me("status");
seteuid(getuid());
  return 1;
}

void help() {
    write("Syntax: <hp>\nTells you your vitals.");
}
