#include "/players/tinman/defs.h"  

#define COST 2

int main(string arg)
{
    string whom, what;
    object mob;

    if (!arg)
         return 0;
    else if (sscanf(arg,"%s %s",whom,what)!=2)
    {
       write("mt whom what ?\n");
       return 1;
    }
    else if(TP->query_sp() < COST)
    {
       write("You are too low on power !\n");
      return 1;
    }
    else if (!objectp(mob = find_living(whom)))
    {
      write("You cant find anyone called "+whom+" !\n");
       return 1;
    }
    write("You conzentrate on "+whom+".\n");
    ltell(mob,"thinks:",":*) "+what+"\n",TP);
    TP->restore_spell_points(-COST);
    return 1;
}
