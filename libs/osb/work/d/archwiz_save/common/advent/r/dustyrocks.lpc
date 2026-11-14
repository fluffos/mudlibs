/* Advent - Dusty Rock Room -- Mateese, 18-Aug-96
 *
 * West end of the passage below the Low N/S Passage. Down here is the
 * Complex Junction and the lower parts of the cave in general.
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
  Set(P_INT_SHORT, "Dusty Rock Room");
  Set(P_INT_LONG,
"You are in a large room full of dusty rocks. There is big hole in the floor. "
"There are cracks everywhere, and a passage leading east.\n"
     );
  Set(P_BRIGHT, 0);
    
  // Exits
  AddExit("east", ADVENT("r/dirtypassage"));
  AddExit("down", ADVENT("r/complexjunct"));
    
  // Details
  AddOrigDetail(({"rock", "rocks", "dusty rock", "dusty rocks" })
	   , "They're just rocks. (Dusty ones, that is.)\n");
}

/*************************************************************************/
