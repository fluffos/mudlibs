#include "/bin/wiz/cmd_defs.h"

int cmd_set_level(string str)
{
 object x;
 string who;
 int what, prev_lev;

 if(!str || sscanf(str, "%s %d",who,what) != 2)
 {
  write("Usage: 'set_level <who> <level>'\n");
  return 1;
 }
 if(!(x = find_player(who)))
 {
  write("Target is not in play.\n");
  return 1;
 }
 prev_lev = (int)x->query_level();
 x->set_level(what);
 write("You have set "+CAP(who)+"'s level to "+what+".\n");
 if(!x->is_wizard() && !x->is_testchar())
 log_file(logwiz+"SET_LEVEL", 
  msg+CAP(who)+" from "+prev_lev+" to "+what+"\n");
 return 1;
}

