#include <command.h>

int
main(string arg)
{
 string message;
if(!arg){
  return notify_fail("Why in heck would you want to emote just your name?\nUse:  emote <message>\n");
}
message = capitalize(this_player()->query_name()) + " ";
tell_room(environment(this_player()), message + arg + "\n");
return 1;
}
