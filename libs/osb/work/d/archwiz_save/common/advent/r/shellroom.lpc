/* Advent - Shell Room -- Mateese, 22-Aug-96
 *
 * North of the Complex Junction, the clam with the Pearl can be found
 * here.
 * Around is a long up-down corridor.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int CheckAction (string action, string verb, string arg, int method)

/* We interfere with the movement if the player tries to go up the south
 * with the clam. Note that this way we don't need to do the movement
 * with all its checks ourselves.
 */
{
  if ("exit" == action && "south" == verb)
  {
    object clam;
    clam = deep_present(ADV_CLAM, this_player());
    if (clam)
    {
      notify_fail("You can't fit this five-foot "
                  +(clam->Query(ADV_CLAM) > 1 ? "oyster" : "clam")
		  +" through that little passage!\n"
		 );
      return 0;
    }
  }
  return ::CheckAction(action, verb, arg, method);
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Shell Room");
  Set(P_INT_LONG,
"You're in a large room carved out of sedimentary rock. The floor and walls "
"are littered with bits of shells imbedded in the stone. A shallow passage "
"proceeds downward, and a somewhat steeper one leads up. A low hands and "
"knees passage enters from the south.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("up", ADVENT("r/archedhall"));
  AddExit("down", ADVENT("r/raggedcorr"));
  AddExit("south", ADVENT("r/complexjunct"));
  CheckExit("south", DACT_CHECK);

  // Items
  AddItem(ADVENT("o/giantclam"), REFRESH_REMOVE);
}

/*************************************************************************/
