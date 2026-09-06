/* Advent - Mirror Canyon -- Mateese, 23-Aug-96
 *
 * The Mirror Canyon north of the Secret N/S Canyon 0.
 * The mirror here is between the two Window On Pits and the true
 * reason for the 'shadowy figures'.
 * Further north is the Reservoir.
 * This whole section is deep below the Hall of Mists.
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
  Set(P_INT_SHORT, "Mirror Canyon");
  Set(P_INT_LONG,
"You are in a north/south canyon about 25 across. The floor is covered by "
"white mist seeping in from the north. The walls extend upward for well over "
"100 feet. Suspended from some unseen point far above you, an enourmous "
"two-sided mirror is hanging parallel to and midway between the canyon walls. "
"A small window can be seen in either wall, some fifty feet up.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_INT_NOISE, "Strange, splashing sounds come from the north.\n");

  // Exits
  AddExit("north", ADVENT("r/reservoir"));
  AddExit("south", ADVENT("r/s-nscanyon0"));
  
  // Details
  AddOrigDetail(({ "mirror", "enormous mirror" }),
"The mirror is obviously provided for the use of the dwarves, who, as you "
"know, are extremely vain.\n"
	   );
  AddOrigDetail(({ "mist", "wisps", "white mist", "white wisps" }),
"Mist is a white vapor, usually water, seen from time to time in caverns. "
"It can be found anywhere but is frequently a sign of a deep pit leading "
"down to water.\n"
	   );
  AddDetail(({"window", "windows" }),
"The windows are too far away to notice details.\n"
	   );
}

/*************************************************************************/
