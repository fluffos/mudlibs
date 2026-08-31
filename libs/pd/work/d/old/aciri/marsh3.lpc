#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^Near the edge of a marsh");
   set_day_long("%^BOLD%^%^BLACK%^"
     "The edge of the marsh can be seen south, then a hill prevents further "
     "viewing to the south. Thin rays of sunlight manage to enter the confines "
     "of the marsh. Soft dirt surrounds pools of muddy water with turtles and "
     "small reptiles and fish in it.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "Long pools of water shine and reflect the moonlight that manages to "
     "penetrate the darkness of the marsh. The edge of the marsh can be seen "
     "to the south, but vision ends at a dark object in the center of the path. "
     "Soft dirt surround the large pools of muddy water.");
   set_items(([
     "pools" : "Pools of very watery mud are surrounded by soft dirt.",
     "dirt"  : "The soft dirt is more alike to mud than to dirt.",
     "edge"  : "The very edge of the marsh is to the south.",
     "hill"  : "A steep hill blocks most vision to the edge of the marsh.",
     "fish"  : "They are too small to catch, just tadpoles and lizards."
   ]));
   set_properties((["light" : 2, "night light" : 1, "swamp" : 1 ]));
   set_exits(([
      "south" : ROOMS"marsh2",
      "north" : ROOMS"marsh4",
   ]));
}

string *query_tracks() { return ({ }); }
