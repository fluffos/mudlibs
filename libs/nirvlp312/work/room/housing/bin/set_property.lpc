#include "../defs.h"

int *priv_cost() { return ({ 2, 100000 }); }

/* Global Variables */
mapping Upgrades;

status
main(string arg, object room, object master)
{
  string *t;
  int i;

  if (!arg || !strlen(arg))
  {
    notify_fail("You must specify which property to set.\nUse "
      +HIW+"settings"+NORM+NORM+" or "+HIW+"properties"+NORM+NORM
      +" to see the available properties you can set.\n");
    return 0;
  }

  t = (string *)master->query_upgrades();
  arg = lower_case(arg);

  if (!sizeof(t) || member_array(arg, t) < 0)
  {
    notify_fail("You have not purchased the upgrade to allow setting of that property.\n");
    return 0;
  }
  
  if (!(room->add_prop(arg)))
    return 0;
    
  write("Property successfully set: "+arg+".\n");
  room->save_info();
  return 1;
}
