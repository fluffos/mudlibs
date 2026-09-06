/* Advent - Cobble Crawl -- Mateese, 15-Aug-96
 *
 * A small passage linking the entrance with the inner cave.
 * The wicker cage to catch the small bird in the Bird Chamber (r/birdchamber)
 * is here.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Cobble Crawl");
  Set(P_INT_LONG,
"You are crawling over cobbles in a low passage.\n"
/* "There is a dim light at the east end of the passage." doesn't apply
 * for us, as the 'After the Grate' room is not lighted.
 */
     );
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);

  // Exits
  AddExit("east", ADVENT("r/aftergrate"));
  AddExit("west", ADVENT("r/debrisroom"));

  // Details
  AddOrigDetail(({ "cobble", "cobbles", "cobblestones", "cobblestone"
	         , "stone", "stones" }),
"They are just ordinary cobbles.\n"
	   );
  
  // Items
  AddItem(ADVENT("o/wickercage"), REFRESH_REMOVE);
}

/*************************************************************************/
