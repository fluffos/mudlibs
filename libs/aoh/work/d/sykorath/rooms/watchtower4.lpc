// part of the town
// made by magictcs - 19 jun 97

// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("The 4th story of the watchtower");
  SetIntLong(
    "This is the 4th story of the huge watchtower.\n"
    "A stony staircase leads up and down.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"story","4th story"}),
    "You are standing on the 4th story of this tower.\n");
  AddDetail(({"watchtower","huge watchtower"}),#'IntLong);
  AddDetail(({"tower","hugest tower"}),
    "This is the hugest tower of this city. You will have a great view over\n"
    "the city if you are standing on the platform of this tower.\n");
  AddDetail("platform","You cannot see it from here - you have to go up!\n");
  AddDetail(({"staircase","stony staircase"}),
    "The staircase is carved into the stone of this tower. It leads up to\n"
    "and down.\n");

  /* exits */
  AddExit("up","./watchtower5");
  AddExit("down","./watchtower3");
}

