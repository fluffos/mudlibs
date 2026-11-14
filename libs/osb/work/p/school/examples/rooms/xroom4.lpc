/*   Example Room 4  (Mateese, 20-Jul-96)
**
** This room is merely an interface to the dynamic parts of the dungeon.
** Well, we have an local command here.
*/

#include <properties.h>
#include "/p/school/sys/school.h"

inherit "/std/room";

int _special_plugh(string arg); // forward
void _enter_dyna(string arg);   // forward

/*------------------------------------------------------------------------*/

void create() 
{
  ::create();

  Set(P_INT_SHORT, "The fourth example room");

  Set(P_INT_LONG, 
"You are in the fourth example room (/d/archwiz/common/lpc/exm/xroom4.c).\n"
"Note that it doesn't have a door at the exit to the second room.\n"
"We have some special commands in this room: 'plugh', 'xyzzy' and 'voy'.\n"
"There are exits to the east, west and to the north.\n"
      );

    /* The exit...*/
  AddExit("east", "/d/archwiz/common/lpc/exm/xroom2");

    /* Entering the hand crafted dynamic part is tricky...*/
  AddExit("north", #'_enter_dyna);

    /* Entering the GD assisted dynamic part is easier...*/
  AddExit("west", "/d/archwiz/common/lpc/exm/xmaze0");

    /* Implement our special commands.
    ** 'plugh' and 'xyzzy' will do the same, so only one AddRoomCmd is
    ** needed for both.
    ** Note that abbreviated commands aren't possible :-(
    */
  AddRoomCmd("voy", "_special_voy");
  AddRoomCmd(({ "plugh", "xyzzy" }), #'_special_plugh);
}

/*------------------------------------------------------------------------*/
/* Implement the commands 'plugh' and 'xyzzy'.
** They don't do much, though.
*/

int _special_plugh(string arg) {
  if (arg) write ("A huge fierce green snake bars your way!\n");
  else write ("Nice command, isn't it?\n");
  return 1;
}

/*------------------------------------------------------------------------*/
/* Implement the command 'voy'.
** This one doesn't do much either.
*/

_special_voy(arg) {
  if (arg) write ("Voying "+arg+"...done.\n");
  else write ("You feel something watching you.\n");
  return 1;
}

/*------------------------------------------------------------------------*/
/* Enter the dynamic part of the dungeon.
** We are a special room of the maze, and the master knows us.
*/

int _enter_dyna(string arg) {
  if (arg) return 0;  /* Moving north with args? Naaah */
  return "/d/archwiz/common/lpc/exm/xdynamaster"->_move_in_dyna(
    this_player(), query_verb(), 0, -1, 0
  );
}


