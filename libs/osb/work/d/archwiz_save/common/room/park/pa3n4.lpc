#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("In the middle of the City Park");
  SetIntLong(
"You are on the path in the City Park. You have traveled a long "
"way. The path splits into four ways.\n");
  SetIndoors(0);
  AddDetail(({"city park","park"}),
"It is the city park of Nightfall City.\n");
  AddDetail(({"nightfall city","city","town","capital"}),
"Nightfall city is the capital of this world.\n");
  AddDetail("path","It splits in four ways.\n");
  AddExit("west","./pa4n4");
  AddExit("east","./pa2n4");
  AddExit("south","./pa3n5");
  AddExit("north","./pa3n3");
  AddItem(OBJ("teddybear"), REFRESH_REMOVE);
}
