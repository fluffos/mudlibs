// part of the town
// made by magictcs - 26 may 97
// TODO: update coords

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <moving.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  Set(P_INT_SHORT,"North tower of the townwall");
  Set(P_INT_LONG,
    "You are in the north tower of the townwall. The north and the south\n"
    "towers of the inner wall are standing on the left and right side of the\n"
    "inner town gate.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"tower","north tower","tower north"}),#'IntLong);
  AddDetail("two towers",
    "You are in one of the both towers.\n");
  AddDetail(({"townwall","high townwall"}),
    "This tower is part of the high townwall.\n");
  AddDetail(({"gate","towngate","inner gate","inner towngate"}),
    "You can reach the gate by going south!\n");

  SetIndoors(1);                         // tower is inside!

  /* exits */
  AddExit("south","./maingate");
  AddExit("northeast","./townwallnw1");
  AddExit("up","./towernu");
}
