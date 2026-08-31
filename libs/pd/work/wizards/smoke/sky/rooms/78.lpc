#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountain" : 1]) );
   set_short("Surrounded by mountains");
   set_long(
            "The path runs through the giant mountains. Steep walls "
            "dictate the directions that can be travelled. Green "
            "grass grows on the flat land. Small shrubs line the "
            "mountain walls. A few palm trees grow along the trail. "
            "A few birds are perched on a ledge high above.");
   set_items(([
            "mountains" : "The mountains stretch in all directions. The "
                        "mountain walls dictate where the path leads. ",
            "shrubs" : "Small shrubs grow at random upon the ground.",
            "birds" : "A few birds are perched on a ledge high above. "
                "They aren't paying any attention to what's going on down "
                 "on the trail.",
            "rocks" : "Jagged rocks protrude from the walls of the mountain. "
                "Some of the rocks are covered in bird poop.",
            "trees" : "A few palm trees grow here, providing a little bit of "
                "shade from the elements.",
            "path" : "A dirt path leads wherever the huge mountains "
                        "will allow. ",
            "grass" : "Grass covers the ground just off of the path."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "Occasionally a twig can be heard snapping from afar.");
   set_exits( ([ 
        "northwest" :  ROOMS "77",
        "south" :  ROOMS "79"]));
}
