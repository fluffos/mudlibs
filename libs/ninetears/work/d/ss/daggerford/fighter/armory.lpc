#include "path.h"
inherit "/std/storeroom";

void setup ()
{
  set_short ("Guild Armory");
  set_long ("This is a room where Fighters can leave items for their "+
   "brethren in need to borrow.  Please do not sell these items, but rather "+
   "return them here when you are finished with them. \n");

  set_light (60);

  add_exit ("south", ROOM+"barracks", "corridor");
}

int clean_up()
{
 return 1;
}
