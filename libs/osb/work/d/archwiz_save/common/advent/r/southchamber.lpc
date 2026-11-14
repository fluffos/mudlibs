/* Advent - South Side Chamber -- Mateese, 18-Aug-96
 *
 * The south chamber of the Hall of the Mountan King.
 * The precious jewelry is here.
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
  Set(P_INT_SHORT, "South Side Chamber");
  Set(P_INT_LONG,
"You are in the south side chamber.\n"
     );
  Set(P_BRIGHT, 0);
    
  // Exits
  AddExit("north", ADVENT("r/hallmtking"));

  // Items
  AddItem(ADVENT("o/treasure"), REFRESH_REMOVE
	 , ([ P_SHORT: "precious jewelry"
            , P_LONG: "The jewelry is all quite exquisite.\n"
            , P_IDS: ({ "jewelry", "jewels" })
            , P_ADS: ({ "some", "precious" })
            , P_WEIGHT: 220
            , P_VALUE: 500
            , P_TREASURE: F_JEWELRY /* Default XP */
           ])
	 );
}

/*************************************************************************/
