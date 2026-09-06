/* Advent - Subterranean Slit in Streambed -- Mateese, 14-Aug-96
 *
 * The water stream before the Cave vanishes here in a slit.
 * This mimicks the original room Slit in Streambed.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Subterranean Slit in Streambed");
  Set(P_INT_LONG,
"You are in a low subterranean tunnel. At your feet all the water of the stream "
"splashes into a 2-inch slit in the rock. Downstream the streambed is bare "
"rock.\n"
     );
  Set(P_INT_SMELL, "The air smells fresh and cool.\n");
  Set(P_INT_NOISE, "It is silent, except for the flow of the water.\n");
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);
  Set(P_NOORIG, 1);

  // Exits
  AddExit("north", ADVENT("r/subtstream"));
  AddExit("south", ADVENT("r/subtoutgrate"));
  AddNowayMsg("down", "You don't fit through a 2-inch slit!\n");
    
  // Details
  AddDetail(({ "bed", "streambed", "rocky bed", "rocky streambed" }),
"A rocky bed for a stream to tumble along.\n"
	   );
  AddDetail(({"slit", "2-inch slit", "2 inch slit"}), 
"It's just a 2-inch slit in the rock, through which the stream is flowing.\n"
	   );
    
  // Items
  AddItem(ADVENT("o/water"), REFRESH_REMOVE
         , ([ P_WATEREXTRA:
"The stream flows into a 2-inch slit in the streambed.\n"
           ])
	 );
}

/*************************************************************************/
