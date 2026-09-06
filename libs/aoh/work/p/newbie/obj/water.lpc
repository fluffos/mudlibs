// for the newbie creation area
#include <classes.h>

inherit "/std/drink";

void create()
{
  ::create();
  SetLong("A plain, clay jug of water.\n");

  Set_Vessel_Name("jug");
  Set_Drink_Name("water");

  AddId( ({ "water", "jug", "jug of water" }) );
  AddClassId(C_DRINK);

  SetFoodMsg1(
    "You drink some water from the clay jug.\n");
  SetFoodMsg2(
    "@@Pl_Name@@ drinks some water from @@Pl_pronoun@@ clay jug.\n"
  );

  SetFoodHeal(5);

  Set_Vessel_Value(10);
  Set_Vessel_Weight(50);
  Set_Vessel_Volume(1000);

  SetSmell("Smells like water might smell if water smelled of anything.\n");
}
