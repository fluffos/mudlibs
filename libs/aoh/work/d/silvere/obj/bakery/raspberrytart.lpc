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
  SetShort("a raspberry tart");
  SetLong("Gooey rasberries baked in a crumbly golden pastry shell.\n");   
  
  SetFood();
  SetFoodStuff(8);
  SetFoodHeal(3);

  Set(P_NOBUY, "I don't buy used food items, thank you.\n");
  
  Set(P_SPECIAL_NAME, "Raspberry Tarts");
  
  SetSmell("Sweet, fresh raspberries.\n");
  
  AddId( ({ "tart" }) );
  AddAdjective( ({ "raspberry", "gooey" }) );
  
  SetWeight(20);
  SetValue(10);
}
