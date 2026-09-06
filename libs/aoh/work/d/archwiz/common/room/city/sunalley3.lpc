#include "path.h"
inherit "std/room";

create() {
  ::create();
  SetIntShort("Sun Alley");
  SetIntLong(
"Sun alley dead-ends at this point. "
"The only way is back to the east, but there is "
"a house to the north which you could enter.\n");
  AddExit("north","./library");
  AddExit("east", "./sunalley2");
  SetIndoors(0);
}

