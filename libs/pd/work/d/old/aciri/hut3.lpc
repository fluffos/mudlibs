#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("A grass hut");
   set_day_long(
     "The hut's roof was made with grass and wide leaves. Beneath a few layers "
     "of grass and leaves is a thick slab of mud used for the walls. Someone "
     "important must live here. An actual door frame has been molded with a "
     "cement-like mud. Refreshing daylight streams into the hut.");
   set_night_long(
     "The walls of this hut have been molded out of mud, covered with leaves and "
     "grass, suggesting someone important lives here. The moonlight and stars "
     "shine in through a window and door frame in the wall. The ground is made "
     "of packed down dirt.");
   set_items(([
     "ground" : "The firm ground is made of packed down dirt.",
     "dirt"   : "The muddy dirt must have been brought in from somewhere without "
                "all this sand..",
     "window" : "The window opening lets light in.",
     "walls"  : "Some sort of mud, leaves, and grass.",
     "grass"  : "Long and thick blades of grass.",
     "leaves" : "Each leaf is about two feet wide and three feet long."
   ]));
   set_properties((["light" : 3, "night light" : 2, "indoors" : 1 ]));
   set_exits(([
      "north" : ROOMS"beach6"
   ]));
}

// string *query_tracks() { return ({ }); }
