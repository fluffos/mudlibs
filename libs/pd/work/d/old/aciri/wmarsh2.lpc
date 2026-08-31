#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^Western edge of a marsh");
   set_day_long("%^BOLD%^%^BLACK%^"
     "The marsh waters continuously get deeper and mushier. The marsh ground "
     "refills any footprint a minute after it is left, making it increadibly "
     "difficult to find any tracks in the marsh. The trees to the west make it "
     "impossible to get back onto the beach from here. The sunlight warms up the "
     "otherwise chilly marsh.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "The moonlight breaks through the thin canopy of trees to shine onto the "
     "deep, mushy ground. With the current lighting and the soft ground "
     "refilling any footprints, tracks are impossible to find. Several large "
     "trees block passage west, onto the beach.");
   set_items(([
     "beach" : "That cannot be seen from here, the trees block the view.",
     "canopy": "A thin canopy, providing neither protection nor shelter.",
     "ground": "The ground makes it impossible to track somebody."
   ]));
   set_properties((["light" : 2, "night light" : 1, "swamp" : 1 ]));
   set_exits(([
      "north" : ROOMS"wmarsh3",
      "south" : ROOMS"wmarsh1",
   ]));
}

string *query_tracks() { return ({ }); }
