#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountain" : 1]) );
   set_short("Surrounded by mountains");
   set_long(
            "The path turns slightly here, leading northwest and south. The "
            "mountains surround the path and some shrubs grow off the sides "
            "of the path. A few palm trees grow at random around here and they"
            " provide a little bit of shade. Large reptilian footprints cover "
            "the ground on and off of the path. Some jagged rocks poke out "
            "of the mountain.");
   set_items(([
            "mountain" : "The mountains stretch in all directions. A mountain "
                        "wall prevents access to any direction other than "
                        "northwest or south.",
            "shrubs" : "Small shrubs grow at random upon the ground.",
            "footprints" : "Large, reptilian footprints cover the ground here,"
                " both on and off of the path.",
            "rocks" : "Jagged rocks protrude from the walls of the mountain. "
                "Some of the rocks are covered in bird poop.",
            "trees" : "A few palm trees grow here, providing a little bit of "
                "shade from the elements.",
            "path" : "A dirt path runs northwest and south, cut "
                "out of the grass. Several large footprints cover the path.",
            "grass" : "Grass covers the ground just off of the path."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "Occasionally a twig can be heard snapping from afar.");
   set_exits( ([ 
        "northwest" :  ROOMS "9",
        "south" :  ROOMS "11"]));
}
