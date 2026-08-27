/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

#define USAGE "subscribe <channel>\n"

int
main(string str)
{
  if( !str ) {
    write("Subscribed to:\n");
    write(implode((string *)this_player()->query_channels(), ", ")+"\n");
    return 1;
  }

  if( !(CHAT_D->channel_exists(str)) )
    return notify_fail(sprintf("Channel '%s' does not exist.\n", str));

  // level & guild checks here

  if( this_player()->is_subscribed_chan(str) )
    return notify_fail("You are already subscribed!\n");

  if( !CHAT_D->is_qualified(this_player(), str) )
    return notify_fail("You are not qualified.\n");

  this_player()->set_channels( this_player()->query_channels() + ({ str }) );

  CHAT_D->add_member(str, this_player());

  write("Subscribed.\n");

  return 1;
}
