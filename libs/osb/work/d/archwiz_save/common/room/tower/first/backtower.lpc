#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Behind a dark tower");
  SetIntLong(
"You're standing behind a shimmering tower. To the south a small cave is "
"built right into the base of the tower. Light shimmers out of "
"it. To the north is the center of the town.\n");
  AddDetail(({"tower","shimmering tower","administration tower"}),
"This is the administration tower of Nightfall.\n");
  AddDetail(({"mud","world","nightfall"}),
"This is the world we live in: Nightfall.\n");
  AddDetail(({"cave","small cave"}),
"You would enter it by just going south.\n");
  AddDetail(({"base","base of the tower","hill"}),
"The administration tower was built on a hill.\n");
  AddDetail(({"light","shimmering light"}),
"It comes out of the cave.\n");
  AddDetail(({"town","nightfall city","capital","city"}),
"It is the world's capital.\n");
  AddDetail(({"centre","center"}),
"It's busy there!\n");
  SetIndoors(0);
  AddExit("southeast","./arounde3");
  AddExit("south",PIRATE("inhut"));
  HideExit("south",1);
}
