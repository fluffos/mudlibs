// Example herb for OSB
//
// (c) Softbyte 21jun97
//
//

#include <properties.h>
#include <herbs.h>

inherit HERB;

varargs void create()
{
  ::create();
  
  // initialisation of the unit

  SetAmount(1);             // one herb 
  SetValuePerUnit(125);     // costs 125 coins
  SetWeightPerUnit(5);      // and weighs 5 gramm


  // this is the look to everybody regardless of any herb skill

  SetShort("green leaf");
  SetLong("A green leaf with white dots.\n");
  SetPluralShort("green leaves");
  SetPluralLong("Some green leaves with white dots.\n");
  AddId("leaf");
  AddPluralId("leaves");
  AddAdjective("green");
  

  // initialisation of the food - optional

  SetFoodMsgs(({"You eat a green leaf.\n",            // msg to player
                "@@Pl_Name@@ eats a green leaf.\n",   // to environment (seeing)
				"Someone eats something.\n"}));       // to environ. (not see.)


  // Initialisation of the herb - all but SetStandard is optional

//    SetStandard(HERB_HEAL_SP,45);  // a healing herb which heals 45 SP
    SetStandard(HERB_HEAL_HP,"Example Herb", 25);  // a healing herb which heals 25 HP

	AddHerbInfo(20,
	   "The green leaf seem to be some useful herb.\n",
	   "The green leaves seem to be some useful herbs.\n");
	AddHerbInfo(40,
	   "The green leaf seems to be a healing herb.\n",
	   "The green leaves seems to be healing herbs.\n");
	AddHerbInfo(60,
	   "The green leaf seems to be a weak healing herb.\n",
	   "The green leaves seems to be weak healing herbs.\n");
}
