#include "path.h"
inherit "std/room";
object board;

void reset()
{
   if(!board)
   {
      board=clone_object("/obj/misc/board");
      board->move(this_object());
      board->set_datafile("Lathander");
   }
}
setup()
{
set_light(90);
set_short("Cleric Armory");
set_long("You are in a small room which appears to be used by the Clerics "+
        "of Lathander for storage of weapons and other equipment.  You can "+
        "leave equipment here for fellow clerics to give them a hand, and if "+
        "you borrow any equipment you find here, make sure you remember to "+
        "return it after use.  The preparation room is to the northeast, "+
        "and your guild is to the south.\n");
add_exit("northwest", ROOM+"lath4", "door");
add_exit("south", ROOM+"lathander", "door");

set_zone("lathander");
}
