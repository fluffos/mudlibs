#include "path.h"
inherit "/std/room";

create() {
  ::create();
  SetIntShort("Display room");
  SetIntLong(
/*
"This is the main display room of the museum. There are many objects of "
"the old underground railway at display. 
*/
"This is the main display room of the museum, but there is nothing more "
"than a few empty displays. Some workers are repairing holes in the metal "
"floor and walls. The exit is to the west.\n");
  SetIndoors(1);
  AddDetail(({"floor","ground"}),
"It is made from iron and has some holes, probably from rust.\n");
  AddDetail(({"wall","walls"}),
"The walls are made from iron and have some holes, probably from rust.\n");
  AddDetail("displays","The displays are all empty.\n");
  AddDetail("workers", "The workers ignore everything but their work.\n");
  AddDetail("holes", "Rust ate the holes into the metal walls.\n");
  AddExit("west","./entrance");
}
