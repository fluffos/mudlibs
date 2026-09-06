#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Squirrel Holding");
  SetIntLong(
"There are a bunch of holes in the tree. Everywhere on "
"on the ground, there are acorn!\n");
  SetIndoors(0);
  AddDetail(({"acorn","acorns"}),
"There are acorns all over the ground.\n");
  AddDetail(({"holding","squirrel holding"}),#'IntLong);
  AddDetail(({"holes","hole","bunch of holes"}),
"As you look a bit closer you see small sparkling eyes deep\n"
"inside the hole.\n");
  AddDetail(({"eyes","eye","sparkling eye","sparkling eyes"}),
"You think those eyes are the eyes of a small animal hiding in the\n"
"hole.\n");
  AddDetail(({"animal","small animal","squirrel","squirrels"}),
"They are vry shy.\n");
  AddExit("west","./pa3n6");
  AddExit("east","./pa1n6");
  AddExit("south","./pa2n7");
  AddExit("north","./pa2n5");
  AddItem(MONSTER("park/squirrel2"),REFRESH_HOME,3);
}
