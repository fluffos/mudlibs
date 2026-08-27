/*  -*- LPC -*-
 *    /daemon/services/channel.c
 *    from the Nightmare IV LPC Library
 *    handles intermud channels using the Intermud 3 protocols
 *    created by Descartes of Borg 950625
 *
 *  10.23.95  Tim modified for this mudlib
 */

#define SERVICE_CHANNEL

#include <daemons.h>
#include <net/daemons.h>
#include <gender.h>

void eventReceiveChannelWhoReply(mixed *packet) {
    object ob;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !(ob = find_player(packet[5])) ) return;
    packet[6] = (string)CHAT_D->map_to_local(packet[6]);
    if( !sizeof(packet[7]) ) {
	message("system", "No one is listening to " + packet[6] + " at " +
		packet[2] + ".\n", ob);
	return;
    }
    message("system", "Listening to " + packet[6] + " at " + packet[2] + ":\n",
	    ob);
    message("system", implode(packet[7], "   ")+"\n", ob);
}

void eventReceiveChannelWhoRequest(mixed *packet) {
    string *who;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    who = (string *)CHAT_D->query_channel_members(packet[6]);
    INTERMUD_D->eventWrite(({ "chan-who-reply", 5, mud_name(), 0, packet[2],
			      packet[3], packet[6], who }));
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
    switch( (int)ob->query_gender() ) {
    case GENDER_MALE:
      gender = 0; break;
    case GENDER_FEMALE:
      gender = 1; break;
    default:
      gender = 2; break;
    }
    INTERMUD_D->eventWrite( ({ "chan-user-reply", 5, mud_name(), 0, 
			       packet[2], 0, packet[6], visname, gender }));
}

void eventReceiveChannelMessage(mixed *packet) {
    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( packet[2] == mud_name() ) return;
    CHAT_D->broadcast_local(packet[6], packet[7] + "@" + packet[2],
			     packet[8]);
}

void eventReceiveChannelEmote(mixed *packet) {
    string target;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( packet[2] == mud_name() ) return;
    if( !packet[7] ) return;
    CHAT_D->broadcast_local(packet[6], packet[7] + "@" + packet[2],
			     packet[8], 1, 0, 0);
}

varargs void eventSendChannel(string who, string ch, string msg, int emote,
			      string target, string targmsg) {
    mixed *packet;
    string targpl, where;

    if( emote ) {
	if( target && targmsg ) {
	    if( sscanf(target, "%s@%s", targpl, where) != 2 ) {
	      targpl = target;
	      where = mud_name();
	    } // tim 2/96 -- still need targeted emotes in here
	}
	else targpl = where = targmsg = 0;
	packet = ({ "channel-e", 5, mud_name(), convert_name(who), 0, 0, ch, 
                    who, msg });
    }
    else packet = ({ "channel-m", 5, mud_name(), convert_name(who), 0, 0, ch, 
		     who, msg });
    INTERMUD_D->eventWrite(packet);
}

void eventSendChannelWhoRequest(string channel, string mud) {
    string pl;

    pl = (string)this_player(1)->query_name();
    INTERMUD_D->eventWrite(({ "chan-who-req", 5, mud_name(), pl, mud, 0,
			      channel }));
}

void eventRegisterChannels(mapping list) {
    mixed *val;
    string channel, ns;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    ns = (string)INTERMUD_D->GetNameserver();
    foreach(channel, val in list) {
	if( !val ) continue;
	if( channel == (string)CHAT_D->map_to_local(channel) ) {
            string name;
	    int num;
	    
	    log_file("channels", "New channel: " + channel + " recognized " +
		     ctime(time()) + "\nValue: " + identify(val));

	    if( val[1] ) {
	      INTERMUD_D->eventWrite(({ "channel-listen", 5, mud_name(), 0, ns,
					0, channel, 0 }));
	      continue; // don't mess w/filtered or banned channels
	    }

	    if( INTERMUD_D->GetMudState(val[0]) >= 0 ) continue;

	    if( (num = strsrch(channel, '_')) >= 0 )
	      name = "i"+channel[num+1..];
	    else
	      name = "i"+channel;
	    
	    name = replace_string(name, "inter", "i")[0..20];

	    if( name == channel )
	      name += "0";

	    if( CHAT_D->channel_exists(name) )
	    {
	      num = 0;
	      sscanf(name, "%s%d", name, num);
	      name = sprintf("%s%d", name, ++num);
	    }
	    
	    if( CHAT_D->add_channel(name, val[0], 0, 0) )
	    {
	      CHAT_D->set_alias(name, channel);
	      INTERMUD_D->eventWrite(({ "channel-listen", 5, mud_name(), 0, ns,
					0, channel, 1 }));
	    }
	    
	}
	else INTERMUD_D->eventWrite(({ "channel-listen", 5, mud_name(), 0, ns,
				       0, channel, 1 }));
    }
}

int eventAdministerChannel(string channel, string *additions, string *subs) {
    if( !((int)master()->valid_apply( ({}) )) ) return 0;
    if( member_array(channel, (string *)INTERMUD_D->GetChannels()) == -1 )
      return 0;
    INTERMUD_D->eventWrite(({ "channel-admin", 5, mud_name(),
			      (string)this_player(1)->query_name(),
			      (string)INTERMUD_D->GetNameserver(),
			      0, channel, additions, subs }));
    return 1;
}

int AddChannel(string channel, int privee) {
    if( !((int)master()->valid_apply( ({}) )) ) return 0;
    if( member_array(channel, (string *)INTERMUD_D->GetChannels()) != -1 )
      return 0;
    INTERMUD_D->eventWrite(({ "channel-add", 5, mud_name(), 
			      (string)this_player(1)->query_name(),
			      (string)INTERMUD_D->GetNameserver(), 0,
			      channel, privee }));
    return 1;
}

int RemoveChannel(string channel) {
    if( !((int)master()->valid_apply( ({}) )) ) return 0;
    if( member_array(channel, (string *)INTERMUD_D->GetChannels()) == -1 )
      return 0;
    INTERMUD_D->eventWrite(({ "channel-remove", 5, mud_name(),
			      (string)this_player(1)->query_name(),
			      (string)INTERMUD_D->GetNameserver(), 0,
			       channel }));
    return 1;
}
