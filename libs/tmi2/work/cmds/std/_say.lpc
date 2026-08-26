//  Original write: Tzar@Earth
//
// Leto thinks that's highly unlikely. Even the tmi-2 0.9 lib
// probably didn't come without a say command :)
// Leto removed some silly arguments to say() and idented the code
// so it would be readable, and optimized Tzar's code quite a bit :)
// say() doesn't work correctly for amcp yet, Leto
// Leto removed wraps, 160296
// Leto changed all message classes to "say", 030396
 
#include <mudlib.h>
 
inherit DAEMON;
 
int cmd_say(string str) {

int last;
 
this_player()->block_attack(2) ;
if ((!str) || (str == " "))
 {
  message("error","[say] Usage: say <message>\n", this_player() );
  return 1;
 }
last = str[<1];
if (last != '?' && last != '!')
 {
  message("say","You say: "+str+"\n", this_player() );
  message("say",wrap(this_player()->query("cap_name")+" says: "+str
  ),environment(this_player()),this_player() );
  return 1;
 }
if (last == '?')
 {
  message("say","You ask: "+str+"\n", this_player() );
  message("say",this_player()->query("cap_name")+" asks: "+ str+"\n",
   environment(this_player()),this_player() );
  return 1;
 }
if (last == '!')
 {
  message("say","You exclaim: "+str+"\n", this_player() );
  message("say",this_player()->query("cap_name") + " exclaims: " + str+"\n" ,
    environment(this_player()),this_player() );
  return 1;
 }
return 1;
}
 
string help() {

return @HelpText

Usage:  say <message>

The say command sends your <message> to everyone in the current room.

HelpText;
}

