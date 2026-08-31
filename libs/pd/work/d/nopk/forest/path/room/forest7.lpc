#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
    set_short("A path in the forest");
    set_long(
      "This path cuts through the forest. The trees grow thick, thier "
      "canopies entertwining blotting out the sky. Small animals play in the "
      "trees. Bushes and undergrowth make leaving the path impossible."
    );
    set_items(([
({"trees", "forest"}) : "Trees of the forest surround the path.",
   "path"    : "The path was cut through the forest.",
   "animals" : "A couple of small squirrels play in the trees.",
   "bushes"  : "The bushes are think and lush making it impossible to traverse through them.",
    ]));
    set_exits( ([ 
       "south" :  "/d/nopk/forest/path/room/forest6",
       "northeast" :  "/d/forest/nwvforest1/rooms/room1",
       "north"  : "/d/nopk/forest/path/room/forest8"
    ]) );
}
