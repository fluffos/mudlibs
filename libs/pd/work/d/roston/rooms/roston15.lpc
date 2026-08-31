#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();     

set_name("three north of town square");
set_items((["snow"   : "A very deep white snow",
            "dirt"  : "A light brown mixture"]));     
set_properties((["light":2, "night light":3]));
set_short("A dirt path");
set_long("The dirt on the path seems to a light brown. "
         "There is snow all over the sides of the path. "
         "The white palace seems to be getting closer and "
         " closer.");

set_exits( ([ "north" : ROOMS "roston16",
              "south" : ROOMS "roston14"]));
//            "west"  : ROOMS "roston25" ]));
}                                                             
