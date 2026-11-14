/*   Base Room for dynamic example maze  (Mateese, 14-Aug-94)
**
** Realized are the basic functions for one maze room.
** The room itself takes just the data presented by xdynamaster and
** displays it.
** See /d/archwiz/common/lpc/exm/xdynamaster for a complete discussion.
*/

#include <properties.h>

inherit "/std/room";

  /* The name of the maze master */
#define MASTER "/d/archwiz/common/lpc/exm/xdynamaster"

int x, y, z;  /* Our coordinate */

void create() {

  ::create();

  Set(P_INT_SHORT, "Little dynamic maze of twisty passages");

  Set(P_INT_LONG,
"You are in a little dynamic maze of twisty passages, all different.\n" +
"In detail, this is /d/archwiz/common/exm/xdynabase.c .\n" +
"There is not much to see here.\n"
             );

    /* The exits are added upon call from xdynamaster */
}

/*------------------------------------------------------------------------*/
/* Move the player to a new room.
** Since we can't create it, it must be done via xdynamaster.
*/

int _move_in_dyna (string arg) {
  if (arg) return 0;  /* Moving with args is not quite useful */

    /* call the move fun in the master with direction and our coordinate */
  return MASTER->_move_in_dyna (this_player(), query_verb(), x, y, z);
}

/*------------------------------------------------------------------------*/
/* Initialize this room.
** We get our coordinate and a list of exits from xdynamaster and set
** up the remaining properties.
*/

init_mroom (string *ex, int cx, int cy, int cz) {
  int i;

  x = cx; y = cy; z = cz;   /* Initialize our coordinate */

    /* Initialize our special exits */
  for (i = 0; i < sizeof(ex); i++)
    AddExit (ex[i], #'_move_in_dyna);
}

