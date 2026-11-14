/* Advent - SW Side of Chasm -- Mateese, 25-Aug-96
 *
 * The southwest side of the chasm.
 * The way over the rickety bridge is blocked by the troll. Though the
 * sign says else, it is not possible to pay enough toll. However, by
 * giving the troll the Nest of Golden Eggs (Giant Room) and heating it
 * with the magic formula, it can be scared away (and will respect the
 * player on later accounts).
 * 
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/chasm");

public int fpay (string arg); // forward

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "SW Side of Chasm");
  Set(P_INT_LONG,
"You are on one side of a large, deep chasm. A heavy white mist rising up "
"from below obscures all view of the far side. A southwest path leads away "
"from the chasm into a winding corridor.\n"
     );
  Set(P_BRIGHT, 0);

  AddRoomCmd("pay", #'fpay);

  // Exits
  AddExit(({"southwest", "down"}), ADVENT("r/slopingcorr"));
  HideExit("down", HIDE_ALWAYS);

  setup("northeast", ADVENT("r/nechasm"));

  // Items
  AddItem(ADVENT("o/troll"), REFRESH_DESTRUCT|REFRESH_HOME);
    
  // Details
  AddDetail(({ "mist", "wisps", "white mist", "white wisps" }),
"Mist is a white vapor, usually water, seen from time to time in caverns. "
"It can be found anywhere but is frequently a sign of a deep pit leading "
"down to water.\n"
	   );
}

/*-----------------------------------------------------------------------*/
public int fpay (string arg)

/* Handle that someone tries to pay the (nonexisting) troll.
 */

{
  int pos;
  object obj;
    
  if (present(ADV_TROLL, this_object())) // pass the cmd to the troll
    return 0;
    
  if (!arg)
    notify_fail("Pay what?\n");
  else
    notify_fail("Great idea. It's just no one here to pay to.\n");
  return 0;
}

/*************************************************************************/
