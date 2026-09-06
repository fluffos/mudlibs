/* Advent - Junction of Three -- Mateese, 19-Aug-96
 *
 * A junction of three secret canyons. North is the West Window on Pit,
 * southeast the Bedquilt, south the Secret Canyon to the Top of Stalactite.
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
  Set(P_INT_SHORT, "Junction of Three Secret Canyons");
  Set(P_INT_LONG,
"You are in a secret canyon at a junction of three canyons, bearing north, "
"south and southeast. The north one is as tall as the other two combined.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("north", ADVENT("r/westpitwindow"));
  AddExit("south", ADVENT("r/s-nscanyon1"));
  AddExit("southeast", ADVENT("r/bedquilt"));
}

/*************************************************************************/
