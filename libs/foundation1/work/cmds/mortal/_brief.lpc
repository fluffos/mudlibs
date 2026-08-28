/*    /cmds/mortal/_brief.c
 *    from Foundation
 *    sets a person's "look" mode
 *    created by Descartes of Borg 941019
 */

#include <std.h>

inherit DAEMON;

int cmd_brief(string str) {
    if((int)this_player()->set_verbose())
      message("system", "Verbose mode.", this_player());
    else message("system", "Brief mode.", this_player());
    return 1;
}

void help() {
    message("help", "Syntax: <brief>\n\n"
      "Toggles between seeing full room descriptions and short ones.",
      this_player());
}
