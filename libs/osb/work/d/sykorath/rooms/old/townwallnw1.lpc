// made by Magictcs - 16 jun 97
// TODO: implement it :)
// TODO: update coords

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("Inside the townwall");
  SetIntLong("You are inside the townwall.");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"townwall","inside townwall"}),#'IntLong);

  /* exits */
  AddExit("northeast","./townwallnw2");
  AddExit("southwest","./towern");
}
