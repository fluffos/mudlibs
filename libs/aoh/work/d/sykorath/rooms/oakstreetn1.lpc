// part of the town
// made by magictcs - 10 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <nightday.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("On the oakstreet");
  SetIntLong(
    "You are walking on the oakstreet. The street is named after the oak to\n"
    "southwest. East is the inner townwall and west a huge watchtower.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"street","oakstreet","oak street"}),#'IntLong);
  AddDetail(({"oak","oak tree","huge oak","huge tree"}),
    "You see a huge oak standing southwest. You can visit this place.\n");
  AddDetail("place","Which place? The one to the south? Just go there!\n");
  AddDetail(({"townwall","inner townwall"}),
    "A huge townwall is to the east. It is the last defence wall for the\n"
    "inner city. It will protect the inhabitans there.\n");
  AddDetail("east","There is the townwall.\n");
  AddDetail("inner city",
  "You can't see much from here. The townwall blocks the view to the east.\n");
  AddDetail(({"watchtower","huge watchtower"}),
    "You can visit the watchtower. From the top of the watchtower must be a\n"
    "great view over the whole city.\n");
  AddDetail("west","A huge watchtower stands there.\n");

  /* exits */
  AddExit("southwest","./roadw3");
  AddExit("north","./oakstreetn2");
}

