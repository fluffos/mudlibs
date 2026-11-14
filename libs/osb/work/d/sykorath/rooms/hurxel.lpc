// part of the town
// made by magictcs - 8 jun 97
// hurxel - questnpc for the 'eatcorpse' quest

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("The house of Hurxel");
  SetIntLong(
    "You are standing in the house (and home) of Hurxel.\n"
    "Add more details.......\n");

  /* details */
  AddDetail(({"main plaza"}),
    "The way west leads back to it.\n");

  /* items */
  AddItem(NPC("hurxel"),REFRESH_HOME);

  /* exits */
  AddDoor("west","./mainroadse2",
    ([ P_SHORT:    "a door",
       P_LONG:     "A small wooden door, a word is written on it.\n",
       P_DOORCODE: "hurxelhousedoor",
       P_ADS:      ({"wooden"}),
       P_SUB_DETAILS: (["word": "You can read it.\n",
                        "words": "Only one word is standing there.\n"]),
       P_SUB_READMSGS: (["word": "You read: 'OUT'.\n",
                         "words": "There is only one word to read.\n"])
    ]) );
}

