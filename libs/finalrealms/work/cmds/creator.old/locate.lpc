/*    /cmds/player/locate.c
 *    from the Nightmare IV LPC Library
 *    Intermud 3 command to locate people on other MUDs
 *    created by Descartes of Borg 950624
 *    Converted for WWC by Hamlet, August 1996.
 */

#include <cmd.h>
#include <network.h>

inherit CMD_BASE;

void setup() {
  position = 1;
}

protected int cmd(string str, object me) {
    if( !str || str == "" ) {
      notify_fail("Locate whom?");
      return 0;
    }

    SERVICES_D->eventSendLocateRequest(str);
    tell_object(me, "Locate request sent.\n");
    return 1;
}

void query_short_help() {
    message("help", "Syntax: <locate [person]>\n\n"
	    "This command allows you to know on which MUDs connected "
	    "through the Intermud 3 network have someone using the "
	    "name you specify.  Note that this person may not actually be "
	    "the person you think it is, as nothing prevents two different "
	    "people from using the same name on different MUDs.\n\n"
	    "See also: mail, mudlist, rwho, tell", this_player());
}
