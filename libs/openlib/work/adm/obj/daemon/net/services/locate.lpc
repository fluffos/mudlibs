/*  -*- LPC -*-
 *    /daemon/services/locate.c
 *    from the Nightmare IV LPC Library
 *    performs player lookups
 *    created by Descartes of Borg 950624
 *
 *  10.23.95  Tim: changed to fit this mudlib
 *  04.12.96  Tim: Added version 3 protocol support
 */

#define SERVICE_LOCATE

#include <daemons.h>
#include <net/daemons.h>

void eventReceiveLocateRequest(mixed *packet) {
    object ob;
    string *sts = ({ });

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !(ob = find_player(packet[6])) || !ob->short() ) return;

    if( in_edit(ob) )
      sts += ({ "in editor" });
    if( in_input(ob) )
      sts += ({ "in input" });
    if( !sizeof(sts) )
      sts = ({ "unknown" });

    INTERMUD_D->eventWrite( ({ "locate-reply",
			       5,
			       mud_name(),
			       0,
			       packet[2], 
			       packet[3],
			       mud_name(), 
			       (string)ob->query_cap_name(),
			       query_idle(ob),
			       implode(sts, ", "),
			       }) );
}

void eventReceiveLocateReply(mixed *packet) {
    object ob;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !stringp(packet[5]) || !(ob = find_player(convert_name(packet[5]))) ) 
      return;
    message("system",
	    sprintf("%s was just located on %s.\n"
		    "Idle %i minutes.\n"
		    "Status: %s\n",
		    packet[7], packet[6], packet[8] / 60, packet[9]), ob);
}

void eventSendLocateRequest(string who) {
    string pl;

    if( !(pl = (string)this_player(1)->query_cap_name()) ) return;
    INTERMUD_D->eventWrite( ({ "locate-req", 5, mud_name(), pl, 0, 0, who }) );
}
