/*    /daemon/services/tell.c
 *    from the Nightmare IV LPC Library
 *    handles the IMP tell service
 *    created by Descartes of Borg 950507
 *    Modified for Discworld by Turrican 1-11-95
 */

#include "/net/intermud3/intermud_cfg.h"

#ifdef SERVICE_TELL

void eventReceiveTell(mixed *packet) {
    object ob;
    string who;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    who = lower_case(packet[5]);
    if( !(ob = find_player(who)) || (int)ob->query_invis() 
#ifndef PLAYER_TELL
        || !(int)ob->query_creator()
#endif
      ) {
	INTERMUD_D->eventWrite(({ "error", 5, mud_name(), 0, packet[2],
				  packet[3], "unk-user", 
				  capitalize(packet[5]) + " is nowhere to "
				    "be found on " + mud_name() + ".",
				  packet }));
	return;
    }
    else if( query_idle(ob) > 600 )
        INTERMUD_D->eventWrite(({ "error", 5, mud_name(), 0, packet[2],
                                  packet[3], "unk-user", 
                                  capitalize(packet[5]) + " on " + 
                                  mud_name() + " is very idle "
                                  "and may take some time to respond.",
                                  packet }));

    ob->event_person_tell(this_object(), packet[6]+"@"+packet[2]+
                           " tells you: ", packet[7], "common");
    /*ob->SetProperty("reply", packet[6] + "@" + packet[2]); */
}

int eventSendTell(string who, string where, string msg) {
    string pl, plc;
    string mudname;
    
    pl = (string)this_player(1)->query_name();
    plc = (string)this_player(1)->query_cap_name();
    mudname = (string)INTERMUD_D->GetMudName(where);
    if(!mudname)
      mudname = (string)INTERMUD_D->GetMudName(implode(explode(where, "_"), 
                                               " "));
    if(!mudname) {
      if(this_player())
        tell_object(this_player(),"That mud is unknown to us.\n");
      return 0;
    }

    INTERMUD_D->eventWrite(({ "tell", 5, mud_name(), pl, mudname,
			      lower_case(who), plc, msg }));
   this_player(1)->my_mess("You tell "+capitalize(who)+"@"+mudname+": ",
                            msg);
    return 1;
}

#endif
