/* Advent - West Side of Fissure -- Mateese, 17-Aug-96
 *
 * The west side of the fissure. Below is the Misty Cavern and the Reservoir.
 * Waving the black rod here (or on the east bank) creates a crystal bridge
 * spanning the fissure.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/fissure");

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
  Set(P_INT_SHORT, "West Side of Fissure");
  Set(P_INT_LONG,
"You are on the west side of the fissure in the hall of mists.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit(({ "west", "north" }), ADVENT("r/westhallmists"));
  CheckExit("north", DACT_CHECK);
    
  setup("east", ADVENT("r/eastfissure"));

  // Details
  AddDetail("fissure", 
"The fissure blocks the way to the west. It is too wide to jump, and "
"the mists obstruct the view of the other side.\n"
           );
  // Items
  AddItem(ADVENT("o/treasure"), REFRESH_REMOVE
	 , ([ P_SHORT: "some diamonds"
            , P_LONG: "They look to be of the highest quality.\n"
            , P_IDS: ({ "diamonds" })
            , P_ADS: ({ "some" })
            , P_WEIGHT: 50
            , P_VALUE: 1000
            , P_TREASURE: F_DIAMONDS /* Default XP */
           ])
	 );
}

/*************************************************************************/
