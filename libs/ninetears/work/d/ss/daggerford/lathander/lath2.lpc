#include "path.h"
inherit "std/room";

setup()
{
set_short("hallway");
set_long("You are in a small hallway inside Lathander's temple.  The "+
        "hallway continues to the northeast, where a stairway is slightly "+
        "visible, and to the south, towards the entryway.  The walls of "+
        "the hall are decorated with bright and beautiful paintings.\n");
set_light(80);
add_alias("painting","paintings");
add_item("paintings","There are a variety of paintings, although all depict "+
        "some aspect of Lathander or his followers.  Most seem to involve "+
        "great inventions and innovations created by worshippers of "+
        "Lathander.\n");
add_item("stairway", "From here you can see that it leads upwards, but you "+
   "can't be sure if it also leads down.\n");
add_item("hallway", "The hallway is made from some kind of bright stone.\n");
add_item(({"wall", "walls"}),"The walls are made of a kind of bright stone.\n");
add_exit("south",ROOM+"lath1","corridor");
add_exit("northeast",ROOM+"lath3","corridor");
set_zone("lathander");
}
