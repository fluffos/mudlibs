/* Advent - Bird Chamber -- Mateese, 17-Aug-96
 *
 * The chamber housing the little bird.
 * This is also the second exit from the Alike Maze (from At Brink of Pit).
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Orange River Chamber");
  Set(P_INT_LONG,
"You are in a splendid chamber thirty feet high. The walls are frozen "
"rivers of orange stone. An awkward canyon and a good passage exit "
"from east and west sides of the chamber.\n"
     );
  Set(P_NODWARF, 1);
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("east", ADVENT("r/awkewcanyon"));
  AddExit("west", ADVENT("r/topsmallpit"));
    
  // Items
  AddItem(ADVENT("o/bird"), REFRESH_REMOVE, (["RefreshRemoveOk":1]));
    
  // Details
  AddDetail("canyon", "An awkward sloping canyon exits east from the chamber.\n");
  AddDetail("passage", "A good passage exits west from the chamber.\n");
  AddDetail(({"wall", "walls", "river", "rivers", "rivers of stone"
             , "rivers of orange stone", "orange stone", "stone" })
, "The walls look as like a river which gradually froze into stone. "
  "The stone itself is of orange colour.\n"
	   );
}

/*************************************************************************/
