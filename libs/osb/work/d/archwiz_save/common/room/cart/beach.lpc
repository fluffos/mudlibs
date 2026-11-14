/* C.A.R.T. Beach Station -- Mateese, 10-Dec-95
 *
 * The old Beach Station of the C.A.R.T. Yellow Line, now out of function.
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
"This was once the C.A.R.T. Station called 'Beach Station'. It still is in a "
"good condition. You find yourself standing on an elevated platform. It's "
"quite windy up here as the sea is nearby. The rails coming from the west "
"end at this point. Another platform is to the east, and to the south is "
"the entrance of the C.A.R.T. museum. "
"An iron staircase leads down.\n"
     );
  Set(P_INT_SMELL, "You smell the salty air from the Sea.\n");
  Set(P_INT_NOISE, "You hear the splashing of the waves far away.\n");

  // Exits
  AddExit("east", CART("beach2"));
  AddExit("down", CITY("vill_shore2"));
  AddExit("west", CART("yellow5"));  HideExit("west", HIDE_ALWAYS);
  AddDoor("south", MUSEUM("entrance"),"wooden door",
    "An old weatherbeaten door.\n", 0, DOOR_STATUS_CLOSED);

  // Miscellaneous
  Set(P_CARTROOM, 1);
  Set(P_INDOORS, 0);

  // Details
  AddDetail(({"rails","rail","rusty rails","rusty rail",
    "old rail","old rails"}),
"The rails are quietly rusting along since they are no longer used. "
"Despite that, they are still holding and would allow passage along them "
"to the west, where in some distance the track vanishes underground.\n"
           );
  AddDetail(({"platform","plateform","elevated plateform","elevated platform"}),
"You feel the wind blowing around you. You freeze.\n");
  AddDetail(({"wind","strong wind"}),"It is blowing around you.\n");
  AddDetail(({"entrance","museum"}),"You may enter the museum to the south.\n");
  AddDetail(({"air","salty air"}),"You may smell it.\n");
  AddDetail(({"wave","waves","sea"}),
"You cannot see anything of the Sea from here.\n");
  AddDetail(({"staircase","iron staircase"}),
"You see the shore at the lower end of the staircase.\n");
  AddDetail(({"iron","white painted iron","white iron"}),
"The staircase is made of white painted iron. It looks precious.\n");
  AddDetail(({"rust","old rust"}),"The rails look old and rusty.\n");
}

/*************************************************************************/
