#include "../defs.h"

int *priv_cost() { return ({ 2, 5000 }); }

status
main(string arg, object room, object master)
{
  object ob;
  string dir, base;
  int num;

  ob = first_inventory(room);

  while(ob)
  {
    if (living(ob) && (object)ob->query_attack())
    {
      notify_fail("Exits may not be changed during combat.\n");
      return 0;
    }
    
    ob = next_inventory(ob);
  }

  if (!arg || !strlen(arg) || sscanf(arg, "%s %d", dir, num) != 2)
  {
    notify_fail("Syntax: "+HIW+"add_exit "+HIK+"<direction> <roomnumber>\n"+NORM+NORM);
    return 0;
  }

  if (HOUSED->forbidden_verb(dir))
  {
    notify_fail("You may not override the command "+HIW+dir+NORM+NORM+".\n");
    return 0;
  }

  base = (string)room->query_base_filename();

  if (!((status)room->add_exit(base+num, dir)))
    return 0;

  write(HIY+"Exit added: <"+HIW+dir+HIY+"> to room#: "+num+"\n"+NORM+NORM);
  write("Note: changes do not take effect until you use 'save_settings'\n");
  return 1;
}
