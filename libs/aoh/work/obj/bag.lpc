/* /obj/bag
**
** A standard bag to clone.
** If want to make your own normal bags, you still have to inherit this since
** it contains the 'official' weight factor.
**
**  05-Oct-92 [Mateese]
**  07-Oct-94 [Mateese] Inherits /std/room/items as well.
*/

#include <properties.h>

inherit "/std/room/items"; // reset() is here
inherit "/std/container";

/*-------------------------------------------------------------------------
** Initialize us.
*/

void create () {

  ::create();
  SetShort ("a bag");
  SetLong ("A simple bag.\n");
  SetIntShort ("inside a bag");
  SetIntLong ("You are in a bag.\n");
  SetPreContent("It contains:\n");
  SetValue (12);
  SetWeight (1000);
  AddId ("bag");
  SetMaxWeight (3500); /* We can carry up to 2.5 kg, makes a total of 3.5 kg */
  SetTransparent (1000);  /* The bag is opaque */
  SetWeightChg (500);  /* The bag halfs the weight. */
  Set(P_HELP_MSG,
"The bag can hold a few small things, making carrying them around easier.\n"
"Simply put the things into it or take them out again.\n"
     );
}

int IsObjBag() { return 1; }

/*************************************************************************/
