// part of the town
// made by magictcs - 10 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <nightday.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("A small crossing");
  SetIntLong(
    "You are on a small crossing on the oakstreet.\n"
    "One way comes from northwest and leads east, another from south and\n"
    "leads north into a yellow building.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"street","oakstreet","oak street"}),#'IntLong);
  AddDetail(({"crossing","small crossing"}),
    "You see a crossing of two ways.\n");
  AddDetail("way",
    "Which way do you want to look at? The first or the second ones?\n");
  AddDetail(({"first way","way 1","one way"}),
    "This way come from the northwest and leads to the east.\n");
  AddDetail(({"second way","way 2","another way"}),
    "This way comes from south and leads into the yellow building - must be\n"
    "the post.\n");
  AddDetail("north","You see a yellow building there. Looks like a post.\n");
  AddDetail(({"building","yellow building"}),
    "It looks like a post.\n");
  AddDetail("east","You see the townwall there.\n");
  AddDetail("northwest",
    "You can't see any detail there. It is too dark in this direction.\n");
  AddDetail("south",
    "The way south leads back to the main gate of the inner city.\n");
  AddDetail(({"townwall","huge townwall"}),
    "This huge townwall protects the inner city.\n");
  AddDetail("inner city","The inner city lies behind the townwall!\n");
  AddDetail("city","Do you want to look at the inner or the outer city?\n");
  AddDetail("outer city","This is where you are.\n");
  AddDetail("post",
    "The post is the place where you can send mails to other people.\n");

  /* exits */
  AddExit("south","./oakstreetn1");
  AddExit("north","./post");
  AddExit("east","./poststreete1");
  AddExit("northwest","./poststreetw1");
}

