// the shopkeeper for the voodoo shop
// made by magictcs - 29 may 1997
// part of the eatcorpse quest

#include <properties.h>
#include <npc.h>
#include <sykorath.h>

inherit "/std/npc";

create() {
  if (::create()) return;
  SetName("Hurxel");
  SetRace("gnome");
  SetShort("Hurxel");
  SetLong(
    "Hurxel is a very old gnome, older than centuries. She is too fragile\n"
    "to leave her house.\n");
  SetGoChance(0);
  SetLevel(23);
  SetGender(GENDER_FEMALE);

  /* questions */
  AddQuestion(({"josie"}),
    "Hurxel says: Oh you know her? She is my granddaughter. I like her very "
    "much.\n");

  /* items */
  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme, ({
    ([ P_STANDARD: ({WT_STAFF,2,PSIZE_GENERIC}) ]),
    ([ P_SHORT: "a wooden crutch",
       P_LONG:
       "This is a wooden crutch. Old people use it to go around.\n",
       P_IDS: ({"crutch",}),
       P_ADS: ({"wooden",}),
       P_WEIGHT: 1000,
       P_VALUE: 30, ]) }) );
}

