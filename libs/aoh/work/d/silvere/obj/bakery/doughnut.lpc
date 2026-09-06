// Food for the bakery in Silvere
// P_SPECIAL_NAME is for the bakery, when they become daily specials
//
// created:          Tune    [Apr-1996]
// updated:          Tune    [24-Apr-1999]

#include <properties.h>

#define P_SPECIAL_NAME   "special_of_the_day"

inherit "/std/food";

void create()
{
  ::create();
  SetShort("a doughnut");
  SetLong("A soft doughnut, made from sweet dough and fried in oil.\n");
  
  Set(P_SPECIAL_NAME, "Fresh Doughnuts");
  
  Set(P_NOBUY, "I have no use for food items, thank you.\n");
  
  SetFood();
  SetFoodStuff(9);
  SetFoodHeal(4);

  
  AddId( ({ "doughnut" }) );
  AddAdjective( ({ "soft", "sweet", "fried" }) );
  
  SetSmell("The light smell of dough and sugar.\n");
  
  SetWeight(25);
  SetValue(0);
}
