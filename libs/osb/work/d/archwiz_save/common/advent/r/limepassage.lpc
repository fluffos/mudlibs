/* Advent - Limestone Passage -- Mateese, 25-Aug-96
 *
 * The Limestone Passage south from the Fork in Path.
 * Further south is the bear.
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
  Set(P_INT_SHORT, "Limestone Passage");
  Set(P_INT_LONG,
"You are walking along a gently sloping north/south passage lined with "
"oddly shaped limestone formations.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);
    
  // Exits
  AddExit(({"north", "up"}), ADVENT("r/forkinpath"));
  AddExit(({"south", "down"}), ADVENT("r/frontbarren"));
  HideExit(({ "up", "down" }), HIDE_ALWAYS);
    
  // Details
  AddOrigDetail( ({"limestones", "limestone", "formations"
              , "limestone formations" }),
"Every now and then a particularly strange shape catches your eye.\n"
	   );

}

/*************************************************************************/
