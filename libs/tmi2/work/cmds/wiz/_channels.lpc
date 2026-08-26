/*
// File     :  _channels.c
// Purpose  :  show (and alter) which channels exist
// 93-08-28 :  Written by Pallando
*/
#include <channels.h>
#include <daemons.h>
#include <net/daemons.h>
#include <mudlib.h>
#include <messages.h>

inherit DAEMON;

#ifdef NO_NEW_CHANNELS
#define SYNTAX "Syntax: channels [-l [regexp]| who <channel> <mudname> ]\n"
#else
#define SYNTAX "Syntax: channels [ { create | delete | admin | who } <channel> [modifiers] } ]\n"

#endif /* NO_NEW_CHANNELS */

int cmd_channels( string arg )
{
    string *chan_names, *current, *lines, line, flag, channel;
    string group, mode;
    mapping chans;
    int i, stat, type;

    chans = (mapping)CHANNELS_D-> q();
    if( !mapp( chans ) ) chans = ([]);
    chan_names = keys( chans );

    chan_names = filter_array( chan_names, "may_use", this_object(), chans );

    if( !arg )
    {
    for( i=0; i<sizeof(chan_names); i++ )
        if( chans[chan_names[i]]["object"] )
          chan_names[i] += "*";

        if( !sizeof( chan_names ) )
            write( "There are no active channels.\n" );
        else
            write( "The channels are:\n"+wrap( implode( chan_names, ", " ) ) );
        return 1;
    }
    channel="";
    if( arg == "-l" || sscanf( arg, "-l %s", channel) == 1 ) {
	lines = ({ });
        for( i=0; i<sizeof(chan_names); i++ ) {
	  line = sprintf( "%-18s %-13s", chan_names[i], 
		  chans[chan_names[i]]["priv"] ? chans[chan_names[i]]["priv"] : "player" );
	  if( chans[chan_names[i]]["object"] ) {
		line += " I3: "+chans[chan_names[i]]["creator"]+", ";
		switch( chans[chan_names[i]]["mode"] ) {
		 case 0: line += "selective ban";
			 break;
		 case 1: line += "selcectve allow";
			 break;
		 case 2: line += "filtered list";
			 break;
		}
	   }
	  lines += ({ line });
	}
	  if( channel ) lines = regexp( lines, channel );
	  this_player()->more( lines );
	  return 1;
   }
    notify_fail( SYNTAX );
    if( sscanf( arg, "%s %s", flag, channel ) != 2 )
        return 0;

    if( flag == "who" && adminp( this_player()) ) {
        string mud;
        if( sscanf( channel, "%s %s", channel, mud ) != 2 )
                return 0;
        message( MSG_COMMAND, "Send channel who request to "+mud+"\n",
                this_player() );
        CHANNELS_D->display_i3channel( channel, mud, this_player() );
        return 1;
    } 
 
	

#ifdef NO_NEW_CHANNELS
    return 0;
#else

    if( flag == "create" && adminp(this_player()) )
    {   sscanf( channel, "%s %s", channel, group);
	if(group) sscanf( group, "%s %s", group, mode );
	write( channel+" "+group+" "+mode+"\n" );
        if( mode )
	    switch( mode ) {
	      case "ban": type = 0; break;
	      case "admit": type = 1; break;
	      case "filter": type = 2; break;
	      default: notify_fail( "Unkown channel mode: "+mode+"\n" );
		       return 0; 
          }
	if( group == "player" || group == "all" ) group = 0;
	if( group && !member_group( geteuid( this_player()), group ) ) {
		notify_fail("You dont even belong to the group "+group+".\n" );
		return 0;
	}
	if( mode )
          stat=(int)CHANNELS_D-> register_channel( channel,
		this_player(), CRE, ({ group, type, (object)I3_DAEMON}) );
	else
	  stat=(int)CHANNELS_D-> register_channel( channel,
                this_player(), CRE, ({ group }) );
        if( stat ) 
            write( "Channel " + channel + " created.\n" );
        else
            write( "You may not do that.\n" );
        return 1;
    } else
    if( flag == "admin" && adminp(this_player()) ) {
	// This looks ugly ? ;)
	string *add_list=({ }), *rem_list=({ }), remove, add;
	if( sscanf( channel, "%s /add %s", channel, add ) == 2 )
		add_list=explode( add, " " );
	else if( sscanf( channel, "%s /remove %s", channel, remove ) == 2)
		rem_list=explode( remove, " " );
	else {
		notify_fail( "You must specifiy either /add or /remove.\n" );
		return 0;
	}
	if( !chans[channel] ) {
                notify_fail("Channel '"+channel+"' doesnt exist.\n" );
                return 0;
        }      
	stat=(int)CHANNELS_D-> register_channel( channel, this_player(), ADM,
				({ add_list, rem_list }) );
	if( stat ) write("Channel admin request send.\n" );
	else {
	 	notify_fail( "Failed to send channel admin request.\n" );
		return 0;
	}
	return 1;
	
    } 
    if( flag == "delete" && adminp(this_player()) )
    {   if( !chans[channel] ) {
		notify_fail("Channel '"+channel+"' doesnt exist.\n" );
		return 0;
	}
        if( CHANNELS_D-> register_channel( channel, this_player(), DEL, 0 ) )
            write( "Channel " + channel + " deleted.\n" );
        else
            write( "You may not do that.\n" );
        return 1;
    }
    return 0;
#endif /* NO_NEW_CHANNELS */
}

int may_use( string chan, mapping chans )
{
    return( !stringp( chans[chan]["priv"] ) || chans[chan]["priv"]=="all" || ( 0 !=
      member_group( geteuid( this_player() ), chans[chan]["priv"] ) ) );
}

int help()
{
#ifndef NO_NEW_CHANNELS
  write( @EndText
Syntax: channels create <channel> [group] [mode]
Syntax: channels delete <channel>
Syntax: channels admin  <channel> </add list|/remove list>
Syntax: channels who    <channel> <MUDName>
Effect: Creates a channel named <channel>
	- group: users must be in that group to be able to use the channel
	- mode: I3 channel mode: ban, admit or filter

Syntax: channels delete <channel>
Effect: Deletes channel <channel> (uncreates it)

EndText
  );
#endif /* NO_NEW_CHANNELS */
  write( @EndText
Syntax: channels [-l [regexp]] 
Effect: Shows the currently existing channels you can use.
Channels appened with an asterix '*' are remote channels.
If you specifiy the '-l' flag, you will get a verbose
listening of all the channels includeing group access and
for I3 channels the creator MUD and their mode.

To use a channel, eg "gossip", you must first tune into it.
  "tune gossip"    (see "help tune" for more details)
then to broadcast <message> to everyone else on the channel, just type
  "gossip<message>"
To see who is on a channel type
  "show gossip"    (see "help show" for more details)

There are a couple of special channels "gwiz" and "code".
These broadcast to users not just on this mud but about 160 other muds.
(See "help mudlist").
EndText
  );
  return 1;
}
