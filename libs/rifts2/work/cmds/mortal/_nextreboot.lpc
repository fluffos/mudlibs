/*    /cmds/mortal/_nextreboot.c
 *    from the Nightmare Mudlib 3.2
 *    Shows when the next reboot occurs
 *    created by Descartes of Borg 940130
 */

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_nextreboot(string str) {
    int x, hours;
    hours = (int)EVENTS_D->query_reboot_interval();
    if(!hours) {
      message("info", "Reboot Interval is disabled. No reboots.",this_player());
      return 1;
    }
    x = (int)EVENTS_D->query_next_reboot() - time();
    if(!(str = (string)this_player()->getenv("TZONE")))
     str = sprintf("%s PST", ctime(time() + x));
    else str = sprintf("%s %s", ctime((int)TIME_D->query_tzone(str) + x), str);
    message("info", sprintf("The next reboot will occurr at %s.", str),
      this_player());
    return 1;
}

void help() {
    message("help", "Syntax: <reboot>\n\n"
      "Tells you when the mud is scheduled for its next reboot.",
      this_player()
    );
}
