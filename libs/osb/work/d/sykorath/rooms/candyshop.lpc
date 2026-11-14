// made by magictcs - 2 jul 97

// TODO: add some more candies :)
// TODO: add a disease 'caries' for eating the candy :)
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit "/std/shop";

//***************
// check if candy
//***************
int CheckTrade(object obj) {
  if (obj->id("sugar")) return 1;
  if (obj->id("id_sweet")) return 1;
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("The candy shop");
  SetIntLong(
    "You are standing in a candy shop. You can buy or sell things here.\n"
    "But the shop will handle only with sweet items.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"candy shop"}),#'IntLong);

  SetIndoors(1);
  SetBuyFactor(200);
  SetMinCash(6000);
  AddValuta("platinum");
  AddValuta("gold");
  AddValuta("silver");
  AddValuta("copper");
  SetSecurity(1);       // noone should enter the store

  /* shopkeeper */
  SetShopkeeper(NPC("sweety"));

  /* Exits */
  AddExit("northwest","./oakstreets2");

  /* articles */
  AddArticle("/std/food",REFRESH_REMOVE,2,
    ([ P_SHORT:  "a lolipop",
       P_LONG:   "A sweet red lolipop, made of sugar.\n",
       P_FOOD_MSGS: ({"You lick the sweet lolipop until it is vanished.\n",
                  "@@Pl_Name@@ licks a lolipop.\n"}),
       P_FOOD_STUFF: 6,
       P_FOOD_HEAL:  2,
       P_VALUE:  13,
       P_WEIGHT: 20,
       P_ADS:    ({"red","sweet"}),
       P_IDS:    ({"lolipop","id_sweet"}) ]) );
  AddArticle("/std/food",REFRESH_REMOVE,2,
    ([ P_SHORT:  "some sugar-candy",
       P_LONG:   "Very sweet candy-sugar made of - yes sugar.\n",
       P_FOOD_MSGS: ({"You eat some sugar-candy. Be aware of caries!\n",
                  "@@Pl_Name@@ eats some sugar-candy.\n"}),
       P_FOOD_STUFF: 6,
       P_FOOD_HEAL:  2,
       P_VALUE:  15,
       P_WEIGHT: 22,
       P_ADS:    ({"very sweet","sweet","candy","some"}),
       P_IDS:    ({"sugar","candy-sugar","candy","id_sweet"}) ]) );
  AddArticle("/std/food",REFRESH_REMOVE,2,
    ([ P_SHORT:  "some liquorice bears",
       P_LONG:   "Some bear made of a black material - called liquorice.\n",
       P_FOOD_MSGS: ({"Yumm yumm - they taste very good.\n",
                  "@@Pl_Name@@ eats some liquorice bears.\n"}),
       P_FOOD_STUFF: 6,
       P_FOOD_HEAL:  2,
       P_VALUE:  45,
       P_WEIGHT: 39,
       P_ADS:    ({"liquorice","some"}),
       P_IDS:    ({"bear","bears","id_sweet"}) ]) );
  AddArticle("/std/food",REFRESH_REMOVE,3,
    ([ P_SHORT:  "some jelly-babies",
       P_LONG:   "Hmm jam jam jelly babies. Some blue, some red, some green, "
                 "some yellow jelly-babies.\n",
       P_FOOD_MSGS: ({"You chew some jelly-babies.\n",
                  "@@Pl_Name@@ licks some jelly-babies.\n"}),
       P_FOOD_STUFF: 6,
       P_FOOD_HEAL:  2,
       P_VALUE:  34,
       P_WEIGHT: 100,
       P_ADS:    ({"jelly","some"}),
       P_IDS:    ({"babies","jelly-babies","id_sweet"}) ]) );
}

