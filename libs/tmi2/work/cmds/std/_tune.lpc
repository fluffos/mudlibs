/*
// File     :  _tune.c
// Purpose  :  tunes users in and out of channels
//             "tune in, turn on, drop out"
// 93-08-26 :  Written by Pallando with apologies to Tim Leary
// 960425	ability to put in/out before the channel instead of behind
*/
#include <channels.h>
#include <daemons.h>
#include <mudlib.h>

inherit DAEMON;

#define SYNTAX "Syntax: tune [<channel>] [ in | out ]\n"

int cmd_tune( string arg )
{
    string flag, chan, *chan_names, *current;
    mapping chans;
    int loop, stat, ret, tuned_in;

    notify_fail( SYNTAX );
    if( !arg ) return 0;

    current = this_player()-> query( "channels/toggle" );
    if( !pointerp( current ) ) current = ({ });

    chans = (mapping)CHANNELS_D-> q();
    if( !mapp( chans ) ) chans = ([]);
    chan_names = keys( chans );

    chan_names = filter_array( chan_names, "may_use", this_object(), chans );

    if( arg == "in" )
    {
        stat = ADD;
        loop = sizeof( chan_names );
        while( loop-- )
            CHANNELS_D-> register_channel( chan_names[loop],
                this_player(), stat, 0 );
        this_player()-> set( "channels/toggle", chan_names );
        write( "All channels tuned in.\n" );
        return 1;
    }

    if( arg == "out" )
    {
        stat = KIL;
        loop = sizeof( current );
        while( loop-- )
            CHANNELS_D-> register_channel( current[loop],
                this_player(), stat, 0 );
        this_player()-> set( "channels/toggle", ({ }) );
        write( "All channels tuned out.\n" );
        return 1;
    }

    if( sscanf( arg, "%s %s", chan, flag ) != 2 )
        chan = arg;

    // SLC ability to put in/out before the channel instead of behind
    if (chan == "in" || chan == "out")
    {
	arg =  flag + " " + chan;
//	sprintf (arg, "%s %s", flag, chan);
	sscanf (arg, "%s %s", chan, flag);
    }

    // NB If you allow channel deletion then change this so
    // that channels that no longer exist may be deleted.
    if( -1 == member_array( chan, chan_names ) )
    {
        notify_fail( "There is no channel " + chan +
            " that you have access to.\n" );
        return 0;
    }

    if( -1 != member_array( chan, current ) ) tuned_in = 1;
    if( !flag ) flag = ( tuned_in ? "out" : "in" );
    switch( flag )
    {
        case "in":  tuned_in = 1; stat = ADD; break;
        case "out": tuned_in = 0; stat = KIL; break;
        default:
            notify_fail( "\"" + flag + "\" is neither \"in\" nor \"out\".\n" );
            return 0;
    }
  
    ret = (int)CHANNELS_D-> register_channel( chan, this_player(), stat, 0 );
    if( !ret ) { write( "Fail.\n" ); return 1; } // Can't happen. 8-)
    current -= ({ chan });
    if( tuned_in ) current += ({ chan });
    this_player()-> set( "channels/toggle", current );
    write( "Channel " + chan + " tuned " + flag + ".\n" );

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
Syntax: tune <channel> in
Effect: Tunes you into channel <channel>

Syntax: tune <channel> out
Effect: Tunes you out of channel <channel>

Syntax: tune <channel>
Effect: Toggles whether you are tuned into channel <channel>.

Syntax: tune in
Effect: Tunes you in to all channels available to you.

Syntax: tune out
Effect: Tunes you out of all channels.

See also: "help show" and "help channels"
EndText
  );
  return 1;
}
