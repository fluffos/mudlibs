/*    -*- LPC -*-
 *    /cmds/player/locate.c
 *    from the Nightmare IV LPC Library
 *    Intermud 3 command to locate people on other MUDs
 *    created by Descartes of Borg 950624
 *
 *    10/23/95  Tim modified to fit our mudlib
 */

#include <command.h>
#include <net/daemons.h>

int
main(string args) {
    if( !args || args == "" )
      return notify_fail("Locate whom?\n");
    SERVICES_D->eventSendLocateRequest(convert_name(args));
    message("system", "Locate query sent.\n", this_player());
    return 1;
}

void help() {
    message("help", "Syntax: <locate [person]>\n\n"
	    "This command allows you to know on which MUDs connected "
	    "through the Intermud 3 network have someone using the "
	    "name you specify.  Note that this person may not actually be "
	    "the person you think it is, as nothing prevents two different "
	    "people from using the same name on different MUDs.\n\n"
	    "See also: mail, mudlist, rwho, tell\n", this_player());
}
