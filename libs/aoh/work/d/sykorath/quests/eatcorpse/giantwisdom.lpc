// made by Magictcs 08 mar 97
// part of the eatcorpse miniquest

#include <moving.h>
#include <properties.h>
#include <sykorath.h>

inherit "/std/food";

mixed drinkpotion() {
  object ob;
  if (!present("potion_of_giant_wisdom",environment())) {
    ob=clone_object(QUEST("eatcorpse/wisdom_id"));
    if (ob)
      ob->move(TP,M_SILENT);
  }
  return
  ({"Ahhhh... this goes down smoothly.\n"
    "A giant wisdom is coming over you ....\n"
    "The bottle vanishes as part of the intergalactic anti-litter program.\n",
    "@@Pl_Name@@ drinks a potion of giant wisdom!\n"});
}

create() {
  ::create();
  SetFoodKind("drink");
  SetShort("a potion");
  AddId(({"potion","bottle","wisdom"}));
  AddAdjective(({"giant"}));
  SetLong(
  "This bottle contains a potion of giant wisdom. With drinking this potion\n"
  "you will be able to read some unknown scratches.\n");
  SetFoodMsgs(#'drinkpotion);
  SetFoodAlc(1);
  SetFoodHeal(5);
  SetWeight(750);
  SetValue(100);
}
