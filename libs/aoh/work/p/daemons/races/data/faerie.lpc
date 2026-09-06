/*obj/race/faerie */

/* Faeries by joan 10/19/1998 */
/* last update 11/03/98 by Joan */

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
  SetAlign(50); /* faeries are dainty and sweet */
  SetFood(100);
  SetDrink(100);
  SetAlc(80); /* Didn't know what else to set here. */ 
 
  SetWeight(1000); /* tiny thin petite */
  SetSize(PSIZE_SMALL);
  SetDef(1);
  SetHome(STARTROOM);
  AddHand("right hand", 1);
  AddHand("left hand", 1); /* faeries have 2 hands */
  AddLeg("left leg",1); /*faeries have 2 legs */
  AddLeg("right leg",1);
  AddAttr("MagicDefence",30); /* are very magic resistant */
  AddStat (A_CON,-5); /* faeries have bad constitution */
  AddStat (A_INT,10); /* VERY intelligent ! */
  AddStat (A_STR,-5); /* but not strong */
  AddStat (A_WIS,10); /* but wise */
  AddStat (A_AGI,10); /* but agile */ 
  AddStat (A_QUI,15); /* but very quick */ 
  AddStat (A_CHA,15); /* but very charasmatic */ 
  AddStat (A_IVISION, ND_REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  AddStat   (A_UVISION, 3 * MAX_SUNBRIGHT);
  SetPlural("faeries");
  SetLong(
   "@@Pl_Name@@ is a skinny faerie. @@Pl_Pro@@ looks rather beautiful. "
   "@@Pl_Poss@@ face is pleasant and elegant. @@Pl_Poss@@ eyes are a bit "
   "different from any eyes you have ever seen before. They slant "
   "slightly upward. While twinkling upon you, @@Pl_poss@@ eyes peer into "
   "your very heart. @@Pl_Poss@@ ears are slightly oversized and taper "
   "to a slightly curved point. You get a happy feeling when you look at "
   "@@Pl_Name@@\n"); 
 
  SetDesc(
   "Faeries are really petite. They are thin with dragonfly like wings. "  
   "They are much more agile than humans are, but also much weaker. They "
   "have a natural sense for magic and laughter which makes them wonderful " 
   "bards and magicians, and because of their speed they make excellent "
   "light swordsmen. Their homes can be found deep within enchanted forests. "
   "They are fiercely protective of nature and wildlife. They patrol "
   "enchanted areas to prevent poaching and destruction by anyone.\n");
  SetInfo(
  "Faeries are a tiny magical people. They are very good at learning  "
  "magic, music and are excellent light swordsmen.\n");
 
          
  AddEquipment("torch", "/obj/torch", 0, 0, ({ "lamp", "lantern" }));
}
 
/***************************************************************************/
