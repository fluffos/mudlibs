#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^Black sand beach, west of a grass hut");
   set_day_long("%^BOLD%^%^WHITE%^"
     "This part of the black sand beach leads just north and then spreads both "
     "east and west. A grass hut is right to the east of this very point. A "
     "couple other huts can be seen along the small beach. A ledge can be seen "
     "to the south.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "The beach grows even darker with the moon replacing the bright sun. The "
     "heat of the sand and the cool air causes the ground to slightly smoke. "
     "The smoke is in such a great proportion that it seems more like a thick "
     "fog. The humid smoke is refreshing when combined with the heat of the "
     "sand.");
   set_items(([
     "beach" : "The beach leads north then splits east and west.",
     "sand" : "The heat of the sand warms you.",
     "huts" : "Grass huts have been set up by somebody.",
     "ledge" : "You notice a sudden drop south of here.",
   ]));
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "south" : ROOMS"beach1",
      "north" : ROOMS"beach3"
   ]));
}

string *query_tracks() { return ({ }); }
