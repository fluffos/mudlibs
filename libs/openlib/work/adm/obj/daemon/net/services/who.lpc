/*  -*- LPC -*-
 *    /daemon/services/who.c
 *    from the Nightmare IV LPC Library
 *    handles the Intermud 3 who service
 *    created by Descartes of Borg 950623
 *
 *  10.23.95  Tim changed to fit this mudlib
 */

#define SERVICE_WHO

#include <daemons.h>
#include <net/daemons.h>

void eventReceiveWhoReply(mixed *packet) {
    string *list, *who;
    object ob;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !packet[5] || !(ob = find_player(convert_name(packet[5]))) ) return;
    list = ({ "Remote who information from " + packet[2] + ":" });
    foreach(who in packet[6]) 
      list += ({ sprintf("%s (%d min. idle): %s", who[0], to_int(who[1]) / 60,
			 who[2]) });
    message("system", implode(list, "\n") + "\n", ob);
}

void eventReceiveWhoRequest(mixed *packet) {
    mixed *msg;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    msg = map(filter(users(), (: ($1->short()) :)),
	      (: ({ (string)$1->query_cap_name(),
		    query_idle($1),
		    (string)$1->short() }) :));
    INTERMUD_D->eventWrite(({ "who-reply", 5, mud_name(), 0, packet[2],
			      packet[3], msg }));
}

void eventSendWhoRequest(string mud) {
    string who;

    who = (string)this_player(1)->query_name();
    INTERMUD_D->eventWrite(({ "who-req", 5, mud_name(), who, mud, 0 }));
}

    

    
