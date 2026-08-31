#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^On the beach, west of a marsh");
   set_day_long("%^BOLD%^%^WHITE%^"
     "This part of the beach is just west of a marsh. Mixed in with the warm "
     "black sand is some soft brown dirt. The black sand ends suddenly at a "
     "very steed ledge. At the bottom of the ledge is the ocean; in the ocean "
     "at the base of the ledge are deadly sharp rocks. The beach continues for "
     "a little, right next to the marsh.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "The night casts shadows on all things, and obviously the black sand "
     "doesn't help much to improve vision. Making it even harder to see, a dark "
     "marsh is right to the east of here. The sand is a little thicker, it is "
     "probably mixed with some of the dirt from the marsh; the sand is noticeably "
     "cooler.");
   set_items(([
     "sand"  : "No longer the blazing hot black sand, but still warm.",
     "beach" : "The beach ends just to the north.",
     "marsh" : "The marsh is cool and damp. The marsh is right to the east of "
               "this very point.",
     "ocean" : "There is no way into the ocean without the minor inconvenience "
               "of sudden and painful death.",
     "ledge" : "The only way to get to the water would be to jump over the ledge "
               "right onto the rocks.",
     "rocks" : "These rocks would shread anyone to pieces that fell on them.",
     "dirt"  : "Soft brown dirt has been mixed in with the sand, making it "
               "much cooler."
   ]));
   set_properties((["light" : 2, "night light" : 0, "beach" : 1 ]));
   set_exits(([
      "north" : ROOMS"wbeach4",
      "east"  : ROOMS"wmarsh1",
      "south" : ROOMS"wbeach2"
   ]));
}

string *query_tracks() { return ({ }); }
