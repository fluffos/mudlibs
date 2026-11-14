/* C.A.R.T. Beach Station 2 -- Mateese, 10-Dec-95
 *
 * The old Beach Station of the C.A.R.T. Blue Line, now out of function.
 */

#include <config.h>
#include <properties.h>
#include <rooms.h>
#include <nightday.h>
#include <weather.h>
#include <doors.h>

#include "path.h"

inherit "/std/room";

/*-----------------------------------------------------------------------*/

void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "C.A.R.T. Beach Station");
  Set(P_INT_LONG,
"This is part of what was once the C.A.R.T. 'Beach Station'. "
"You find yourself standing on an elevated platform. It's quite windy up here "
"as the sea is nearby. The rails coming from the north end at this point. "
"Another platform is to the west.\n"
     );
  Set(P_INT_SMELL, "You smell the salty air from the Sea.\n");
  Set(P_INT_NOISE, "You hear the splashing of the waves far away.\n");

  // Exits
  AddExit("west", CART("beach"));

  // Miscellaneous
  Set(P_CARTROOM, 1);
  Set(P_INDOORS, 0);

  // Details
  AddDetail(({"rails","rail","rusty rails","rusty rail",
    "old rail","old rails"}),
"The rusty rails are corroding since they are no longer used.\n");
  AddDetail(({"platform","plateform","elevated plateform","elevated platform"}),
"You feel the wind blowing around you. You freeze.\n");
  AddDetail(({"wind","strong wind"}),"It is blowing around you.\n");
  AddDetail(({"air","salty air"}),"You may smell it.\n");
  AddDetail(({"wave","waves","sea"}),
"You cannot see anything of the Sea from here.\n");
  AddDetail(({"rust","old rust"}),"The rails look old and rusty.\n");
}

/*************************************************************************/
