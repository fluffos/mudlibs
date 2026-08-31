#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountain" : 1]) );
   set_short("Surrounded by mountains");
   set_long(
            "The path runs northeast and west through the mountains. Plants cover "
            "the ground on both sides of the path. Several shrubs clutter against"
            "the north wall and a few others grow randomly off the path. Jagged"
            " rocks come out from the walls of the mountain. A few palm trees grow"
            " at random throughout the passage. Large footprints cover the ground"
            " both on and off of the path.");
   set_items(([
            "mountain" : "The mountains stretch in all directions. A mountain "
                        "wall only allows access to the northeast and west.",
            "shrubs" : "Small shrubs grow at random upon the ground. Several "
                "shrubs clutter together along the north wall.",
            "footprints" : "Large, reptilian footprints cover the ground here,"
                " both on and off of the path.",
            "north wall" : "Behind several shrubs that are clumped together, "
                "there appears to be a hole entering into the face of the "
                "northern wall of the mountain.",
            "rocks" : "Jagged rocks protrude from the walls of the mountain. "
                "Some of the rocks are covered in bird poop.",
            "trees" : "A few palm trees grow here, providing a little bit of "
                "shade from the elements.",
            "path" : "A dirt path runs northeast and west, cut out of the grass."
                " Several large footprints cover the path.",
            "hole" : "There is a hole behind the shrubs that line against the"
                " north wall. It's hard telling what might reside in there.",
            "grass" : "Grass covers the ground just off of the path."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "Occassionally a twig can be heard snapping from
afar.");
   set_exits( ([ 
        "northeast" :  ROOMS "12",
        "hole" :  ROOMS "hole1",
        "west" :  ROOMS "14"]));
set_invis_exits(({"hole"}));
}
