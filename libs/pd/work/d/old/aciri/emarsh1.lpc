#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^The edge of a marsh");
   set_day_long("%^BOLD%^%^BLACK%^"
     "The air is muggy and hot, not to mention increadibly humid. The watery "
     "mud on the ground bubbles and boils from the heat of the hot black sand "
     "just east of here. A black sand beach lies to the east. The ocean water "
     "goes east as far the eye can see.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "With the moonlight blocked by the thin marsh canopy, this part of the "
     "marsh is very dark at night. With the night and muddy ground combined, "
     "tracks are hard to find. A beach and ocean rest to the east of this point.");
   set_items(([
     "beach" : "The beach is just to the east of here.",
     "sand"  : "Hot black sand warms up the marsh.",
     "ground": "Muddy ground makes tracks hard to find.",
     "mud"   : "The wet mud covers all of the ground."
   ]));
   set_properties((["light" : 2, "night light" : 0, "swamp" : 1 ]));
   set_exits(([
      "east" : ROOMS"ebeach4"
   ]));
}

string *query_tracks() { return ({ }); }
