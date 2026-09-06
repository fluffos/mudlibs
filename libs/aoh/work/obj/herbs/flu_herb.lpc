// Heal the flu herb for OSB
//
// (c) Softbyte 07jul97
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

  SetShort("light green leaf");
  SetLong("A light green leaf.\n");
  SetPluralShort("light green leaves");
  SetPluralLong("Some light green leaves.\n");
  AddId("leaf");
  AddPluralId("leaves");
  AddAdjective("green");
  AddAdjective("light");
  

  // initialisation of the food - optional

  SetFoodMsgs(({"You eat a light green leaf.\n",            // msg to player
                "@@Pl_Name@@ eats a light green leaf.\n",   // to environment (seeing)
				"Someone eats something.\n"}));       // to environ. (not see.)


  // Initialisation of the herb - all but SetStandard is optional


	AddHerbInfo(20,
	   "The light green leaf seem to be some useful herb.\n",
	   "The light green leaves seem to be some useful herbs.\n");
	AddHerbInfo(40,
	   "The light green leaf seems to be a herb against illness.\n",
	   "The light green leaves seems to be herbs against illness.\n");
	AddHerbInfo(60,
	   "The light green leaf is able to cure mild forms of the flu.\n",
	   "The light green leaves are able to cure mild forms of the flu.\n");
}

public void NotifyEat(object pl)
{
object ob;
  ob=present("_flu",pl);
  if (!ob)
  {
      tell_object(pl,"Although good tasting you feel no effect of the leaf.\n");
  }
  else
  {
    ob->remove();
    if (present("flu",pl))
    {
      tell_object(pl,"You still feel not very well.\n");
    }
    else
    {
      tell_object(pl,"You are cured from the flu.\n");
    }
  }  
  return;
}
