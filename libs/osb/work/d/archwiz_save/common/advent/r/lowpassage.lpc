/* Advent - Low N/S Passage -- Mateese, 18-Aug-96
 *
 * A low passage, connecting the Hall of the Moutain King with Y2.
 * The Bars of Silver are here.
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
  Set(P_INT_SHORT, "Low N/S Passage");
  Set(P_INT_LONG,
"You are in a low N/S passage at a hole in the floor. The hole goes down "
"to a E/W passage.\n"
     );
  Set(P_BRIGHT, 0);
    
  // Exits
  AddExit("north", ADVENT("r/y2"));
  AddExit("south", ADVENT("r/hallmtking"));
  AddExit("down", ADVENT("r/dirtypassage"));

  // Items
  AddItem(ADVENT("o/treasure"), REFRESH_REMOVE
	 , ([ P_SHORT: "bars of silver"
            , P_LONG: "The bars of silver are probably worth a fortune.\n"
            , P_IDS: ({ "bars", "silver" })
            , P_ADS: ({ "bars of" })
            , P_WEIGHT: 4000
            , P_VALUE: 1000
            , P_TREASURE: F_SILVER /* Default XP */
           ])
	 );
}

/*************************************************************************/
