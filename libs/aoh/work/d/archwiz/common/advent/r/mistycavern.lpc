/* Advent - Misty Cavern -- Mateese, 21-Aug-96
 *
 * The Misty Cavern connecting the Oriental Room with the Alcove and
 * the Emerald section.
 * Below is the Reservoir, above the Hall of Mists (notice the fissure?).
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
  Set(P_INT_SHORT, "Misty Cavern");
  Set(P_INT_LONG,
"You are following a wide path around the outer edge of a large cavern. "
"Far below, through a heavy white mist, strange splashing noises can be heard. "
"The mist rises up through a fissure in the ceiling.\n"
"The path exits to the south and west.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_INT_NOISE, "Strange splashing noises can be heard from below.\n");

  // Exits
  AddExit("west", ADVENT("r/alcove"));
  AddExit("south", ADVENT("r/oriental"));

  // Details
  AddOrigDetail(({ "fissure" , "ceiling" }),
"You can't really get close enough to examine it.\n"
	   );
  AddOrigDetail(({ "mist", "wisps", "white mist", "white wisps" }),
"Mist is a white vapor, usually water, seen from time to time in caverns. "
"It can be found anywhere but is frequently a sign of a deep pit leading "
"down to water.\n"
	   );
    
  // Items
  AddItem(ADVENT("o/mingvase"), REFRESH_REMOVE);
}

/*************************************************************************/
