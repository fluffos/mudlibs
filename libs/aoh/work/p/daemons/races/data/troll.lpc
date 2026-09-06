/* obj/race/troll
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

  SetAlign  (-10); /* They start quite nasty */
  SetFood   (100);
  SetDrink  (100);
  SetAlc    (200);
  SetWeight (80000);
  SetSize(PSIZE_LARGE);
  SetDef    (1);
  SetHome(STARTROOM);
  AddHand   ("right hand", 2);
  AddHand   ("left hand", 2);
  AddAttr("MagicDefence",0);
  AddStat   (A_CON,  3); /* Good constitution */
  AddStat   (A_DEX, -1); /* Less dexterity */
  AddStat   (A_INT, -6); /* Have nothing to do with magic */
  AddStat   (A_STR,  4); /* but they're very strong */
  AddStat   (A_IVISION, -(MAX_SUNBRIGHT));  /* can see in the darkness */
  AddStat (A_UVISION, ND_REL_STATE(ND_LATE_MORNING, MAX_SUNBRIGHT));
  SetLong   ( 
    "@@Pl_Name@@ is a troll. @@Pl_Poss@@ eyes are glowing and @@Pl_poss@@ body \n"+
    "looks dangerous. A pair of long teeth look out of @@Pl_poss@@ mouth.\n");
  SetDesc ("Trolls are big, strong but dull. They're good at fighting but bad at\n"+
           "thinking. They can see in darkness but fear the light of the sun.\n");
  AddEquipment("sunglasses", "/obj/sunglasses", 0, 0, ({ "glasses" }));
}

/***************************************************************************/
