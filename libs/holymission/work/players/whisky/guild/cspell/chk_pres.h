
#include "defs.h"

mixed chk_present(string arg,int cost,int wisdom)
{
   object mob;

       if (!stringp(arg) || !(mob = present(arg,_e(_tp))) )
       {
           write("Whom ?\n");
           return 1;
       }
       else if (wisdom > _tp->query_wis())
       {
           write("You are not wise enough to cast this spell.\n");
           return 1;
       }
       else if (cost > _tps)
       {
          write("You are too low on power !\n");
          return 1;
       }
       else if (objectp(mob) && living(mob))
           return mob;
     write(
     capitalize(arg)+" is not a living !\n");
     return 1;
}

       
        
