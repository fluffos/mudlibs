/* channel.c 
 *
 * this is the thingie that takes care of the channels and
 * distribute the stuff to the channel-system.
 *
 * Baldrick dec '97
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}

protected int cmd(string str, object me, string verb) 
  {
  if (verb == "channel")
    {
    write("Some day you might get to know what channels you have turned on.\n");
    return 1;
    }
  "global/do_chat"->do_chat( str, verb );
  this_object()->set_trivial_action();
  return 1;
}

