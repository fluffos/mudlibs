#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Poacher's Hideout");
  SetIntLong(
"You discovered the hut of the poacher!  Everywhere you "
"look, you see a lot of animal furs.\n");
  SetIndoors(0);
  AddDetail(({"hut","poacher's hut"}),
"Actually you stumbled in it when you did not think about it.\n"
"It has to be well hidden.\n");
  AddDetail(({"fur","animal fur","animal furs","furs"}),
"They don't look too valuable.\n");
  AddExit("east","./pa4n2");
  AddExit("south","./pa5n3");
  AddExit("north","./pa5n1");
  AddItem(MONSTER("park/poacher"),REFRESH_HOME,2);
}
