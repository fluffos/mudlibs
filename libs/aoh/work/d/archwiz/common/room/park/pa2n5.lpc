#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Baby Bunny Rabbits");
  SetIntLong(
"This is the perfect area for the frolic of baby bunny rabbits "
"and other baby animals.\n");
  SetIndoors(0);
  AddDetail(({"animals","animal","baby rabbits","baby bunny rabbits",
    "baby rabbit","baby bunny rabbit","bunny rabbits","bunny rabbit",
    "baby animals","baby animal"}),
"They love to play around.\n");
  AddExit("west","./pa3n5");
  AddExit("east","./pa1n5");
  AddExit("south","./pa2n6");
  AddExit("north","./pa2n4");
  AddItem(MONSTER("park/rabbit"),REFRESH_HOME,3);
}
