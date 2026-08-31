//      /bin/dev/_echo.c
//      from the Nightmare Mudlib
//      echoes to the player's environment
//      created by ????

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_echo(string str) {
    if(!str) {
        notify_fail("Echo what?\n");
        return 0;
    }
    message("environment", str, environment(this_player()));
    seteuid(UID_LOG);
    log_file("shouts", geteuid(previous_object())+" (echo): "+str+"\n");
    seteuid(getuid());
    return 1;
}

void help() {
    message("help",
      "Syntax: <echo [message]>\n\n"
      "Echoes the message to everyone in your environment.  Do not abuse "
      "this power or you will have to deal with law.", this_player());
}
