/* Advent - Immense N/S Passage -- Mateese, 20-Aug-96
 *
 * The Immense N/S Passage leading from the Giant Room to the Cavern
 * with Waterfall.
 * The Rusty Door here can be opened if the hinges are oiled.
 */

#include <properties.h>
#include <rooms.h>
#include <lock.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public string DoorExtra()
{
  object door;
  mixed tmp;

  if (-1 == member(m_indices(Query(P_EXITS_DATA)), "north"))
    return "";
  door = Query(P_EXITS_DATA)["north", EXIT_DOOR-EXIT_OBJ];
  if (!door)
    return "";
  if (LOCK_CLOSED == door->Query(P_LOCKSTATE))
    return "The way north is barred by a massive, rusty, iron door.\n";
  return "The way north leads through a massive, rusty, iron door.\n";
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Immense N/S Passage");
  Set(P_INT_LONG,
"You are at one end of an immense north/south passage.\n"
     );
  SetExtraEntry("immpassage extra long", P_INT_LONG, #'DoorExtra);
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("south", ADVENT("r/giantroom"));
  AddDoor("north", ADVENT("r/waterfall")
	  , ([ P_OTHERROOM: 0, P_OILED: 0, P_LOCKSTATE: LOCK_CLOSED ])
	  , ADVENT("o/rustydoor")
	  );
}

/*************************************************************************/
