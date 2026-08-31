#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "forest" : 1]) );
   set_short("In a jungle");
   set_long(
            "%^GREEN%^There are many trees covering the area. A worn path leads "
            "through the jungle but is partially covered by wild growing "
            "plants. The air is thick and humid making it hard to breathe. "
            "A spider web hangs in between two trees just off the path.%^RESET%^");
   set_items(([
            "trees" : "There are plenty of trees on each side of the path. "
                        " They are all different sizes and varieties, "
                        "but they all have an exotic look to them.",
            "path" : "An old, worn dirt path leads through the jungle. "
                 "It gets hard to see sometimes because the plants are "
                 "so dense with all the plantlife.",

            "plants" : "All sorts of different plant species grow in the jungle"
                 ". Most of them are huge compared to more domesticated plants "
                 "common to the land of Tirun.",
            "web" : "A very handsomely spun spider web hangs in between two "
                "trees just off the path. A big spider is walking across it "
                "towards some unlucky bug that flew too close to it."
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "Loud birds can be heard talking to eachother "
                 "from the treetops.");
   set_exits( ([ 
        "southwest" :  ROOMS "63",
        "east" :  ROOMS "60"]));
}
