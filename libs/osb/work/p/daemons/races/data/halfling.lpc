/* obj/race/halfling
*/

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
  SetAlign(50); /* Halflings are nice little creatures */
  SetFood(75);
  SetDrink(75);
  SetAlc(50);
  SetSize(PSIZE_SMALL);
  SetDef(0);
  SetHome(STARTROOM);
  SetWeight(40000);
  AddHand("right hand", 1);
  AddHand("left hand", 1);
  AddAttr("MagicDefence",10);
  AddStat(A_CON,1);
  AddStat(A_DEX,3);
  AddStat(A_INT,-1);
  AddStat(A_STR,-3);
  AddStat(A_IVISION, ND_REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  AddStat(A_UVISION, 3 * MAX_SUNBRIGHT);
  SetLong(
"@@Pl_name@@ is a halfling. @@Pl_Poss@@ body is small and tiny, but there is\n\
something very special about @@Pl_obj@@: @@Pl_Poss@@ feet are as tall as\n\
those of a very much taller person. They are nearly as large as @@Pl_poss@@\n\
legs are. This makes @@Pl_Name@@ look rather clumsy, but this would be utterly\n\
wrong. @@Pl_Poss@@ eyes looks curiously around, ready to catch everything of\n\
any importance. You feel that there could be only few that could escape @@Pl_po\
ss@@ attention.\n");
  SetDesc(
"Halflings are a small but very curious race. There is nearly nothing that\n\
a halfling does not find interesting. He wants to know everything, though no\n\
normal halfling would ever try to learn anything about magic. They are very\n\
good rogues and not bad fighters, though there are probably better ones. They\n\
are in most cases very friendly and like to help others. No halfling would\n\
dare to harm another halfling, being all too close relatives to one another.\n\
Halflings like fun and the good sides of life. Why should one be cruel if\n\
he/she could be nice? This is the first question a halfling will ask before\n\
attacking another one either by combat or words.\n");
  AddEquipment("torch", "/obj/torch", 0, 0, ({ "lamp", "lantern" }));
}

/***************************************************************************/

