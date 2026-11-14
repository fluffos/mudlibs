/* Advent - In Pit -- Mateese, 18-Aug-96
 *
 * A small pit below the east end of the passage to the lower parts
 * of the Cave. 
 * The stream of water from the entrace makes a short guest appearance here.
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
  Set(P_INT_SHORT, "In Pit");
  Set(P_INT_LONG,
"You are in the bottom of a small pit with a little stream, which enters "
"and exits through tiny slits.\n"
     );
  Set(P_NOISE, "It is silent, except for the flow of the water.\n");
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);
    
  // Exits
  AddExit("up", ADVENT("r/onbrinkpit"));
  AddNowayMsg("down", "You don't fit through the tiny slits.\n");
    
  // Items
  AddItem(ADVENT("o/water"), REFRESH_REMOVE);
}

/*************************************************************************/
