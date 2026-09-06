/* Advent - Dirty Passage -- Mateese, 18-Aug-96
 *
 * A dirty passage down below the Low N/S Passage. To the east is just
 * a pit, to the west the way leads to the Complex Junction, Bedquilt
 * and the lower parts of the cave.
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
  Set(P_INT_SHORT, "Dirty Passage");
  Set(P_INT_LONG,
"You are in a dirty broken passage. To the east is a crawl. The the west "
"is a larger passage. Above you is a hole to another passage.\n"
     );
  Set(P_BRIGHT, 0);
    
  // Exits
  AddExit("east", ADVENT("r/onbrinkpit"));
  AddExit("up", ADVENT("r/lowpassage"));
  AddExit("west", ADVENT("r/dustyrocks"));
}

/*************************************************************************/
