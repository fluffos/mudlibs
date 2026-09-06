/* Advent - Golden Nugget Room -- Mateese, 17-Aug-96
 *
 * The golden nugget is found here.
 * To bring it outside, the player has to use the Y2 second entrance.
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
  Set(P_INT_SHORT, "Low Room");
  Set(P_INT_LONG,
"This is a low room with a crude note on the wall:\n"
"  'You won't get it up the steps'.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("north", ADVENT("r/hallofmists"));
  
  // Details
  AddOrigDetail(({ "note", "crude note" })
           , "The note says, 'You won't get it up the steps'.\n"
	   );
    
  // Items
  AddItem(ADVENT("o/treasure"), REFRESH_REMOVE
	 , ([ P_SHORT: "a large gold nugget"
            , P_LONG: "It's a large sparkling nugget of gold.\n"
            , P_IDS: ({ "nugget", "gold", ADV_NUGGET })
            , P_ADS: ({ "large", "nugget of" })
            , P_WEIGHT: 5000
            , P_VALUE: 2000
            , P_TREASURE: F_NUGGET /* Default XP */
            , ADV_NUGGET: 1
           ])
	 );
}

/*************************************************************************/
