/*
 * part of the town
 * made by magictcs - 22 may 97
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>
#include <skills.h>

inherit SY_STREET;

create() {
  ::create();
  SetIntShort("A dirty road");
  SetIntLong(
    "The dirty road leads further to the southeast. To the east is a "
    "small house. \n");

  SetIndoors(0);
  SetCoordinates( ({ ({640,640,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"road"}),
    P_ADS:  ({"dirty"}),
    P_LONG: #'IntLong ]) );
  AddDetail("east",
    "A small house is standing there. You can enter it through the small\n"
    "wooden door.\n");
  AddDetail("southeast","The townwall can be seen there.\n");
  AddDetail("townwall","You cannot see much of it from here.\n");
  AddVItem( ([
    P_IDS:  ({"house"}),
    P_ADS:  ({"small"}),
    P_LONG: "The house must be the one of Hurxel. You can enter it.\n" ]) );

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

  AddSkill(SK_SEARCH,"dirt",75,({"dirty road","road"}));

  /* exits */
  AddExit("northwest","./mainplazase");
  AddExit("southeast","./doorroom");

  Set(P_INT_WIZMSG,
    "%^RED%^add details, add clean command, add 'search dirt' command, "
    "make it friendlier!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

