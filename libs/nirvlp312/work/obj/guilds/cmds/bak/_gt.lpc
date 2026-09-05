#include "../guild_defs.h"
int cmd_gt(string str)
{
  if(!str) return 0;

  MASTER->broadcast("[" + GUILDNAME + "] " + (string)this_player()->query_name() + ": " + str);
  return 1;
}
