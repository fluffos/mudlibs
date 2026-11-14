/* Advent - West End of Hall of Mists -- Mateese, 17-Aug-96
 *
 * East of here is the Long Hall, south the Alike Maze.
 * To the west, the Hall of Mists.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int CheckAction (string action, string verb, string arg, int method)

/* Going the north way to the West End of Hall of Mists yields a small
 * message.
 */
{
  if ("exit" == action && "north" == verb)
    write(
"You have crawled through a very low wide passage parallel to and north of "
"the hall of mists.\n"
	 );
  return ::CheckAction(action, verb, arg, method);
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "West End of Hall of Mists");
  Set(P_INT_LONG,
"You are at the west end of the hall of mists. A low wide crawl continues "
"west and another goes north. To the south is a little passage 6 feet off "
"the floor.\n" 
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit(({"south", "up"}), ADVENT("r/amaze001"));
  AddExit(({"east", "north"}), ADVENT("r/westfissure"));
  AddExit("west", ADVENT("r/eastlonghall"));
  HideExit("up", HIDE_ALWAYS);
  CheckExit("north", DACT_CHECK);
  Set(P_VMASTER, ADVENT("r/alikemaze"));

  // Details
  AddOrigDetail(({ "mist", "wisps", "white mist", "white wisps" }),
"Mist is a white vapor, usually water, seen from time to time in caverns. "
"It can be found anywhere but is frequently a sign of a deep pit leading "
"down to water.\n"
	   );
}

/*************************************************************************/
