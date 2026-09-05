#include "../defs.h"

int *priv_cost() { return ({ 2, 5000 }); }

status
main(string arg, object room, object master)
{
  object ob;

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

  if (!arg || !strlen(arg))
  {
    notify_fail("You must specify an exit to remove.\n");
    return 0;
  }

  if (!((status)room->remove_exit(arg)))
    return 0;

  write(HIY+"Exit removed: "+arg+".\n"+NORM+NORM);
  write("Note: changes do not take effect until you use 'save_settings'\n");
  return 1;
}
