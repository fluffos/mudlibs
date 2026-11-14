/* Advent - Giant Room -- Mateese, 20-Aug-96
 *
 * The Giant Room west of the Narrow Corridor and south of the Cavern
 * with Waterfall.
 * The Nest of Golden Eggs and the words of the magic formula are here.
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
  Set(P_INT_SHORT, "Giant Room");
  Set(P_INT_LONG,
"You are in the giant room. The ceiling here is too high up for your lamp "
"to show it. Cavernous passages lead east, north and south. On the west "
"wall is scrawled the inscription 'Fee fie foe foo [sic]'.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("south", ADVENT("r/narrowcorr"));
  AddExit("east", ADVENT("r/recentcavein"));
  AddExit("north", ADVENT("r/immpassage"));
 
  // Details
  AddOrigDetail(({ "inscription", "scrawled inscription", "sign" })
	   , "It says, 'Fee fie foe foo [sic].'\n"
	   );

  // Items
  AddItem(ADVENT("o/eggnest"), REFRESH_REMOVE);
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  SetFlag(F_FIEFOO);
}

/*************************************************************************/
