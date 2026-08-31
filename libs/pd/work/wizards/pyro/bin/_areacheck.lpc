#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_areacheck(string str) {
  int numsize = 25;
  if(str && sscanf(str, "%d", numsize) != 1) return notify_fail("Syntax: <skyscan ([numRooms])>\n");
  write("You leap into the sky and scan "+environment(this_player())->query_short()+" before returning to the ground.\n");
  message("info", this_player()->query_cap_name()+" leaps into the air and surveys the environment, before returning gracefully to the ground.", environment(this_player()), this_player());
  //write("/wizards/pyro/sandbox/long_map"->get_map(numsize));
  write("/wizards/pyro/sandbox/long_map"->get_map(numsize, this_player(), 1, 1));
  return 1;
}

