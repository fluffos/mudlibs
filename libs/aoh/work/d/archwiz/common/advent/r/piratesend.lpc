/* Advent - Pirate's Dead End -- Mateese, 16-Aug-96
 *
 * The dead end in the Alike Maze where the Pirate's Treasure Chest 
 * is located. Also any things the Pirate looted from the players
 * is stored here.
 * By spotting the chest, the pirate will be deactivated for the player.
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
  Set(P_INT_SHORT, "Dead End");
  Set(P_INT_LONG,
"This is the pirate's dead end.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_NOWAY_MSG, "You'll have to go back the way you came.\n");
  Set(P_NODWARF, 1);
    
  // Exits
  Set(P_VMASTER, ADVENT("r/alikemaze"));
  AddExit(({"southeast", "out" }), ADVENT("r/amaze013"));
  HideExit("out", HIDE_ALWAYS);
    
  // Items
  AddItem(ADVENT("o/piratechest"), REFRESH_REMOVE);
}

/*************************************************************************/
