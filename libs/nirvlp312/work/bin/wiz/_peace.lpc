#include "/bin/wiz/cmd_defs.h"

int cmd_peace()
{
 object att, *ob;
 int    h, s;
 s = sizeof(ob = all_inventory(ENVTP));
 
 while(h < s)
 {
  if(att = (object)ob[h]->query_attack())
  {
   ob[h]->stop_fight();
   att->stop_fight();
  }
  h ++;
 }

 tell_room(ENVTP, 
  CAP((string)TP->QN)+" has called a stop to all fighting!\n");
 return 1;
}

