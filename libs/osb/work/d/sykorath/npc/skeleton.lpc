// the skeleton warrior for the graveyard
// made by magictcs - 9 jul 1997
// nothing special yet

#include <properties.h>
#include <sykorath.h>

inherit "/std/npc";

create() {
  if (::create()) return;
  SetName("warrior");
  SetRace("notreal");
  SetShort("skeleton warrior");
  SetLong(
    "A dangerous skeleton warrior. Better run away if you see him!\n");
  AddId(({"warrior"}));
  SetAds(({"skeleton"}));
  SetLevel(7);
  SetAggressive(1);
  SetGender(GENDER_MALE);

  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme, ({
    ([ P_STANDARD: ({WT_SWORD,3,PSIZE_GENERIC}) ]),
    ([ P_SHORT: "a bone sword",
       P_LONG:
       "This is a special sword. It is made of bones from elves.\n",
       P_ADS: ({"bone","special"}),
       P_WEIGHT: 1000,
       P_VALUE: 30, ]) }) );
}

