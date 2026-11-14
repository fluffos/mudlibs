#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cave");
  SetIntLong(
"You're in a cave with walls which seem to absorb the light.\n");
  AddDetail("cave",QueryIntLong());
  AddDetail(({"walls","wall"}),"The walls seem to absorb the light.\n");
  AddDetail(({"floor","ground","ceiling"}),"It looks pretty normal.\n");
  SetIndoors(1);
  SetBright(-10);
  AddExit("southeast","./incave5");
  AddExit("west","./doorx");
}
