#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^On a beach");
   set_day_long("%^BOLD%^%^WHITE%^"
     "Many footprints lead all over the beach, overlapping and crossing tracks "
     "so many times, it would be nearly impossible for an expert tracker to "
     "trace any certain track. The hot black sand leads northwest as the beach "
     "continues. A hut was erected just south of here.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "The night and black sand combined make it impossible to find tracks along "
     "the beach. Sand continues northwest along the beach. There is a hut just "
     "south of this point, the door is facing this direction.");
   set_items(([
     "footprints":"Footprints lead everywhere, in a confusing jangle.",
     "beach" : "The beach makes a twist to the northwest.",
     "sand" : "The black sand pulses hot, warm, hot, etc.",
     "hut"  : "Grass has been laid in place of bricks to form a hut."
   ]));
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "east"      : ROOMS"beach4",
      "south"     : ROOMS"hut2",
      "northwest" : ROOMS"wbeach1"
   ]));
}

string *query_tracks() { return ({ }); }
