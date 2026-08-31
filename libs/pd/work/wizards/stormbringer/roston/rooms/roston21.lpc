#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();          

set_name("east of town square");
set_items((["snow"  : "A deep white snow",
            "dirt"  : "A light brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("A dirt path");
set_long("You are on the east side of town, the church is "
         "is right in front of you. The snow is melting "        
         "in the small bit of warmth.");

set_exits( ([ "east" : ROOMS "roston22",
              "west" : ROOMS "roston12" ]));
}                                                                     
