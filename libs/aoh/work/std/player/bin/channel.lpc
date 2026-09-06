/*--------------------------------------------------------------------------
 * /std/player/bin/channel.c  --  The channel commands.
 *
 * Copyright (C) 1997, 1998 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * CHANGES
 *  06/28/98 [Mica] implemented features.h
 *  07/02/98 [Mica] the channel-command now uses CHANNEL_D->QueryUserChannels()
 */

#include <properties.h>
#include <msgclass.h>
#include <secure/wizlevels.h>
#include <daemons.h>
#include <macros.h>
#include <channel.h>
#include <inetd.h>
#include <features.h>
#include <i3.h>

/* 'tell' something on a channel
 */

int tell(string msg) {
	string ch;

	if ( ! msg )
		return notify_fail( "Send what?\n"), 0;

	if ( ! ({int})this_player()->Query( P_CHANNELS_ON ) )
		msg_write( CMSG_GENERIC,
				 "You temporarily have turned off all your channels.\n" );

	if ( ({int})this_player()->Query( P_FROG ) )
		msg = "Hriibit! Hriiibit!";

	ch = query_verb()[1..<1];
	if ( ch == "" ) ch = IS_IMMORTAL( this_player() ) ? "general" : "players";

	CHANNEL_D->SendTell(ch, capitalize(({string})this_player()->Query(P_REALNAME)), msg);
	return 1;
}

/* emote something on a channel
 */

int emote(string msg) {
	string ch;

	if ( ! msg )
		return notify_fail( "Send what?\n"), 0;

	if ( ! ({int})this_player()->Query( P_CHANNELS_ON ) )
		msg_write( CMSG_GENERIC,
				 "You temporarily have turned off all your channels.\n" );

	if ( ({int})this_player()->Query(P_FROG) )
		msg = "hops up into the air.";

	ch=query_verb()[2..];
	if ( ch == "" ) ch = IS_IMMORTAL( this_player() ) ? "general" : "players";

	CHANNEL_D->SendEmote(ch, capitalize(({string})this_player()->Query(P_REALNAME)), msg);

	return 1;
}

/* turn channel (or all channels) on
 */

int chon(string str) {
	string * channels;

	if ( ! str ) {
		this_player()->Set( P_CHANNELS_ON, 1 );
		msg_write( CMSG_GENERIC, "Turning all your channels on again.\n" );
	}
	else {
		if ( ! ( channels = ({string *})this_player()->Query( P_CHANNELS ) ) )
			channels = ({string *})this_player()->Set( P_CHANNELS, ({}) );

		if ( str == "*" ) {
			write( "Turning all channels on.\n" );
			channels = filter( ({string *})CHANNEL_D->QueryChannelNames()||({}),
				 lambda( ({ SYM(a) }),
				 ({ SF(call_other), CHANNEL_D,
			"RegisterChannel",
			SYM(a), ({SF(this_player)}) }) ) );
			this_player()->Set( P_CHANNELS, channels );
		}
		else if ( member(channels, str ) != -1 )
			write("The "+str+" channel is already turned on.\n");
		else {
			if ( ({int})CHANNEL_D->RegisterChannel( str, this_player() ) ) {
				msg_write( CMSG_GENERIC, "Turning "+str+" channel on.\n" );
				this_player()->ChannelOn(str);
			}
			else
				msg_write( CMSG_GENERIC, "Unknown channel: "+str+".\n" );
		}
		if ( ! ({int})this_player()->Query( P_CHANNELS_ON ))
			msg_write( CMSG_GENERIC, "Note that you used 'choff' to temporarily turn off _all_ channels.\n");
	}
	return 1;
}

/* turn channel (or all channels) off
 */

int choff(string str) {
	string * channels;

	if (!str) {
		this_player()->Set( P_CHANNELS_ON, 0 );
		msg_write( CMSG_GENERIC, "Temporarily turning off all your channels.\n");
	}
	else {
		if ( ! ( channels = ({string *})this_player()->Query( P_CHANNELS ) ) )
			channels = ({string *})this_player()->Set( P_CHANNELS, ({}) );

		if ( str == "*" ) {
			channels = filter( ({string *})CHANNEL_D->QueryChannelNames()||({}),
				 lambda( ({ SYM(a) }),
				 ({ SF(call_other), CHANNEL_D,
			"UnregisterChannel",
			SYM(a), ({SF(this_player)}) }) ) );
			this_player()->Set( P_CHANNELS, ({}) );
			msg_write(CMSG_GENERIC, "Turning all channels off.\n");
		}
		else if ( member( channels, str ) == -1 )
			msg_write( CMSG_GENERIC, "The "+str+" channel is already turned off.\n");
		else {
			/* test if we might turn it on */
			if ( ({int})CHANNEL_D->RegisterChannel( str, this_player(), 1 ) ) {
				CHANNEL_D->UnregisterChannel( str, this_player() );
				this_player()->ChannelOff(str);
				msg_write( CMSG_GENERIC, "Turning "+str+" channel off.\n" );
			}
			else
				msg_write( CMSG_GENERIC, "Unknown channel: "+str+".\n" );
		}

		if ( ! ({int})this_player()->Query( P_CHANNELS_ON ))
			msg_write( CMSG_GENERIC, "Note that you used 'choff' to temporarily turn off _all_ channels.\n");
	}
	return 1;
}

/* channel who, including intermud and intermud-3
 */

private mixed filter_invis(object who) {
	return !(IS_IMMORTAL(who) && ({int})who->Query(P_INVIS));
}

private string filter_listeners(object who) {
	string listener;

	if ( ! objectp( who ) )
		return 0;

	if ( ! interactive( who ) ) {
		if ( IS_IMMORTAL( this_player() ) )
			return "["+object_name(who)+"]";
		else
			return 0;
	}

	listener = capitalize(({string})who->Query(P_REALNAME));

	if (({int})who->Query(P_INVIS))
		listener = "("+listener+")";

	return listener;
}

private string decl( int num ) {
	if ( ( ! num ) || ( num > 1 ) )
		return "are";
	else
		return "is";
}

int chwho(string str) {
	int learner;
	object *c_users;
	string *listeners, what, where, msg, tmp;
	mixed * da;

	learner = IS_IMMORTAL( this_player() );
	if (!str) str = learner ? "general" : "players";

	/* handle intermud chwho */
	if ( sscanf( str, "%s@%s", what, where ) == 2 ) {
#ifdef FEATURES_INTERMUD3
		if ( tmp = ({string})I3_TOOL("mudlist")->mud_find( where ) )
			I3_TOOL("channel")->send_chan_who_req(
				what, tmp, ({string})this_player()->Query(P_REALNAME));
		else
#endif
			if ( msg = ({string})INET_D->send_packet( where,
					([
						I2H_REQUEST: "channel",
						I2H_SENDER: ({string})this_player()->Query(P_REALNAME),
						I2H_CHANNEL : what,
						"CHANNEL": what,
						"CMD":"list",
						]), 1 ) ) {
							msg_write( CMSG_GENERIC, msg );
							return 1;
			}
		msg_write( CMSG_GENERIC, "Intermud request sent.\n" );
		return 1;
	}

	if ( ! ({int})CHANNEL_D->RegisterChannel( str, this_player(), 1 ) )
		return notify_fail("Unknown channel: "+str+".\n");

	if ( ! ( da = ({mixed *})CHANNEL_D->ChannelData( str ) ) )
		return notify_fail("Unknown channel: "+str+".\n");

	c_users = ( da[CHANNEL_LISTENERS]||({}) ) - ({ 0 });

	if ( da[CHANNEL_FLAGS] & CHANNEL_FLAG_ANONYMOUS ) {
		msg_write( CMSG_GENERIC, "There "+decl(sizeof(c_users))+
				 " "+sizeof(c_users)+
				 " listener"+(sizeof(c_users)>1?"s":"")+
				 " on the anonymous channel "+str+".\n" );
	}
	else {
		if ( ! IS_IMMORTAL( this_player() ) ) {
			c_users = filter( c_users, SF( filter_invis ) );
		}

		listeners = map( c_users, SF( filter_listeners ) ) - ({ 0 });

		if (sizeof(listeners)) {
			msg_write( CMSG_GENERIC,
				"The current listeners of the "+str+" channel are:\n"+
				implode(listeners-({0}), ", ")+".\n" );
		}
		else {
			msg_write( CMSG_GENERIC,
				"Nobody seems to listen to the "+str+" channel.\n");
		}
	}

	return 1;
}

/* list of all available channels
 */

private string * filter_local( mapping d ) {
	return sort_array( m_indices(filter_indices(d,
					lambda( ({ SYM(a) }),
						({ SF_EQUAL,
							({ SF_INDEX,
								({ SF_INDEX, d, SYM(a) }),
								CHANNEL_TYPE
							}),
							CHANNEL_TYPE_LOCAL
						}) ) ) ), SF(>));
}

private string * filter_intermud( mapping d ) {
	return sort_array( m_indices(filter_indices(d,
					lambda(({SYM(a) }),
						({ SF_EQUAL,
							({ SF_INDEX,
								({ SF_INDEX, d, SYM(a) }),
								CHANNEL_TYPE
							}),
							CHANNEL_TYPE_IMUD
						}) ) ) ), SF(>) );
}

#ifdef FEATURES_INTERMUD3
private string * filter_intermud_3( mapping d ) {
	return sort_array( m_indices(filter_indices(d,
					lambda(({SYM(a) }),
						({ SF_EQUAL,
							({ SF_INDEX,
								({ SF_INDEX, d, SYM(a) }),
								CHANNEL_TYPE
							}),
							CHANNEL_TYPE_IMUD3
						}) ) ) ), SF(>) );
}
#endif

int channels(string str) {
	mapping d;
	mixed * ch;
	string res;
	int i, ic;

	d = ({mapping})CHANNEL_D->QueryUserChannels( this_player() );

	switch( str ) {
		case 0:
		case "all":
			ch = ({ filter_local(d), filter_intermud(d)
#ifdef FEATURES_INTERMUD3
				, filter_intermud_3(d)
#else
				, 0
#endif
				});
			break;
		case "local":
			ch = ({ filter_local(d), 0, 0 });
			break;
		case "intermud":
			ch = ({ 0, filter_intermud(d), 0 });
			break;
#ifdef FEATURES_INTERMUD3
		case "intermud-3":
			ch = ({ 0, 0, filter_intermud_3(d) });
			break;
#endif
		default:
#ifdef FEATURES_INTERMUD3
			return notify_fail("Usage: channels [<all>|<local>|<intermud>|<intermud-3>]\n" ), 0;
#else
			return notify_fail("Usage: channels [<all>|<local>|<intermud>]\n" ), 0;
#endif
	}

	res = "";

	for( i = 0; i <= 2; i ++ ) {
		if ( ! ch[i] )
			continue;

		switch( i ) {
			case 0:
				res += "Local channels:\n";
				break;
			case 1:
				res += "Intermud channels:\n";
				break;
#ifdef FEATURES_INTERMUD3
			case 2:
				res += "Intermud-3 channels:\n";
				break;
#endif
		}

		for ( ic = 0; ic < sizeof( ch[i] ); ic ++ ) {
			res += sprintf( "  %-22'.'s %3s",
				ch[i][ic]+" ",
				(member( d[ch[i][ic]][CHANNEL_LISTENERS]||({}), this_player())!=-1) ?
				"on" : "off" );
			if ( ! ( ( ic + 1 ) % 3 ) )
			 res += "\n";
		}
		res += "\n";
	}

	if ( ! ({int})this_player()->Query( P_CHANNELS_ON ))
		res += "You temporarily have turned off all your channels.\n";

	msg_write( CMSG_GENERIC|MMSG_MORE, res );

	return 1;
}

/* channel history
 */

int chhis( string str ) {
	string name;
	int lines;

	if ( ! str ) {
		name = IS_IMMORTAL(this_player()) ? "general" : "players";
		lines = 0;
	}
	else {
		str = norm_id( str );
		if ( sscanf( str, "%s %d", name, lines ) != 2 ) {
			name = str;
			lines = 0;
		}
	}

	if ( ! ({int})CHANNEL_D->RegisterChannel( name, this_player(), 1 ) )
		return notify_fail("Unknown channel: "+name+".\n");

	CHANNEL_D->SendChannelHistory( name, this_player(), lines );
	return 1;
}
