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
  SetShort("an apple tart");
  SetLong(
   "Steaming, spiced apple filling baked into a crumbly "
   "golden pastry shell.\n");
   
  Set(P_SPECIAL_NAME, "Apple Tarts");
  
  Set(P_NOBUY, "I don't buy used food items, thank you.'\n");
   
  SetFood();
  SetFoodStuff(10);
  SetFoodHeal(3);
  
  AddId( ({ "tart", "pastry" }) );
  AddAdjective( ({"apple", "steaming", "spiced" }) );
  
  SetWeight(20);
  SetValue(0);
  
  SetSmell("Mmmmm....cinnamon and nutmeg....\n");
  
  SetFoodMsgs( ({
    "You consume the sticky, sweet tart, burning your tongue a bit on the "
      "hot, oozing filling.\n",
    "@@Pl_Name@@ consumes an apple tart, licking the sticky sweet filling "
      "from @@Pl_possessive@@ fingers.\n",
    "Someone eats something nearby.\n"
   }) );
}
