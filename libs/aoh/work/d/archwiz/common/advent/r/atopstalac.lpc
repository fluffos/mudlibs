/* Advent - Top of Stalactite -- Mateese, 19-Aug-96
 *
 * Coming from the Secret N/S Canyon 1, the player may enter the Alike Maze
 * here at a random point.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int ExitDown (string arg)

/* Enter the Alike Maze.
 */

{
  string dest;
    
  if (arg)
    return 0;

  if (random(100) <= 40)
    dest = ADVENT("r/amaze006");
  else if (random(100) <= 50)
    dest = ADVENT("r/amaze009");
  else
    dest = ADVENT("r/amaze004");

  if (ME_OK != this_player()->move(dest, M_GO))
    raise_error("Move into "+dest+" failed.\n");

  return 1;
}

/*-----------------------------------------------------------------------*/
public int ExitClimb (string arg)

/* If the players tries to climb (or jump) down the stalactite, transform it
 * silently into an 'down' movement.
 */

{
  if (!arg)
  {
    notify_fail("Climb what or where?\n");
    return 0;
  }
  if (!sizeof(norm_id(arg, 1) & ({ "down", "stalactite" }) ) )
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
  Set(P_INT_SHORT, "Top of Stalactite");
  Set(P_INT_LONG,
"A large stalactite extends from the roof and almost reaches the floor below. "
"You could climb down it, and jump from it to the floor, but having done so "
"you would be unable to reach it to climb back up.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_VMASTER, ADVENT("r/alikemaze"));
    
  // Exits
  AddExit("north", ADVENT("r/s-nscanyon1"));
  AddExit("down", #'ExitDown);
  AddExit(({"climb", "jump"}), #'ExitClimb);
  HideExit(({"climb", "jump"}), HIDE_ALWAYS);

  // Details
  AddOrigDetail(({ "stalactite", "large stalactite" }),
"You could probably climb down it, but you can forget coming back up.\n"
	   );
}

/*************************************************************************/
