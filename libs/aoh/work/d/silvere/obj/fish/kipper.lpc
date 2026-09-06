// smoked and salted herring for the fishmonger's shop
// created:           Auryn    [16-May-1999]

#include <properties.h>

inherit "/std/food";

void create()  {
  ::create();
  SetShort("a kipper");
  SetLong("A smoked and salted herring\n");
  
  Set(P_NOBUY, "Thanks, but I have no use for a kipper.\n");
  
  SetFood();
  SetFoodStuff(9);
  SetFoodHeal(4);

  
  AddId( ({ "herring" }) );
  AddAdjective( ({ "smoked","salted" }) );
  
  SetSmell("A strong smell of fish and wood smoke\n");
  
SetWeight(25);
SetValue(20);
}

