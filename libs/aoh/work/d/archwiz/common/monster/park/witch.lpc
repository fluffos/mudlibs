#include "path.h"
#include <combat.h>
#include <rooms.h>
#include <money.h>
#include <properties.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("witch");
  SetShort("the bad witch of the west");
  SetLong("The bad witch of the west puts something in a cauldron.\n");
  SetIds(({"witch","witch of the west"}));
  SetAds(({"bad","evil"}));
  SetGender(2);
  SetLevel(6);
  SetHP(70);
  SetAlign(-100);
  SetAC(6);
  SetWimpy(10);
  SetHands(({({"left hand",0,5}),({"right hand",0,10})}));
  AddQuestion(({"girl","riding hood","little red riding hood","hood",
    "red hood","red riding hood"}),
"The witch looks angry.\n"
"The witch says: Once she'd used to be often around playing with my puzzle.\n"
"  But then she grew older and my puzzle got lost.. and now I am lonely\n"
"  again. She's more with my sister the good witch of the west now.\n");
  AddQuestion(({"witch","good witch","witch of the west","sister",
    "good witch of the west"}),
"The witch curses.\n"
"The witch says: Once we love eachother dearly, but then this stupid man\n"
"  came around, loving her not me. He's dead long time now, but we two\n"
"  cannot come together since.. and I got the way I am.. having been\n"
"  lonely all life.\n");
  AddQuestion("grandma",
"The witch says: She's a bitch! That man how parted me and my sister has\n"
"  been her son. Her grandchild though is the daughter of her daughter.\n");
  AddQuestion("puzzle",
"The witch says: It got lost some time ago.. Perhaps one day a mighty\n"
"  wizard will give me a new one.\n");
  AddQuestion("hunter",
"The witch says: It's long since I met him.\n");
  AddItem("/obj/money",REFRESH_REMOVE,
    (["Money":MONEY_DEMON->CreateMoney(random(1)+1,({"silver"}))]));
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme,
    ([P_SHORT: "a black witchrobe",
      P_LONG: "A black robe, with some runes on it.\n",
      P_IDS: ({"witchrobe","robe","cloak"}),
      P_ADS: ({"witch","black"}),
      P_WEIGHT: 2000,
      P_VALUE: 300,
      P_DEFENCES: ({0,0,0,0,3,0,0,4}),
      P_SIZE:PSIZE_NORMAL,
      P_RESET_QUALITY:random(100)+1]));
  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme,
    ([P_SHORT: "a witch broom",
      P_LONG: "A long broom which could have belonged to a witch.\n",
      P_IDS: ({"broom","witchbroom"}),
      P_ADS: ({"witch","long"}),
      P_WEIGHT: 2000,
      P_VALUE: 300,
      P_WC: 11,
      P_RESET_QUALITY: random(30)+40,
      P_SIZE:PSIZE_NORMAL,
      P_WEAPON_TYPE:WT_CLUB,
      P_DAM_TYPE:DT_BLUDGEON]));
//  AddItem(OBJ("puzzle"),REFRESH_REMOVE);
}
