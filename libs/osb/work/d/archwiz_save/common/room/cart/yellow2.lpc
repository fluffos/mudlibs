/* C.A.R.T. Yellow Line 2 -- Mateese, 10-Dec-95
 *
 * In the C.A.R.T. tunnel, twice east from Central Station, just before
 * the treasure dump site.
 * TODO: add the CART monster.
 */

#include <properties.h>
#include <rooms.h>
#include "path.h"

inherit "/std/room";

/*-----------------------------------------------------------------------*/

void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "C.A.R.T. Tunnel");
  Set(P_INT_LONG,
"The old C.A.R.T. tunnel runs deep under the earth from east to west. "
"Where once trains ran along, small creatures found their place.\n"
     );
  Set(P_INT_SMELL, "The air smells stale and earthy.\n");
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("west", CART("yellow1"));
  AddExit("east", CART("yellow3"));

  // Miscellaneous
  Set(P_CARTROOM, 1);

  // Details
  AddDetail(({ "track", "tracks", "rail", "rail tracks", "rails" }),
"The tracks run through the tunnel. In former times, C.A.R.T. trains ran "
"along them, but nowadays they left to rust and dirt.\n"
           );
  AddDetail( ({"rust", "stains of rust", "rust stains", "rust stain" }),
"Stains of rust are visible everywhere on the tracks.\n"
           );
  AddDetail( "dirt",
"Stones, sand, splinters of wood and other debris, scattered over the tracks.\n"
"Nothing interesting at all.\n"
           );
  AddDetail( ({ "wall", "walls", "ceiling" }),
"Raw, unblended rock forms the walls and the ceiling of the tunnel.\n"
	   );
  AddDetail("tunnel",
"The tunnel is quite old, but still trespassable. At one wall someone carved "
"a picture into the stone.\n"
           );
  AddDetail(({"picture", "face", "portrait", "carving" }),
"The carving portraits Randyandy, the former Archwizard of Building and "
"Transit.\n"
           );

  // Items

  // A random rat and bat.
  AddItem( ({ MONSTER("rat"), MONSTER("bat"), 0, 0}), REFRESH_DESTRUCT);
  AddItem( ({ MONSTER("bat"), MONSTER("rat"), 0, 0}), REFRESH_DESTRUCT);

}

/*************************************************************************/
