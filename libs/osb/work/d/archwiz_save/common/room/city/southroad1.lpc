#include "path.h"
inherit "std/room";

create() {
  ::create();
  SetIntShort("South Road");
  SetIntLong(
"You are on South Road, a quiet suburban lane running west from here. "
"The road looks well-kept to the south but gets badly tended as it "
"leaves the city to the west. Far in the distance is a forest. "
"You hear a strange noise coming from the east.\n");
  SetIntNoise("You hear the roaring of a big stream to the east.\n");
  AddExit("west", "./southroad2");
  AddExit("south","./southave1");
  SetIndoors(0);
}

