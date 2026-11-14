#include "path.h"

// the old file points to /d/avalon/common/std/road.c,
// which doesn't exist here.. 
// Sonic, 18-May-1997
inherit "/std/room";

create() {
  ::create();
  SetIntShort("South Avenue");
  SetIntLong(
"You are at the western end of South Avenue, a quiet suburban lane. "
"The well-kept road continues to the east but gets badly tended as it "
"leaves the city turning north. Far in the distance to the west is a forest "
"and to the east you can see a big stream that flows through Nightfall City, "
"the capital of this world.\n");
  AddExit("east", "./southave2");
  AddExit("north","./southroad1");
  SetIndoors(0);
}

