#include "path.h"
#include <money.h>
#include <combat.h>
#include <properties.h>
#include <rooms.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetRace("human");
  SetName("wicked");
  SetShort("a wicked step-mother");
  SetLong("An ugly, snotty step-mother.\n");
  SetIds(({"wicked","step-mother","mother"}));
  SetAds(({"step","wicked","snotty","ugly"}));
  SetLevel(5);
  SetHP(60);
  SetAlign(-40);
  SetAC(4);
  SetHands( ({ ({"left hand",0,5}),({"right hand",0,6})}));
  AddQuestion(({"girl","riding hood","hood","red riding hood",
    "little red riding hood"}),
"The stepmother looks shocked.\n"
"She says: She is gone? I am sad to hear this.. she has been the only\n"
"  one who ever cared about me. Perhaps the good witch of the west will be\n"
"  able to help you, but first you should talk to her grandma. She is\n"
"  a wicked old person though, but she loves her little grandchild more\n"
"  than anything else. Who'd not understand this.. she is a charming girl.\n");
  AddQuestion("grandma",
"The stepmother answers: She's a bitch!\n");
  AddQuestion("hunter",
"The stepmother says: He takes care about all the animals around. He refused\n"
"  to marry me though.\n"
"The stepmother curses..\n"
"..then she starts to cry bitterly.\n");
  AddQuestion("wolf",
"The stepmother answers: Talking of the big bad wolf? His father would\n"
"  have killed him as a puppy when he'd know what a creature he turns\n"
"  out to be now.\n");
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme,
    ([P_SHORT: "a night gown",
      P_LONG: "A wonderful satin nightgown.\n",
      P_IDS: ({"gown","nightgown"}),
      P_ADS: ({"satin","wonderful","night"}),
      P_VALUE: 160,
      P_WEIGHT: 1000,
      P_AC: 1,
      P_ARMOUR_TYPE:AT_CLOAK,
      P_RESET_QUALITY:random(30)+30,
      P_SIZE:PSIZE_NORMAL]));
  AddItem("/obj/money",REFRESH_REMOVE,
    (["Money":MONEY_DEMON->CreateMoney(random(20)+1,({"copper"}))]));
}
