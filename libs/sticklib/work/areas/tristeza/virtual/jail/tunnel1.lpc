#include "defs.h"

#include <room.h>

#define CELL "/room/city/law/cell1"

void
create_room()
{
    set_short("Tunnel complex");
    set_long(
      "You are in a damp, rough-walled stone tunnel. Many confusing, twisty "+
      "passages lead into various directions. Well, what did you expect from "+
      "a dungeon which has been dug with spoons...");

    set_light_level(LT_DIM);
    set_wd(WD_INDOORS);

    add_exit("south", DIRR + "/tunnel3");
    add_exit("west", DIRR + "/tunnel6");
    add_exit("southeast", DIRR + "/tunnel2");
}

void
init_room()
{
    add_action("north", "north");
}

status
north()
{
    if (!CELL->digged()) return 0;

    this_player()->move_player("north#" + CELL);

    return 1;
}
