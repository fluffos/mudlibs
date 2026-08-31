#include <std.h>
#include <pkcave.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([ "light" : 2,
                      "indoors" : 1,]));
    set_name("Cave3");
    set_long("Damp and moist, this cave makes you feel unnerved. Seems its getting hotter the longer you stay "
             "in this place. The walls seem to be eminating a low heat that keeps getting stronger. "
           "You notice there are still large tracks on the cave floor.");
    set_items((["wall" : "The walls are spaced for something large to pass through. " 
                         "Seems there are claw marks on the rock.",
                "claw marks" : "Marks made from something that dug this passage.",
                "tracks" : "Large footprints of a 4 toed creature that must weigh alot "
                           "due to the depth of the print into the firm soil." ]));
    set_smell("default", "A faint wiff of decay can be picked up");
    set_listen("default", "You hear nothing but the beating of your own heart");
    set_exits((["southwest" : ROOMS"cave[]",
                "northeast" : ROOMS" " ]));
}
