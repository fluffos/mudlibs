#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^On a black sand beach");
   set_day_long("%^BOLD%^%^WHITE%^"
     "The hot black sand is spread over the beach. Not at all a thin coat atop "
     "something else, the sand goes down pretty deep. The sweltering heat of the "
     "sand is almost unbearable. Waves flow towards the island, and crash against "
     "the hot sand, dissolving. The motion of the waves is constant, and quite "
     "hypnotical.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "The stars and moon are the only light that reach the hot black sand on the "
     "beach of this island. The sand, even now at night, is increadibly hot. The "
     "cool ocean waves can be seen crashing onto the hot sand, and quickly "
     "dissolving, an enchanting view in the moonlight.");
   set_listen("default", "The sand hisses from it's intense heat.");
   set_items(([
     "sand"  : "The swelteringly hot sand covers the beach.",
     "ocean" : "A cool blue mass with waves.",
     "waves" : "They dissolve upon contact with the sweltering heat of the sand.",
     "beach" : "The beach continues west and east."
   ]));
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "south" : ROOMS"hut3",
      "east"  : ROOMS"beach7",
      "west"  : ROOMS"beach3"
   ]));
}

string *query_tracks() { return ({ }); }
