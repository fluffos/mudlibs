/* Advent - Hall Of Mists -- Mateese, 17-Aug-96
 *
 * The cave opens up: the famous Hall of Mists.
 * This is one fixed starting position of the little dwarf.
 * Entering here the first time is awarded with 3500 XP.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int CheckAction (string action, string verb, string arg, int method)

/* We interfere with the movement if the player tries to go up the dome
 * with the nugget. Note that this way we don't need to do the movement
 * with all its checks ourselves.
 */
{
  if ("exit" == action && "up" == verb)
  {
    if (deep_present(ADV_NUGGET, this_player()))
    {
      notify_fail("The dome is unclimbable.\n");
      return 0;
    }
  }
  return ::CheckAction(action, verb, arg, method);
}

/*-----------------------------------------------------------------------*/
public int ExitClimb (string arg)

/* If the players tries to climb up the dome, transform it silently into
 * an 'up' movement.
 */

{
  if (!arg)
  {
    notify_fail("Climb what or where?\n");
    return 0;
  }
  if (!sizeof(norm_id(arg, 1) & ({ "up", "dome" }) ) )
  {
    notify_fail("That won't help.\n");
    return 0;
  }
  return UseExit("up", 0, M_GO);
}

/*-----------------------------------------------------------------------*/
public string DetailDome ()
{
  if (deep_present(ADV_NUGGET, this_player()))
    return 
      "It's not sure you'll be able to get up it with what you're carrying.\n"
    ;
  return "It looks like you might be able to climb up it.\n";
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Hall of Mists");
  Set(P_INT_LONG,
"You are at one end of a vast hall stretching forward out of sight to the "
"west. There are openings to either side. Nearby, a wide stone staircase "
"leads downward. The hall is filled with wisps of white mist swaying to and "
"fro almost as if alive. A cold wind blows up the staircase. There is "
"a passage at the top of a dome behind you. "
"Rough stone steps lead up the dome.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit(({"north", "down"}), ADVENT("r/hallmtking"));
  AddExit("south", ADVENT("r/nuggetroom"));
  AddExit("west", ADVENT("r/eastfissure"));
  AddExit("up", ADVENT("r/topsmallpit"));
  CheckExit("up", DACT_CHECK);
  AddExit("climb", #'ExitClimb);
  HideExit( ({ "north", "climb" }), HIDE_ALWAYS);
  
  // Details
  AddOrigDetail(({ "stair", "staircase", "stairs", "wide staircase"
             , "stone staircase", "wide stone staircase" })
	   , "The staircase leads down.\n"
	   );
  AddOrigDetail(({ "steps", "rough steps", "stone steps", "rough stone steps" })
	   , "The rough stone steps lead up the dome.\n"
	   );
  AddOrigDetail(({ "mist", "wisps", "white mist", "white wisps" }),
"Mist is a white vapor, usually water, seen from time to time in caverns. "
"It can be found anywhere but is frequently a sign of a deep pit leading "
"down to water.\n"
	   );
  AddOrigDetail("dome", #'DetailDome);
  AddOrigDetail(({ "opening", "openings" }),
"They lead into darkness. However, just the openings to the north and south "
"are big enough to commode you.\n"
	   );

  // Items
  AddItem(ADVENT("o/dwarf"), REFRESH_DESTRUCT);
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  if (!QueryFlag(F_IN_MISTS))
  {
    SetFlag(F_IN_MISTS);
    this_player()->AddXP(3500);
  }
}

/*************************************************************************/
