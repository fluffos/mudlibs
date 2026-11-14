#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("the mole part 3");
  SetIntLong(
"This is the mole of the Nightfall City harbour. It leads further west.\n"
"To the north is the quay #5 and to the south you can see quay #6.\n");
  SetIndoors(0);
  SetIntNoise("You hear the splashing of the waves rolling against the mole.");
  AddDetail(({"mole","mole part 3","part 3"}),#'IntLong);
  AddDetail(({"nightfall city harbour","city harbour","harbour"}),
    "You may board ship to all parts of the world in this harbour.\n");
  AddDetail(({"quay","quais"}),
    "There is a quay to the north and one to the south.\n");
  AddDetail("quay 6","It's to the south.\n");
  AddDetail("quay 5","It's to the north.\n");
  AddExit("north","./quai5");
  AddExit("west","./nf_mole2");
  AddExit("south","./quai6");
}
