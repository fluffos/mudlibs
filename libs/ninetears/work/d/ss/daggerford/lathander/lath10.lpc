#include "path.h"
inherit "std/room";

setup()
{
set_light(100);
set_short("temple");
set_long("You are standing in the southeastern corner of the temple.  Rows "+
        "of benches surround you, with more benches to the back of the "+
        "temple, the west.  To the north is the center aisle which leads "+
        "from the rear of the church all the way to the pulpit.  The "+
        "large glass window on the eastern wall allows the first rays of "+
        "morning to light the services to Lathander.\n");

add_exit("west", ROOM+"lath7", "corridor");
add_exit("north", ROOM+"lath9", "corridor");

add_alias("pew", "pews", "bench", "benches");
add_item("benches", "These are simple wooden benches.  They aren't "+
        "exceptionally comfortable, but the do provide a place to sit "+
        "during a service.\n");
add_item("window", "The glass seems to be of exceptional quality, "+
        "especially considering its size.  You wonder how they made such "+
        "a large piece of glass, as it seems to be one solid sheet, rather "+
        "than a number of separate panes.\n");
add_alias("pulpit", "aisle");
add_item("aisle", "It's a short distance north of here.\n");
set_zone("lathander");
}
