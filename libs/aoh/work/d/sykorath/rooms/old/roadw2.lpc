// part of the town
// made by magictcs - 3 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("The east-west road");
  SetIntLong(
    "You are on the east-west road. To the north stands a very huge tower.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"road","east west road","east-west road"}),#'IntLong);
  AddDetail(({"tower","huge tower","very huge tower"}),
    "The tower looks like a huge watchtower. You can enter it by using\n"
    "the exit to the north.\n");
  AddDetail("north","To the north is a huge watchtower blocking the view.\n");

  /* exits */
  AddExit("north","./watchtower1");
  AddExit("west","./roadw1");
  AddExit("east","./roadw3");
}

