/* Written by Valodin Jan 16, 1993
   Queries the WC of a player and displays it.

*/
#include <std.h>

inherit DAEMON;


int cmd_wc(string str)
{
  object *weapons;
  string *wielded_by;
  string *wielding_limbs;
  object wtemp;
  object ob;
  int i, wlsize, z;

  if((!str) || !(ob = to_object(str)))
  {
    notify_fail("Find WC of what object?  See \"help format\"\n");
    return 0;
  }
  if(!living(ob))
  { /* must be a weapon */
    write("Querying " + str + "  " + ob->query_short() + "\n");
    write("WC: " + ob->query_wc() + "\n");
    return 1;
  }

  weapons = ({});
  wielded_by = ({});
  wielding_limbs = ob->query_wielding_limbs();
  wlsize = sizeof(wielding_limbs);
  for(i = 0; i < wlsize; i++)
  {
    if(wtemp = ob->query_weapon(wielding_limbs[i]))
    {
      if((z = member_array(wtemp, weapons)) == -1)
      {
        weapons += ({ wtemp });
        wielded_by += ({ wielding_limbs[i] });
      }
      else
        wielded_by[z] += (" and " + wielding_limbs[i]);
    }
  }
  write("Querying " + str + "  " + ob->query_name() + "\n");
  switch(sizeof(weapons))
  {
    case 0: write("No weapons wielded.\n");
            return 1;
    case 1: write("1 weapon wielded: \n");
            break;
    default: write(sizeof(weapons) + " weapons wielded: \n");
  }
  wlsize = sizeof(weapons);
  for(i = 0; i < wlsize; i++)
    write(weapons[i]->query_wc() + "  " + weapons[i]->query_short() +
          " wielded in " + wielded_by[i] + "\n");
  return 1;
}

int help()
{
  write("Command: wc\nSyntax: wc <object>\n" +
        "Shows the weapon class of a weapon, or weapon\n" +
        "classes of all the weapons wielded by a living\n" +
        "object.  See \"help format\" to see how to specify\n" +
        "objects.\n" +
        "See also: ac, format, I\n");
  return 1;
}
