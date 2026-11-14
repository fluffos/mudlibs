#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("A Clearing with Full Moon");
  SetIntLong(
"Full Moon in the sky...you can barely see your surrounding "
"area. But you sense something is out there!\n");
  SetIndoors(1);
  AddDetail("sky","It's full moon.\n");
  AddDetail("sun","It is not here.\n");
  AddDetail("clearing",#'IntLong);
  AddDetail(({"moon","full moon"}),
"It's full moon tonight!\n");
  AddExit("west","./pa5n1");
  AddExit("east","./pa3n1");
  AddExit("south","./pa4n2");
  AddItem(MONSTER("park/werewolf"),REFRESH_HOME);
}
