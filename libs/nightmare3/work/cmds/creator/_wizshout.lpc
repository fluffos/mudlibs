//    /cmds/creator/_wizshout.c
//    Nightmare mudlib
//    Global shout for Immortals
//    by Kalinash April 17, 1994.

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_wizshout(string drow) {
    if(!drow)
        return notify_fail("Shout what?\n");
    message("shout", sprintf("%s shouts: %s", this_player()->query_cap_name(),
      drow), users());
    log_file("shouts", (string)previous_object()->query_CapName()+" (wizshout): "+drow+"\n");
    return 1;
}
