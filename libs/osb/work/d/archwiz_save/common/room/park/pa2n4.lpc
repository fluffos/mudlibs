#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Path leading deeper into the Park");
  SetIntLong(
"You are deeper in the park. Weird sounds are floating in the air. "
"The path splits once again in four different directions.\n");
  SetIndoors(0);
  SetIntNoise("You hear weird sounds.\n");
  AddDetail(({"park","city park"}),
"It is the famous city park.\n");
  AddDetail(({"sounds","sound","weird sounds","weird sound"}),
"It is somehow floating in the air.\n");
  AddNoise(({"sounds","weird sounds","weird sound","sound"}),
"It sounds really weird.\n");
  AddDetail("path","It splits into four directions.\n");
  AddExit("west","./pa3n4");
  AddExit("east","./pa1n4");
  AddExit("south","./pa2n5");
  AddExit("north","./pa2n3");
}
