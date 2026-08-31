#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountain" : 1]) );
   set_short("Surrounded by mountains");
   set_long(
            "The path turns slightly here, leading southwest and east. The "
            "mountains surround the path and some shrubs grow off the sides "
            "of the path. A few palm trees grow at random around here and they"
            " provide a little bit of shade. Large reptilian footprints cover "
            "the ground on and off of the path. Some jagged rocks poke out "
            "of the mountain. A birds nest can be seen on a ledge high
above.");
   set_items(([
            "mountain" : "The mountains stretch in all directions. A mountain "
                        "wall prevents access to any direction other than "
                        "southwest or east.",
            "shrubs" : "Small shrubs grow at random upon the ground.",
            "footprints" : "Large, reptilian footprints cover the ground here,"
                " both on and off of the path.",
            "rocks" : "Jagged rocks protrude from the walls of the mountain. "
                "Some of the rocks are covered in bird poop.",
            "trees" : "A few palm trees grow here, providing a little bit of "
                "shade from the elements.",
            "path" : "A dirt path runs southwest and east, cut "
                "out of the grass. Several large footprints cover the path.",
            "nest" : "A large birds nest is perched high upon a ledge that "
                "seems like it might be accessable. Someone might be able "
                "to climb up and investigate further.",
            "grass" : "Grass covers the ground just off of the path."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "Occasionally a twig can be heard snapping from afar.");
   set_exits( ([ 
        "southwest" :  ROOMS "18",
        "climb" : ROOMS "nest",
        "east" :  ROOMS "20"]));
set_invis_exits(({"climb"}));
}
