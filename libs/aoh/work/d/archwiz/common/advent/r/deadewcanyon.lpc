/* Advent - Dead End of E/W Canyon -- Mateese, 19-Aug-96
 *
 * A dead end north/west of the Tall E/W Canyon.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Dead End");
  Set(P_INT_LONG,
"The canyon runs into a mass of boulders -- dead end.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("south", ADVENT("r/tallewcanyon"));
}

/*************************************************************************/
