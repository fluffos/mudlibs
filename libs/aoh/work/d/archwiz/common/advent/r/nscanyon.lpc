/* Advent - N/S Canyon -- Mateese, 19-Aug-96
 *
 * A canyon leading north to Swiss Cheese Room. Entrance is from above
 * from the Secret E/W Canyon.
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
  Set(P_INT_SHORT, "N/S Canyon");
  Set(P_INT_LONG,
"You are at a wide place in a very tight N/S canyon.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("north", ADVENT("r/tallewcanyon"));
  AddExit("south", ADVENT("r/canyondead"));
}

/*************************************************************************/
