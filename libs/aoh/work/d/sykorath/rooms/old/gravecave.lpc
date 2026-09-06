// part of the graveyard
// made by magictcs - 13 jul 97

// TODO: add a special inscription here or so
// maybe other stuff,......
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("In a small cave");
  SetIntLong(
    "You entered a small cave below the earth.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,-3}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"cave","small cave"}),#'IntLong);

  /* exits */
  AddExit("up","./graveyard4");
}

