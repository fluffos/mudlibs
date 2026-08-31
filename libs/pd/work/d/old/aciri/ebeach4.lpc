#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^Northeastern tip of the becah");
   set_day_long("%^BOLD%^%^WHITE%^"
     "The hot black sand, and beach, ends here and becomes a dark marsh. The "
     "sand is hot, but not as much as before, probably because of the cool water "
     "and dirt in the marsh. Waves crash onto the beach and are pulled back by "
     "the force of the water.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "The shadows of night close in over everything, leaving little to be seen. "
     "So many footprints lead in and out of the marsh here that in combination "
     "with the night, not even a skilled tracker could trace somebody. The once "
     "saphire, now grey ocean crashes softly onto the beach.");
   set_items(([
     "sand" : "The sand is not as hot here, more of an uncomfortable warm.",
     "beach": "The beach gives way to a marsh here.",
     "ocean": "Constantly in motion, the waves crash onto the sand.",
   ]));
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "north" : ROOMS"emarsh2",
      "west"  : ROOMS"emarsh1",
      "south" : ROOMS"ebeach3"
   ]));
}

string *query_tracks() { return ({ }); }
