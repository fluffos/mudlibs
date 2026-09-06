// part of the inner townwall
// made by Magictcs - 16 jun 97
// one way leads down to the prisoncells
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
  SetIntLong(
    "You are inside the townwall. A staircase leads down into the prison.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"townwall","inside townwall"}),#'IntLong);
  AddDetail(({"staircase","stony staircase"}),
    "It is a stony staircase and it leads down into a dark prison.\n");
  AddDetail(({"prison","dark prison"}),
    "The prison is down. You see no light emitting from downstairs.\n");

  /* exits */
  AddExit("south","./townwalle2");
  AddExit("northwest","./townwallne2");
  AddExit("down","./prison");
}

