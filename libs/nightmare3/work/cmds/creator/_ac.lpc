//      /bin/dev/_ac.c
//      from the Nightmare Mudlib
//      queries the ac of an object and displays it
//      created by Valodin@Nightmare 930306

#include <std.h>

inherit DAEMON;

int show_ac(object ob) {
  int i, limbsize, ac;
  string *limbs;        
  string type;
  object eob;

  if(!(ac = ob->query_ac()))
  {
    write("No Armour Class\n");
    return 1;
  }
    message("Nsystem", sprintf("AC: %d\tprotects ", ac), this_player());
  type = ob->query_type();
  if(type == "two handed")
    limbs = ({ "both hands" });
  else
    if(type == "blade" || type == "blunt" || type == "projectile" || 
       type == "knife")
      if (!(eob = environment(ob)) || !(living(eob)))
        limbs = ({ "a hand" });
      else
      {  
        limbs = eob->query_wielding_limbs();
        for(i = 0; i < sizeof(limbs); i++)
          if(ob != (object)eob->query_weapon(limbs[i]))
            limbs -= ({ limbs[i] });
        if(!limbs)
          limbs = ({ "a hand" });
      }
  else
    limbs = ob->query_limbs();
  limbsize = sizeof(limbs);
  for (i = 0; i < limbsize; i++)
  {
    message("Nsystem", sprintf("%s", limbs[i]), this_player());
    if(i == (limbsize - 1))
      write("\n");
    else
       if(i == (limbsize - 2))
         message("Nsystem", ", and ", this_player());
       else
        message("Nsystem", ", ", this_player());
  }
  return 1;
}

int has_ac(object ob)
{
  if(ob->query_ac()) return 1;
  else return 0;
}

int cmd_ac(string str)
{
  object *inv;
  int inv_size;
  object ob;
  int i;               

  if((!str) || !(ob = to_object(str))) 
  {
    notify_fail("Find AC of what object?  See \"help format\"\n");
    return 0;
  }  
  if(!living(ob))
  { /* must be an object */
    message("Nsystem", sprintf("Querying %s: %s", str, ob->query_short()), this_player());
    show_ac(ob);
    return 1;
  }

  inv = filter_array(all_inventory(ob), "has_ac", this_object());
  inv_size = sizeof(inv);
  if(inv_size) 
    message("Nsystem", sprintf("Querying inventory of %s: %s", str, ob->query_short()), this_player());
  else
    write(str + ": " + ob->query_short() + " has no armor.\n");
  for (i = 0; i < inv_size; i++)
  {       
    message("system", sprintf("\n%s", inv[i]->query_short()), this_player());
    show_ac(inv[i]); 
  }
      
  return 1;
}

int help()
{
  write("Command: ac\nSyntax: ac <object>\nShows the armor class of an object,\
 or armor\nclasses of all the objects held by a living\nobject.  See \"help\
 format\" to see how to specify\nobjects.\nSee also: wc, format, I\n");
  return 1;
}
