inherit "std/room";

#include "path.h"

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a maze of twisty little passages, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"maze","twisty little passage","twisty little passages",
    "twisty passage","twisty passages","little passage",
    "little passages","passage","passages"}),#'IntLong);
  AddExit("north","./maze1");
  AddExit("south","./maze3");
  AddExit("west","./maze2");
  AddExit("east","./cellar");
}
