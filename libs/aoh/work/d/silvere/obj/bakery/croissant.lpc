// Food for the bakery in Silvere
// P_SPECIAL_NAME is for the bakery, when they become daily specials
//
// created:          Tune    [??-Mar-1997]
// updated:          Tune    [24-Apr-1999]

#include <properties.h>

#define P_SPECIAL_NAME   "special_of_the_day"


inherit "/std/food";

void create()
{
  ::create();
  SetShort("a croissant");
  SetLong("A buttery, flaky, and rather fattening croissant.\n");
  
  Set(P_SPECIAL_NAME, "Croissants");
  
  SetFood();
  SetFoodStuff(6);
  SetFoodHeal(5);

  Set(P_NOBUY, "I have no need for used croissants, thank you.\n");
  
  SetFoodMsgs( ({
    "You greedily gobble down the light flaky pastry.\n",
    Pl_name()+" wolfs down a croissant in several huge bites. No manners!\n"
  }) );
  
  SetSmell("Smells of fresh pastry and butter.\n");
  
  AddId("croissant");
  AddAdjective( ({ "buttery", "flaky", "fattening" }) );
  
  SetWeight(20);
  SetValue(0);
}
