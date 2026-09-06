/* Advent - East Pit -- Mateese, 19-Aug-96
 *
 * The pit in the east end of the twopit room. The oil for the door between
 * the Immense N/S passage and Cavern with Waterfall can be found here.
 * The hole above is pure decoration.
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
  Set(P_INT_SHORT, "East Pit");
  Set(P_INT_LONG,
"You are the bottom of the eastern pit in the twopit room.\n"
"There is a small pool of oil in one corner of the pit.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);

  // Exits
  AddExit("up", ADVENT("r/easttwopit"));
  AddNowayMsg("up", "The hole is too far up for you to reach.\n");

  // Details
  AddOrigDetail(({ "hole", "large hole" })
               , "The hole is in the wall above you.\n");
    
  // Items
  AddItem(ADVENT("o/water"), REFRESH_REMOVE
	 , ([ P_SHORT: "a pool of oil"
            , P_LONG: "It looks like ordinary oil.\n"
            , P_IDS: ({ "oil" })
            , P_ADS: ({ "pool", "of" })
            , P_DRINK: 1
            , P_POISON: 5
            , P_FD_MSG1: "You drink from the pool of oil. Yuck!\n"
            , P_INVIS: 0
           ])
	 );
}

/*************************************************************************/
