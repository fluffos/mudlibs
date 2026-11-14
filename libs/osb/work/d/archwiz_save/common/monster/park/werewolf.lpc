#include "path.h"
#include <combat.h>
#include <rooms.h>
#include <properties.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("werewolf");
  SetShort("a werewolf");
  SetLong("This is a werewolf, howling at the moon.\n");
  SetIds(({"wolf","werewolf"}));
  SetAds(({"evil","howling"}));
  SetLevel(4);
  SetHP(60);
  SetSize(PSIZE_NORMAL);
  SetAlign(-60);
  SetAC(2);
  SetWimpy(5);
  SetHands(({({"left hand",0,6}),({"mouth",0,6})}));
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme,
    ([P_SHORT: "a black ring",
      P_LONG: "A black ring, that probably can protect you.\n",
      P_IDS: ({"ring"}),
      P_ADS: ({"black"}),
      P_VALUE: 80,
      P_WEIGHT: 60,
      P_ARMOUR_TYPE:AT_RING,
      P_MAGIC: "This ring will give you aditional protection against acid and electro shocks.\n",
      P_DEFENCES: ({0,0,0,0,0,0,0,0,0,5,6}),  // against electro and acid
      P_RESET_QUALITY: random(70)+10,
      P_SIZE:PSIZE_NORMAL]));
}
