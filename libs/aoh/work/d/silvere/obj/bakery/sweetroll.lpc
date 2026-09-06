// Food for the bakery in Silvere
// P_SPECIAL_NAME is for the bakery, when they become daily specials
//
// created:          Tune    [24-Apr-1999]

#include <properties.h>

#define P_SPECIAL_NAME   "special_of_the_day"

inherit "/std/food";

void create()
{
  ::create();
  SetShort("a sweet roll");
  SetLong(
   "A golden, crusty roll, baked from sweet dough and topped "
   "with sugar icing.\n");
   
  SetFood();
  SetFoodStuff(18);
  SetFoodHeal(5);

  Set(P_NOBUY, "I don't buy used food items, thank you.\n");
               
  Set(P_SPECIAL_NAME, "Sweetrolls");
  
  AddId( ({ "roll", "sweetroll" }) );
  AddAdjective( ({"sweet", "golden", "crusty" }) );
  
  SetWeight(16);
  SetValue(0);
  
  SetSmell("Fragrant, and freshly baked.\n");
  
  SetFoodMsgs( ({
    "The sweetness of the icing satiates your palatte, and the rich "
      "doughy bread fills your stomach.\n",
    "@@Pl_Name@@ consumes a sweet roll, licking icing from @@Pl_possessive@@ "
      "fingers.\n",
    "Someone eats something nearby.\n"
   }) );
}
