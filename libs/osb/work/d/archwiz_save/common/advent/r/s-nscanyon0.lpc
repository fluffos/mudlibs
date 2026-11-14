/* Advent - Secret N/S Canyon 0 -- Mateese, 19-Aug-96
 *
 * Over the Slab Room, this canyon leads north to the reservoir and south
 * to the Secret Canyon with the dragon. After the dragon one can reach
 * the Hall of the Mt King again.
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
  Set(P_INT_SHORT, "Secret N/S Canyon");
  Set(P_INT_LONG,
"You are in a secret N/S canyon above a large room.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("north", ADVENT("r/mirrorcanyon"));
  AddExit("south", ADVENT("r/s-canyon"));
  AddExit("down", ADVENT("r/slabroom"));
}

/*************************************************************************/
