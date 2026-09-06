inherit "/std/room";
#include "path.h"

create() {
  ::create();
  SetIntShort("fireplace");
  SetIntLong(
"Oops! You didn't take the same way back and you find yourself at a fireplace "
"with a table and some comfortable garden chairs. It seems to be a nice place "
"to have your grill-parties on a summer evening.\n"
"To the east you think you see the place where you came into the garden, to  "
"the west are the bushes and trees.\n");
 AddDetail(({"chairs","chair"}),"The chairs doesn't look very special.\n");
 AddDetail(({"table"}),"The table is covered with dust.\n");
 AddDetail("dust","It is everywhere.\n");
 AddDetail(({"bush","bushes","tree","trees","plant","plants"}),
 "The plants are part of nature.\n");
 AddDetail("nature","It is all around you when you look into the garden.\n");
 AddDetail("fireplace","Only ashes is left.\n");
 AddDetail(({"ash","ashes"}),"It's black and white.\n");
 AddExit("east","./entrance");
 AddExit("west","./westroom");
 }
