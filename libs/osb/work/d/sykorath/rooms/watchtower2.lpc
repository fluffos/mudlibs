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
  SetIntShort("The second story of the watchtower");
  SetIntLong(
    "This is the second story of the huge watchtower.\n"
    "A stony staircase leads up and down.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"watchtower","huge watchtower"}),#'IntLong);
  AddDetail(({"tower","hugest tower"}),
    "This is the hugest tower of this city. You will have a great view over\n"
    "the city if you are standing on the platform of this tower.\n");
  AddDetail("platform","You cannot see it from here - you have to go up!\n");
  AddDetail(({"staircase","stony staircase"}),
    "The staircase is carved into the stone of this tower. It leads up and\n"
    "down.\n");
  AddDetail(({"stone","white spotted stone"}),
    "It is some sort of granite.\n");
  AddDetail("granite","Yes granite - you know the white spotted stone?!\n");
  AddDetail(({"second story","story"}),
    "You are standing on the second story of this watchtower.\n");
  AddDetail("up",
    "The staircase leads up to another story.\n");
  AddDetail("down",
    "The staircase leads down to the entrance.\n");
  AddDetail("entrance","You can go there by going down.\n");
  AddDetail(({"another story","upper story"}),"You can go up to it.\n");

  /* exits */
  AddExit("up","./watchtower3");
  AddExit("down","./watchtower1");
}

