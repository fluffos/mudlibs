#include "../defs.h"

int *priv_cost() { return ({ 2, 0 }); }

status
main(string arg, object room, object master)
{
  int num;

  if (!arg && !strlen(arg))
  {
    notify_fail("You must specify a new setting for your linewrapping.\n");
    return 0;
  }

  if (sscanf(arg, ""+"%d", num) != 1)
  {
    notify_fail("Must specify a numeric argument, not: "+arg+".\n");
    return 0;
  }

  if (num < 20)
  {
    notify_fail("Please choose a number over 20.\nLet's not be silly here.\n");
    return 0;
  }

  write("Former linewrap setting: "+(int)master->query_wrap_pref()+"\n");
  write("Current linewrap setting: "+num+"\n");
  master->set_wrap_pref(num);
  return 1;
}
