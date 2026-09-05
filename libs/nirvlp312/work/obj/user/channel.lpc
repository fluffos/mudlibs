/******************************************************************************
 * Program: channel.c
 * Path: /obj/user
 * Type: Include file for player.c
 * Created: July 7, 2014 by Dragnar
 *
 * Purpose: Variables and functions that are needed for channels.
 *
 * History:
 *          07/07/2014 - Gnar
 *            Updated to use the channel daemon.
 ******************************************************************************/
#include <security.h>

#pragma strict_types
#pragma save_types
#define CHAN "/bin/channel_daemon"

#include "/bin/channel.h"

string *channel_names;

int
add_channel(string new_chan) {
  if (!CHAN->valid_channel(new_chan)) {
    
    /** Everyone should be on Announce Channel **/
    if( new_chan == "announce" )
      CHAN->add_channel( new_chan, this_object() );
      
    return 1;
  }

  CHAN->add_channel( new_chan, this_object() );
  if( member_array( new_chan, channel_names) < 0 )
    channel_names += ({ new_chan });
  
  if( this_object()->query_level() > EXPLORE || (new_chan != "msg" && new_chan != "jukebox") )
    add_action( "broadcast", new_chan );
    
  return 1;
}

int
remove_channel(string channel) {
  int index;

  if ((index = member_array(channel, channel_names)) == -1) {
    write("You are not on that channel.\n");
    return 1;
  }
  
  CHAN->remove_channel( channel, this_object() );
  channel_names -= ({ channel_names[index] });
  remove_action(channel);
  return 1;
}

int
broadcast(string msg) {
  string channel;

  channel = query_verb();
  CHAN->channel_message(channel, msg);
  this_object()->add_channelcount();
  return 1;
}

int
list_channels() {
  
  CHAN->query_player_channels( this_object() );
  return 1;
}

void
init_channels() {
  int index;

  for (index = 0; index < sizeof(channel_names); index++)
     if(this_object()->query_level() > 20 || channel_names[index] != "msg" || channel_names[index] != "jukebox")
      add_channel( channel_names[index] );
      
  /** Force announce channel on all players **/
  if( member_array( "announce", channel_names ) < 0 )
    add_channel( "announce" );
}

