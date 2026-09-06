/* obj/race/giant  */
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

  SetAlign  (-300); /* Giants are evil */
  SetFood   (500);
  SetDrink  (300);
  SetAlc    (1100);
  SetWeight (280000);
  SetDef    (1);
  SetHome(STARTROOM);
  SetSize(PSIZE_LARGE);
  AddHand   ("right fist", 1);
  AddHand   ("left fist", 1);
  AddAttr("MagicDefence",0); // NOTHING to do with magic
  AddStat (A_CON,15);   /* Giants have VERY good constitution */
  AddStat (A_INT,-10);  /* Giants are stupid! */
  AddStat (A_STR,15);   /* Giants are very strong */
  AddStat (A_WIS,-10);  /* Giants are not very wise */
  AddStat (A_AGI,-9);   /* Giants are clumsy */
  AddStat (A_QUI,-8);   /* Giants are slow */
  AddStat (A_CHA,0);    /* Giants have no charisma */
  AddStat (A_IVISION, -ND_REL_STATE(ND_LATE_MORNING, MAX_SUNBRIGHT));  /* can see in the darkness */
  AddStat (A_UVISION, ND_REL_STATE(ND_LATE_MORNING, MAX_SUNBRIGHT));
  SetLong   (
    "@@Pl_Name@@ is a giant and looks like an huge human at first glance. "
    "@@Pl_Poss@@ huge dull eyes are rounder than a human's eyes and reflect "
    "a shallow intelligence and beady meanness. @@Pl_Poss@@ enormous ears "
    "are pointy and sit low upon @@Pl_poss@@ head. Rather heavy set, @@Pl_Name@@ "
    "is slow and clumsy, but strong. "
    "A slight shudder of fear runs through you when you look at @@Pl_Name@@\n");
  SetDesc ("Slow, clumsy and stupid Giants are also mean. "
	   "They prefer the company of trolls and orcs and together plan "
	   "the world domination through brutality.\n");
  AddEquipment("sunglasses", "/obj/sunglasses", 0, 0, ({ "glasses" }));
}

/***************************************************************************/
