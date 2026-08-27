#include "path.h"
inherit "std/room";

setup()
{
set_light(100);
set_short("temple");
set_long("You are in the northwest corner of the temple.  This is a rather "+
        "large temple to Lathander Morninglord, god of spring, dawn, "+
        "birth and renewal.  The temple faces east "+
        "with a large glass window dominating the eastern wall.  Services "+
        "to Lathander are held at dawn to greet the newborn sun.  Around "+
        "you are benches on which worshippers may sit during services.  "+
        "The temple continues to the east and south.\n");

add_exit("south", ROOM+"lath6", "corridor");
add_exit("east", ROOM+"lath8", "corridor");

add_alias("pew", "pews", "bench", "benches");
add_item("benches", "These are simple wooden benches.  They aren't "+
        "exceptionally comfortable, but the do provide a place to sit "+
        "during a service.\n");
add_item("window", "You're too far away to see it properly, but from here it "+
         "looks like one huge pane of glass.\n");
set_zone("lathander");
}
