#include "/bin/wiz/cmd_defs.h"

int cmd_set_home(string str)
{
 string who, what;
 object x;
 if(!str || sscanf(str,"%s %s",who,what) != 2)
 {
  write("Usage: 'set_home <player> <file>'\n");
  return 1;
 }
 if(!(x=find_player(who)))
 {
  write("Target is not in play.\n");
  return 1;
 }
 if((int)x->query_level() > (int)this_player()->query_level())
 {
  write("You may not set the home of a higher level wiz.\n");
  return 1;
 }
 x->set_home(what);
 write("You have set "+who+"'s home to "+what+".\n");
 if(!x->is_wizard() && !x->is_testchar())
 log_file(logwiz+"SET_HOME", msg+CAP(who)+" -> "+what+"\n");
 return 1;
}
