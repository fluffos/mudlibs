#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();           

set_name("east of town square");
set_items((["snow"   : "The snow is very deep here.",
            "dirt"  : "The light brown dirt is very soft and warm."]));        
set_properties((["light":2, "night light":3]));
set_short("A dirt path");
set_long("The path has a strange white glow to it. There are " 
         "rose petals all over the ground. The white palace "
         "is right in front of you.");

set_exits( ([ "east" : ROOMS "roston20",
              "west" : ROOMS "roston18" ]));
}                                                
