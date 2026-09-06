/* Advent - Pirate's Chest -- Mateese, 17-Aug-96
 *
 * The Pirate's Treasure Chest, found in Pirate's Dead End (r/piratesend).
 * It is a normal treasure, just with the 'open' and 'unlock' verbs
 * added for additional flavour.
 * Spotting the chest sets F_PIRATE and thus stops the pirate for this
 * player.
 */

#include <config.h>
#include <properties.h>
#include <rooms.h>
#include "advent.h"

inherit ADVENT("o/treasure");

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  Set(P_SHORT, "a treasure chest");
  Set(P_LONG, 
"It's the pirate's treasure chest, filled with riches of all kind.\n"
     );
  Set(P_WEIGHT, 10000);
  Set(P_VALUE, 100);
  AddId(({ "chest", "box", "treasure" })); 
  AddAdjective(({ "treasure", "pirates", "pirate's" })); 

  Set(P_TREASURE, F_PCHEST);
  Set(P_XP, 1200);
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  Set(F_PIRATE);
  add_action("fopen", "open");
  add_action("fopen", "unlock");
  add_action("fclose", "lock");
  add_action("fclose", "close");
}

/*-----------------------------------------------------------------------*/
/* Both commands use a low-priority notify_fail(), so we don't have to check
 * if the commands really mean the chest.
 */

public int fopen (string arg)
{
  notify_fail("The chest's lock withstands your attempts.\n", NOTIFY_NOT_CMD-1);
  return 0;
}

public int fclose (string arg)
{
  notify_fail("The chest is already "+query_verb()+"ed.\n", NOTIFY_NOT_CMD-1);
  return 0;
}

/*************************************************************************/
