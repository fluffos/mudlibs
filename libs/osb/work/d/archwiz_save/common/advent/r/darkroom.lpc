/* Advent - Dark Room -- Mateese, 21-Aug-96
 *
 * The Dark Room northeast of the Plover Room. Tricky part is to bring
 * a lamp into here, as the entrance to the Plover Room is restricted.
 * The Platinum Pyramid is here.
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
  Set(P_INT_SHORT, "Dark Room");
  Set(P_INT_LONG,
"You're in the dark room. A corridor leading south is the only exit.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("south", ADVENT("r/plover"));
    
  // Items
  AddItem(ADVENT("o/treasure"), REFRESH_REMOVE
	 , ([ P_SHORT: "a platinum pyramid"
            , P_LONG: "The platinum pyramid is 8 inches on a side.\n"
            , P_IDS: ({ "pyramid", "platin", "platinum" })
            , P_ADS: ({ "platin", "platinum" })
            , P_WEIGHT: 1500
            , P_VALUE: 1200
            , P_TREASURE: F_PYRAMID
            , P_XP: 1600
           ])
	 );
}

/*************************************************************************/
