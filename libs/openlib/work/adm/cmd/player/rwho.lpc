/*  -*- LPC -*-
 *    /cmds/player/rwho.c
 *    from the Nightmare IV LPC Library
 *    Sends an Intermud 3 who request
 *    created by Descartes of Borg 950623
 *
 *  10/23/95  Tim changed for this mudlib
 */

#include <command.h>
#include <net/daemons.h>

int
main(string str) {
    if( !str )
      return notify_fail("usage: rwho <mud>\n");
    if( !(str = (string)INTERMUD_D->GetMudName(str)) )
      return notify_fail(mud_name() + " is not aware of such a place.\n");
    SERVICES_D->eventSendWhoRequest(str);
    message("system", "Remote who query sent to " + str + ".\n",
	    this_player());
    return 1;
}

void help() {
    write("Syntax: <rwho [mud]>\n\n"
      "Gives you a who list in abbreviated form from a mud on the\n"
      "global network following the CD protocols for intermud communication.\n"
      "The information given by the who varies from mud to mud.\n"
    );
}
