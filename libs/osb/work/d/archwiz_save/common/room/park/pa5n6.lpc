#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Baby Lamb's Area");
  SetIntLong("Baaaaaa -- This is the hidden area of the Joe's Farm\n");
  SetIndoors(0);
  AddDetail(({"joe's farm","farm","hidden area","area"}),
"This is the hidden area of Joe's farm.\n");
  AddExit("east","./pa4n6");
  AddExit("south","./pa5n7");
  AddExit("north","./pa5n5");
  AddItem(MONSTER("park/lamb"),REFRESH_HOME,3);
}
