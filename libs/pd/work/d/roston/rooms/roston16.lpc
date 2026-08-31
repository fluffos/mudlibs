#include <std.h>
#include <roston.h>
inherit ROOM;

void create() {
  ::create();      

set_name("four north of town square");
set_items((["snow"   : "A very deep white snow",
            "dirt"  : "A light brown mixture"]));        
set_properties((["light":2, "night light":3]));
set_short("A dirt path");
set_long("The white palace seems to be right in front of you. "
         "The dirt seems to be getting light, and the snow on "
         "side of the path seems to be getting fuller, and more "
         "white.");
           
        
set_exits( ([ "north" : ROOMS "roston17",
              "south" : ROOMS "roston15",
              "up"    : ROOMS "supply" ]));
}                                                             
