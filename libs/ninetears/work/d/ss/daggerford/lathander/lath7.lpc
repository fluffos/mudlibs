#include "path.h"
inherit "std/room";

setup()
{
set_light(100);
set_short("temple");
set_long("You are in the southwest rear corner of the temple.  This is a "+
        "large temple to Lathander Morninglord, god of spring, dawn, "+
        "birth and renewal.  The eastern wall of the temple "+
        "is a large window which allows the rising sun to illuminate the "+
        "dawn services held here.  Around you are benches to sit on.  There "+
        "are more rows of benches to the east and north.\n");

add_exit("north", ROOM+"lath6", "corridor");
add_exit("east", ROOM+"lath10", "corridor");

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
