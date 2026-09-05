#include "../defs.h"

int *priv_cost() { return ({ 2, 0 }); }

status
main(string arg, object room, object master)
{

  if (!arg || !strlen(arg))
  {
    notify_fail("Uninvite whom?\n");
    return 0;
  }

  if (!((status)master->remove_invited(arg)))
    return 0;

  write(HIY+capitalize(arg)+" no longer is invited to enter.\n"+NORM+NORM);
  return 1;
}
