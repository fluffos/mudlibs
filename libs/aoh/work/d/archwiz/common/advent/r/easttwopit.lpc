/* Advent - East End of Twopit Room -- Mateese, 18-Aug-96
 *
 * The east end of the twopit room. East is the Swiss Cheese Room.
 * In the pit here is the lake of oil, which can be used to oil the hinges
 * of the door between the Immense N/S Passage and the Cavern with Waterfall.
 * The hole above is pure decoration.
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
  Set(P_INT_SHORT, "East End of Twopit Room");
  Set(P_INT_LONG,
"You are at the east end of the twopit room. The floor here is littered "
"thin rock slabs, which make it easy to descend the pits. There is a path "
"here bypassing the pits to connect passages from east and west.\n"
"There are holes all over, but the only big one is on the wall directly "
"over the west pit where you can't get to it.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("east", ADVENT("r/swisscheese"));
  AddExit("west", ADVENT("r/westtwopit"));
  AddExit("down", ADVENT("r/eastpit"));
  AddNowayMsg("up", "The hole is too far up for you to reach.\n");

  // Details
  AddOrigDetail(({ "slabs", "thin slabs", "rock slabs", "thin rock slabs" })
           , "They almost form natural stairs down into the pit.\n"
	   );
  AddOrigDetail(({ "hole", "large hole" })
               , "The hole is in the wall above you.\n");
}

/*************************************************************************/
