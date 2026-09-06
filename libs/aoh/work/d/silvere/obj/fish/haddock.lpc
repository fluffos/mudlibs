// some dried fish for the fishmonger's shop
// created:           Auryn    [16-May-1999]

#include <properties.h>

inherit "/std/food";

void create()  {
  ::create();
  SetShort("a stockfish");
  SetLong("A haddock, dried in the sun, but not salted\n");
  
  Set(P_NOBUY, "Thanks, but I have no use for a stockfish.\n");
  
  SetFood();
  SetFoodStuff(5);
  SetFoodHeal(4);

  
  AddId( ({ "haddock" }) );
  AddAdjective( ({ "dried" }) );
  
  SetSmell("A strong smell of fish.");
  
  SetWeight(15);
  SetValue(0);
}
