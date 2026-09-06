/* Advent - East End of Long Hall -- Mateese, 17-Aug-96
 *
 * East of here is the Hall of Mists.
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
  Set(P_INT_SHORT, "East End of Long Hall");
  Set(P_INT_LONG,
"You are at the east end of a very long hall, apparently without side "
"chambers. To the east a low wide crawl slants up. To the north a round "
"two foot hole slants down.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("west", ADVENT("r/westlonghall"));
  AddExit(({"east", "up"}), ADVENT("r/westhallmists"));
  AddExit(({"north", "down"}), ADVENT("r/crossover"));
  HideExit(({"up", "down"}), HIDE_ALWAYS);
}

/*************************************************************************/
