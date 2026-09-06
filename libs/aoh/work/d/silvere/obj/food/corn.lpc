// Corn for the cornfield newbie area
// created:          Tune     [13-May-1999]
// last changed:  

#include <properties.h>

inherit "/std/food";

void create()
{
  ::create();
  SetShort("an ear of corn");
  
  // long is changed by the cornfield when the corn is cloned, depending
  // on the season
  SetLong("An ear of corn.\n");
  
  AddId( ({ "corn", "maize"}) );
  AddAdjective("ear of");
  
  SetValue(0);
  SetWeight(20);
  
  SetFoodStuff(3);
  SetFoodHeal(0);

  SetFoodMsgs( ({
   "Uncooked corn is not especially tasty, but you choke it down anyway.\n",
   "@@Pl_Name@@ nibbles on a raw ear of corn.\n" }));
   
  SetSmell("Makes you think of roasted sweet corn on the cob.\n");
  
  Set(P_NOBUY, "I don't buy used food items, thank you.'\n");
}

