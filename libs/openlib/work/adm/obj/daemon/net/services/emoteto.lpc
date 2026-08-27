/*  -*- LPC -*-
 *    /daemon/services/emoteto.c
 *    from the Foundation II Object Library
 *    handles the I3 emoteto service
 *    created by Descartes of Borg 950914
 *
 *  10.23.95  Tim changed to fit this mudlib
 */

#define SERVICE_EMOTETO

#include <daemons.h>
#include <net/daemons.h>

void eventReceiveEmote(mixed *packet) {
    object ob;
    string who;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    who = convert_name(packet[5]);
    if( !(ob = find_player(who)) || !(string)ob->short() ) {
	INTERMUD_D->eventWrite(({ "error", 5, mud_name(), 0, packet[2],
				  packet[3], "unk-user", 
				  capitalize(packet[5]) + " is nowhere to "
				    "be found on " + mud_name() + ".",
				  packet }));
	return;
    }
    packet[7] = replace_string(packet[7], "$N", packet[6] + "@" + packet[2]);
    message("emote", packet[7] + "\n", ob);
}

void eventSendEmote(string who, string where, string msg) {
    string pl, plc;
    
    pl = (string)this_player(1)->query_name();
    plc = (string)this_player(1)->query_cap_name();
    where = (string)INTERMUD_D->GetMudName(where);
    INTERMUD_D->eventWrite(({ "emoteto", 5, mud_name(), pl, where, 
			      convert_name(who), plc, msg }));
}
