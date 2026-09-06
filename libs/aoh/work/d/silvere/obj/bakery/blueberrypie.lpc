// Food for the bakery in Silvere
// P_SPECIAL_NAME is for the bakery, when they become daily specials
//
// created:          Tune    [??-Apr-1997]
// updated:          Tune    [24-Apr-1999]

#include <properties.h>

#define P_SPECIAL_NAME   "special_of_the_day"

inherit "/std/food";

void create()
{
  ::create();
  SetShort("a blueberry pie");
  SetLong(
    "A luscious looking blueberry pie, oozing with sugary blueberry "
    "filling and baked in a golden-brown pastry shell.\n"); 
    
  SetFood();
  SetFoodStuff(20);
  SetFoodHeal(9);
  
  Set(P_NOBUY, "Used food? No thanks. Do you have anything else of value?\n");
  
  Set(P_SPECIAL_NAME, "Blueberry Pie");

  SetSmell("Sweet, ripe blackberries.....yum...\n");
  
  SetFoodMsgs( ({
    "You nibble at a piece of blueberry pie..and bite..and devour. Mmm!\n",
    Pl_name() + " eats a gooey, rich piece of blueberry pie and doesn't "
       "even offer you a bite.\n"  }) );
    
  AddId( ({ "pie" }) );
  AddAdjective( ({ "blue", "berry", "blueberry" }) );
  
  SetWeight(100);
  SetValue(0);
}
