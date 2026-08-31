#include <std.h>
#include <pkcave.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 2,
                     "indoors" : 1,]));
    set_name("Cave5");
    set_long("Chills run up and down your spine as the cold "
             "air hits the small hairs on the back of your "
             "neck. The walls of this cave are spaced rather "
             "far apart maybe to allow something very large to pass "
             "through here. Tracks can be seen on the floor of this "
             "passage. Bones litter the floor as well.");
    set_items((["tracks" : "Large tracks in the soil",
                "bones" : "Scattered bones from past adventures who died here" ]));
    set_smell("default", "A faint wiff of decay can be picked up");
    set_listen("default", "You hear nothing but the beating of your own
heart");
    set_exits((["south" : ROOMS"cave4",
                "north" : ROOMS"cave6" ]));
}

   void reset()
{
    if(!present("dragon"))
        new(MOB"white_dragon")->move(this_object());
    if(!present("baby dragon"))
        new(MOB"tiny_dragon")->move(this_object());
}   
