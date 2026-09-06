/* Advent - After the Entrance Grate -- Mateese, 14-Aug-96
 *
 * The room immediately after the Entrance Grate.
 * In the original this was named 'Below the Grate' and was lighted, but we
 * are already beneath the surface...
 * To the east, the Hall of Fame has been added.
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
  Set(P_INT_SHORT, "After the Grate");
  Set(P_INT_LONG,
"You are in a small chamber beneath the earth. A low crawl over cobbles "
"leads further inwards to the west. A streambed coming from north ends here. "
"A new passage leads away east.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);

  // Exits
  AddDoor("north", ADVENT("r/subtoutgrate"), ([]), ADVENT("o/grate"));
  AddExit("west", ADVENT("r/cobblecrawl"));
  AddExit("east", ADVENT("r/halloffame")); /* NIGHTFALL */

  // Details
  AddOrigDetail(({ "bed", "streambed", "rocky bed", "rocky streambed" }),
"A rocky bed for a stream, now dried out. Coming from the north, it turns "
"west here and vanishes under the cobbles.\n"
	   );
  AddOrigDetail(({ "cobble", "cobbles" "cobblestones", "cobblestone"
	         , "stone", "stones" }),
"They are just ordinary cobbles.\n"
	   );
  AddDetail(({"crawl", "low crawl" }),
"The way further inwards leads through a low passage west.\n"
	   );
  AddDetail(({"passage", "east passage", "new passage" }),
"The passage appears hewn out of the rock quite recently.\n"
	   );
}

/*************************************************************************/
