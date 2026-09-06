/* Advent - Witt's End -- Mateese, 23-Aug-96
 *
 * The problem is exiting this room: the player has to use any direction
 * but 'west', and has a 20% (original: 5%) chance of exiting the room.
 * Dropping the Spelunker magazine here is awarded with 100 XP.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int CheckAction (string action, string verb, string arg, int method)

/* We interfere with the movement if the player tries to leave.
 * Note that this way we don't need to do the movement
 * with all its checks ourselves.
 */
{
  if ("exit" == action && "west" != verb && random(100) <= 80)
  {
    notify_fail(
"You have crawled around in some little holes and wound up back "
"in the main passage.\n"
               );
    return 0;
  }
  return ::CheckAction(action, verb, arg, method);
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Witt's End");
  Set(P_INT_LONG,
"You are at Witt's End. Passages lead off in *all* directions.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit(({ "north", "northeast", "east", "southeast"
	   , "south", "southwest", "northwest"
	   , "up", "down" 
	   /* "west" is missing on purpose! */
          }), ADVENT("r/anteroom"));
  CheckExit(({ "north", "northeast", "east", "southeast"
	   , "south", "southwest", "northwest"
	   , "up", "down"
           }), DACT_CHECK);
  AddNowayMsg("west", 
"You have crawled around in some little holes and found your way blocked by "
"a recent cave-in. You are now back in the main passage.\n"
	     );
}

/*************************************************************************/
