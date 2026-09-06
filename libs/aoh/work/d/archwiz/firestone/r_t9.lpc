inherit "/std/room";

#include <rooms.h>
#include "path.h"

create() {
  ::create();
  SetIntShort("In a corridor");
  SetIntLong("You are in a corridor.\n");
  SetIndoors(1);
  AddExit("west","./r_t4");
  AddItem(FIRESTONE("orc"),REFRESH_HOME,random(5)+2);
}
