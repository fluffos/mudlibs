#include "/bin/wiz/cmd_defs.h"

int cmd_place(string str)
{
 string name, where;
 object targ;

 if(!str || sscanf(str, "%s %s", name, where) != 2)
 {
  write("Usage: 'place <player> <file>'\n");
  return 1;
 }
 if(!(targ = find_player(name)) && !(targ=find_living(name)))
 {
  write("Target not in play.\n");
  return 1;
 }
 if(catch(where->load_it()))
 {
  write("Incorrect file or corrupt object.\n"+
        "Place FAILED.\n");
  return 1;
 }
 MO(targ, where);
 write("You have moved "+CAP(name)+" to "+where+".\n");
 TL(targ, "You have been moved to "+(string)ENV(targ)->short()+
  " by "+CAP((string)TP->RN)+".\n");
 return 1;
}

