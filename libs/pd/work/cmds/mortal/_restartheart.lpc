//	/cmds/mortal/_restart.c
//      -- seeker

#include <std.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;

int cmd_restartheart(string str) {
 this_player()->net_dead();
 this_player()->restart_heart();
 message("info", "You now have your heart beat back.", this_player());
 return 1;
}

void help() {
    write("Syntax: <restartheart>\nGives you your heartbeat back "
          "if you have lost it. It is illegal to play the mud while "
          "abusing not having a heart beat. It is also illegal to "
          "attack monsters with no heart beat.", this_player());
}
