#include <std.h>
#include <kabaal.h>
inherit ROOM;

void create()
{
 ::create();
set_short("lost in the rain forest");
   set_long("The path turns off to the northeast. The path is relatively "
           "straight despite the density of the trees. Birds fly over head "
           "and animals play in the forest. The air is damp, as is the ground.");
set_items( 
          ([ "path" : "It leads west to west and northeast.",
	     "ground": "It sinks as you walk, yet you can't see it completely.",
             "forest" : "Tall trees surround you." ]) );
set_property("light", 2);
set_property("night light", 1);
set_smell("default", "The humid air stifils your senses.");
set_listen("default", "You hear animals squeeking.");
set_exits( (["west" :ROOMS "e1",
              "northeast" : ROOMS "logan1"]) );
}
