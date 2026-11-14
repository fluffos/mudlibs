/* Advent - Front of Barren Room -- Mateese, 26-Aug-96
 *
 * Before the Barren Room.
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
  Set(P_INT_SHORT, "In Front of Barren Room");
  Set(P_INT_LONG,
"You are standing at the entrance to a large, barren room. A sign posted "
"above the entrance reads: 'Caution! Bear in room!'\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);
    
  // Exits
  AddExit(({"west", "up"}), ADVENT("r/limepassage"));
  AddExit("east", ADVENT("r/barrenroom"));
  HideExit("up", HIDE_ALWAYS);
    
  // Details
  AddOrigDetail( "sign", 
"The sign reads, 'Caution! Bear in room!'\n"
	   );

}

/*************************************************************************/
