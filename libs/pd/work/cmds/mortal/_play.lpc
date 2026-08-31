#include <std.h>

inherit DAEMON;

int cmd_play(string str)
{
if(this_player()->query_arena()) return notify_fail("You are in the arena.\n");
 if (str!="paintball") return 0;
 if (!"/d/paintball/start"->query_paintball()) return 0;
 if (file_name(environment(this_player()))=="/d/paintball/start")
   return 0;
 write("You have been transferred to the starting room.");
 this_player()->move_player("/d/paintball/start", "Into the light");
 return 1;
}
int help()
{
  write( @EndText
Syntax: play
Effect: if a paintball game has started, this allows you to join.

EndText
  );
  return 1;
}
