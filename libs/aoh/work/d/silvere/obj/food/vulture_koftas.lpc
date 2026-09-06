// meat for the silvere (west) butcher shop
// created: [tune]  28-may-98

inherit "/std/food";

void create()
{
  ::create();
  
  SetShort("vulture koftas");
  SetLong("A small packet of lightly seasoned vulture mince koftas, which "
          "were rolled into balls and then grilled on skewers.\n");
  
  AddId( ({ "koftas", "balls", "mince", "vulture", "meat" }) );  
  // needs meat id to be traded at butcher
  
  AddAdjective( ({ "vulture", "mince", "grilled" }) );
  
  SetFood();
  
  SetFoodMsgs(
   ({ "You pop the vulture koftas into your mouth, one after the other. "
      "They actually taste a little like chicken.\n",
      "@@Pl_Name@@ eats vulture koftas from a small packet.\n" }) );
   
  SetFoodStuff(22);
  
  SetSmell("Smells of seasonings, onions and garlic.\n");

}
