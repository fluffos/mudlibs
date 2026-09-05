#include "../guild_defs.h"

int cmd_deduct(string str)
{
  object ob;

  if(!str) return 0;
  ob = find_player(str);
  if(!ob) return 0;

  MASTER->deduct_slave(ob);
  return 1;
}
