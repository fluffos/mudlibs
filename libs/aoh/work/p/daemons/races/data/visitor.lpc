/* obj/race/visitor
**
** Visitors are new players which haven't decided on a race yet.
*/

#include <races.h>
#include <attributes.h>
#include <stdrooms.h>
#include <stdrooms.h>

inherit RACEOBJ;

/*-------------------------------------------------------------------------*/

void create() {
  ::create ();

  SetAlign  (0);
  SetFood   (100);
  SetDrink  (100);
  SetAlc    (100);
  SetWeight (75000);
  AddHand   ("right hand", 1);
  AddHand   ("left hand", 1);
  SetDef    (0);
  SetHome   ( NEWBIEROOM );
  SetLong   (
 "You see @@Pl_Name@@, a new player in OSB. @@Pl_Poss@@ body is just\n"
+"an unshaped gathering of mist in the air.\n"
            );
  AddStat   (A_CON, 0);
  AddStat   (A_DEX, 0);
  AddStat   (A_INT, 0);
  AddStat   (A_STR, 0);
  AddStat   (A_WIS, 0);
  AddStat   (A_CHA, 0);
  AddStat   (A_AGI, 0);
  AddStat   (A_QUI, 0);
  AddStat   (A_IVISION, 0);
  AddStat   (A_UVISION, 3 * MAX_SUNBRIGHT);
  SetDesc ("Aren't we all visitors somehow?\n");
}

/***************************************************************************/
