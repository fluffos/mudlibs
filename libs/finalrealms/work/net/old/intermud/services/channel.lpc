/*    /daemon/services/channel.c
 *    from the Nightmare IV LPC Library
 *    handles intermud channels using the Intermud 3 protocols
 *    created by Descartes of Borg 950625
 *    Modified for Discworld by Turrican 1-11-95
 */

#define SERVICE_CHANNEL

string GetLocalChannel(string ch);

void eventReceiveChannelWhoReply(mixed *packet) {
    object ob;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !(ob = find_player(packet[5])) ) return;
    packet[6] = GetLocalChannel(packet[6]);
    if( !sizeof(packet[7]) ) {
	tell_object(ob, "No one is listening to " + packet[6] + " at " +
		packet[2] + ".\n");
	return;
    }
    tell_object(ob, "Listening to " + packet[6] + " at " + packet[2] + ": ");
    tell_object(ob, implode(packet[7], " ")+"\n");
}

string *filter_listeners(object ob, string chan) {
  if (!ob->query_creator() || ob->check_earmuffs("intermud-all") ||
      ob->check_earmuffs(chan))
    return 0;
  return 1;
}

void eventReceiveChannelWhoRequest(mixed *packet) {
    string *who;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    who = (string *)filter_array(users(), "filter_listeners", this_object(),
        packet[6])->query_cap_name();
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
    switch( (string)ob->query_gender_string() ) {
	case "male": gender = 0; break;
        case "female": gender = 1; break;
        default: gender = 2; break;
    }
    INTERMUD_D->eventWrite( ({ "chan-user-reply", 5, mud_name(), 0, 
			       packet[2], 0, packet[6], visname, gender }));
}

void eventReceiveChannelMessage(mixed *packet) {
    object *people;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( packet[2] == mud_name() ) return;
    people = filter(users(), (: $1->check_not_ignored($(packet[2])) && 
        $1->check_not_ignored($(packet[7])) && 
        $1->check_not_ignored($(packet[7])+"@"+$(packet[2])) :));
    event(people, "intermud_tell", sprintf("%s@%s: ", 
        packet[7], packet[2]), packet[8], 
        GetLocalChannel((string)packet[6]));
/* 
    CHAT_D->eventSendChannel(packet[7] + "@" + packet[2], packet[6],
			     packet[8]); */
}

void eventReceiveChannelEmote(mixed *packet) {
    string target;
    object *people;

  if( file_name(previous_object()) != INTERMUD_D ) return;
    if( packet[2] == mud_name() ) return;
    if( !packet[7] ) return;
    people = filter(users(), (: $1->check_not_ignored($(packet[2])) &&
        $1->check_not_ignored($(packet[7])) &&
        $1->check_not_ignored($(packet[7])+"@"+$(packet[2])) :));
    event(people, "intermud_tell", "", 
        replace_string(packet[8], "$N", packet[7]+"@"+packet[2]), 
        GetLocalChannel((string)packet[6]));
/*    CHAT_D->eventSendChannel(packet[7] + "@" + packet[2], packet[6],
			     packet[8], 1, 0, 0); */
}

varargs void eventSendChannel(string who, string ch, string msg, int emote,
			      string target, string targmsg) {
    mixed *packet;
    string targpl, where;

    if( emote ) {
	if( target && targmsg ) {
	    if( sscanf(target, "%s@%s", targpl, where) != 2 )
	      targpl = target;
	    where = mud_name();
	}
	else targpl = where = targmsg = 0;
	packet = ({ "channel-e", 5, mud_name(), lower_case(who), 0, 0, ch, 
                    who, msg });
    }
    else packet = ({ "channel-m", 5, mud_name(), lower_case(who), 0, 0, ch, 
		     who, msg });
    INTERMUD_D->eventWrite(packet);
}

void eventSendChannelWhoRequest(string channel, string mud) {
    string pl;

    pl = (string)this_player(1)->query_name();
    INTERMUD_D->eventWrite(({ "chan-who-req", 5, mud_name(), pl, mud, 0,
			      channel }));
}

string GetLocalChannel(string channel) {
  switch (channel) {
    case "imud_code":
      return "intercre";
    case "imud_gossip":
      return "intergossip";
    case "intermud":
      return "intermud";
  }
  return 0;
}

void eventRegisterChannels(mapping list) {
    mixed *val;
    string channel, ns, local;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    ns = (string)INTERMUD_D->GetNameserver();
    foreach(channel, val in list) {
	if( !val ) continue;
	if( !( local = GetLocalChannel(channel) ) ) {
	    INTERMUD_D->eventWrite(({ "channel-listen", 5, mud_name(), 0, ns, 
				      0, local, 0 }));
//	    log_file("channels", "New channel: " + local + " recognized " +
//		     ctime(time()) + "\nValue: " + sprintf("%O", val) + "\n\n");
	}
	else INTERMUD_D->eventWrite(({ "channel-listen", 5, mud_name(), 0, ns,
				       0, local, 1 }));
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
