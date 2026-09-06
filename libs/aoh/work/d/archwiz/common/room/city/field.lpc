#include "path.h"

inherit "std/room";

create() {
  ::create();
  SetIntShort("Corn Fields");
  SetIntLong(
"You are in the middle of fields where wheat is grown. The road runs north "
"and south along the fields. To the south are some low and shabby "
"buildings. A path leads towards the coast to the east.\n");
  AddDetail(({"path","small path"}),"It leads towards the coast.\n");
  AddDetail("coast","It is far to the east.\n");
  AddDetail(({"field","fields"}),
"This is where the farmers work.\n");
  AddDetail(({"wheat"}),"It grows on the fields.\n");
  AddDetail(({"road"}),QueryIntLong());
  AddDetail(({"buildings","building","low buildong",
  "shabby building","low buildings","shabby buildings"}),
"The southern part of the city is not the best place to live.\n");
  AddDetail(({"city","nightfall city","capital"}),
"It is the world's capital.\n");
  AddExit("east",PIRATE("path1"));
  AddExit("north", "./fields");
  AddExit("south", "./row7");
  SetIndoors(0);
}

