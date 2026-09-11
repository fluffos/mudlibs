// a glass of wine, to be sold in the wine shop
// created:        Auryn [22-May-1999]

inherit "/std/drink";

void create()
{
  ::create();
  SetLong("A wine glass from the wine shop in Silvere.\n");
 
  Set_Vessel_Name("glass");
  Set_Drink_Name("elvish white wine");

  AddId("wine");
  AddAdjective( ({"elvish","white"}) );

  SetFoodMsg1("You take a sip of wine from your glass. It tastes "
"wonderful... an excellent vintage, definitely worth the price..\n");
  SetFoodMsg2("@@Pl_Name@@ takes a sip from a glass of "
	      "wine and nods appreciatively.\n");

  SetFoodAlc(5);
  SetFoodHeal(4);
  Set_Vessel_Value(2);
  Set_Vessel_Weight(30);
  Set_Vessel_Volume(250);
}

