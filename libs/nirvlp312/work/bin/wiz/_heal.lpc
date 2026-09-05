#include "/bin/wiz/cmd_defs.h"

int cmd_heal(string str)
{
 object ob;
 if(!str)
  ob = TP;
 else
  if(!(ob = find_living(str)))
  {
   write("Target is not in play.\n");
   return 1;
  }
 ob->heal_self(10000);
 if(ob != TP)
  TL(ob, CAP((string)TP->RN)+" has healed you.\n");
 write("You heal "+CAP((string)ob->RN)+".\n");
 return 1;
}
