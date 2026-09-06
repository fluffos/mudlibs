#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Red Robin Singing Area");
  SetIntLong(
"Tall evergreen trees everywhere in the forest. "
"Red Robin usually visit this area to look for "
"food for their family.\n");
  SetIndoors(0);
  AddDetail(({"robin","red robin","bird","birds"}),
"It's the home area of red robin.\n");
  AddDetail(({"forest","tall forest","green forest"}),
"It is a forest of tall evergreen trees.\n");
  AddDetail(({"trees","tree","tall trees","tall tree","green tree",
    "green trees","tall evergreen trees","tall evergreen tree","evergreen tree",
    "evergreen trees"}),
"The trees are really tall and are green the whole year.\n");
  AddExit("west","./pa2n7");
  AddExit("north","./pa1n6");
  AddItem(MONSTER("park/robbin"),REFRESH_HOME,3);
}
