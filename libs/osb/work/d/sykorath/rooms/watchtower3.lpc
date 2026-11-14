// part of the town
// made by magictcs - 19 jun 97
// TODO: add a 'schiessscharte'
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("The third story of the watchtower");
  SetIntLong(
    "This is the third story of the huge watchtower.\n"
    "One wall contains an embrasure. A stony staircase leads up and down.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"watchtower","huge watchtower"}),#'IntLong);
  AddDetail(({"tower","hugest tower"}),
    "This is the hugest tower of this city. You will have a great view over\n"
    "the city if you are standing on the platform of this tower.\n");
  AddDetail(({"stone","white spotted stone"}),
    "It is some sort of granite.\n");
  AddDetail("granite","Yes granite - you know the white spotted stone?!\n");
  AddDetail("platform","You cannot see it from here - you have to go up!\n");
  AddDetail(({"staircase","stony staircase"}),
    "The staircase is carved into the stone of this tower. It leads up to\n"
    "an upper story and down to a lower ones.\n");
  AddDetail(({"third story","story"}),
    "This is the third story. You are standing on it.\n");
  AddDetail(({"wall","one wall"}),
    "The wall contains an embrasure.\n");
  AddDetail("walls",
    "The walls look equal, but one wall has an embrasure in it.\n");
  AddDetail("embrasure",
    "You can't see anything through it, because the view is blocked by\n"
    "another wall from another house.\n");
  AddDetail("another wall","It is a wall from another house.\n");
  AddDetail(({"another house","house"}),
    "The walls of this house block the view through the embrasure.\n");

  /* exits */
  AddExit("up","./watchtower4");
  AddExit("down","./watchtower2");
}

