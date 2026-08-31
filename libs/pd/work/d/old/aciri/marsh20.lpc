#include <aciri.h>
#include <std.h>
inherit PIER;

string *query_tracks();

void create() {
 ::create();
   set_short("In a gloomy marsh");
   set_day_long(""
     "%^BOLD%^%^BLACK%^The marsh is dead and slimy, terrifyingly hideous dead"
     "trees prevent any kind of light from getting in.  The fog isn't very "
     "noticable anymore.  A few tombstones can be seen east of here, on the "
     "other side of an impassable, black fence.  Shapes seem to be moving around "
     "within.  The mud actually seems to be formed into a tiled path here...");
   set_night_long(""
     "%^BOLD%^%^BLACK%^The marsh is dead and slimy, terrifyingly hideous dead"
     "trees prevent any kind of light from getting in.  The fog isn't very "
     "noticable anymore.  A few tombstones can be seen east of here, on the "
     "other side of an impassable, black fence.  Shapes seem to be moving around "
     "within.  The mud actually seems to be formed into a tiled path here...");
   set_items(([
     "mud"   : "Branches are halfway sunken into it. The mud is firm enough to "
               "provide real support here.",
     "ground": "The ground is more like dirt here than mud.  It looks to be tiled...",
     ]));
   set_properties((["light" : 2, "night light" : 1, "swamp" : 1 ]));
   set_exits(([
      "west"  : ROOMS"marsh19",
      "east"  : ROOMS"marsh21",
   ]));
}

string *query_tracks() { return ({ }); }
