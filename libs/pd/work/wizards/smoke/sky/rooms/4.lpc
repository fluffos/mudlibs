#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountain" : 1]) );
   set_short("Surrounded by mountains");
   set_long(
            "The path turns sharply leading south and east. The mountains tower"
            " in every direction. Jagged rocks stick out from the walls of the "
            "mountains. Grass and a few shrubs grow just off of the path. "
            "Several large reptilian footprints cover the ground on and off "
            "of the path. A few palm trees grow randomly about.");
   set_items(([
            "mountains" : "The mountains stretch in all directions. A mountain"
                        " wall prevents access to the north and west of here.",
            "shrubs" : "Small shrubs grow at random upon the ground.",
            "footprints" : "Large, reptilian footprints cover the ground here,"
                " both on and off of the path.",
            "rocks" : "Jagged rocks protrude from the walls of the mountain. "
                "Some of the rocks are covered in bird poop.",
            "trees" : "A few palm trees grow here, providing a little bit of "
                "shade from the elements.",
            "path" : "A dirt path runs south and east, cut out of the grass. "
                "Several large footprints cover the path.",
            "grass" : "Grass covers the ground just off of the path."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "Occasionally a twig can be heard snapping from afar.");
   set_exits( ([ 
        "east" :  ROOMS "5",
        "south" :  ROOMS "3"]));
}
