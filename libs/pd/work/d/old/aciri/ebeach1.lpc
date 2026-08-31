#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^Northeastern stretch of the beach");
   set_day_long("%^BOLD%^%^WHITE%^"
     "The beach curves and heads north and west. This is the northeastern "
     "stretch of the beach. The hot sand provides all the heat for the beach, "
     "which is enough to drive someone mad. The sun provides no heat compared "
     "to the strange black sand. Footprints lead southwest and north.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "A cool night breeze blows the hot black sand into the air for a brief "
     "moment. The air is chilly and the moon provides no real light nor heat, "
     "yet the sand is burning hot. The beach makes a sudden turn here, from "
     "going east-west to north-south.");
   set_items(([
     "beach" : "The beach travels along the coast of the island.",
     "sand"  : "The burning sand gives off enough heat to make you sweat.",
     "footprints" : "They lead down every available path.",
     "coast" : "The beach is right along the island's coast."
   ]));
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "north"      : ROOMS"ebeach2",
      "southwest"  : ROOMS"beach7"
   ]));
}

string *query_tracks() { return ({ }); }
