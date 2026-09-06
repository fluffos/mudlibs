/*--------------------------------------------------------------------------
 *  /obj/herbs/clocksaw --  Standard herb
 *
 *  Copyright (C) 1997 by One Step Beyond.
 *  All Rights Reserved.
 *  Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 *
 *  01-feb-98 [tune]      Creation
 *
 *  This is a "standard" herb which requires no setup; simply clone
 *  and use. It heals a small, random number of HP (25-55).
 *
 */  
 
 
#include <properties.h>
#include <herbs.h>

inherit HERB;

private string eat_text(int i);

varargs void create()
{
  int strength;
  
  ::create();
  
  SetShort("dark green herb");
  SetLong("A pleasantly fragrant herb with dark green leaves.\n");
  
  SetPluralShort("several dark green herbs");
  SetPluralLong("Some pleasantly fragrant herbs with dark green leaves.\n");
  
  AddId("leaf");
  AddPluralId("leaves");
  
  AddAdjective(({ "green","dark","sharp","serrated" }));
  
  strength = random(30) + 25;
  
  SetStandard( HERB_HEAL_HP, "clocksaw", strength,
               eat_text(strength) );
    

  SetFoodMsgs(({"You eat the dark green herb.\n",            // msg to player
                "@@Pl_Name@@ eats a green herb.\n",   // to environment (seeing)
				"Someone eats something.\n"}));       // to environ. (not see.)

  SetHerbLong(
        "The herb has strong, dark green leaves with sharp, serrated "
        "edges, and tiny red flowers budding from the stem.\n");
        
  AddHerbInfo(16,
	   "The green leaf seems to be from a medicinal herb.\n",
	   "The green leaves seem to be from a medicinal herb.\n");
  AddHerbInfo(45,
	   "The dark green leaf appears to be an herb with nutritional properties.\n",
	   "The dark green leaves appear to be herbs with nutritional properties.\n");
  AddHerbInfo(70,
	   "The dark green herb is clocksaw, which satiates when eaten.\n",
	   "The dark green herbs are clocksaw leaves, which satiate when eaten.\n");
}


private string eat_text(int i)
{
   switch(i)
   {
      case 25..35:
        return "You feel pleasantly satisfied, as if that limp green herb "
               "in actuality had been a lovely, greasy meat pie.\n";
        break;
      case 36..45:
        return "You feel rather satiated and pleasantly full, as if you "
               "had eaten a good pub meal.\n";
        break;
      case 46..55:
        return "Your stomach feels warm and full, as if you had eaten a "
               "large meal with several courses, and topped it off with "
               "a frothy tankard of ale.\n";
        break;
      default:
        return "You feel pleasantly full, not at all hungry anymore.\n";
   }
  return "You feel pleasantly full, not at all hungry anymore.\n";
}
