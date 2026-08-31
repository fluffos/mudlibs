#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^On a black sand beach");
   set_day_long("%^BOLD%^%^WHITE%^"
     "Black sand stretches east and west along the length of the beach. The "
     "eerie black sand, for one reason or another, is always either warm or "
     "hot to the touch. Grass Huts have been erected along the beach. This "
     "must be the center of a small village or community."); 
   set_night_long("%^BOLD%^%^WHITE%^"
     "The black sand beach has had grass huts set up all over it. The beach only "
     "goes a little further north, but conintues east and west for a while. The "
     "grass huts look a little primitive in origin. Many footprints have been "
     "left in the sand around here.");
   set_items(([
     "footprints":"Footprints lead everywhere, they are in too much of a clutter "
                  "to follow any perticular tracks.",
     "beach" : "The beach coninues east and west for a while.",
     "sand" : "The sand is warm here, though not too hot.",
     "huts" : "Crude grass huts have been set up on the beach.",
   ]));
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "south" : ROOMS"beach2",
      "north" : ROOMS"beach8",
      "east"  : ROOMS"beach6",
      "west"  : ROOMS"beach4"
   ]));
}

string *query_tracks() { return ({ }); }
