// meat for the silvere (west) butcher shop
// created: [tune]  28-may-98

inherit "/std/food";

void create()
{
  ::create();
  
  SetShort("salted gorgon hocks");
  SetLong("A squarish slab of dried gorgon hock, which has been salted "
          "to preserve it.\n");
  
  AddId( ({ "hocks", "hock", "gorgon", "slab", "meat" }) );  
  // needs meat id to be traded at butcher
  
  AddAdjective( ({ "dried", "salted", "gorgon", "preserved" }) );
  
  SetFood();
  
  SetFoodMsgs(
   ({ "You gnaw on the tough, stringy gorgon and finally manage "
      "to swallow it down.\n",
      "@@Pl_Name@@ gnaws on a tough bit of salten gorgon hock.\n" }) );
   
  SetFoodStuff(22);
  
  SetSmell("The salted gorgon smells a bit like cured ham.\n");

}
