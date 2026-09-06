/* Advent - At Y2 -- Mateese, 18-Aug-96
 *
 * The second entrance/exit to the cave, the player can teleport from here
 * to the treasure dump and vice verse. This is the way to bring the
 * nugget out of the cave.
 * Btw, 'Y2' is a mark on cave-maps denoting second entrances.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public string PlughExtra()
{
  return random(100) <= 25 ? "A hollow voice says, 'Plugh'.\n" : "";
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "At Y2");
  Set(P_INT_LONG,
"You are in a large room with a passage to the south, a passage to the west, "
"and a wall of broken rock to the east. There is a large 'Y2' on a rock "
"in the room's center.\n"      
     );
  SetExtraEntry("plughextra", P_INT_LONG, #'PlughExtra);
  Set(P_BRIGHT, 0);
    
  // Exits
  AddExit("east", ADVENT("r/jumbleofrock"));
  AddExit("south", ADVENT("r/lowpassage"));
  AddExit("west", ADVENT("r/eastpitwindow"));

  // Details
  AddOrigDetail(({ "rock", "y2" })
	       , "There is a large 'Y2' painted on the rock.\n");
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  SetFlag(F_PLUGH);
}

/*************************************************************************/
