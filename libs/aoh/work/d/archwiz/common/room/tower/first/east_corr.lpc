#include "path.h"

inherit "/std/room";

void create() {
  ::create();
  SetIntShort("East corridor of the first floor");
  SetIntLong(
"You are in the long east corridor of the first floor. To the south is the "
"Office of Finance. North you can enter the Office of Magic. "
"The Learners Quarters are to the east.\n");
  AddExit("west",TOWER("center"));
  AddExit("north","/p/magic/example/rooms/office/office");
  AddExit("south",COMMON("finance/office"));
  AddExit("east",TOWER("learner/main"));
}

