/* Advent - Debris Room -- Mateese, 15-Aug-96
 *
 * A room filled with debris. The black rod to build the crystal bridge
 * over the Fissure (r/westfissure, r/eastfissure) is here.
 * The player can teleport from there to the treasure dump and vice versa.
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
  Set(P_INT_SHORT, "Debris Room");
  Set(P_INT_LONG,
"You are in a debris room filled with stuff washed in from the surface. "
"A low wide passage with cobbles becomes plugged with mud and debris here, "
"but an awkward canyon leads upward and west.\n"
"A note on the walls says, \"Magic word XYZZY.\"\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_NODWARF, 1);

  // Exits
  AddExit("east", ADVENT("r/cobblecrawl"));
  AddExit(({"west", "up"}), ADVENT("r/awkewcanyon"));
  HideExit("up", HIDE_ALWAYS);

  // Details
  AddOrigDetail(({ "debris", "mud", "stuff" }), "Yuck.\n");
    AddOrigDetail(({ "cobble", "cobbles", "cobblestones", "cobblestone"
	           , "stone", "stones" }),
"They are just ordinary cobbles.\n"
	   );
  AddOrigDetail("note", "The note says, \"Magic word XYZZY.\"\n");
  AddOrigReadMsg("note", "The note says, \"Magic word XYZZY.\"\n");
  AddOrigDetail(({"canyon", "passage" }), "You see nothing special.\n");

  // Items
  AddItem(ADVENT("o/blackrod"), REFRESH_REMOVE);
}

/*-----------------------------------------------------------------------*/
public void init()

/* Activate the 'xyzzy' command. */

{
  ::init();
  SetFlag(F_XYZZY, this_player());
}

/*************************************************************************/
