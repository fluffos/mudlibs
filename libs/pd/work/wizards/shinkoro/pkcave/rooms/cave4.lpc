#include <std.h>
#include <pkcave.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 2,
                     "indoors" : 1,]));
    set_name("Cave4");
    set_long("Chills run up and down your spine as the cold "
             "air hits the small hairs on the back of your "
             "neck. The walls of this cave are spaced rather "
             "far apart maybe to allow something very large to pass "
             "through here. Tracks can be seen on the floor of this "
             "passage.");
    set_items((["wall" : "The walls are spaced for something large to pass through. "
                         "Seems there are claw marks on the rock.",
                "claw marks" : "Marks made from something that dug this passage.",
                "tracks" : "Large footprints of a 4 toed creature that must weigh alot "
                           "due to the depth of the print into the firm soil."
]));
    set_smell("default", "A faint wiff of decay can be picked up");
    set_listen("default", "You hear nothing but the beating of your own
heart");
    set_exits((["southeast" : ROOMS"cave[]",
                "north" : ROOMS"cave5" ]));
}
    void reset()
{
    if(!present("dragon"))
        new(MOB"tiny_dragon")->move(this_object());

}
