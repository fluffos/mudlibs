// made by Magictcs 08 mar 97
// a corpse to eat :) made of liquorice
// but you have to take it first :(((, so don't make it too heavy!
// count the number of eaten corpses in the playerobject directly!

#include <properties.h>
#include <secure/wizlevels.h>

#define TP this_player()
#define DELAY 30

inherit "/std/food";
inherit "/std/corpse";

// questmaster stuff:
mixed eatcorpse() {
  int num;
  num=TP->Query("NUMCORPSES");
  if (num < 20) {
    TP->Set("NUMCORPSES",num+1);
  }
  return
  ({"Ahhhh... that tastes cool.\n",
    "@@Pl_Name@@ eats a corpse.\n"});
}

create() {
  food::create();
  corpse::create();

  // food stuff:
  SetFoodKind("eat");
  SetFoodMsgs(#'eatcorpse);
  SetFoodAlc(0);
  SetFoodHeal(3);
  call_out("SetWeight",1,10300+random(1000));
  SetValue(0);

  // corpse stuff:
  Set(P_DECAY_TIME,DELAY);
  Set(P_DECAY,0);                    // fresh corpse
  Set(P_RACE,"liquorice bear");      // all corpse has the same type
  Set(P_NAME,"a liquorice bear");      // set by cloning object
  DoDecay(1);                        // start the decay
  if (!is_clone()) return;
  TP->Set("KILLEDCORPSES",TP->Query("KILLEDCORPSES")+1);
}

