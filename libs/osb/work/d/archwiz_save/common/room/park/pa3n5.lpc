#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Playground of the Baby Foxes");
  SetIntLong(
"It is so peaceful here.  Birds are singing and playing in the "
"sky. This is where all the baby animals are hidden by their "
"mother while they are hunting for food.\n");
  SetIndoors(0);
  AddDetail("playground",#'IntLong);
  AddDetail(({"baby fox","baby foxes","fox","foxes",
    "baby animals","baby animal","babies","baby"}),
"They love to play around.\n");
  AddDetail(({"birds","bird"}),
"The birds are singing and playing in the sky.\n");
  AddNoise("singing","It fills the air.\n");
  SetIntNoise("You hear the birds singing.\n");
  AddExit("west","./pa4n5");
  AddExit("east","./pa2n5");
  AddExit("south","./pa3n6");
  AddExit("north","./pa3n4");
  AddItem(MONSTER("park/babyfox"),REFRESH_HOME,3);
}
