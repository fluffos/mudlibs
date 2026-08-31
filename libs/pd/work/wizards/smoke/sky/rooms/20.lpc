#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountain" : 1]) );
   set_short("Surrounded by mountains");
   set_long(
            "The path runs east and west through the mountains. Plants and "
            "shrubs cover the ground on both sides of the path. A jungle "
            "opens up to the east. Thousands of trees are growing in a "
            "valley of the mountain. Large reptilian footprints cover the "
            "ground on and off of the path. Large scratches adorn the "
            "walls of the mountain.");
   set_items(([
            "mountain" : "The mountains stretch in all directions. A mountain "
                        "wall prevents access to the north and south of here.",
            "shrubs" : "Small shrubs grow at random upon the ground.",
            "footprints" : "Large, reptilian footprints cover the ground here,"
                "both on and off of the path.",
            "rocks" : "Jagged rocks protrude from the walls of the mountain. "
                "Some of the rocks are covered in bird poop.",
            "trees" : "Thousands of trees are east of here, making up a "
                "huge jungle.",
	    "jungle" : "Thousands of trees are east of here, making up a"
		"huge jungle.",
            "path" : "A dirt path runs east and west, cut out of the grass. "
                "Several large footprints cover the path.",
            "scratches" : "Whatever did that was not only big, but probably "
                "mean, too.",
            "grass" : "Grass covers the ground just off of the path."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "Occasionally a twig can be heard snapping from afar.");
   set_exits( ([ 
        "east" :  ROOMS "21",
        "west" :  ROOMS "19"]));
}
