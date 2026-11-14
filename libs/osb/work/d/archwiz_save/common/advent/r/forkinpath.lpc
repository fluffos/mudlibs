/* Advent - Fork in Path -- Mateese, 25-Aug-96
 *
 * Coming from the Chasm, the path forks towards the Volcano northeast
 * and towards the Bear south.
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
  Set(P_INT_SHORT, "Fork in Path");
  Set(P_INT_LONG,
"The path forks here. The left fork leads northeast. A dull rumbling seems "
"to get louder in that direction. The right fork leads southeast down "
"a gentle slope. The main corridor eanters from the west.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_INT_NOISE, "A dull rumbling can be heard from northeast.\n");
  Set(P_NODWARF, 1);
    
  // Exits
  AddExit(({"northeast", "left"}), ADVENT("r/warmjunct"));
  AddExit(({"southeast", "right", "down"}), ADVENT("r/limepassage"));
  AddExit("west", ADVENT("r/corridor"));
  HideExit(({ "left", "right", "down" }), HIDE_ALWAYS);
}

/*************************************************************************/
