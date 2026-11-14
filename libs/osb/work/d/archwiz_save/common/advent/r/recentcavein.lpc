/* Advent - Recent Cave-in -- Mateese, 20-Aug-96
 *
 * A dead end east of the Giant Room.
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
  Set(P_INT_SHORT, "Recent Cave-in");
  Set(P_INT_LONG,
"The passage here is blocked by a recent cave-in.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("west", ADVENT("r/giantroom"));
}

/*************************************************************************/
