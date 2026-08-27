/*    /daemon/services/locate.c
 *    from the Nightmare IV LPC Library
 *    performs player lookups
 *    created by Descartes of Borg 950624
 *    Modified for Discworld by Turrican 1-11-95
 */

#define SERVICE_LOCATE

void eventReceiveLocateRequest(mixed *packet) {
    object ob;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !(ob = find_player(packet[6])) || (int)ob->query_invis() ) return;
    INTERMUD_D->eventWrite( ({ "locate-reply", 5, mud_name(), 0, packet[2], 
			       packet[3], mud_name(), 
			       (string)ob->query_cap_name() }) );
}

void eventReceiveLocateReply(mixed *packet) {
    object ob;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !stringp(packet[5]) || !(ob = find_player(lower_case(packet[5]))) ) 
      return;
    tell_object(ob, packet[7] + " was just located on " + packet[6] + ".\n");
}

void eventSendLocateRequest(string who) {
    string pl;

    if( !(pl = (string)this_player(1)->query_name()) ) return;
    INTERMUD_D->eventWrite( ({ "locate-req", 5, mud_name(), pl, 0, 0, who }) );
}
