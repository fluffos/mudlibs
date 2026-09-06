/* half-elves updated for OSB by Joan 1/25/98  */
/* half-elves seem a bit orphaned and not cared for much  */
/* how about we try to liven them up a bit. */

#include <races.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
#include <stdrooms.h>

inherit RACEOBJ;

public void create()
{
  (::create());
  SetAlign(35);
  SetFood(100);
  SetDrink(100);
  SetAlc(150); /* Well, they can drink a lot! */
  SetWeight(68000); /* Heavier then elfs */
  SetSize(PSIZE_NORMAL);
  SetDef(1);
  SetHome(STARTROOM);
  AddHand("right hand",1);  
  AddHand("left hand",2); /* lefthanded */
  AddAttr("MagicDefence",20);
  AddStat (A_CON,1); /* half-elves have a normal constitution */
  AddStat (A_INT,3); /* half-elves intelligent ! */
  AddStat (A_STR,1); /* half-elves have normal strength */
  AddStat (A_WIS,3); /* half-elves are wise */
  AddStat (A_AGI,1); /* half-elves are fairly agile */ 
  AddStat (A_QUI,1); /* half-elves are fairly quick */ 
  AddStat (A_CHA,2); /* half-elves are charasmatic */ 
  AddStat(A_IVISION, ND_REL_STATE(ND_DAWN,MAX_SUNBRIGHT));
  AddStat(A_UVISION, 3*MAX_SUNBRIGHT);
  SetPlural("half-elves");
/*
 * this line caused an bug and did therefore not load..
 * i commented it out.
 * Sonic, 14-Feb-1998
 *
  SetPlural("half-elves");
 */
  SetLong("@@Pl_Name@@ is a half-elf. Tall and husky @@Pl_Poss@@ is not fat but "
  "@@Pl_Poss@@ is not as slender and graceful as an elf. @@Pl_Poss@@ cheeks are "
  "rosier and rounder than those of an elf. @@Pl_Name@@ looks quite quick "
  "and strong.\n"
  "You feel a bit uneasy when you look at @@Pl_Name@@\n");
  SetDesc("Half-elves are quick and stronger than their elven brothers. "
	  "When good, they make excellent paladins. When bad, they make " 
	  "the most cunning theives and assasins. Graced with a simple "
	  "magical apptitude they do better in minor magical arts. "
	  "With elven blood running in their veins, they dwell deep in " 
	  "the elven forests. Unlike elves, they build their cities " 
	  "on the ground and only partialy in the trees.\n");
  AddEquipment("torch", "/obj/torch", 0, 0, ({ "lamp", "lantern" }));
}
