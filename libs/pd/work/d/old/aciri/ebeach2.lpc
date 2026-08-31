#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^Northeastern stretch of the beach");
   set_day_long("%^BOLD%^%^WHITE%^"
     "The hot sands of the beach continue north from here. The black sand quakes "
     "from the heat, almost as if it were boiling. The sand only grows hotter "
     "and hotter; one can't help but wonder what, if not the sun, causes the "
     "horrid sand to heat up so much. The cool ocean waters splash onto the "
     "sand, only to boil and dissolve.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "The hissing and boiling of water can be heard, but the dark night does not "
     "allow vision of what is happening. The dim moonlight is the only lighting "
     "available, thanks to clouds blocking out all the star's light. Cool ocean "
     "waves splash up onto the shore.");
   set_items(([
     "waves" : "Waves splash onto the shore, and dissolve shortly after.",
     "sand"  : "The heat unnaturally keeps growing from the sand.",
     "beach" : "The beach and sand continue north for a bit."
   ]));
   set_listen("default", "The bubbling of boiling water can be heard.");
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "north" : ROOMS"ebeach3",
      "south" : ROOMS"ebeach1"
   ]));
}

string *query_tracks() { return ({ }); }
