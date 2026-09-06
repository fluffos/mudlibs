inherit "std/room";

#include <rooms.h>
#include "path.h"

create() {
  ::create();
  SetIntShort("A crawlway");
  SetIntLong(
"You are in a north/south crawlway. There is a hole above you, but it "
"provides no opportunities for climbing.\n");
  SetIndoors(1);
  SetIntLight(-1);
  AddDetail("hole","You can't climb it.\n");
  AddDetail(({"way","crawlway","north/south crawlway"}),#'IntLong);
  AddExit("north","./cellar");
  AddExit("south","./gallery");
  AddItem(OBJ("fcdguide"),REFRESH_REMOVE);
}
