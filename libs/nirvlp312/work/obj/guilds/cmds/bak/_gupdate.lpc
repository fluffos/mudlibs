#include "../guild_defs.h"

int cmd_gupdate(string str)
{
  object ob;

  if(!str) str = (string)TP->QRN;

  if(str != "all") { 
  ob = find_player(str);
  if(!ob) return 0;
 }
 else {
    object *us; int x;
     x = sizeof(us = users());
     while(x--)
       if((string)us[x]->query_guild_name() == GUILDNAME)
         MASTER->renew_slave(us[x]);
     return 1;
   }

  MASTER->renew_slave(ob);
  return 1;
}
