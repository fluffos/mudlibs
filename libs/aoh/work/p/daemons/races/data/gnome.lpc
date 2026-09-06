/* obj/race/gnome */
/* updated for OSB 11/10/98 by Joan */


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
  SetAlign(-100); /* gnomes are nasty */
  SetFood(80);
  SetDrink(80);
  SetAlc(110); /* gnomes drink, sing and dance a lot */
  SetWeight(30000); /* lighter than dwarves */
  SetSize(PSIZE_SMALL);
  SetDef(1); /* Is a perfect Illusionist */
  SetHome(STARTROOM);
  AddHand("right hand", 1);
  AddHand("left hand", 1);
  AddAttr("MagicDefence",30); /* are very magic resistant */
  AddStat (A_CON,-1); /* gnomes have poor constitution */
  AddStat (A_INT,8); /* VERY intelligent ! */
  AddStat (A_STR,-8); /* but not strong at all */
  AddStat (A_WIS,8); /* but wise */
  AddStat (A_AGI,5); /* but agile */ 
  AddStat (A_QUI,9); /* but very quick */ 
  AddStat (A_CHA,1); /* but not very charasmatic */ 
  AddStat(A_IVISION, -(MAX_SUNBRIGHT / 2));
  AddStat(A_UVISION, ND_REL_STATE(ND_LATE_MORNING, MAX_SUNBRIGHT));
  SetLong(
    "@@Pl_Name@@ is a nasty little gnome. @@Pl_Pro@@ is slightly built with  " 
    "a pinkish cast to @@Pl_Pro@@ swarthy skin. @@Pl_Pro@@ has a pointy pinched "
    "face and a huge nose. @@Pl_Poss@@ mean, beady little black eyes peer "
    "at you with an arrogant glare. "
    "You get an uneasy feeling looking at this gnome.\n");
  SetDesc(
    "Small, nosey and excellent tinkers, gnomes are intelligent and "
    "curious by nature. Quick and dexterious they make excellent "
    "thieves. Mean from living underground without sunlight, gnomes "
    "grow up to be destructive.\n");
  
  AddEquipment("sunglasses", "/obj/sunglasses", 0, 0, ({ "glasses" }));
}

/***************************************************************************/
