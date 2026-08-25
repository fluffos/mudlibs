/*    /cmds/mortal/_wimpydir.c
 *    from Nightmare IV
 *    allows a mortal to set which direction they will wimpy in
 *    created by Descartes of Borg 940409
 */

#include <std.h>

inherit DAEMON;

#define VALID_EXITS ({ "north", "south", "east", "west", "northwest",\
"northeast", "southwest", "southeast", "up", "down",\
"out", "exit" })

int cmd_wimpydir(string str) {
    if(!str) {
        message("system", sprintf("Wimpy direction set to %s.",
          (string)this_player()->query_wimpydir()), this_player());
        return 1;
    }
    if(member_array(str, VALID_EXITS) == -1) {
        message("system", "Invalid direction.", this_player());
        return 1;
    }
    this_player()->set_wimpydir(str);
    message("system", "Wimpyrdir now set to: "+str, this_player());
    return 1;
}

void help() {
    message("help", "Syntax: <wimpydir ([dir])>\n\n"
      "If you specify a direction, then when you wimpy, you will "
      "first try to wimpy in that direction.  If you do not "
      "specify a direction, it will tell you your current direction "
      "of preference.", this_player());
}
