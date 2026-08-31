#include <std.h>
#include <kabaal.h>
inherit ROOM;

void create()
{
 ::create();
set_short("lost in the rain forest");
   set_long("A hidden path leads east some more. The forest is "
           "dense but the path is visible. The moist ground almost "
           "seems to sink a little bit under your feet.");
set_items( 
          ([ "path" : "It leads west to east.",
	     "ground": "It sinks as you walk, yet you can't see it completely.",
             "forest" : "Tall trees surround you." ]) );
set_property("light", 2);
set_property("night light", 1);
set_smell("default", "The humid air stifils your senses.");
set_listen("default", "You hear animals squeeking.");
set_exits( (["west" :ROOMS "5",
              "east" : ROOMS "e2"]) );
}

