/* obj/race/elf */
/* updated for OSB 11/03/98 by Joan */
/* last update 11/03/1998 by Joan */

#include <races.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
#include <stdrooms.h>

inherit RACEOBJ;

/*-------------------------------------------------------------------------*/

public void create()
{
  (::create());
  SetAlign(50); /* Elves are nice */
  SetFood(100);
  SetDrink(100);
  SetAlc(80); /* Didn't know what else to set here. */
  SetWeight(65000); /* Not as heavy as humans */
  SetSize(PSIZE_NORMAL);
  SetDef(1);
  SetHome(STARTROOM);
  AddHand("right hand", 1);
  AddHand("left hand", 1); /* Elves have 2 hands */
  AddAttr("MagicDefence",30);
  AddStat (A_CON,-3); /* Elves have bad constitution */
  AddStat (A_INT,6); /* VERY intelligent ! */
  AddStat (A_STR,-4); /* but not strong */
  AddStat (A_WIS,5); /* and they are wise */ 
  AddStat (A_AGI,1); /* but more dexterity than humans. */
  AddStat (A_QUI,1); /* they are faster than humans. */
  AddStat (A_CHA,2); /* and they are charasmatic. */
  AddStat (A_IVISION, ND_REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  AddStat (A_UVISION, 3 * MAX_SUNBRIGHT);
  SetPlural("elves");
  SetLong( 
    "@@Pl_Name@@ is a tall elf. @@Pl_Pro@@ is gracefully built, and "
    "@@Pl_poss@@ skin has a fair, translucent complexion. @@Pl_Pro@@ "
    "has enormous, soft brown eyes, which peer "
    "at your very soul with the wisdom of the ancients. The eye color is "
    "rich and pierces your intellect with an aristocratic arrogance. "
    "You feel as though your very soul has been touched.\n");
  SetDesc(
"Graceful, elegant, intelligent and musical elves are natural mages and "
"bards. They are are quick and agile and make suberb archers and light "
"swordsmen. They live deep in enchanted forests. Nothing is quite so "
"magical as an elven forest. These enchanted forests are quite different "
"from any other forests. Enter enchanted forests with care. Elves fiercely "
"protect the enchanted forests and their inhabitants.\n");
  SetInfo("Elegant and intelligent elves are natural mages.\n");

          
  AddEquipment("torch", "/obj/torch", 0, 0, ({ "lamp", "lantern" }));
}

/***************************************************************************/
