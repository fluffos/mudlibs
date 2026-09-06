// made by MagicTCS 09 mar 97
// a bear consting of liquorice
// the corpses can be eaten!!
// part of the eatcorpses quest

#include <rooms.h>
#include <moving.h>
#include <combat.h>
#include <properties.h>
#include <sykorath.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetRace("bear");
  SetName("Liquorice bear");
  SetShort("a liquorice bear");
  SetLong(
    "You see a cruel liquorice bear.\n"
    "The body of this bear consists of liquorice only.\n"
  );
  SetGoChance(0);                  // no go away!
  SetGender(random(1)+1);          // change gender randomly
  SetAggressive(random(1));        // some aggressive, some none
  SetLevel(15);
//  SetKillXP();         // ????
  if (random(5)) {
    AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme,
    ([P_SHORT: "a blunt knife",
      P_LONG: 
      "This knife is not very sharp, but a liquorice bear is able to handle it\n"
      "very good!\n",
      P_WEAPON_TYPE:WT_KNIFE,
      P_DAM_TYPE:DT_SLASH,
      P_WC: 6,
      P_RESET_QUALITY:random(49)+100,
      P_WEIGHT: 4000,
      P_VALUE: 560,
      P_ADS: ({"blunt"}) ]) );
  }
  if (random(3)) {
    AddItem("/std/armour",REFRESH_REMOVE,#'wearme,
    ([P_SHORT: "a rubber shield",
      P_LONG: 
      "This shield will absorb many hits!\n",
      P_ARMOUR_TYPE:AT_SHIELD,
      P_AC: 1,
      P_WEIGHT: 4000,
      P_VALUE: 634,
      P_ADS: ({"rubber"})
      ]));
  }
  SetAds(({"liquorice"}));
  SetIds(({"bear"}));
  SetCorpse(BASE+"eatcorpse/lcorpse");    // clone a non standard corpse
}

