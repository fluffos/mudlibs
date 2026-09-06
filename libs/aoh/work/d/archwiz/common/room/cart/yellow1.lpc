/* C.A.R.T. Yellow Line 1 -- Mateese, 10-Dec-95
 *
 * In the C.A.R.T. tunnel, right east from Central Station.
 * It is lit by stray light from central station (thus it is still dependant
 * from sunlight).
 */

#include <config.h>
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
"The old C.A.R.T. tunnel runs from east to west. In the west the dim light "
"of Central Station can be seen, to the east it is all dark. "
"Every now and then a light swift in the air can be felt.\n"
     );

  // The lighting depends on the actual sunlight (shining through the opening
  // in the west), so pretend that we're an outdoors room.
  // The details for 'sky' and 'heaven' need to be deactivated.
  Set(P_OUTDOORS, 1);
  Set(P_BRIGHT, (2 * MAX_SUNBRIGHT) / 100);
  Set(P_SUNBRIGHT, (3 * MAX_SUNBRIGHT) / 100);
  AddDetail (({ "sky", "heaven" }), "You can't see it here.\n");

  // Exits
  AddExit("west", CART("central"));
  AddExit("east", CART("yellow2"));

  // Miscellaneous
  Set(P_CARTROOM, 1);

  // Details
  AddDetail(({"central", "station", "central station" }),
"Central Station, former hub of the C.A.R.T. system, lies to the west. "
"It's illumination casts a dim light into the tunnel.\n"
           );
  AddDetail(({"light", "dim light" }),
"The dim light falling in from the west is emitted by the illumination "
"of Central Station.\n"
           );
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
  AddDetail("tunnel",
"The tunnel is quite old, but still trespassable.\n"
           );

  // Items

  // A partly random number of bats.
  AddItem( ({ MONSTER("bat"), MONSTER("bat"), 0, 0})
         , REFRESH_DESTRUCT, 0, 2);

}

/*-----------------------------------------------------------------------*/
varargs mixed * FilterWeatherData(object client, mixed *data, int newstate) 

/* This function is called by the nightday-Server when it notifies
** the players here. We return 0 to suppress all messages.
*/

{
  return 0;
}

/*************************************************************************/
