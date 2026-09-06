/* Advent - Complex Junction -- Mateese, 18-Aug-96
 *
 * The east of the three vital junctions in the lower cave.
 * To the west are Bedquilt and Swiss Cheese Room.
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
  Set(P_INT_SHORT, "Complex Junction");
  Set(P_INT_LONG,
"You are at a complex junction. A low hands and knees passage from the north "
"joins a higher crawl from the east to make walking passage going west. "
"There is also a large room above. The air is damp here.\n"
     );
  Set(P_BRIGHT, 0);
    
  // Exits
  AddExit("east", ADVENT("r/anteroom"));
  AddExit("north", ADVENT("r/shellroom"));
  AddExit("west", ADVENT("r/bedquilt"));
  AddExit("up", ADVENT("r/dustyrocks"));
    
  // Details
  AddOrigDetail(({"rock", "rocks", "dusty rock", "dusty rocks" })
	   , "They're just rocks. (Dusty ones, that is.)\n");
}

/*************************************************************************/
