#include "path.h"
inherit "std/room";

void create() {
  ::create();
  SetIntShort("Crossing of main street and east road");
  SetIntLong(
"You are on a road going out of the village. East road runs north from here, "
"along the eastern perimeter of the city. To the south are some fields planted "
"with all the crops the city needs. The main street runs east towards the sea "
"and west into the city.\n");
  AddExit("north","./eastroad1");
  AddExit("east", "./jetty");
  AddExit("west", "./vill_road2");
  AddExit("south","./crop");
  SetIndoors(0);
}


