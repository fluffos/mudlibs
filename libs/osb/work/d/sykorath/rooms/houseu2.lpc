// part of the town
// made by magictcs - 3 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

//***********
// climb down
//***********
int climbdown(string str) {
  write("You climb the ladder down.\n");
  TP->move(SYKORATH("houseu1"),M_GO,"down");
  return ME_OK;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("The top of the house");
  SetIntLong(
    "You are standing on top of a huge house.\n"
    "A hole is in the ground.\n"
    "To the south is a huge watchtower.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"house","huge house"}),#'IntLong);
  AddDetail(({"top","topof house","top of huge house"}),
    ".\n");
  AddDetail("down",
    "A ladder stands in the room in the story below. You can go down.\n");
  AddDetail("ceiling","You see the sky above you!\n");
  AddDetail("ground","A hole leads down.\n");
  AddDetail("ladder","It stands in the story below you.\n");
  AddDetail("hole","You can use the hole for going down.\n");
  AddDetail(({"huge watchtower","watchtower"}),
    "The watchtower is some stories higher than this house.\n");
  AddDetail("south",
    "The view to the south is blocked by a huge watchtower.\n");

  /* exits */
  AddExit("down",#'climbdown);
}

