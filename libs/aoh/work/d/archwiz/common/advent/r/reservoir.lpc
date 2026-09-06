/* Advent - Reservoir -- Mateese, 23-Aug-96
 *
 * Reservoir for the water from the Waterfall.
 * South is the Mirror Canyon, up the Misty Cavern and the Hall of Mists.
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
  Set(P_INT_SHORT, "Reservoir");
  Set(P_INT_LONG,
"You are at the edge of a large underground reservoir. An opaque cloud of "
"white mist fills the room and rises rapidly upward. The lake is fed by a "
"stream, which tumbles out of a hole in the wall about 10 feet overhead and "
"splashes noisily into the water somewhere within the mist. The only passage "
"goes back toward the south.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_INT_NOISE, 
"You hear the stream splashing into the lake, somewhat obscured by the mist.\n"
     );

  // Exits
  AddExit("south", ADVENT("r/mirrorcanyon"));

  AddRoomCmd("swim", "fswim");

  // Items
  AddItem(ADVENT("o/water"), REFRESH_REMOVE
         , ([ P_SHORT: "a lake"
            , P_LONG: 
"A large reservoir of water. It is filled by a stream tumbling out of a hole "
"about 10 feet overhead.\n"
            , P_IDS: ({ "water", "stream", "lake", "reservoir" })
            , P_ADS: ({ "lake", "strea", "reservoir", "of" })
           ])
	 );

  // Details
  AddOrigDetail(({ "mist", "wisps", "white mist", "white wisps" }),
"Mist is a white vapor, usually water, seen from time to time in caverns. "
"It can be found anywhere but is frequently a sign of a deep pit leading "
"down to water.\n"
	   );
}

/*-----------------------------------------------------------------------*/
public int fswim (string arg)
{
  if (!arg 
   || !sizeof(norm_id(arg, 1) & ({ "reservoir", "water", "lake" }) ) )
    return 0;
  write("The water is icy cold and you would soon freeze to death.\n");
  return 1;
}

/*************************************************************************/
