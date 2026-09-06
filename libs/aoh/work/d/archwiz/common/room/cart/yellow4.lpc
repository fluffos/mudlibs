/* C.A.R.T. Yellow Line 4 -- Mateese, 10-Dec-95
 *
 * In the C.A.R.T. tunnel between the Dump Site and the Beach Station.
 * Quite far underground, so the sunlight has only limited effect.
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
"The old C.A.R.T. tunnel runs from east to west. Far in the east a small "
"patch of non-darkness can be seen. The rail tracks are rusted and covered "
"with dirt.\n"
     );
  Set(P_INT_NOISE, "It is silent except for silent trips of small feet.\n");

  // The lighting depends on the actual sunlight (shining through the opening
  // in the west), so pretend that we're an outdoors room.
  // The details for 'sky' and 'heaven' need to be deactivated.
  Set(P_OUTDOORS, 1);
  Set(P_SUNBRIGHT, (5 * MAX_SUNBRIGHT) / 100);
  AddDetail (({ "sky", "heaven" }), "You can't see it here.\n");

  // Exits
  AddExit("east", CART("yellow5"));
  AddExit("west", CART("yellow3"));

  // Miscellaneous
  Set(P_CARTROOM, 1);

  // Details
  AddDetail(({ "track", "tracks", "rail", "rail tracks", "rails" }),
"The tracks run through the tunnel, slightly ascending to the east. "
"In former times, C.A.R.T. trains ran along them, but nowadays they left "
"to rust and dirt.\n"
           );
  AddDetail( ({"rust", "stains of rust", "rust stains", "rust stain" }),
"Stains of rust are visible everywhere on the tracks.\n"
           );
  AddDetail( "dirt",
"Stones, sand, splinters of wood and other debris, scattered over the tracks.\n"
"Nothing interesting at all.\n"
           );
  AddDetail("tunnel",
"The tunnel is quite old, but still trespassable. Its level raises to the east.\n"
           );
  AddDetail(({"patch", "non-darkness", "patch of non-darkness"}),
"You see a small part of the sky - the tunnel seems to lead to the surface "
"in the east.\n"
           );

  // Items

  // A partly random number of rats.
  AddItem( ({ MONSTER("rat"), MONSTER("rat"), 0, 0})
         , REFRESH_ALWAYS, 0, 4);

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
