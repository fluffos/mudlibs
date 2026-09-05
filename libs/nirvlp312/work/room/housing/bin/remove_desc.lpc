#include "../defs.h"

int *priv_cost() { return ({ 2, 0 }); }

status
main(string arg, object room, object master)
{

  if (!arg || !strlen(arg))
  {
    notify_fail("You must specify an item description to remove.\n");
    return 0;
  }

  if (!((status)room->remove_item(arg)))
    return 0;

  write(HIY+"Item description removed: "+arg+".\n"+NORM+NORM);
  write("Note: changes do not take effect until you use 'save_settings'\n");
  return 1;
}
