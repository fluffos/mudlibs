#include "/bin/wiz/cmd_defs.h"

int cmd_add_xp(string str)
{
 object x;
 string who;
 int    what;
 if(!str || sscanf(str,"%s %d",who,what) != 2)
 {
  write("Usage: 'add_xp <player> <#>'\n");
  return 1;
 }
 if(!(x=find_player(who)))
 {
  write("Target is not in play.\n");
  return 1;
 }
 x->add_exp(what);
 write("You have added "+what+" xp to "+CAP(who)+".\n");
  if(!x->is_testchar() && !x->is_wizard())
 log_file(logwiz+"ADD_XP",msg+"+"+what+" xp to "+CAP(who)+"\n");
 return 1;
}

