// part of the town
// made by magictcs - 19 jun 97
// TODO: add exit of tower
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("The entrance of the watchtower");
  SetIntLong(
    "You are standing in the entrance of the huge watchtower. It is the\n"
    "hugest tower of this city.\n"
    "A stony staircase leads up.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail("city","The tower stands in this city.\n");
  AddDetail(({"watchtower","huge watchtower","entrance",}),#'IntLong);
  AddDetail(({"tower","hugest tower"}),
    "This is the hugest tower of this city. You will have a great view over\n"
    "the city if you are standing on the platform of this tower.\n");
  AddDetail("platform","You cannot see it from here - you have to go up!\n");
  AddDetail(({"stone","white spotted stone"}),
    "It is some sort of granite.\n");
  AddDetail("granite","Yes granite - you know the white spotted stone?!\n");
  AddDetail(({"staircase","stony staircase"}),
    "The staircase is carved into the stone of this tower. It leads up to\n"
    "an upper story.\n");
  AddDetail("up","The staircase leads up.\n");

  /* exits */
  AddExit("up","./watchtower2");
  AddExit("south","./roadw2");
}

