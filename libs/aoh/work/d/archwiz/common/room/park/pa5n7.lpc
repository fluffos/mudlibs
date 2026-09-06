#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Good Witch od the West House");
  SetIntLong(
"A beautiful house in middle of the forest. "
"Singing can be heard throughout the area. "
"Flowers are growing everywhere around the house.\n");
  SetIndoors(0);
  SetIntNoise("You hear singing from everywhere.\n");
  AddNoise("singing","It is heard from everywhere.\n");
  AddDetail(({"flowers","flower"}),
"They look beautiful and seem to grow even better than anywhere else.\n");
  AddDetail(({"beautiful house","house","west house"}),
"It is the beautiful house of the good witch of the west.\n");
  AddExit("east","./pa4n7");
  AddExit("north","./pa5n6");
  AddItem(MONSTER("park/goodwitch"),REFRESH_HOME);
}
