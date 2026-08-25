/*    /cmds/player/rwho.c
 *    from the Nightmare IV LPC Library
 *    Sends an Intermud 3 who request
 *    created by Descartes of Borg 950623
 *    Shamelessly stolen from Nameless Sorrows by Hamlet.
 *    Swallowed a regurgitated by Hamlet for WWC.
 */

#include <cmd.h>
#include <network.h>

inherit CMD_BASE;

void setup() {
  position = 1;
}

protected int cmd(string str, object me) {
    if( !str ) {
      notify_fail("Get a remote who from where?\n");
      return 0;
    }

    if( !(str = (string)INTERMUD_D->GetMudName(str)) ) {
      notify_fail("That place is unknown to us.\n");
      return 0;
    }
    SERVICES_D->eventSendWhoRequest(str, this_player() -> query_name());
    write("Remote who query sent to " + str + ".\n");

    return 1;
}

void query_short_help() {
    write("Syntax: <rwho [mud]>\n\n"
      "Gives you a who list in abbreviated form from a mud on the\n"
      "global network following the CD protocols for intermud communication.\n"
      "The information given by the who varies from mud to mud.\n"
    );
}
