//      /bin/dev/_echo.c
//      from the Nightmare Mudlib
//      echoes to the player's environment
//      created by ????

#include <std.h>

inherit DAEMON;

int cmd_echo(string str) {
    if(!str) {
        notify_fail("Echo what?\n");
        return 0;
    }
    message("environment", str, environment(this_player()));
    return 1;
}

void help() {
    message("help",
      "Syntax: <echo [message]>\n\n"
      "Echoes the message to everyone in your environment.  Do not abuse "
      "this power or you will have to deal with law.", this_player());
}
