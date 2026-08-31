#include <aciri.h>
#include <daemons.h>
#include <std.h>
inherit DOCKS;

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^Boat landing");
   set_day_long("%^BOLD%^%^WHITE%^"
     "The boat landing was built under a steep ledge, right by the "
     "the ocean side. The docks are in good working condition, but there is "
     "noone around to be seen. Cool blue waves splash onto the shore, spraying "
     "surf onto the hot black sand.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "The ocean water is a light grey in the moonlight. What stands "
     "out most about the surroundings of this unattended boat landing is the jet "
     "black sand. Even now, at night, the sand is hot. The docks are in fair "
     "condition, positioned in a slightly concealed manner, under a steep "
     "ledge.");
   set_items(([
     "landing" : "The landing is completely unattended.",
     "sand" : "The black sand is very hot to the touch.",
     "docks" : "Somebody tried to conceal them, but who and why?",
     "waves" : "Waves splash onto the hot sand.",
     "ledge" : "The dirt ledge has tree roots growing out of it. The steep "
               "ledge leads up to the island."
   ]));
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "up" : ROOMS"beach1"
   ]));
}

int *query_coords() { return OCEAN_D->query_coord_from_letter("c"); }

string *query_tracks() { return ({ }); }
