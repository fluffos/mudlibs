inherit "std/room";

#include <rooms.h>
#include "path.h"

create() {
  ::create();
  SetIntShort("Dead End");
  SetIntLong(
"You have come to a dead end in the maze. The only exit is back south.\n");
 SetIndoors(1);
 SetBright(-10);
 AddDetail(({"end","dead end"}),#'IntLong);
 AddDetail(({"maze"}),"You're currently lost in it.\n");
 AddDetail(({"exit"}),"It leads back south.\n");
 AddExit("south","./maze10");
 AddItem(ARMOUR("leatherarmour"),REFRESH_REMOVE);
}
