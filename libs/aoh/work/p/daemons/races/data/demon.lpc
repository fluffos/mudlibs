/* obj/race/demon
*/

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

  SetAlign  (-500);
  SetFood   (100);
  SetDrink  (100);
  SetAlc    (10); /* can't stand much of it */
  SetWeight (80000);
  SetSize(PSIZE_LARGE);
  SetDef    (1);
  SetHome(STARTROOM);
  AddHand   ("right claw", 2);
  AddHand   ("left claw", 2);
  AddHand   ("tail", 2); /* something to make demons unique */
  /* Make the tail a natural weapon, not a real hand */
  racedata[RD_HANDS][2][HAND_WEAPON] = 1;
  AddAttr("MagicDefence",25);
  AddStat   (A_CON, -3);
  AddStat   (A_DEX,  3);
  AddStat   (A_INT,  3); /* demons are by definition magical creatures */
  AddStat   (A_STR, -3); /* but no beasts of burden :) */
  AddStat   (A_IVISION, -(2*MAX_SUNBRIGHT));  /* can see in the darkness */
  AddStat   (A_UVISION, (MAX_SUNBRIGHT));
  SetLong   ( 
    "@@Pl_Name@@ is a demon. @@Pl_Poss@@ body is glowing dark red.\n"
    +"A long clawed tail is flapping from @@Pl_poss@@ back.\n"
            );
  SetDesc ("\
Demons are pure unadulterated evil.  Their bodies are formed of the\n\
flames of hell, and their souls forged of the evilest sins cast by\n\
the mortals of OSB!  As demons evolve, they go to plastic surgeons\n\
to alter their appearance, each assuming its own unique form.\n\
Intelligent and tough, these creatures wander the dark caves of OSB\n\
searching for their next victims.  They despise the sunlight, and as part\n\
of their curse can rarely drink very much.  However, these demons fight\n\
viciously with their deadly claws and prehensile tail.\n\
As minions of evil, they are best avoided in fights.\n\
");
  AddEquipment("sunglasses", "/obj/sunglasses", 0, 0, ({ "glasses" }));
}

/***************************************************************************/
