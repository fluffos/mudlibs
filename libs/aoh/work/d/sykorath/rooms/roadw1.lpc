// part of the town
// made by magictcs - 3 jul 97
// TODO: add details, special commands, items
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("The east-west road");
  SetIntLong(
    "You are on the east-west road. Another way leads to the north.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"road","east west road","east-west road"}),#'IntLong);
  AddDetail(({"way","another way","north"}),
    "One way leads to the north to a huge house.\n");
  AddDetail(({"house","huge house"}),"You can visit it.\n");

  /* exits */
  AddExit("west","./westgate");
  AddExit("east","./roadw2");
  AddExit("north","./beforehugehouse");
  AddExit("southeast","./oakstreets1");
}

