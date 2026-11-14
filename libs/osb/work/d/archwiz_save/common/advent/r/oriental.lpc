/* Advent - Oriental Room -- Mateese, 21-Aug-96
 *
 * The Oriental Room between Swiss Cheese Room and the Large Low Room.
 * One exit leads to the Misty Cavern and thus indirectly to the Emerald.
 * The Ming Vase is here.
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
  Set(P_INT_SHORT, "Oriental Room");
  Set(P_INT_LONG,
"This is the oriental room. Ancient oriental cave drawings cover the walls.\n"
"An gently sloping passage leads upward to the north, another passage leads "
"southeast, and a hands and knees crawl leads west.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("west", ADVENT("r/lowroom"));
  AddExit("southeast", ADVENT("r/swisscheese"));
  AddExit(({ "north", "up" }), ADVENT("r/mistycavern"));
  HideExit("up", HIDE_ALWAYS);

  // Details
  AddOrigDetail(({"drawings", "cave drawings", "ancient drawings"
	     , "oriental drawings" }),
"They seem to depict people and animals.\n"
	   );
    
  // Items
  AddItem(ADVENT("o/mingvase"), REFRESH_REMOVE);
}

/*************************************************************************/
