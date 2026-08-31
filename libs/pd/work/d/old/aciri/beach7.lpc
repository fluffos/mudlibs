#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^Corner on the beach, north and west");
   set_day_long("%^BOLD%^%^WHITE%^"
     "The beach is hot, not from the sun above, but from the smoldering black "
     "sand on the ground. The heat of the sun only intensifies the almost "
     "unbearable sand. Ocean water as far as the eye can see, just past the "
     "burning black sand. Footprints lead all over the place, but mainly up "
     "to a grass hut, just to the north.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "The hot black sand sizzles and smokes in the cool night air. A hut of some "
     "sort is north of here. The ocean extends as far as the mortal eye can see, "
     "an ever constant, cool, refreshing mass of water. The hut is missing it's "
     "roof, possibly it was blown off during a storm.");
   set_items(([
     "ocean" : "It seems as the ocean is there taunting you.",
     "smoke" : "Smoke rises from the change in temerature between the sand and "
               "the air.",
     "sand"  : "Even hotter here than before, the sand is smoldering.",
     "footprints":"They lead every which way.",
     "hut" : "The grass hut's root has been blown off."
   ]));
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "north"      : ROOMS"hut4",
      "west"       : ROOMS"beach6",
      "northeast"  : ROOMS"ebeach1"
   ]));
}

string *query_tracks() { return ({ }); }
