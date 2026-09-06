// meat for the silvere (west) butcher shop
// created: [tune]  27-may-98

inherit "/std/food";

void create()
{
  ::create();
  
  SetShort("a rat mince pie");
  SetLong("A smallish, crusty brown, rat mince pie. Dark ochre gravy "
          "oozes out of cracks in the pastry case.\n");
  
  AddId( ({ "pie", "meat" }) );  // needs meat id to be traded at butcher
  AddAdjective( ({ "rat", "mince", "crusty", "brown" }) );
  
  SetFood();
  
  SetFoodMsgs(
   ({ "You slurp down the messy rat mince pie, licking gravy from your fingers.\n",
      "@@Pl_Name@@ slurps down a messy rat mince pie, licking gravy from "
      "@@Pl_possessive@@ fingers.\n" }) );
   
  SetFoodStuff(15);
  
  SetSmell("The oblong pie smells of thick gravy and grease drippings.\n");

}
