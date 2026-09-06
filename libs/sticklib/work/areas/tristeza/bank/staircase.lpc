inherit "/basic/id";

#include "locker_defs.h"

void
create()
{
    set_short("A staircase");
    set_long("It's a staircase leading down.");
    set_id("staircase");
    return;
}

void
init()
{
    add_action("moveDown","down");
    add_action("moveDown","d");
    return;
}

status
moveDown()
{
    this_player()->move_player("down#"+L_DIR+"lockerroom");
    return 1;
}
