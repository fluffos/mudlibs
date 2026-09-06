/* Advent - At Brink of Pit -- Mateese, 16-Aug-96
 *
 * Near the end of the Alike Maze, here is a side-exit to the Bird Chamber.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int ExitClimb (string arg)
{
  if (!arg)
  {
    notify_fail("Climb what or where?\n");
    return 0;
  }
  if (!sizeof(norm_id(arg, 1) & ({ "down", "orange", "column" }) ) )
  {
    notify_fail("That won't help.\n");
    return 0;
  }
  return UseExit("down", 0, M_GO);
}

/*-----------------------------------------------------------------------*/
void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "At Brink of Pit");
  Set(P_INT_LONG,
"You are on the brink of a thirty foot pit with a massive orange column "
"down one wall. You could climb down here but you could not get back up.\n"
"The maze continues at this level.\n"
     );
  Set(P_BRIGHT, 0);
    
  // Exits
  Set(P_VMASTER, ADVENT("r/alikemaze"));
  AddExit("down", ADVENT("r/birdchamber"));
  AddExit("north", ADVENT("r/amaze012"));
  AddExit("east", ADVENT("r/amaze013"));
  AddExit("south", ADVENT("r/amaze106"));
  AddExit("west", ADVENT("r/amaze010"));
  AddExit("climb", #'ExitClimb);
  HideExit("climb", HIDE_ALWAYS);
 
  // Details
  AddOrigDetail( ({ "column", "massive column", "orange column"
	      , "massive orange column" })
	   , "It looks like you could climb it down.\n"
	   );
  AddOrigDetail( ({ "pit", "thirty foot pit", "30 foot pit"})
	   , "You'll have to climb down to find out anything more.\n"
	   );
}

/*************************************************************************/
