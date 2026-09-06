/* Advent - Large Low Room -- Mateese, 19-Aug-96
 *
 * This room allows alternate access to the oriental room and connects
 * the chasm part of the cave.
 * It can be reached one-way from the Steep Incline after the Cavern with
 * Waterfall and randomly from Bedquilt.
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
  Set(P_INT_SHORT, "Large Low Room");
  Set(P_INT_LONG,
"You are in a large low room. Crawls lead north, southeast and southwest.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("north", ADVENT("r/deadcrawl"));
  AddExit("southwest", ADVENT("r/slopingcorr"));
  AddExit("southeast", ADVENT("r/oriental"));
}

/*************************************************************************/
