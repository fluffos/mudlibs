/*    /daemon/services/locate.c
 *    From the Dead Souls V Object Library
 *    performs player lookups
 *    Created by Descartes of Borg 950624
 *    Version: @(#) locate.c 1.2@(#)
 *    Last modified: 96/12/09
 */

#define SERVICE_LOCATE

#include <daemons.h>
#include <rooms.h>
#define MSG_SYSTEM   ((1 << 10) | MSG_NOBLOCK)             /* sys messages */

void eventReceiveLocateRequest(mixed *packet) {
    string str_status;
    int idl = 0;
    object ob;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !(ob = find_player(packet[6])) || ob->GetInvis()) return;
    if( interactive(ob) ) {
	string *tmp = ({ });
	if( in_input(ob) || in_edit(ob) )
	    tmp += ({ "editing" });
	if( (idl = query_idle(ob)) > 60 )
	    tmp += ({ "inactive" });
	if( sizeof(tmp) ) str_status = implode(tmp, ", ");
	else str_status = 0;
    }
    else str_status = "link-dead";
    INTERMUD_D->eventWrite( ({ "locate-reply", 5, mud_name(), 0, packet[2], 
	packet[3], mud_name(),
	(string)ob->GetName(), idl, str_status }) );
}

void eventReceiveLocateReply(mixed *packet) {
    object ob;
    string m;
    int idl;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !stringp(packet[5]) || !(ob = find_player(convert_name(packet[5]))) ) 
	return;
    m = packet[7] + " was just located on " + packet[6] + ".";
    if( (idl = (int)packet[8]) > 60 )
	m += sprintf(" (idle %02d:%02d:%02d)", idl/3600, (idl/60)%60, idl%60);
    if( stringp(packet[9]) )
	m += " [str_status: " + packet[9] + "]";
    ob->eventPrint(m);
}

void eventSendLocateRequest(string who) {
    string pl;
    mixed *locate_request = ({ "locate-req", 5, mud_name(), pl, 0, 0, who });
    if( !(pl = (string)this_player(1)->GetKeyName()) ) return;
    INTERMUD_D->eventWrite( ({ "locate-req", 5, mud_name(), pl, 0, 0, who }) );
}
