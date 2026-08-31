#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountain" : 1]) );
   set_short("Surrounded by mountains");
   set_long(
            "The mountains twist and turn as the path winds through "
            "them. Large palm trees grow along the path. Some carvings"
            " in the mountainside of small creatures are on both "
            "sides of the mountain. Some shrubs grow along the mountains"
            " face.");
   set_items(([
            "mountains" : "The mountains stretch in all directions. A mountain"
                        " wall denies any possibility of straying from "
                        "the path.",
            "shrubs" : "Small shrubs grow at random upon the ground.",
            "trees" : "A few palm trees grow here, providing a little bit of "
                "shade from the elements.",
            "path" : "A dirt path runs through the mountains. ",
            "carvings" : "These carvings in the mountain face look like "
                "some dwarves. They look really old, ancient travellers "
                "probably carved them long ago."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "Occassionally a twig can be heard snapping from
afar.");
   set_exits( ([ 
        "southwest" :  ROOMS "82",
        "southeast" :  ROOMS "84"]));
}
