#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^On the western beach");
   set_day_long("%^BOLD%^%^WHITE%^"
     "The black sand beach makes a curve, and starts heading north along the "
     "edge of the island. Surf sprays up over the unclimbable ledge to the west. "
     "The cool blue ocean is a mockery to the scorching hot sand on the beach. "
     "The breeze does not take away a bit of the sand's bite.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "The heat of the scorching black sand makes the moonlight seem extremely "
     "cold. The sand is a jet, solid black. The only break of color in the sand "
     "is a rock here and there. Surf sprays over a dark ledge, and sizzles as it "
     "hits the sand.");
   set_items(([
     "sand" : "Scorching hot sand makes the ocean water sizzle when they "
              "contact.",
     "ledge": "The ledge is far too steep to climb down.",
     "ocean": "The refreshing ocean waters extend as far as the eye can see.",
     "surf" : "The surf sprays up onto the sand, only to be dissolved."
   ]));
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "north"     : ROOMS"wbeach2",
      "southeast" : ROOMS"beach5"
   ]));
}

string *query_tracks() { return ({ }); }
