#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("A grass hut");
   set_day_long(
     "The hut was made with many long, wide blades of grass and of large leaves "
     "that could only be found in a marsh or swamp. Wide leaves with a layer of "
     "grass above it have been laid out over the ground. Underneath the grass "
     "and leaves on the ground is a thick layer of dirt, providing a firm "
     "place to stand.");
   set_night_long(
     "The chill night air is enough to remind anyone that bricks and mortar do "
     "a far better job of retaining heat within a building than grass and "
     "leaves. The ground is firm and a comfortable change from the hot sand. "
     "Leaves and grass have been weaved into walls and a ceiling.");
   set_items(([
     "leaves" : "They are large and wide, the 'bricks'",
     "grass"  : "The grass is used to weave the leaves into a wall, the 'mortar'",
     ({"ceiling", "roof", "walls", "wall" }) : "The walls and ceiling are made "
                "out of grass and leaves.",
     "ground" : "A hard surface, unlike the sand outside this very door."
   ]));
   set_properties((["light" : 3, "night light" : 2, "indoors" : 1 ]));
   set_exits(([
      "north" : ROOMS"beach5"
   ]));
}

// string *query_tracks() { return ({ }); }
