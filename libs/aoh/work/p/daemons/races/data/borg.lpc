/* testrace by Thon
   Borrowed by Tune and values modified */

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

  SetAlign  (-1000);
  SetFood   (1000);
  SetDrink  (1000);
  SetAlc    (2000); 
  SetWeight (85000);
  SetSize(PSIZE_LARGE);
  SetDef    (1);
  SetHome(STARTROOM);
  AddHand   ("right hand", 1);
  AddHand   ("left hand", 1);

  AddAttr("MagicDefence",10);
  AddStat   (A_CON, 300);
  AddStat   (A_DEX, 100);  // drones shouldn't be very agile
  AddStat   (A_INT, 300);
  AddStat   (A_STR, 349);
  AddStat   (A_WIS, 249);
  AddStat   (A_CHA, 200);
  AddStat   (A_AGI, 100);
  AddStat   (A_QUI, 200); 
  AddStat   (A_IVISION, -(50*MAX_SUNBRIGHT));  /* can see in the darkness */
  AddStat   (A_UVISION, (1500 * MAX_SUNBRIGHT) / 2);
  SetLong   ( 
    "@@Pl_Name@@ is a Borg Drone. @@Pl_Poss@@ full title is @@Pl_Name@@ of 10, "
    "Tertiary Adjunct to Unimatrix 2. @@Pl_Poss@@ skin is pale and studded with "
    "implants, @@Pl_poss@@ uniform black.\n"
            );
  SetDesc ("\
Drones are members of the Borg Collective.\n\
");
  AddEquipment("sunglasses", "/obj/sunglasses", 0, 0, ({ "glasses" }));
}

void InitRace(object player)
{
   player->cmd_title("the new Borg. Resistance is futile.");
}
/***************************************************************************/
