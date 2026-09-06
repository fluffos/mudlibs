// made by magictcs - 17 aug 97
// TODO: coords update

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit "/std/shop";

//******************************
// check if something for breads
//******************************
int CheckTrade(object obj) {
  if (obj->id("bread")) return 1;
  if (obj->id("id_bread")) return 1;
  if (obj->id("flour")) return 1;
  if (obj->id("milk")) return 1;
  if (obj->id("sugar")) return 1;
  if (obj->id("egg")) return 1;
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("The elf-bakery");
  SetIntLong(
    "This is the public part of the elf-bakery. The baker works mostly\n"
    "with flour made out of old corpses, not of grain!\n");
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);


  /* details */
  AddDetail(({"bakery"}),#'IntLong);

  SetIndoors(1);
  SetBuyFactor(200);
  SetMinCash(6000);
  AddValuta("platinum");
  AddValuta("gold");
  AddValuta("silver");
  AddValuta("copper");
  SetSecurity(1);       // noone should enter the store

  /* shopkeeper */
  SetShopkeeper(NPC("baker"));

  /* Exits */
  AddExit("","");

  /* articles */
  AddArticle("/std/food",REFRESH_REMOVE,2,
    ([ P_SHORT:  "a bread",
       P_LONG:   "A bread, made of old 'elves' flour.\n",
       P_FOOD_MSGS: ({"You eat the elf-bread.\n",
                  "@@Pl_Name@@ eats the elf-bread.\n"}),
       P_FOOD_STUFF: 6,
       P_FOOD_HEAL:  2,
       P_VALUE:  13,
       P_WEIGHT: 200,
       P_ADS:    ({"elf"}),
       P_IDS:    ({"bread","elf-bread"}) ]) );
/*
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
*/
}

