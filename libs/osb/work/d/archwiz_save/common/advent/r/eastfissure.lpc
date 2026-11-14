/* Advent - East Bank of Fissure -- Mateese, 17-Aug-96
 *
 * The east bank of the fissure. Below is the Misty Cavern and the Reservoir.
 * Waving the black rod here (or on the west side) creates a crystal bridge 
 * spanning the fissure.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/fissure");

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "East Bank of Fissure");
  Set(P_INT_LONG,
"You are on the east bank of a fissure slicing clear across the hall. "
"The mist is quite thick here, and the fissure is too wide to jump.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("east", ADVENT("r/hallofmists"));
    
  setup("west", ADVENT("r/westfissure"));
    
  // Details
  AddDetail("fissure", 
"The fissure blocks the way to the west. It is too wide to jump, and "
"the mists obstruct the view of the other side.\n"
           );
}

/*************************************************************************/
