/*
// File     :  _channels.c
// Purpose  :  show (and alter) which channels exist
// 93-08-28 :  Written by Pallando
*/
#include <channels.h>
#include <daemons.h>
#include <mudlib.h>

inherit DAEMON;

#ifdef NO_NEW_CHANNELS
#define SYNTAX "Syntax: channels\n"
#else
#define SYNTAX "Syntax: channels [ { create | delete } <channel> } ]\n"
#endif /* NO_NEW_CHANNELS */

int cmd_channels( string arg )
{
    string *chan_names, *current;
    mapping chans;

    chans = (mapping)CHANNELS_D-> q();
    if( !mapp( chans ) ) chans = ([]);
    chan_names = keys( chans );

    chan_names = filter_array( chan_names, "may_use", this_object(), chans );

    if( !arg )
    {
        if( !sizeof( chan_names ) )
            write( "There are no active channels.\n" );
        else
            write( "The channels are:\n"+wrap( implode( chan_names, ", " ) ) );
        return 1;
    }

    notify_fail( SYNTAX );
#ifdef NO_NEW_CHANNELS
    return 0;
#else
    if( sscanf( arg, "%s %s", flag, channel ) != 2 )
        return 0;

    if( flag == "create" )
    {
        stat = (int)CHANNELS_D-> register_channel( channel,
            this_player(), CRE, 0 );
        if( CHANNELS_D-> register_channel( channel, this_player(), CRE, 0 ) )
            write( "Channel " + channel + " created.\n" );
        else
            write( "You may not do that.\n" );
        return 1;
    }
    if( flag == "delete" )
    {
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
    return( !stringp( chans[chan]["priv"] ) || ( 0 !=
      member_group( geteuid( this_player() ), chans[chan]["priv"] ) ) );
}

int help()
{
#ifndef NO_NEW_CHANNELS
  write( @EndText
Syntax: channels create <channel>
Effect: Creates a channel named <channel>

Syntax: channels delete <channel>
Effect: Deletes channel <channel> (uncreates it)

EndText
  );
#endif /* NO_NEW_CHANNELS */
  write( @EndText
Syntax: channels
Effect: Shows the currently existing channels you can use.

To use a channel, eg "wiz", you must first tune into it.
  "tune wiz"    (see "help tune" for more details)
then to broadcast <message> to everyone else on the channel, just type
  "wiz <message>"
To see who is on a channel type
  "show wiz"    (see "help show" for more details)

There are a couple of special channels "gwiz" and "interwiz".
These broadcast to users not just on this mud but about 50 other muds.
(See "help mudlist").
EndText
  );
  return 1;
}
