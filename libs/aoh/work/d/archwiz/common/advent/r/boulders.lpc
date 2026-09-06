/* Advent - Chamber of Boulders -- Mateese, 25-Aug-96
 *
 * The Chamber of Boulders, east of the Junction with Warm Walls.
 * The Rare Spices are here.
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
  Set(P_INT_SHORT, "Chamber of Boulders");
  Set(P_INT_LONG,
"You are in a small chamber filled with large boulders. The walls are very "
"warm, causing the air in the room to be almost stifling from the heat.\n"
"The only exit is a crawl heading west, through which is coming a low "
"rumbling.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_INT_NOISE, "A low rumbling can be heard from west.\n");
  Set(P_NODWARF, 1);
    
  // Exits
  AddExit("west", ADVENT("r/warmjunct"));

  // Details
  AddOrigDetail(({"boulders", "boulder", "rocks", "rock" }), 
"They are ordinary boulders. They're warm.\n"
	   );
    
  // Items
  AddItem(ADVENT("o/treasure"), REFRESH_REMOVE
	 , ([ P_SHORT: "some rare spices"
            , P_LONG: "A selection of rare spices.\n"
            , P_IDS: ({ "rare", "spice", "spices" })
            , P_ADS: ({ "selection of", "some", "rare", "exotic" })
            , P_WEIGHT: 50
            , P_VALUE: 250
            , P_TREASURE: F_SPICES
            , P_XP: 1600
            , P_SMELL: "They smell wonderfully exotic.\n"
           ])
	 );
}

/*************************************************************************/
