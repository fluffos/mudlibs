inherit "std/room";

#include <doors.h>
#include "path.h"

create() {
  ::create();
  SetIntShort("Grating Room");
  SetIntLong(
"You are in a small room with an iron ladder leading up. A twisty passage "
"leads west. There is a grating securely fastened into the ceiling. Light "
"is coming in from above. A skeleton, probably the remains of a luckless "
"adventurer, lies here.\n");
  SetIndoors(0);
  AddDetail("skeleton","It is quite rotten, and you find nothing useful.\n");
  AddDetail(({"room","small room"}),#'IntLong);
  AddDetail(({"ladder","iron ladder"}),"It leads up.\n");
  AddDetail("iron","Just iron.\n");
  AddDetail(({"passage","twisty passage"}),"It leads west.\n");
  AddDetail(({"grating","tough grating"}),"It looks tough.\n");
  AddDetail("ceiling","There's a grating in it.\n");
  AddDetail("light","It comes from outside these tunnels.\n");
  AddExit("west","./maze14");
  AddDoor("up",CITY("clearing1"),"grating",
    "A massive iron grating with a lock. ",
    "skeleton_grating",DOOR_STATUS_LOCKED);
}

