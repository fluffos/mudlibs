// part of the town
// made by magictcs - 22 may 97
// TODO: add more details
// TODO: add clean command, add "search dirt" command
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("A dirty road");
  SetIntLong(
    "The dirty road leads further to the southeast. To the east is a small\n"
    "house. \n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"road","dirty road"}),#'IntLong);
  AddDetail("east",
    "A small house is standing there. You can enter it through the small\n"
    "wooden door.\n");
  AddDetail("southeast","The townwall can be seen there.\n");
  AddDetail("townwall","You cannot see much of it from here.\n");
  AddDetail(({"house","small house"}),
    "The house must be the one of Hurxel. You can enter it.\n");

  AddDoor("east","./hurxel",
    ([ P_SHORT:    "a door",
       P_LONG:     "A small wooden door, a word is written on it.\n",
       P_DOORCODE: "hurxelhousedoor",
       P_ADS:      ({"wooden"}),
       P_SUB_DETAILS: (["word": "You can read it.\n",
                        "words": "Only one word is standing there.\n"]),
       P_SUB_READMSGS: (["word": "You read: 'IN'.\n",
                         "words": "There is only one word to read.\n"])
    ]) );

  /* exits */
  AddExit("northwest","./mainplaza");
  AddExit("southeast","./mainroadse");
}

