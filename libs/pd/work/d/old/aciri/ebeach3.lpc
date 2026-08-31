#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^Northeastern stretch of the beach");
   set_day_long("%^BOLD%^%^WHITE%^"
     "Ripples form in the air from the heat of the sand. The black sand still "
     "continues north, then becomes a marsh. The saphire blue ocean tosses and "
     "flows constantly cool and refreshing. Even the shade of the dark marsh is "
     "a welcome relief from the sweltering heat of the sand.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "The nighttime darkness is no relief from the sweltering heat. The shadowy "
     "grey ocean waves splash onto the shore, then sizzle and dissolve. Searing "
     "black sand covers the beach north.");
   set_items(([
     "sand" : "The hot sand continues north for a little while.",
     "beach": "The beach is almost at it's end.",
     "ocean": "It looks cool and refreshing.",
   ]));
   set_listen("default", "The air hisses and whistles with the increadible heat "
              "the sand lets off.");
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "north" : ROOMS"ebeach4",
      "south" : ROOMS"ebeach2"
   ]));
}

string *query_tracks() { return ({ }); }
