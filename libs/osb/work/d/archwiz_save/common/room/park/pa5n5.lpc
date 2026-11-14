#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Long Lost Texas Longhorn");
  SetIntLong(
"You stumbled into the area where the wicked witch of the "
"west sends poor helpless animal far from their home!\n");
  SetIndoors(0);
  AddDetail("area",#'IntLong);
  AddExit("east","./pa4n5");
  AddExit("south","./pa5n6");
  AddExit("north","./pa5n4");
  AddItem(MONSTER("park/longhorn"),REFRESH_HOME,2);
}
