#include <rooms.h>
#include "path.h"

inherit "std/room";

create() {
  ::create();
  SetIntShort("Grasshopper Area");
  SetIntLong(
"This meadow is full of grasshoppers.\n"
"Chirp...chirp...everywhere you listen..you hear chirping.\n");
  SetIntNoise("You hear the chirping of grasshoppers.\n");
  SetIndoors(0);
  AddDetail(({"meadow","green meadow"}),#'IntLong);
  AddDetail(({"grasshoppers","grasshopper"}),
"The grasshoppers chirp everywhere.\n");
  AddExit("west","./pa2n6");
  AddExit("south","./pa1n7");
  AddExit("north","./pa1n5");
  AddItem(MONSTER("park/grasshopper"),REFRESH_HOME,3);
}
