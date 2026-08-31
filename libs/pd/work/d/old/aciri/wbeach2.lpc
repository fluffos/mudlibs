#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^On the western beach");
   set_day_long("%^BOLD%^%^WHITE%^"
     "The hot black sand is not as hot as it was closer to the docks, but is "
     "hot enough to burn. The beach leads a little bit north, then becomes a "
     "marsh. The ocean looks great for a nice, refreshing swim; it's just too "
     "bad the ledge leading down to the ocean is too steep of a drop to allow "
     "anyone to decend to the water, and the sharp rocks jutting out of the "
     "water prevent any diving.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "The night is cool near to the marsh, but the sand on the ground, though it "
     "is not as hot here, is still burning hot. Because of a steep ledge and "
     "many sharp rocks in the water, it is impossible to enter the cool night "
     "water from here. The beach becomes a dark marsh a little north of here.");
   set_items(([
     "marsh" : "The sand ends for another unstable surface; a marsh.",
     "sand"  : "A little cooler here, but not much.",
     "ledge" : "Don't think about it.",
     "rocks" : "Those rocks could easily become your deathbed with a single "
               "slip.. or push.",
     "ocean" : "There is absolutely no way of getting into it from here.",
     "water" : "It would feel so good, so refreshing.."
   ]));
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "north" : ROOMS"wbeach3",
      "south" : ROOMS"wbeach1"
   ]));
}

string *query_tracks() { return ({ }); }
