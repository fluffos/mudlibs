#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Area Of Male Deer");
  SetIntLong(
"This is where all the male deers hang out. It's a very peaceful place.\n"
            );
  SetIndoors(0);
  AddDetail("area",#'IntLong);
  AddExit("west","./pa5n7");
  AddExit("east","./pa3n7");
  AddExit("north","./pa4n6");
  AddItem(MONSTER("park/madeer"),REFRESH_HOME,1);
}
