#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^Western tip of the beach");
   set_day_long("%^BOLD%^%^WHITE%^"
     "This is the western tip of the beach, the point at which the hot black "
     "sand ends. The beach gives way to a thick marsh. The trees and vines "
     "prevent any passage east, into the marsh, both east and north. The beach "
     "is south of here.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "The sand ends here, at the shadowy marsh trees, vines, and other foliage. "
     "The black sand is just barely warm here, because it is mixed with much of "
     "the dirt from the marsh. The marsh shadows are cast down across this part "
     "of the beach.");
   set_items(([
     "beach"  : "The beach ends here, at the begining of the marsh.",
     "shadows": "Shadows come from the marsh and spread onto the beach.",
     "marsh"  : "A thick marsh stops any movement north.",
     "sand"   : "The sand is more like arm dirt now.",
   ]));
   set_properties((["light" : 2, "night light" : 2, "beach" : 1 ]));
   set_exits(([
      "south" : ROOMS"wbeach3"
   ]));
}

string *query_tracks() { return ({ }); }
