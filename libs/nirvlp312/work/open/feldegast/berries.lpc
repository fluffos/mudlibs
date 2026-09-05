#include "defs.h"

/* /players/feldegast/std/generic_heal.c */
inherit HEAL;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("berries");
  add_alias("fermented berries");
  set_short("A basket of fermented berries");
  set_long("This is a wicker basket with a cheesecloth lining, filled with berries.\n");
  set_type("berries");
  set_msg("You stuff a handful of fermented berries in your mouth.\n");
  set_msg2(" eats a handful of fermented berries.\n");
  add_cmd("eat");
  set_heal(50,50);
  set_charges(3);
  set_intox(2);
  set_stuff(7);
  set_soak(7);
  set_value(600); /* per charge */
}
