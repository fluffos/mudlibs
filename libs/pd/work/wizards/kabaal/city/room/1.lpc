#include <std.h>
#include <kabaal.h>
inherit ROOM;

void create()
{
 ::create();
set_short("lost in the rain forest");
   set_long("Animals are everywhere. The lush green leaves "
           "sparkle in the faint sunlight. The moist ground can "
           "hardly be seen from here, but climbing back "
           "down is impossible from here.");
set_items( 
          ([ "vines" : "The vines go from tree to tree.",
             "trees" : "The trees tower over you.",
             "ground": "You can hardly see it from here.",
             "monkeys" : "They seem to be moving quickly." ]) );
set_property("light", 2);
set_property("night light", 1);
set_smell("default", "The humid air stifils your senses.");
set_listen("default", "You hear animals squeeking.");
set_exits( (["north" :"/d/standard/rain_forest/canopy_s1",
              "south" : ROOMS "2"]) );
}
