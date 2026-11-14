#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Dark and Evil Forest");
  SetIntLong(
"Howling sounds throughout the area.  The hair on the back of "
"your neck starts to rise.  You are tempted to run out of this "
"room.\n");
  SetIndoors(0);
  SetIntNoise("Howling fills the air.\n");
  AddNoise("howling","Sounds like some wolf.\n");
  AddDetail(({"forest","dark forest","evil forest","dark and evil forest",
    "trees","tree"}),
"This part of the forest has an evil aura.\n");
  AddDetail(({"aura","evil aura"}),
"You feel uncomfortable.\n");
  AddExit("west","./pa5n2");
  AddExit("east","./pa3n2");
  AddExit("south","./pa4n3");
  AddExit("north","./pa4n1");
  AddItem(MONSTER("park/blwolf"),REFRESH_HOME,2);
}
