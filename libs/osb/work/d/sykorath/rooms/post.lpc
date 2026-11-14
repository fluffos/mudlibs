// part of the town
// made by magictcs - 18 jun 97
// TODO: add exits,more details
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("The post");
  SetIntLong(
    "You are standing in the post office. Usually a mailbox can be found "
    "here. An exit leads south back to the oakstreet.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"post","post office"}),#'IntLong);
  AddDetail(({"oakstreet","street","oak street","main street"}),
    "The oakstreet is one of the main streets of the outer city.\n");
  AddDetail("outer city","This post belongs to it.\n");

  AddItem("/mail/dpost", REFRESH_NONE);

  /* exits */
  AddExit("south","./oakstreetn2");
}

