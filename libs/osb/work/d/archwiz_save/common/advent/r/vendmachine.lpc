/* Advent - Dead End, near Vending Machine -- Mateese, 28-Aug-96
 *
 * The Dead End in the Different Maze with the Vending Machine.
 * It used to give out fresh batteries (thus depraving the player from
 * its rare coins), but this isn't useful anymore.
 * As compensation, the mere entrance is rewarded :-)
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
  Set(P_INT_SHORT, "Dead End, near Vending Machine");
  Set(P_INT_LONG,
"You have reached a dead end. There is a massive vending machine here. "
"There is a message here scrawled in the dust in a flowery script.\n"
     );
  Set(P_BRIGHT, 0);
  Set(P_VMASTER, ADVENT("r/diffmaze"));

  // Exits
  AddExit(({ "north", "out" }), ADVENT("r/dmaze02"));
  HideExit("out", HIDE_ALWAYS);
    
  // Details
  AddOrigDetail(({"message", "script", "dust", "flowery script" }),
"The message reads, 'This is not the maze where the pirates leaves "
"his treasure chest.'\n"
	   );
  AddOrigDetail(({ "machine", "vending machine", "massive machine" }),
"A massive, sturdy vending machine, definitely from a different continuum. "
"There are unreadable instructions on it, and as a whole the machine looks "
"clearly dysfunctional.\n"
	   );
  AddOrigDetail(({ "instructions" }),
"You see what once might have been letters, but now are just black dots.\n"
	   );
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  if (!QueryFlag(F_MACHINE))
  {
    this_player()->AddXP(1000);
    SetFlag(F_MACHINE);
  }
}

/*************************************************************************/
