/*    /cmds/mortal/_version.c
 *    from Nightmare Mudlib 3.2
 *    gives version info about the mud and up time
 *    written by Descartes of Borg 940130
 */

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_version(string str) {
    int x;
    string tz;

    if(!(tz = (string)this_player()->getenv("TZONE"))) {
        tz = "PST";
        x = time() - uptime();
    }
    else x = (int)TIME_D->query_tzone(tz) - uptime();
    tz = sprintf("%s %s", ctime(x), tz);
    message("info", sprintf("%s (Driver: %s, Mudlib: %s %s)\nUp since: %s",
      mud_name(), version(), mudlib(), mudlib_version(), tz),
      this_player());
    return 1;
}

void help() {
    message("help", "Syntax: <version>\n\n"
      "Gives you version information about the LPMud as well as how "
      "long the mud has been up in your local time if you have it "
      "specified.", this_player()
    );
}
