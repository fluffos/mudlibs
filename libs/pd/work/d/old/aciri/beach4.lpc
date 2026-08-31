#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^BOLD%^%^WHITE%^On a beach");
   set_day_long("%^BOLD%^%^WHITE%^"
     "The warm black sand beach leads east and west from here. A hut has been "
     "set up north of here, with the doorway facing this direction, making it "
     "possible to enter. The sun shines down onto the beach brightly. Footprints "
     "lead everywhere, making it nearly impossible to track someone.");
   set_night_long("%^BOLD%^%^WHITE%^"
     "Warm black sand leads east and west along the beach. There is a hut north "
     "and another southwest. The latter of the two huts is unaccessible from "
     "this angle. The moonlight shows hundreds of footprints leading in almost "
     "every direction, making it impossible to find someone's tracks.");
   set_items(([
     "footprints":"Footprints lead everywhere, they are in too much of a clutter "
                  "to follow any perticular tracks.",
     "beach" : "The beach coninues east and west for a while.",
     "sand" : "The sand is as warm as freshly spilt blood.",
     "huts" : "Huts have been erected on the beach.",
   ]));
   set_properties((["light" : 2, "night light" : 1, "beach" : 1 ]));
   set_exits(([
      "east" : ROOMS"beach3",
      "north": ROOMS"hut1",
      "west" : ROOMS"beach5"
   ]));
}

string *query_tracks() { return ({ }); }
