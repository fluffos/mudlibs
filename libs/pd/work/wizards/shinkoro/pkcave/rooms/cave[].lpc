#include <std.h>
#include <pkcave.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light"            : 2,
                     "indoors"          : 1,
                     "no attack"        : 1,
                     "no steal"         : 1,
                     "no teleport"      : 1,]));
    set_name("PKcave square");
    set_long("This is the center room of a branch of tunnels "
             "that lead off in two directions. Unlike the rest "
             "of this cave, this room is rather large. The walls "
             "are not smooth as if someone had dug it out with tools. "
             "This place was carved out by other means. Some moisture "
             "has formed on the ceiling and every now and then some "
             "drips down on your head.");
    set_smell("default", "A faint wiff of decay can be picked up");
    set_listen("default", "You hear nothing but the beating of your own heart");
    set_exits((["south" : ROOMS"cave1",
                "northeast" : ROOMS"cave3",
                "northwest" : ROOMS"cave4" ]));
}


