/*  -*- LPC -*-
 *    /daemon/services/tell.c
 *    from the Nightmare IV LPC Library
 *    handles the IMP tell service
 *    created by Descartes of Borg 950507
 *
 *  10.23.95  Tim changed to fit this mudlib
 */

#define SERVICE_TELL

#include <daemons.h>
#include <net/daemons.h>

void eventReceiveTell(mixed *packet) {
    object ob;
    string who;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    who = convert_name(packet[5]);
    if( !(ob = find_player(who)) || !ob->short() ) {
	INTERMUD_D->eventWrite(({ "error", 5, mud_name(), 0, packet[2],
				  packet[3], "unk-user", 
				  capitalize(packet[5]) + " is nowhere to "
				    "be found on " + mud_name() + ".",
				  packet }));
	return;
    }
    message("tell", packet[6] + "@" + packet[2] + " tells you: " +
	    packet[7] +"\n", ob);
    ob->SetProperty("reply", packet[6] + "@" + packet[2]);
}

void eventSendTell(string who, string where, string msg) {
    string pl, plc;
    
    pl = (string)this_player(1)->query_name();
    plc = (string)this_player(1)->query_cap_name();
    where = (string)INTERMUD_D->GetMudName(where);
    INTERMUD_D->eventWrite(({ "tell", 5, mud_name(), pl, where, 
			      convert_name(who), plc, msg }));
    message("tell", "You tell " + capitalize(who) + "@" + 
	    where + ": " + msg, this_player(1));
}

    

    
