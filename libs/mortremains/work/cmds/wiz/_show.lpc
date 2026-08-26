/*
// File     :  _show.c
// Purpose  :  shows who is using which channels
// 93-08-28 :  Written by Pallando
*/
#include <channels.h>
#include <daemons.h>
#include <net/dns.h>
#include <mudlib.h>

inherit DAEMON;

#define SYNTAX "Syntax: show [<channel>]\n"

int cmd_show( string channel )
{
    string ret, *chan_names, *current, chan, mud;
    mapping chans;

    if( !channel || channel == "channels" )
    {
        current = this_player()-> query( "channels/toggle" );
        if( !pointerp( current ) || !sizeof( current ) )
            ret = "You are tuned out of all channels.\n";
        else
            ret = "You are tuned into:\n" + wrap( implode( current, ", " ) );
        if( channel )
        {
            write( ret );
            return 1;
        } else {
            notify_fail( ret );
            return 0;
        }
    }
    if(sscanf(channel, "%s %s", chan, mud) == 2) {
        if(!((mapping)DNS_MASTER->query_mud_info(mud))) {
             message("error", "We are unaware of "+mud+".\n", this_player());
             return 1;
        }
        message("system", "Query sent.\n", this_player());
        GWIZLIST_Q->send_gwizlist_q(chan, mud);
        return 1;
    }
    chans = (mapping)CHANNELS_D-> q();
    if( !mapp( chans ) ) chans = ([]);
    chan_names = keys( chans );

    chan_names = filter_array( chan_names, "may_use", this_object(), chans );

    if( -1 == member_array( channel, chan_names ) )
    {
        write( "You can find no channel " + channel + "\n" );
        return 1;
    }
    write( "The following users are tuned into channel " + channel + ":\n" );
    write( wrap( CHANNELS_D-> display_channel( channel, this_player() ) ) );
    return 1;
}

int may_use( string chan, mapping chans )
{
    return( !stringp( chans[chan]["priv"] ) || ( 0 !=
      member_group( geteuid( this_player() ), chans[chan]["priv"] ) ) );
}

int help()
{
  write( @EndText
Syntax: "show" or "show channels"
Effect: Shows the channels you are tuned into.

Syntax: show <channel>
Effect: Shows who is tuned into channel <channel>.

See also: "help tune" and "help channels"
EndText
  );
  return 1;
}
