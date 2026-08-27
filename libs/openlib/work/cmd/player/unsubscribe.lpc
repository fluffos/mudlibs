/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

#define USAGE "unsubscribe <channel>\n"

int
main(string str)
{
  if( !str )
    return notify_fail(USAGE);

  if( !this_player()->is_subscribed_chan(str) )
    return notify_fail("You are not subscribed!\n");

  this_player()->set_channels( this_player()->query_channels() - ({ str }) );

  if( CHAT_D->channel_exists(str) )
    CHAT_D->remove_member(str, this_player());

  write("Unsubscribed.\n");

  return 1;
}
