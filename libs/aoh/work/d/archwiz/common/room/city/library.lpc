#include <properties.h>
#include "path.h"
inherit "std/room";

go_west() {
  write("The huge gate is closed. The archive is not open yet.\n");
  return 1;
}

go_north() {
  write("The huge gate is closed. The reading room is not open yet.\n");
  return 1;
}

create() {
  ::create();
  SetIntShort("Library Entrance Hall");
  SetIntLong(
"You are standing in the vast entrance hall of what seems to have been "
"once a public library thriving with seekers for wisdom. An empty desk "
"stretches along the east wall.\n"
"There are large gates to the north and to the west. There is something "
"written above the gates. The exit to the city is to the south.\n"
  );
/*
  AddExit("north","./lib_reading");
  AddExit("west","./lib_archive");
*/
  AddExit("west",#'go_west);
  HideExit("west",1);
  AddExit("north",#'go_north);
  HideExit("north",1);
  AddExit("south","./sunalley3");
  AddDetail("desk",
"It was probably the reception desk a long time ago. The desk is stained "
"with ink.\n");
  AddDetail(({"gates","gate"}),"You should be more specific. Which gate do you mean?\n");
  AddDetail(({",northern gate","north gate"}),
"The inscription reads: --- Reading Room ---\n");
  AddDetail(({"west gate","western gate"}),
"The inscription reads: --- Archives ---\n");
}
