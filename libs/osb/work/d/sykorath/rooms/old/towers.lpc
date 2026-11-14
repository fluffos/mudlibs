// part of the town
// made by magictcs - 28 may 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("South tower of the townwall");
  SetIntLong(
    "You are in the south tower of the townwall. The north and the south\n"
    "towers of the inner wall are standing on the left and right side of the\n"
    "inner town gate.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"tower","south tower","tower south"}),#'IntLong);
  AddDetail("two towers",
    "You are in one of the both towers.\n");
  AddDetail(({"townwall","high townwall"}),
    "This tower is part of the high townwall.\n");
  AddDetail(({"gate","towngate","inner gate","inner towngate"}),
    "The gate is further to the north!\n");

  /* exits */
  AddExit("north","./maingate");
  AddExit("southeast","./townwalls1");
  AddExit("up","./towersu");
}
