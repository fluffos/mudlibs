//	/cmds/mortal/_sleep.c
//      -- seeker

#include <std.h>
#include <daemons.h>

#define _PILLOW "/d/nopk/standard/obj/misc/pillow"
inherit DAEMON;

int cmd_sleep(string str) {
 if (this_player()->query_current_attacker())
   return notify_fail("You cannot sleep in battle.\n");
 if (this_player()->query_riding())
   this_player()->force_me("dismount");
 new(_PILLOW)->move(this_player());
 message("info", "You fall fast asleep, tired from exhaustion.", this_player());
 message("info", (string)this_player()->query_cap_name()+" falls fast asleep.", environment(this_player()), this_player());
  return 1;
}

void help() {
    write("Syntax: <sleep>\nA faster way to heal by sleeping.");
}
