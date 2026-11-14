// made by magictcs - 2 jul 97
// TODO: add more details,exits
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("On a graveyard.\n");
  SetIntLong(
    "You are standing on an old graveyard. It is the entrance of it. The\n"
    "exit is to the west. The graveyard is surrounded by a small wall.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"old graveyard","old yard","graveyard","yard"}),#'IntLong);
  AddDetail(({"small wall","wall","rotten wall","small rotten wall"}),
    "The wall is nearly rotten, but still around one metres huge.\n");
  AddDetail("entrance","It is the place where you stand actually.\n");
  AddDetail("exit","You can leave the graveyard by going west.\n");
  AddDetail(({"grave","graves"}),
    "It is the entrance, no graves are here.\n");

  /* exits */
  AddExit("west","./nowhere???");
  AddExit("north","./graveyard2");
  AddExit("east","./graveyard3");
  AddExit("south","./graveyard4");
}

