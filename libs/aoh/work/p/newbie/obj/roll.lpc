// for the newbie creation area
#include <classes.h>

inherit "/std/food";

void create()
{
  ::create();
  SetShort("a bread roll");
  SetLong("A fresh, crusty bread roll.\n");

  AddId( ({ "bread", "roll", "bread roll" }) );
  AddClassId(C_FOOD);
  SetValue(5);
  SetWeight(12);

  SetFoodMsgs( ({
    "You consume a crusty bread roll.\n",
    "@@Pl_Name@@ consumes a crusty bread roll.\n"
  }) );

  SetFoodStuff(10);
  SetFoodHeal(5);

  SetSmell("Sweet white bread, and freshly baked...\n");
}
