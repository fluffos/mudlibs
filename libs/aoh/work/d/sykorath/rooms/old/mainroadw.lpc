// part of the town
// made by magictcs - 1 jun 97
// TODO: hmm details? description? something special?
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
  SetIntShort("A road");
  SetIntLong(
    "You are on a dirty road. To the west is the main gate of the inner\n"
    "city. East can be seen the main plaza.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"road","dirty road"}),#'IntLong);
  AddDetail(({"city","inner city"}),
    "You are standing in the inner city. It is surrounded by a huge\n"
    "townwall.\n");
  AddDetail(({"townwall","wall"}),
    "The townwall surrounds the inner city. To the west is the main gate\n"
    "of the townwall.\n");
  AddDetail("west","If you go west you will arrive at the main gate.\n");
  AddDetail(({"main gate","gate","maingate"}),
    "It is to the west.\n");
  AddDetail("east","To the east is the mainplaza.\n");
  AddDetail(({"main plaza"}),
    "The way east leads back to it.\n");

  /* exits */
  AddExit("east","./mainplazaw");
  AddExit("west","./maingate");
}

