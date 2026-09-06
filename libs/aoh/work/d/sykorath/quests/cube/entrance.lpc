// the entrance for the maze
// made by Magictcs - 2 may 97
// TODO: add exits to other areas
// TODO: make the room more friendly

#include "cube.h"

inherit CUBE("cuberoom");

create() {
  ::create();
  Set(P_VMASTER,CUBE("vmaster"));
  SetIntShort("An entrance to a cube maze");
  SetIntLong(
    "You are standing at the entrance of a maze located in a huge cube.\n");
  AddExit("north",CUBE("cuberoom211"));
  AddExit("west",SYKORATH("oakstreets3"));
  SetIndoors(0);
}

