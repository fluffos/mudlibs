// part of the town
// made by magictcs - 23 jul 97

// TODO: add more details (and something special)
// TODO: update coords

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("On the oakstreet");
  SetIntLong(
    "You are walking on the oakstreet. The street is named after the oak to the "
    "northeast. To the north stands a huge watchtower.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"street","oakstreet","oak street"}),#'IntLong);
  AddDetail(({"oak","oak tree","huge oak","huge tree"}),
    "You see a huge oak standing northeast. You can visit this place.\n");
  AddDetail("place","Which place? The one to the northeast? Just go there!\n");
  AddDetail(({"watchtower","huge watchtower"}),
    "You can visit the watchtower. From the top of the watchtower must be a\n"
    "great view over the whole city.\n");
  AddDetail("north","A huge watchtower stands there.\n");

  /* exits */
  AddExit("south","./oakstreets2");
  AddExit("northeast","./roadw3");
  AddExit("northwest","./roadw1");
}
