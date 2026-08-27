#include <command.h>
#include <daemons.h>
#include <net/daemons.h>
#include <net/socket.h>


void remote_finger(object me, string target, string mud);

int
main(string str) {
    object ob;
    string wer, wo;

    if(!str) {
	string ret;

	ret = (string)FINGER_D->GetFinger(0);
	if( !ret ) return notify_fail("General finger appears broken.\n");
	message("system", ret, this_player());
	return 1;
    }
    else if(sscanf(str, "%s@%s", wer, wo)) { 
        if( wer == "" ) {
	  if( !(wo = (string)INTERMUD_D->GetMudName(wo)) )
	    return notify_fail(mud_name() +
			       " is not aware of such a place.\n");
	  SERVICES_D->eventSendWhoRequest(wo);
	  message("system", "Remote who query sent to " + wo + ".\n",
		  this_player());
	  return 1;
	}
	else
	  remote_finger(this_player(), (wer ? wer : ""), wo);
    }
    else {
	string ret;

	ret = (string)FINGER_D->GetFinger(convert_name(str));
	if( !ret )
	  return notify_fail("Finger of "+ capitalize(str) + " failed.");
	message("system", ret, this_player());
    }
    return 1;
}
 
void remote_finger(object ob, string who, string mud) {
    int tc_flag, ud_flag, id;

    if( !(mud = (string)INTERMUD_D->GetMudName(mud)) ) {
	return write( mud_name() + " is blissfully unaware of the MUD " 
		"you seek.\n");
    }
    SERVICES_D->eventSendFingerRequest(convert_name(who), mud);
    write("Remote finger sent to " + mud + ".\n");
}
 
void help() {
    message("help",
      "Syntax: <finger (([player])(@)([mud]))>\n\n"
      "Gives you information about a player named.  If you do not mention "
      "a particular mud, it searches for that player info here.  If you "
      "do not mention a player or a mud, it gives general finger info for "
      "everyone on line here.  If you mention another mud but no player, "
      "it gives you general info on the players on that mud.\n\n"
      "See also: gmuds, mail, muds, rwho, tell, users, who\n", this_player()
    );
}
