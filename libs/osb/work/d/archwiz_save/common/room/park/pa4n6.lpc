#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Area Of Deer Mother");
  SetIntLong(
"Stream is running through the forest.  Birds are singing and "
"feeding their babies.\n");
  SetIndoors(0);
  AddDetail(({"stream","river"}),
"It is a small stream of water, but the water looks not drinkable.\n");
  AddDetail(({"birds","bird","baby","babies"}),
"They hop around the forest.\n");
  AddDetail(({"forest","trees","tree","small forest"}),
"It's just a small forest near a stream.\n");
  AddExit("west","./pa5n6");
  AddExit("east","./pa3n6");
  AddExit("south","./pa4n7");
  AddExit("north","./pa4n5");
  AddItem(MONSTER("park/mdeer"),REFRESH_HOME);
}
