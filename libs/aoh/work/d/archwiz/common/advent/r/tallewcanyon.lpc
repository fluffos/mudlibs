/* Advent - Tall E/W Canyon -- Mateese, 19-Aug-96
 *
 * The canyon south of Swiss Cheese coming from the N/S canyon.
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
  Set(P_INT_SHORT, "Tall E/W Canyon");
  Set(P_INT_LONG,
"You are in a tall E/W canyon. A low tight crawl goes 3 feet north and "
"seems to open up.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("north", ADVENT("r/swisscheese"));
  AddExit("east", ADVENT("r/nscanyon"));
  AddExit("west", ADVENT("r/deadewcanyon"));
}

/*************************************************************************/
