// part of the town
// made by magictcs - 23 jul 97

// TODO: update coords
// TODO: add more details (and something special)
// TODO: check back wall - rear wall? (details too)

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

// remove if cube entry is opened!
int cubeentry() {
  write("The cube isn't finished yet.\n");
  return 0;
}

//***************
// detailhandling
//***************
string lookmarks() {
  if (!TP) return "";
  TP->SetExplored();
  return
  "Someone painted with red color some words onto the wall:\n"
  "   --> Kill the godfather <--\n"
  "As you take a close look you see that it is not red color,\n"
  "it is BLOOD.\n";
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("On the oakstreet");
  SetIntLong(
    "You are walking on the oakstreet. To the south you see the back wall\n"
    "(rear wall?) of a house. East is a huge cube.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"street","oakstreet","oak street"}),#'IntLong);
  AddDetail(({"oak","oak tree","huge oak","huge tree"}),
    "You can't see the oak from here. You are too far away.\n");
  AddDetail(({"wall","back wall","rear wall"}),
    "It is one of the outer walls of the house. You see some marks on the\n"
    "wall.\n");
  AddDetail(({"marks","mark","some marks","marks on wall","some marks on wall",
    "mark on wall"}),#'lookmarks);
  AddDetail("house","It is the candyshop. But there is no entry here.\n");
  AddDetail("entry","There is non here to the shop");
  AddDetail(({"shop","candyshop"}),
    "This is the place where you can buy sweet candy. What else do you\n"
    "expect?\n");

  /* exits */
  AddExit("west","./oakstreets2");
// TODO: open the exit, if the cube is finished
  AddExit("east",#'cubeentry);
//  AddExit("east",BASE+"cube/entrance");
}

