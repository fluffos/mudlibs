#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^On a black sand beach");
   set_day_long("%^BOLD%^%^WHITE%^"
     "The beach is covered in hot black sand. The sand is unusually hot to the "
     "touch, even for the daytime. The entire beach is composed of black sand. "
     "There is a very steep ledge, leading down to a boat landing here.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "Moonlight illuminates the black sand beach. The sand is warm to the touch, "
     "regardless of the chill night air. The beach leads north a little then "
     "ends abruptly. A few grass huts can be spotted from here. A ledge leads "
     "down to a boat landing.");
   set_items(([
     "landing" : "The landing has been partially concealed.",
     "sand" : "The black sand is strangely hot.",
     "ledge" : "The dirt ledge has tree roots growing out of it, so you can "
               "climb down."
   ]));
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "down" : ROOMS"landing",
      "north": ROOMS"beach2"
   ]));
}

string *query_tracks() { return ({ }); }
