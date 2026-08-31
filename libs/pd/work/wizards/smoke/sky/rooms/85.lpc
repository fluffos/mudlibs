#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountain" : 1]) );
   set_short("Surrounded by mountains");
   set_long(
            "The tall mountains completely surround the small path. "
            "Palm trees and small shrubs grow along the trail. Grass "
            "grows wherever it can find some room. Some large rocks "
            "must have fallen down the mountain and now almost block "
            "off the path.");
   set_items(([
            "mountains" : "The mountains stretch in all directions. A mountain"
                        " wall denies any possibility of straying from "
                        "the path.",
            "shrubs" : "Small shrubs grow at random upon the ground.",
            "rocks" : "Some large rocks fell down the mountain and landed "
                "right here, almost blocking off the path.",
            "trees" : "A few palm trees grow here, providing a little bit of "
                "shade from the elements.",
            "path" : "A dirt path runs through the mountains. ",
            "grass" : "Grass covers the ground just off of the path."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "Occasionally a twig can be heard snapping from afar.");
   set_exits( ([ 
        "northwest" :  ROOMS "84",
        "east" :  ROOMS "86"]));
}
