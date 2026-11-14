/* obj/race/orc
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

  SetAlign  (-50); /* Orcs are evil */
  SetFood   (100);
  SetDrink  (100);
  SetAlc    (100); 
  SetWeight (95000);
  SetSize(PSIZE_NORMAL);
  SetDef    (1);
  SetHome(STARTROOM);
  AddHand   ("right claw", 1);
  AddHand   ("left claw", 1);
  AddAttr("MagicDefence",5);
  AddStat   (A_CON,  4); /* Good constitution */
  AddStat   (A_DEX, -2); /* Less dexterity */
  AddStat   (A_INT, -7); /* Have nothing to do with magic */
  AddStat   (A_STR,  5); /* but they're very strong */
  AddStat   (A_IVISION, -ND_REL_STATE(ND_NOON, MAX_SUNBRIGHT));  /* can see in the darkness */
  AddStat (A_UVISION, ND_REL_STATE(ND_LATE_MORNING, MAX_SUNBRIGHT));
  SetLong   ( 
    "@@Pl_Name@@ is an orc. @@Pl_Poss@@ fur is like black velvet.\n"+
    "A pair of long fangs looks out of @@Pl_poss@@ mouth.\n");
  SetDesc (
"Orcs are humanoid. They are a bit smaller but also a bit\n\
stronger and tougher than humans. They are not very intelligent\n\
(some would call them dumb) and not very well educated. They are\n\
dexterous with weapons and some of them are very good weaponsmiths.\n\
Orcs have long hair and wonderful silky, black fur all over their\n\
body. They've got fangs like a wild boar and really like wearing\n\
clothes with many bright colors. Orcs run around looking like a \n\
small weaponry.\n");
  AddEquipment("sunglasses", "/obj/sunglasses", 0, 0, ({ "glasses" }));
}

/***************************************************************************/
