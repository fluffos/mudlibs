#include "path.h"
#include <doors.h>
inherit "std/room";

create() {
  ::create();
  SetIntShort("Sunset Boulevard");
  SetIntLong(
"This is Sunset Boulevard. It crosses a stream over a bridge with "
"marble statues on both ends. The street continues north and there seems "
"to be an intersection to the south. To the east rises majestically the "
"Administration Tower of Nightfall. The astonishing thing is that the "
"tower emits a golden light. It looks like pure magic. A path leads around "
"the tower which starts to the southeast. To the west is the local "
"Police Station.\n");
  AddDetail(({"boulevard","sunset boulevard","road","wide road"}),
QueryIntLong());
  AddDetail(({"tridents","trident"}),
"The tridents here are of no use for you.\n");
  AddDetail(({"police station","police","station"}),
"It is to the west of you.\n");
  AddDetail(({"nightfall","mud","world"}),
"This world is called Nightfall.\n");
  AddDetail(({"nightfall city","city","capital","town"}),
"It is the capital of the world.\n");
  AddDetail(({"intersection","south"}),
"Look at it further south.\n");
  AddDetail(({"light"," golden light","magic","magical light"}),
"You feel magic from the tower. It is that strong that even an unexperienced "
"adventurer can feel it.\n");
  AddDetail(({"path","small path","rocky path","small rocky path"}),
"A small rocky path leads around the tower.\n");
  AddDetail(({"marble","valuable marble","white marble"}),
"It is valuable white marble.\n");
  AddDetail(({"stream","river"}),
"It flows from west to east.\n");
  AddDetail(({"stone","massive stone","sandstone"}),
"It is sandstone.\n");
  AddDetail(({"stone bridge","massive bridge","massive stone bridge","bridge"}),
"It is a massive stone bridge. There are statues on both ends.\n");
  AddDetail(({"statues","statue","gods","god","water gods","water god"}),
"They seem to resemble water gods, since the statues are holding tridents.\n");
  AddDetail(({"administration tower","tower"}),
"The tower is the residence of the Nightfall Administration. All Archmages "
"and Lords have their offices in this building. The golden surface brightly "
"reflects the sunlight. You may enter the tower to the east.\n");
  AddExit("north","./boul1");
  AddExit("south","./boul3");
  AddExit("southeast",TOWER("first/arounde1"));
  AddExit("east",TOWER("first/adv_hall"));
  AddDoor("west","./policehq","small door",
  "This small door leads into the police station.\n", 0, DOOR_STATUS_CLOSED);
  SetIndoors(0);
}
