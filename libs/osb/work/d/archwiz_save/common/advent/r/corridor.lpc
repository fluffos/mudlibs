/* Advent - Corridor -- Mateese, 25-Aug-96
 *
 * The corridor between the Chasm (NE Side) and the Fork in Path, leading
 * to the Volcano and the Bear.
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
  Set(P_INT_SHORT, "Corridor");
  Set(P_INT_LONG,
"You're in a long east/west corridor. A faint rumbling noise can be heard "
"in the distance.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_INT_NOISE, "A faint rumble fills the air.\n");
  Set(P_NODWARF, 1);

  // Exits
  AddExit("east", ADVENT("r/forkinpath"));
  AddExit("west", ADVENT("r/nechasm"));
}

/*************************************************************************/
