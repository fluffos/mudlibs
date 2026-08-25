/*    /daemon/services/tell.c
 *    from the Nightmare IV LPC Library
 *    handles the IMP tell service
 *    created by Descartes of Borg 950507
 *    Modified for Discworld by Turrican 1-11-95
 */

#define SERVICE_TELL

void eventReceiveTell(mixed *packet) {
    object ob;
    string who;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    who = lower_case(packet[5]);
    if( !(ob = find_player(who)) || (int)ob->query_invis() ) {
	INTERMUD_D->eventWrite(({ "error", 5, mud_name(), 0, packet[2],
				  packet[3], "unk-user", 
				  capitalize(packet[5]) + " is nowhere to "
				    "be found on " + mud_name() + ".",
				  packet }));
	return;
    }
    ob->event_person_tell(this_object(), packet[6]+"@"+packet[2]+
                           " tells you: ", packet[7], "common");
    /*ob->SetProperty("reply", packet[6] + "@" + packet[2]); */
}

void eventSendTell(string who, string where, string msg) {
    string pl, plc;
    
    pl = (string)this_player(1)->query_name();
    plc = (string)this_player(1)->query_cap_name();
    where = (string)INTERMUD_D->GetMudName(where);
    INTERMUD_D->eventWrite(({ "tell", 5, mud_name(), pl, where, 
			      lower_case(who), plc, msg }));
}
