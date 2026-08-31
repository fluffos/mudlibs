#include <aciri.h>
#include <std.h>
inherit PIER;

string *query_tracks();

void create() {
 ::create();
   set_short("In a gloomy marsh");
   set_day_long(""
     "%^BOLD%^%^BLACK%^The marsh is dead and slimy, terrifyingly hideous dead"
     "trees prevent any kind of light from getting in.  A dense fog rolls around "
     "aimlessly to the east, making it difficult to see much.  A large pond is "
     "located west of here.");
   set_night_long(""
     "%^BOLD%^%^BLACK%^The marsh is dead and slimy, terrifyingly hideous dead "
     "trees prevent any kind of light from getting in.  A dense fog rolls around "
     "aimlessly to the east, making it difficult to see much.  A large pond is "
     "located west of here.");
   set_items(([
     "pond"  : "This pond would be great for fishing in.",
     "mud"   : "Branches are halfway sunken into it. The mud is firm enough to "
               "provide real support here.",
     "ground": "The ground is more like dirt here than mud.",
     ]));
   set_properties((["light" : 2, "night light" : 1, "swamp" : 1 ]));
   set_exits(([
      "west"  : ROOMS"marsh8",
      "east"  : ROOMS"marsh20",
   ]));
}

string *query_tracks() { return ({ }); }
