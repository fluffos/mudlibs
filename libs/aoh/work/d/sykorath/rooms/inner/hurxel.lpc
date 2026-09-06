/*
 * house of hurxel
 * part of the eatcorpse quest
 * made by magictcs - 8 jun 97
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <moving.h>
#include <npc.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("The house of Hurxel");
  SetIntLong(
    "You are standing in the house (and home) of Hurxel.\n"
    );

  SetIndoors(1);
  SetCoordinates( ({ ({660,640,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"plaza","mainplaza"}),
    P_ADS:  ({"main"}),
    P_LONG: "The way west leads back to it.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"house","home"}),
    P_LONG: "Yes, it is the house and home of Hurxel. If she is here, "
            "you can talk to her.\n" ]) );

  /* items */
  AddItem(NPC("hurxel"),REFRESH_HOME);

  /* exits */
  AddDoor("west","./to_hurxel",
    ([ P_SHORT:    "a door",
       P_LONG:     "A small wooden door, a word is written on it.\n",
       P_DOORCODE: "hurxelhousedoor",
       P_ADS:      ({"wooden"}),
       P_SUB_DETAILS: (["word": "You can read it.\n",
                        "words": "Only one word is standing there.\n"]),
       P_SUB_READMSGS: (["word": "You read: 'OUT'.\n",
                         "words": "There is only one word to read.\n"])
    ]) );

  Set(P_INT_WIZMSG,
    "%^RED%^add more details, (extend the house?), "
    "make it friendlier!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

