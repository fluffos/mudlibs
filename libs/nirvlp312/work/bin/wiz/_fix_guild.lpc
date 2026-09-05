#include "cmd_defs.h"

int cmd_fix_guild(string str)
{
 object fool;
 int x;

 if(!str)
 {
  write("Usage: 'fix_guild <name>'\n");
  return 1;
 }
 if(!(fool = find_player(str)))
 {
  write(capitalize(str)+" is not logged in.\n");
  return 1;
 }
 fool->set_guild_exp(0);
 fool->set_guild_rank(0);
 fool->set_guild_name(0);
 fool->set_home(0);
 fool->set_guild_file(0);
 write("Ok, you have removed "+capitalize(str)+"'s guild status.\n");
  if(!fool->is_wizard() && !fool->is_testchar())
 log_file("FIX_GUILD", msg+CAP(str)+"\n");
 return 1;
}

