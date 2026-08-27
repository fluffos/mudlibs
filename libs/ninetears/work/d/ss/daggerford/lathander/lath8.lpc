#include "path.h"
inherit "std/room";

setup()
{
set_light(100);
set_short("temple");
set_long("You are in the front of the temple, in the northeast corner.  Rows "+
        "of benches occupy the space around you, provide places of comfort "+
        "for early morning services.  There are rows of benches behind "+
        "you to the west, and the main aisle is to the south.  From here "+
        "the large glass window seems to take up the entire eastern wall.\n");

add_exit("west", ROOM+"lath5", "corridor");
add_exit("south", ROOM+"lath9", "corridor");

add_alias("pew", "pews", "bench", "benches");
add_item("benches", "These are simple wooden benches.  They aren't "+
        "exceptionally comfortable, but the do provide a place to sit "+
        "during a service.\n");
add_item("window", "The glass seems to be of exceptional quality, "+
        "especially considering its size.  You wonder how they made such "+
        "a large piece of glass, as it seems to be one solid sheet, rather "+
        "than a number of separate panes.\n");

set_zone("lathander");
}
