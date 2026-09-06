/* Advent - Volcano - Breathtaking View -- Mateese, 25-Aug-96
 *
 * Wonderful, isn't it?
 * One of the most famous room descriptions in interactive fiction.
 * Note: This could be the ex-volcano in the forest south of NF-City
 *       (/d/hell/wurzel/rooms/surf1), which went underground.
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
  Set(P_INT_SHORT, "Breath-Taking View");
  Set(P_INT_LONG,
"You are on the edge of a breath-taking view. Far below you is an active "
"volcano, from which great gouts of molten lava come surging out, cascading "
"back down into the depths. The glowing rock fills the farthes reaches of "
"the cavern with a blood-red glare, giving everything an eerie, macabre "
"appearance. The air is filled with flickering sparks of ash and a heavy "
"smell of brimstone. The walls are hot to the touch, and the thundering of "
"drowns out all other sounds. Embedded in the jagged roof far overhead are "
"myriad twisted formations composed of pure alabaster, which scatter the "
"murky light into sinister apparitions upon the walls. To one side is a deep "
"gorge, filled with a bizarre chaos of tortured rock which seems to have been "
"crafted by the devil himself. An immense river of fire crashes out from "
"the depths of the volcano, burns its way through the gorge, and plummets "
"into a bottomless pit far off to your left. To the right, an immense geyser "
"of blistering steam erupts continuously from a barren island in the center "
"of a sulfurous lake, which bubbles ominously. The far right wall is aflame "
"with an incandescence of its own, which lends an additinal infernal splender "
"to the already hellish scene. A dark, forboding passage exits to the south.\n" 
      );
  Set(P_INT_NOISE, 
      "The thundering of the volcano drowns out all other sounds.\n"
     );
  Set(P_INT_SMELL,
      "The heavy smell of sulfur and gasses is overwhelming.\n"
     );
    
  // Exits
  AddExit("south", ADVENT("r/warmjunct"));
  Set(P_NOWAY_MSG, "Don't be ridiculous.\n");

  // Details
  AddOrigDetail( ({"volcano", "active volcano"}), 
"Great gouts of molten lava come surging out of the volcano and go cascading "
"back down into the depths. The glowing rock fills the farthest reaches of the "
"cavern with a blood-red glare, giving everything an eerie, macabre appearance.\n"
	   );
  AddOrigDetail( ({"sparks", "ash", "sparks of ash"}), 
"The sparks are too far away for you to get a good look at them.\n"
	   );
  AddOrigDetail( ({"roof", "jagged roof", "formations"}), 
"Embedded in the jagged roof far overhead are myriad twisted formations "
"composed of pure white alabaster, which scatter the murky light into "
"sinister apparitions on the walls.\n"
	   );
  AddOrigDetail( ({"gorge", "deep gorge"}),
"The gorge is filled with a bizarre chaos of tortured rock which seems to "
"have been crafted by the devil himself.\n"
	   );
  AddOrigDetail( ({"fire", "river of fire", "river" }),
"The river of fire crashes out from the depths of the volcano, burns its way "
"through the gorge, and plummets into a bottomless pit far off to your left.\n"
	   );
  AddOrigDetail( ({"geyser", "immense geyser", "lake", "sulfurous lake" }),
"The geyser of blistering steam erupts continuously from a barren island in "
"the center of a sulfurous lake, which bubble ominously.\n"
	   );
}

/*************************************************************************/
