/* Advent - On Brink of Pit -- Mateese, 18-Aug-96
 *
 * East end of the passage to the lower parts of the Cave.
 * In the pit down here is some water.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int ExitClimb (string arg)

/* If the players tries to climb down the pit or enter it, 
 * transform it silently into a 'down' movement.
 */

{
  if (!arg)
  {
    notify_fail(capitalize(query_verb())+" what or where?\n");
    return 0;
  }
  if (!sizeof(norm_id(arg, 1) & ({ "down", "pit" }) ) )
  {
    notify_fail("That won't help.\n");
    return 0;
  }
  return UseExit("down", 0, M_GO);
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "On Brink of Pit");
  Set(P_INT_LONG,
"You are on the brink of a small clean climbable pit. A crawl leads west.\n"
     );
  Set(P_BRIGHT, 0);
    
  // Exits
  AddExit("west", ADVENT("r/dirtypassage"));
  AddExit("down", ADVENT("r/inpit"));
  AddExit(({ "climb", "enter" }), #'ExitClimb);
  HideExit(({ "climb", "enter" }), HIDE_ALWAYS);

  // Details
  AddOrigDetail(({"pit", "clean pit" }),
"It looks like you might be able to climb down into it.\n"
	   );
}

/*************************************************************************/
