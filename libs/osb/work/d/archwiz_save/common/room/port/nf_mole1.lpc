#include "path.h"

inherit "std/room";

create() {
  ::create();
  SetIntShort("the mole part 1");
  SetIntLong(
"This is the mole of the Nightfall City harbour. It leads further east. "
"To the city you have to go west.\n"
"To the north is the quay #1 and to the south the quay #2.\n");
  SetIndoors(0);
  SetIntNoise("You hear waves rolling against the mole.");
  AddDetail(({"mole part 1","mole","part 1"}),#'IntLong);
  AddDetail(({"nightfall city harbour","city harbour","harbour"}),
    "You may board ships to all parts of the known world at this harbour.\n");
  AddDetail(({"quay","quais"}),"There is a quay to either north and south.\n");
  AddDetail("quay 1","It's north.\n");
  AddDetail("quay 2","It's south.\n");
  AddExit("west", "./nf_port");
  AddExit("east", "./nf_mole2");
  AddExit("north", "./quai1");
  AddExit("south", "./quai2");
}
