/* Advent - Arched Hall -- Mateese, 22-Aug-96
 *
 * The corridor from the Shell Room ends here.
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
  Set(P_INT_SHORT, "Arched Hall");
  Set(P_INT_LONG,
"You are in an arched hall. A coral passage once continued up and east "
"from here, but is now blocked by debris. The air smells of sea water.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_INT_SMELL, "The air smells stale, but of sea water.\n");

  // Details
  AddOrigDetail(({ "debris", "mud", "stuff" }), "Yuck.\n");
  AddOrigDetail(({ "cobble", "cobbles", "cobblestones", "cobblestone"
	         , "stone", "stones" }),
"They are just ordinary cobbles.\n"
	   );

  // Exits
  AddExit("down", ADVENT("r/shellroom"));
}

/*************************************************************************/
