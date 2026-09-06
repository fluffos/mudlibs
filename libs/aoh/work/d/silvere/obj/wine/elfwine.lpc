// a bottle of wine, to be sold in the wine shop
// created:        Auryn [22-May-1999]

#include <properties.h>

inherit "std/drink";

void create()
{
  ::create();

  Set_Vessel_Name("bottle");
  Set_Drink_Name("elvish white wine");

  AddId( ({"wine","white wine"}) );

  SetFoodMsg1("You drink some wine from your bottle. Don't you have "
	      "any manners?\n");
  SetFoodMsg2("@@Pl_Name@@ drinks some wine from a bottle. Some people "
	      "just don't know how to behave...\n");

  SetFoodAlc(25);
  SetFoodHeal(10);
  Set_Vessel_Value(20);
  Set_Vessel_Weight(100);
  Set_Vessel_Volume(750);
  SetValue(400);

  SetLong("A fine glass bottle from the wine shop in Silvere.\n");
}
