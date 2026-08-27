#include "path.h"
inherit "std/room";

setup()
{
set_light(100);
set_short("balcony");
set_long("You are on the balcony overlooking the temple.  The balcony "+
        "is used for large services to lathander.  There are many rows of "+
        "benches, most of which appears rather dusty and unused.  "+
        "To the north is the stairs leading back to the temple.\n");

add_exit("north", ROOM+"lath14", "corridor");

add_alias("pew", "pews", "bench", "benches");
add_item("benches", "These are simple wooden benches.  They aren't "+
        "exceptionally comfortable, but the do provide a place to sit "+
        "during a service.\n");
add_item("balcony", "It's made of wood, and has a wonderful view of the "+
         "temple.\n");
set_zone("lathander");
}
