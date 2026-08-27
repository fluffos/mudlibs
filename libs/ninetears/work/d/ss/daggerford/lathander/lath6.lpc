#include "path.h"
inherit "std/room";

setup()
{
set_light(100);
set_short("Rear of temple");
set_long("You are in the rear of the temple.  This is a rather large temple "+
        "to Lathander Morninglord, god of spring, dawn, birth and renewal.  "+
        "The temple faces east, where a large glass window "+
        "dominates the eastern wall.  Services to Lathander are held at "+
        "dawn and in the light of the rising sun.  There are benches around "+
        "you and an aisle leading to the front of the church.  The benches "+
        "continue to the north and the south.  To the west, thru a large "+
        "archway, is the foyer of the temple.\n");

add_exit("north", ROOM+"lath5", "corridor");
add_exit("south", ROOM+"lath7", "corridor");
add_exit("west", ROOM+"lath1", "corridor");
add_exit("east", ROOM+"lath9", "corridor");

add_alias("pew", "pews", "bench", "benches");
add_item("benches", "These are simple wooden benches.  They aren't "+
        "exceptionally comfortable, but the do provide a place to sit "+
        "during a service.\n");
add_item("window", "The glass seems to be of exceptional quality, "+
        "especially considering its size.  You wonder how they made such "+
        "a large piece of glass, as it seems to be one solid sheet, rather "+
        "than a number of separate panes.\n");
add_item("archway", "The large archway is a heavy stone structure.\n");
add_item("foyer", "It's too dark in there to see clearly from this distance. "+
  "if you move west you'll see it better.\n");

set_zone("lathander");
}
