#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountain" : 1]) );
   set_short("Surrounded by mountains");
   set_long(
            "The path runs east and west through the mountains. Long grass "
            "and shrubs grow throughout the passage. Several palm trees stand "
            "off the path. Jagged rocks protrude from the walls of the mount"
            "ain. A birds nest can be seen high above perched on a ledge. Large "
            "footprints cover the ground on and off of the path.");
   set_items(([
            "mountain" : "The mountains stretch in all directions. A mountain "
                        "wall prevents access to the north and south of here.",
            "shrubs" : "Small shrubs grow at random upon the ground.",
            "footprints" : "Large, reptilian footprints cover the ground here,"
                " both on and off of the path.",
            "rocks" : "Jagged rocks protrude from the walls of the mountain. "
                "Some of the rocks are covered in bird poop.",
            "trees" : "A few palm trees grow here, providing a little bit of "
                "shade from the elements.",
            "path" : "A dirt path runs east and west, cut out of the grass. "
                "Several large footprints cover the path.",
            "nest" : "A birds nest is perched on a ledge high above. A steep "
                "wall of the mountain prevents access to the nest.",
            "ledge" : "A birds nest is perched high above on a ledge.",
            "grass" : "Grass covers the ground just off of the path."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "Occassionally a twig can be heard snapping from
afar.");
   set_exits( ([ 
        "east" :  ROOMS "17",
        "west" :  ROOMS "1"]));
}
