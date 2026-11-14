inherit "/std/room";

#include "path.h"

void create() {
  ::create();
  SetIntShort("West corridor of the first floor");
  SetIntLong(
"You are in the long west corridor of the first floor. To the north is "
"the LPC Office, to south you see an empty room. "
"The corridors leads further west into the hall of Adventurers.\n");
  AddExit("west","./adv_hall");
  AddExit("north",COMMON("lpc/office"));
  AddExit("east",TOWER("center"));
  AddExit("south",COMMON("bldg/office"));
}

