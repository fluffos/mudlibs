#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^Western edge of a marsh");
   set_day_long("%^BOLD%^%^BLACK%^"
     "The edge of the marsh, right next to the beach is cool, but not "
     "uncomfortably so. A small ammount of the beach's black sand can be seen "
     "on the ground; it was probably blown into the marsh by the ocean winds. "
     "The murky, wet ground is the perfect place for the growth of the weeds, "
     "trees, ferns, and other underbrush that can be seen everywhere.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "The trees make it fairly hard to see during the night within this marsh. "
     "Everything seems a bit gloomier in a marsh, and this holds true here. All "
     "under the thin canopy of the marsh seems shadowy and dark, expeciallly at "
     "night.");
   set_items(([
     "marsh" : "You stand in the murky waters of the marsh.",
     "trees" : "The sparse trees form a thin cover over the marsh.",
     "sand"  : "A little bit of the beach's black sand has blown into the marsh.",
     "underbrush":"Underbrush grows everywhere!",
     "ferns" : "Ferns grow in abundance along with the other underbrush.",
     "canopy": "A very thin canopy of trees."
   ]));
   set_properties((["light" : 2, "night light" : 1, "swamp" : 1 ]));
   set_exits(([
      "north" : ROOMS"wmarsh2",
      "west"  : ROOMS"wbeach3",
   ]));
}

string *query_tracks() { return ({ }); }
