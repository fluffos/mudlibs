#include "path.h"

inherit "std/room";

create() {
  ::create();
  SetIntShort("the mole part 2");
  SetIntLong(
"This is the mole of the Nightfall City harbour. It leads further west and east. "
"To the city you have to go west.\n"
"To the north is the quay #3 and to the south the quay #4.\n");
  SetIndoors(0);
  SetIntNoise("You hear the noise of the rolling sea.");
  AddDetail(({"nightfall city harbour","harbour","city harbour"}),
    "You may board ships to all parts of the known world here.\n");
  AddDetail(({"quais","quay"}),
    "There's a quay to the north and one to the south.\n");
  AddDetail(({"mole","part 2","mole part 2"}),#'IntLong);
  AddDetail("quay 3","It's north.\n");
  AddDetail("quay 4","It's south.\n");
  AddExit("west", "./nf_mole1");
  AddExit("east", "./nf_mole3");
  AddExit("north", "./quai3");
  AddExit("south", "./quai4");
}
