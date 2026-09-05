#include "../defs.h"

int *priv_cost() { return ({ 2, 0 }); }

/* Global Variables */
mapping Upgrades;

status
main(string arg, object room, object master)
{
  string *t;
  int i;

  if (!arg || !strlen(arg))
  {
    notify_fail("You must specify which property to remove.\nUse "
      +HIW+"settings"+NORM+NORM+" or "+HIW+"properties"+NORM+NORM
      +" to see room properties.\n");
    return 0;
  }

  t = (string *)master->query_upgrades();
  arg = lower_case(arg);
    
  if (!sizeof(t) || member_array(arg, t) < 0)
  {
    notify_fail("You don't even have the upgrade that allows setting of that property.\n");
    return 0;
  }
  
  if (!(room->remove_prop(arg)))
    return 0;
    
  write("Property successfully removed: "+arg+".\n");
  return 1;
}
