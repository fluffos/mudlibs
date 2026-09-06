#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Baby Deer Playground");
  SetIntLong(
"Green meadow with the forest surrounding the meadow. Little "
"baby animals play here with their mothers.\n");
  SetIndoors(0);
  AddDetail(({"meadow","green meadow","playground"}),#'IntLong);
  AddDetail(({"little animals","little animal","animals","animal",
    "baby animals","baby animal","little baby animals","little baby animal"}),
"They love to play around here.\n");
  AddExit("west","./pa5n5");
  AddExit("east","./pa3n5");
  AddExit("south","./pa4n6");
  AddExit("north","./pa4n4");
  AddItem(MONSTER("park/deer"),REFRESH_HOME,3);
}
