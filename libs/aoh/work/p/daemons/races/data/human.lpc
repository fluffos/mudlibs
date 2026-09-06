/* obj/race/human
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

  SetAlign  (0);
  SetFood   (100);
  SetDrink  (100);
  SetAlc    (100);
  SetSize(PSIZE_NORMAL);
  SetDef    (0);
  SetHome(STARTROOM);
  SetWeight (75000);
  AddHand   ("right hand", 1);
  AddHand   ("left hand", 1);
  AddAttr("MagicDefence",10);
  AddStat   (A_CON, 0);
  AddStat   (A_DEX, 0);
  AddStat   (A_INT, 0);
  AddStat   (A_STR, 0);
  AddStat   (A_IVISION, ND_REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  AddStat   (A_UVISION, 3 * MAX_SUNBRIGHT);
  SetLong(
    "@@Pl_Name@@ is a human. @@Pl_Pro@@ is of medium size. Every giant "
    "would look down to @@Pl_obj@@, but every dwarf or gnome has to put "
    "his/her head back to look up to @@Pl_obj@@. If someone likes humans "
    "@@Pl_Name@@ would for sure catch their attention.\n"
   );
  SetDesc(
    "Humans are the most versatile of all races. There is nothing in the "
    "world of OSB a human could not learn. Ok, they have no special powers "
    "when they start, but they haven't any disadvantages either. A human "
    "is nearly everywhere welcome in OSB though orcs have different reasons "
    "and thoughts about this welcome than most other races. So if you "
    "are not sure whether you want to be a magician or not, if you want "
    "to be a perfect jack of all trades then a human is the race you "
    "should prefer most.\n"
);
  AddEquipment("torch", "/obj/torch", 0, 0, ({ "lamp", "lantern" }));
  SetInfo(
  "Humans have no special features but also no known disadvantages.\n");
}

/***************************************************************************/
