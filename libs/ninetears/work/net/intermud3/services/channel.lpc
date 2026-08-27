/*    /daemon/services/channel.c
 *    from the Nightmare IV LPC Library
 *    handles intermud channels using the Intermud 3 protocols
 *    created by Descartes of Borg 950625
 *    Modified for Discworld by Turrican 1-11-95
 *    Modified for WWC by Hamlet, August 1996.
 */

#include "/net/intermud3/intermud_cfg.h"

#ifdef SERVICE_CHANNEL

string GetLocalChannel(string ch);
string GetRemoteChannel(string ch);

void eventReceiveChannelWhoReply(mixed *packet) {
    object ob;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !(ob = find_player(packet[5])) ) return;
    packet[6] = GetLocalChannel(packet[6]);
    if( !sizeof(packet[7]) ) {
	tell_object(ob, "No one is listening to " + packet[6] + " on " +
		packet[2] + ".\n");
	return;
    }
    tell_object(ob, "Listeners of " + packet[6] + " on " + packet[2] + ":\n" +
                    implode(packet[7], " ")+"\n");
}

void eventReceiveChannelWhoRequest(mixed *packet) {
    string *who;

#ifdef SHOW_CHANNEL_USERS
    who = CHANNEL_HAND->get_chan_users(packet[6]);
    
    INTERMUD_D->eventWrite(({ "chan-who-reply", 5, mud_name(), 0, packet[2],
			      packet[3], packet[6], who }));
#else
    INTERMUD_D->eventWrite(({ "chan-who-reply", 5, mud_name(), 0, packet[2],
                              packet[3], packet[6], ({ "Just ask." }) }));
#endif
}

void eventReceiveChannelUserRequest(mixed *packet) {
    object ob;
    string visname;
    int gender;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !(ob = find_player(packet[6])) ) {
	INTERMUD_D->eventWrite( ({ "error", 5, mud_name(), 0, packet[2], 0,
				   "unk-user", packet[6] + " is not a valid "
				     "player.", packet }) );
	return;
    }
    visname = (string)ob->query_cap_name();
    switch( (string)ob->query_gender_string() ) {
	case "male": gender = 0; break;
        case "female": gender = 1; break;
        default: gender = 2; break;
    }
    INTERMUD_D->eventWrite( ({ "chan-user-reply", 5, mud_name(), 0, 
			       packet[2], 0, packet[6], visname, gender }));
}

void eventReceiveChannelMessage(mixed *packet) {
    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( packet[2] == mud_name() ) return;

#ifdef LOG_CHANNELS
    log_file(LOG_CHANNELS, "(" + packet[6] + ") " + packet[7] + "@" + 
                           packet[2] + ": " + packet[8] + "\n");
#endif

#ifdef WWC
    CHANNEL_HAND -> deliver_message(GetLocalChannel(packet[6]),
      packet[7] +"@"+ packet[2], packet[8]);
#endif
#ifdef FR
// Taniwha
   if(sizeof(packet) > 7)
    "/global/do_chat"->received_cre(GetLocalChannel(packet[6])+" "+
      packet[7] + " " + replace_string(packet[2]," ","_") + " " + packet[8]);
#endif
#ifdef NEWMOON
     "/global/creator"->do_inter_channels( " "+packet[8],
                                           packet[7]+"@"+packet[2],
                                           GetLocalChannel(packet[6]) );
#endif


}

void eventReceiveChannelEmote(mixed *packet) {
    string target;
    object *people;

  if( file_name(previous_object()) != INTERMUD_D ) return;
    if( packet[2] == mud_name() ) return;
    if( !packet[7] ) return;

#ifdef LOG_CHANNELS
    log_file(LOG_CHANNELS, "(" + packet[6] + ") " + packet[7] + "@" +
                           packet[2] + " " + packet[8] + "\n");
#endif

#ifdef WWC
    CHANNEL_HAND -> deliver_message(GetLocalChannel(packet[6]),
           packet[7] + "@" + packet[2], "@"+
           replace_string(packet[8], "$N ", ""));
#endif
#ifdef FR
    "/global/do_chat"->received_cre(GetLocalChannel(packet[6])+" "+
        packet[7] + " " + packet[2] + " " +
        replace_string(replace_string(packet[8],"$N ",""), " ", "_"));
#endif
#ifdef NEWMOON
    "/global/creator"->do_inter_channels( ":"+
        replace_string(packet[8],"$N ",""),
        packet[7]+"@"+packet[2], GetLocalChannel(packet[6]) );
#endif

}

varargs void eventSendChannel(string who, string ch, string msg, int emote,
			      string target, string targmsg) {
    mixed *packet;
    string targpl, where;
    string outchan;

    if(! (outchan = GetRemoteChannel(ch)) )
      return;

    if( emote ) {
	if( target && targmsg ) {
	    if( sscanf(target, "%s@%s", targpl, where) != 2 )
	      targpl = target;
	    where = mud_name();
	}
	else targpl = where = targmsg = 0;
	packet = ({ "channel-e", 5, mud_name(), lower_case(who), 0, 0, 
                    outchan, who, msg });
    }
    else packet = ({ "channel-m", 5, mud_name(), lower_case(who), 0, 0, 
                     outchan, who, msg });
    INTERMUD_D->eventWrite(packet);
}

void eventSendChannelWhoRequest(string channel, string mud) {
    string pl;

    pl = (string)this_player(1)->query_name();
    INTERMUD_D->eventWrite(({ "chan-who-req", 5, mud_name(), pl, mud, 0,
			      channel }));
}

/* Use this for translations from incoming channel messages and whatever
   names you have locally defined for channels.
*/
string GetLocalChannel(string channel) {
  int i;

  i = member_array(channel, CHAN_TRANSLATE["remote"]);

  if(i == -1)
    return 0;
  else
    return CHAN_TRANSLATE["local"][i];
}

/* This translates in the other direction.  Look at intermud_cfg.h to
   see what's actually being used.
*/
string GetRemoteChannel(string channel) {
  int i;

  i = member_array(channel, CHAN_TRANSLATE["local"]);
 
  if(i == -1)
    return 0;
  else
    return CHAN_TRANSLATE["remote"][i];
}

void eventRegisterChannels(mapping list) {
    mixed *val;
    string channel, ns;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    ns = (string)INTERMUD_D->GetNameserver();

#ifdef STORE_CHANNELS
    rm(STORE_CHANNELS);
    write_file(STORE_CHANNELS, "CHANNEL                       OWNER"
                               "                         ACCESS\n\n");
#endif

    foreach(channel, val in list) {
	if( !val ) continue;

#ifdef STORE_CHANNELS
        write_file(STORE_CHANNELS, sprintf("%-30s%-30s%s\n",
                   channel, val[0], ( !val[1] ? "banned list" :
                                      ((val[1] == 1) ? "allowed list" : 
                                                       "filtered") )));
#endif

#ifndef ALL_CHANNELS
        if (!GetLocalChannel(channel))
            INTERMUD_D->eventWrite(({ "channel-listen", 5, mud_name(), 0, ns,
                                      0, channel, 0 }));
	else
#endif 
            INTERMUD_D->eventWrite(({ "channel-listen", 5, mud_name(), 0, ns,
                                       0, channel, 1 }));
    }
}

int eventAdministerChannel(string channel, string *additions, string *subs) {
    if( !((int)master()->high_programmer(geteuid(this_player(1)))) )
      return 0;
    if( member_array(channel, (string *)INTERMUD_D->GetChannels()) == -1 )
      return 0;
    INTERMUD_D->eventWrite(({ "channel-admin", 5, mud_name(),
			      (string)this_player(1)->query_cap_name(),
			      (string)INTERMUD_D->GetNameserver(),
			      0, channel, additions, subs }));
    return 1;
}

int AddChannel(string channel, int privee) {
    if( !((int)master()->high_programmer(geteuid(this_player(1)))) )
      return 0;
    if( member_array(channel, (string *)INTERMUD_D->GetChannels()) != -1 )
      return 0;
    INTERMUD_D->eventWrite(({ "channel-add", 5, mud_name(),
			      (string)this_player(1)->query_cap_name(),
			      (string)INTERMUD_D->GetNameserver(), 0,
			      channel, privee }));
    return 1;
}

int RemoveChannel(string channel) {
    if( !((int)master()->high_programmer(geteuid(this_player(1)))) )
      return 0;
    if( member_array(channel, (string *)INTERMUD_D->GetChannels()) == -1 )
      return 0;
    INTERMUD_D->eventWrite(({ "channel-remove", 5, mud_name(),
			      (string)this_player(1)->query_cap_name(),
			      (string)INTERMUD_D->GetNameserver(), 0,
			       channel }));
    return 1;
}

#endif
