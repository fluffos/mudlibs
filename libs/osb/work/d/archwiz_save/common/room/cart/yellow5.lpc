/* C.A.R.T. Yellow Line 5 -- Mateese, 10-Dec-95
 *
 * The tunnel opening where the yellow line vanishes underground
 * (resp. appears from underground :-)
 */

#include <properties.h>
#include "path.h"

inherit "/std/room";

/*-----------------------------------------------------------------------*/

void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "C.A.R.T. Track surfacing");
  Set(P_INT_LONG,
"The rail track of an old C.A.R.T. line ascends from west, emerging "
"from a tunnel underground, to east to the elevated structure of "
"the Beach Station.\n"
"Southwards the jetty connecting Nightfall City with the port can be seen.\n"
     );

  // Exits
  AddExit("east", CART("beach"));
  AddExit("west", CART("yellow4"));

  // Miscellaneous
  Set(P_INDOORS, 1);
  Set(P_CARTROOM, 1);

  // Details
  AddDetail(({ "track", "tracks", "rail", "rail tracks", "rails" }),
"The tracks slope down from the east to the west. The lack of use lead "
"to a certain rusting, but they still hold firm.\n"
           );
  AddDetail( ({"rust", "stains of rust", "rust stains", "rust stain" }),
"Stains of rust are visible everywhere on the tracks.\n"
           );
  AddDetail( "tunnel",
"The tunnel leads underground, with the tracks vanishing in the darkness.\n"
           );
  AddDetail(({"station", "beach station"
             , "C.A.R.T. station", "CART station", "C.A.R.T.", "CART" })
           , "An old station of the C.A.R.T. network.\n"
           );
  AddDetail("jetty",
"The jetty runs east-west between Nightfall City and the port. You can't "
"reach it from here.\n"
           );

  // Items
}

/*************************************************************************/
