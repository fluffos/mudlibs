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
  SetIntShort("The 5th story of the watchtower");
  SetIntLong(
    "This is the 5th story of the huge watchtower.\n"
    "One wall contains an embrasure. A stony staircase leads up and down.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"story","5th story"}),
    "You are standing on the 5th story of this tower.\n");
  AddDetail(({"watchtower","huge watchtower"}),#'IntLong);
  AddDetail(({"tower","hugest tower"}),
    "This is the hugest tower of this city. You will have a great view over\n"
    "the city if you are standing on the platform of this tower.\n");
  AddDetail("platform","You cannot see it from here - you have to go up!\n");
  AddDetail(({"staircase","stony staircase"}),
    "The staircase is carved into the stone of this tower. It leads up to\n"
    "an upper story and down to a lower ones.\n");
  AddDetail(({"wall","one wall"}),
    "The wall contains an embrasure.\n");
  AddDetail("walls",
    "The walls look equal, but one wall has an embrasure in it.\n");
  AddDetail("embrasure",
    "You cannot see much of the surrounding, because it is y very small\n"
    "embrasure. But you have a look over a huge house in front of you.\n"
    "Behind the house is something like a forest.\n");
  AddDetail("forest",
    "You see no way into or out of the forest.\n");

  /* exits */
  AddExit("up","./watchtower6");
  AddExit("down","./watchtower4");
}

