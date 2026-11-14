/* Advent - NE Side of Chasm -- Mateese, 25-Aug-96
 *
 * The northeast side of the chasm.
 * Further to the north is the volcano and the bear.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/chasm");

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "NE Side of Chasm");
  Set(P_INT_LONG,
"You are on the far side of the chasm. A northeast path leads away from "
"the chasm on this side.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);

  // Exits
  AddExit("northeast", ADVENT("r/corridor"));

  setup("southwest", ADVENT("r/swchasm"));
}

/*************************************************************************/
