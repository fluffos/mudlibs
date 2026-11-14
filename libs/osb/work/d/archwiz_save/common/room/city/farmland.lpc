#include "path.h"
inherit "std/room";

create() {
  ::create();
  SetIntShort("Farmland");
  SetIntLong(
"The country gets rural here. There are some ruins here. Probably it was "
"a farm. Fields are to the east, and taller structures can be seen to the "
"west, where South Avenue runs.\n");
  AddExit("west", "./southave4");
  AddExit("east", "./fields");
  SetIndoors(0);
}
