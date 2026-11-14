// part of the town
// made by magictcs - 16 jul 97

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
  SetIntShort("On the poststreet");
  SetIntLong(
    "You are walking on the poststreet. To the northwest you see a yellow\n"
    "building, but no entry can be seen from here.\n"
    "You see the inner townwall to the east.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"poststreet","street"}),#'IntLong);
  AddDetail(({"building","yellow building"}),
    "It is a yellow building like each post building.\n");
  AddDetail(({"post","post building"}),
    "It is the post of this town, where you can send your mails to other\n"
    "people. But there is no entry from here.\n");
  AddDetail("northwest","To the northwest is a yellow building.\n");
  AddDetail(({"entry","no entry"}),
    "Can't you see one? There is NO entry here!\n");
  AddDetail(({"townwall","inner townwall"}),
    "The town wall is firther to the east. It is a very huge wall,\n"
    "nearly unclimbable.\n");
  AddDetail(({"huge wall","very huge wall","huge townwall",
    "very huge townwall"}),
    "Yes it is very huge. This is the reason why you can see it from here.\n");

  /* exits */
  AddExit("west","./oakstreetn2");
  AddExit("northeast","./poststreetne1");
  AddExit("east","./poststreete2");
}

