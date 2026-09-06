/* obj/race/dwarf */
/* updated for OSB by Joan 11/25/98 */
 
#include <races.h>
#include <attributes.h>
#include <nightday.h>
#include <combat.h>
#include <properties.h>
#include <stdrooms.h>

inherit RACEOBJ;
 
/*-------------------------------------------------------------------------*/
 
public void create()
{
  (::create());
  SetAlign(0);
  SetFood(100);
  SetDrink(100);
  SetAlc(130);          // :-) They can drink ...
  SetWeight(35000);     // Smaller and lighter than halflings
  SetSize(PSIZE_SMALL);
  SetDef(0);
  SetHome(STARTROOM);
  AddHand("right hand", 1);
  AddHand("left hand", 1); // Dwarves have 2 hands
  AddAttr("MagicDefence",5); // *shiver* Magic??
  AddStat (A_CON,5); /* dwarves have a good constitution */
  AddStat (A_INT,0); /* dwarves are not very intelligent ! */
  AddStat (A_STR,7); /* dwarves are strong */
  AddStat (A_WIS,3); /* dwarves have an inate wisdom */
  AddStat (A_AGI,3); /* dwarves are not very agile */ 
  AddStat (A_QUI,3); /* dwarves are not very quick */ 
  AddStat (A_CHA,1); /* dwarves are not very charasmatic */ 
  AddStat(A_IVISION, -ND_REL_STATE(ND_LATE_MORNING, MAX_SUNBRIGHT));
  AddStat(A_UVISION, ND_REL_STATE(ND_LATE_MORNING, MAX_SUNBRIGHT));
  SetPlural("dwarves");
  SetPlural("dwarves");
  SetLong("@@Pl_Name@@ is a dwarf. @@Pl_Poss@@  eyes, round and happy, "
  "twinkle merrily as @@Pl_poss@@  gaze falls on you. @@Pl_Pro@@ " 
  "is short but sturdy and looks quite strong.\n"
  "You feel quite merry when you look at @@Pl_Name@@\n");
  SetDesc("Short, strong, sturdy and earthy dwarves are born miners, smiths, "
  "and warriors. Sometimes, dwarves devote themselves to their Gods. "
  "This devotion coupled with dwarven determination drives them to "
  "great heights as clerics, monks and healers. However, the majority "
  "of dwarves live within the earth borrowing, mining and searching for "
  "precious gems and metals.\n");
  AddEquipment("torch", "/obj/torch", 0, 0, ({ "lamp", "lantern" }));
  AddEquipment("sunglasses", "/obj/sunglasses", 0, 0, ({ "glasses" }));
}
 
/***************************************************************************/
 
