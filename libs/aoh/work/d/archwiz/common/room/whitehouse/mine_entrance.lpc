inherit "/std/room";

#include <rooms.h>
#include "path.h"

create() {
  ::create();
  SetIntLong(
"You are standing at the entrance of what might have been a coal "
"mine. The shaft enters the west wall, and there is another exit on "
"the south end of the room.\n");
  SetIntShort("Mine Entrance");
  SetIndoors(1);
  AddDetail(({"entrance","room"}),#'IntLong);
  AddDetail(({"mine","coal mine"}),
    "Looks as if you've found the entrance.\n");
  AddDetail("shaft","It leads into the western wall.\n");
  AddDetail(({"west wall","western wall"}),"The shaft leads into it.\n");
  AddDetail(({"wall","walls","ceiling"}),"Boring.\n");
  AddDetail(({"south end","end"}),"There's an exit.\n");
  AddDetail(({"exit"}),"You may leave there.\n");
  AddExit("south","./slide_room");
  AddExit("west","./squeaky_room");
  AddItem(MONSTER("minework"),REFRESH_HOME);
}
