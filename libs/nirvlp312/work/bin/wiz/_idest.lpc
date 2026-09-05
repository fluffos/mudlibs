#include "/bin/wiz/cmd_defs.h"

int cmd_idest(string str)
{
 string name, what;
 object ob, targ;

 if(!str || sscanf(str, "%s %s", name, what) != 2)
 {
  write("Usage: 'idest <player> <object>'\n");
  return 1;
 }

 if(!(targ = find_player(name)))
 {
  write("Target is not in play.\n");
  return 1;
 }

 if(!(ob = present(what, targ)))
 {
  write("Object is not on target.\n");
  return 1;
 }
 
 destruct(ob);
 TL(targ, CAP((string)TP->RN)+" has dested "+what+" off you.\n");
 write("You have dested "+what+" off of "+targ->query_name()+".\n");
 return 1;
}
