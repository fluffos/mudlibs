#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

int cmd_setreboot(string str) {
    int x;

    if(!str || !archp(previous_object())) return 0;
    sscanf(str, "%d", x);
    EVENTS_D->set_reboot_interval(x);
    message("info", "Reboot interval set to "+str+" hours.", this_player());
    return 1;
}

void help() {
    message("help", "Syntax: <setreboot [interval]>\n\n"
      "Sets up the interval at which the mud will automatically reboot.  "
      "The interval should be specified in hours.",
      this_player()
    );
}
