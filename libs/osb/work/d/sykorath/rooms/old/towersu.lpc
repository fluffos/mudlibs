// part of the town
// made by magictcs - 17 jun 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("Inside the south tower");
  SetIntLong(
    "Inside the south tower.\n");
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
  AddExit("down","./towers");
}

