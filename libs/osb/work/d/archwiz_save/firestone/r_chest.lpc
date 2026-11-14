#include <moving.h>
#include <rooms.h>
#include <combat.h>
#include <properties.h>
#include <money.h>
#include "path.h"

inherit "std/room";
 
int nhide;
object troll;

reset() {
  ::reset();
  nhide=0;
}

descr() {
object mon;
  if (nhide || troll) return;
  write("You see a troll! He was in hiding behind the chest!\n");
  troll = clone_object("/std/npc");
  troll->SetName("Baby Troll");
  troll->SetShort("a little baby troll");
  troll->SetLong("It looks nasty...\n");
  troll->SetRace("troll");
  troll->SetIds( ({"troll"}) );
  troll->SetAds( ({"baby","nasty","little"}) );
  troll->SetLevel(1);
  troll->SetAlign(-10);
  troll->SetAC(0);
  troll->SetMaxHP(25);
  troll->SetHP(22);
  troll->SetGender(1);
  troll->SetHands( ({ ({"left hand",0,6}),({"right hand",0,6}) }) );
  troll->move(this_object(),M_SILENT);
  mon=clone_object("/obj/money");
  mon->AdjustMoney(random(2)+1,"silver");
  mon->move(troll,M_SILENT);
  nhide=1;
}

create() {
  ::create();
  SetIntShort("In a corridor");
  SetIntLong("You are in a corridor.\n");
  SetIndoors(1);
  AddExit("west","./r_t1");
  AddExit("east","./r_t3");
  AddItem("/obj/chest",REFRESH_REMOVE,({
    ([P_SHORT: "a big wooden chest",
      P_LONG: "A big wooden chest in which you can put things.\n",
      P_ADS: ({"big","wooden"}),
      P_WEIGHT: 20000,
      P_MAX_WEIGHT: 30000,
      P_VALUE: 100,
      P_ITEMS_REFRESH:
      ({ 
         ({ 
            "/obj/money",REFRESH_REMOVE
	  , (["Money":MONEY_DEMON->CreateMoney(random(200)+1,({"copper"}))])
          , 0
         })
       , ({ 
            "/std/armour",REFRESH_REMOVE
          , ([ P_SHORT: "a leather jacket",
	       P_LONG:
"A worn but sturdy leather jacket. On the back is a lot of rivets making "
"the pattern of a star.\n",
	       P_ADS: ({"worn","sturdy","leather"}),
	       P_IDS: ({"jacket"}),
	       P_SIZE:PSIZE_NORMAL,
	       P_QUALITY: 45,
	       P_VALUE: 50,
               P_AC: 2,
	       P_WEIGHT: 3500,
	       P_ARMOUR_TYPE:AT_MAIL
            ])
          , 0
         }) // "std/armour"          
       }) // P_ITEMS_REFRESH
     ]) // AddItem "chest", properties 1
    , ([P_LOCKSTATE:LOCK_CLOSED]) 
    }) // AddItem "chest", property list
  );
  AddDetail("chest",#'descr);
  nhide = 0;
}
 
