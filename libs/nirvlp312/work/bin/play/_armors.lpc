/*
 * you can't take that away from me !
 * vert@nirv 2001, basic concept by eurale@nirv
 */

#include "all.h"
#include <ansi.h>

string *armours;

void reset(int arg)
{
    if(arg) return;
   armours = ({
    "armor","shield","helmet","boots","amulet",
    "chest","necklace","cloak","bracelet","pants","belt",
    "gloves","earring","ring","underwear", "misc",
 });
}

object *
locate_armor(string type)
{
	  int i;
	  string *t;
    object ob, *obs;
    if(!this_player()) return ({ });
    obs=({});
    ob = present(type, this_player());
    if(!ob) return ({});
    while(ob)
    {
      if(ob->query_worn()) {
        i = sizeof(t = (string*)ob->query_types());
        while(i--)
          if (t[i] == type) obs+=({ob});
      }
      ob = next_inventory(ob);
    }
    return obs;
}

int
cmd_armors(string arg)
{
    object ob, *obs;
    int s, x;
    
    if(ghost()) return 0;
    
    if(arg)
    {
      obs = locate_armor(arg);
      s = sizeof(obs);
      if(!s)
        write("You aren't wearing an armor of type " + arg + ".\n");
      else
      {
        write("Armors of type "+arg+":\n");
        for(x=0;x<s;x++)
          write((string)obs[x]->short() + ".\n");
      }
    }
    else
    {
      int i, sc;
      string fish;

      s = sizeof(armours);
      write("\n\tArmors:\n");
      for(i = 0; i < s; i ++)
      {  
        write(BOLD+"  *"+NORM+pad(capitalize(armours[i]), 10));
        
        obs = locate_armor(armours[i]);
        sc = sizeof(obs);
        if(!sc)
        {
          write("- Empty.\n");
          if(armours[i]=="ring" || armours[i]=="earring")
          {
            write(BOLD+"  *"+NORM+pad(capitalize(armours[i])+" 2",10)+"- Empty.\n");
          }
        }  
        else
        {
          for(x=0;x<sc;x++)
          {
            if(x != 0) /* only ring or earring */
            {
              write(BOLD+"  *"+NORM+pad(capitalize(armours[i])+" 2",10));
            }
            write("- "+(string)obs[x]->short()+".\n");
          }
        }
      }
      fish = "";
      ob = first_inventory(this_player());
      while(ob)
      {
        if((int)ob->query_worn() && member_array((string)ob->query_type(), armours) == -1)
/* added 5.15.03 ish by verte */
          if(ob->short())
          fish += "  " + (string)ob->short() + ".\n";
        ob = next_inventory(ob);
      }
      if(strlen(fish))
        write("\n\tAdditional worn items:\n" + fish);
    write("\n");
    }
    return 1;
}

string * query_valid_types() {
  return armours;
}

