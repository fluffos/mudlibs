#include "path.h"
inherit "std/room";

create() {
  ::create();
  SetIntShort("South Road");
  SetIntLong(
"You are on South Road, a quiet suburban lane running east-west. "
"You come closer to the forest that lies west of here.\n");
  AddExit("west", "./southroad3");
  AddExit("east", "./southroad1");
  SetIndoors(0);
}

