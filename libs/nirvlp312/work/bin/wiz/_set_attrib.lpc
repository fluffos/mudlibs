#include "/bin/wiz/cmd_defs.h"

int cmd_set_attrib(string str)
{
 string who, what;
 object x;
 int  amt;

 if(!str || sscanf(str, "%s %s %d",who,what,amt) != 3)
 {
  write("Usage: 'set_attrib <player> <attrib> <#>'\n");
  return 1;
 }

 if(!(x = find_player(who)))
 {
  write("Target is not in play.\n");
  return 1;
 }

 x->set_attrib(what, amt);
 write("You have set "+CAP(who)+"'s attrib '"+what+"' to "+amt+".\n");
 if(!x->is_wizard() && !x->is_testchar())
 log_file(logwiz+"SET_ATTRIB",msg+CAP(who)+" : "+what+" to "+amt+"\n");
 return 1;
}

