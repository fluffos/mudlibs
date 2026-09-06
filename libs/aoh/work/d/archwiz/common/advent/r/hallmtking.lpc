/* Advent - Hall Of Mountain King -- Mateese, 17-Aug-96
 *
 * The Hall of the Mountain King is north/up from the Hall of Mists
 * and has several side chambers.
 * Most passages are blocked by the snake, but this can be scared away
 * using the little bird from the Bird Chamber.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public int CheckAction (string action, string verb, string arg, int method)

/* We interfere with the movement if the player tries to use one of
 * the exits if the snake is here.
 */
{
  if ("exit" == action 
   && -1 != member(({"north", "west", "south", "southwest"}), verb)
   && present(ADV_SNAKE, this_object())
   && !QueryFlag(F_SNAKE, this_player())
     )
  {
    if ("southwest" != verb || random(100) <= 35)
    {
      notify_fail("You can't get by the snake.\n");
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
  Set(P_INT_SHORT, "Hall of the Mountain King");
  Set(P_INT_LONG,
"You are in the hall of the mountain king, with passages off in all directions.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_NOWAY_MSG, "Well, perhaps not quite all directions.\n");

  // Exits
  AddExit(({"east","up"}), ADVENT("r/hallofmists"));
  AddExit("north", ADVENT("r/lowpassage"));
  AddExit("south", ADVENT("r/southchamber"));
  AddExit("west", ADVENT("r/westchamber"));
  AddExit("southwest", ADVENT("r/s-ewcanyon"));
  HideExit( ({ "up", "southwest" }), HIDE_ALWAYS);
  CheckExit( ({ "north", "south", "west", "southwest" }), DACT_CHECK);

  // Items
  AddItem(ADVENT("o/snake"), REFRESH_DESTRUCT|REFRESH_HOME);
}

/*************************************************************************/
