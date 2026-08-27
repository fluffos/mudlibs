#include "path.h"
inherit "std/room";

setup ()
{
set_short("hallway");
set_long("You are in a hallway in Lathander's Temple.  The hallway leads "+
        "to the southwest.  In the northwest corner, there is a stairway "+
        "leading up.  Along the eastern wall, there is a door.\n");
set_light(80);
add_alias("stair","stairs","stairway");
add_item("stairway","The stairway is very large and ornate.  It is "+
        "decorated with gold trim.  You aren't sure, but it looks "+
        "like real gold, not just coloring.\n");
add_item("hallway", "A normal hallway made from some kind of bright stone.\n");
add_item("door","An average wooden door.\n");

add_exit("southwest",ROOM+"lath2","corridor");
add_exit("east",ROOM+"lath4","door");
add_exit("up",ROOM+"lath14","corridor");
set_zone("lathander");
}
