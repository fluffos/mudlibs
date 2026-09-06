/* Advent - Window On Pit 2 (west) -- Mateese, 23-Aug-96
 *
 * A window overlooking a pit, which is in fact the Mirror Canyon.
 * The shadowy figure is the player itself, mirrored through the fog.
 * West is the Junction of Three.
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
  Set(P_INT_SHORT, "West Window On Pit");
  Set(P_INT_LONG,
"You're at a low window overlooking a huge pit, which extends up out of "
"sight. A floor is indistinctly visible over 50 feet below. Traces of white "
"mist cover the floor of the pit, becoming thicker to the left. Marks in "
"the dust around the window would seem to indicate that someone has been "
"here recently. Directly across the pit from you and 25 feet away there is "
"a similar window looking into a lighted room. A shadowy figure can be seen "
"there peering back at you.\n"
     );
  Set(P_BRIGHT, 0);
    
  // Exits
  AddExit("west", ADVENT("r/threejunct"));
  Set(P_NOWAY_MSG, "The only passage is back west to the junction.\n");

  AddRoomCmd("wave", "fwave");

  // Details
  AddOrigDetail(({ "window", "low window" }), "It looks like regular window.\n");
  AddOrigDetail(({ "pit", "huge pit" }), 
"It's so deep you can barely make out the floor below, and the top isn't "
"visible at all.\n"
	   );
  AddOrigDetail(({ "marks", "dust", "marks in dust", "marks in the dust" }),
"Evidently you're not alone here.\n"
	   );
  AddOrigDetail(({ "figure", "shadowy figure" }),
"The shadowy figure seems to be trying to attract your attention.\n"
	   );
  AddOrigDetail(({ "mist", "wisps", "white mist", "white wisps" }),
"Mist is a white vapor, usually water, seen from time to time in caverns. "
"It can be found anywhere but is frequently a sign of a deep pit leading "
"down to water.\n"
	   );
}

/*-----------------------------------------------------------------------*/
public int fwave (string arg)
{
  if (!arg 
   || !sizeof(norm_id(arg, 1) & ({ "hand", "hands", "figure"}) ) )
    return 0;
  write("The shadowy figure waves back at you.\n");
  return 1;
}

/*************************************************************************/
