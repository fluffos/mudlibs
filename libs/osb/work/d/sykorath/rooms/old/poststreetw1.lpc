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
  SetIntShort("On the poststreet");
  SetIntLong(
    "You are walking on the poststreet. To the east you see a yellow\n"
    "building, but no entry can be seen from here.\n");
  SetIndoors(0);
  SetIntLight(-10);           // darker than normal
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"poststreet","street"}),#'IntLong);
  AddDetail(({"building","yellow building"}),
    "It is a yellow building like each post building.\n");
  AddDetail(({"post","post building"}),
    "It is the post of this town, where you can send your mails to other\n"
    "people. But there is no entry from here.\n");
  AddDetail(({"entry","no entry"}),
    "Can't you see one? There is NO entry here!\n");

  /* exits */
  AddExit("southeast","./oakstreetn2");
  AddExit("northwest","./fountain");
}

