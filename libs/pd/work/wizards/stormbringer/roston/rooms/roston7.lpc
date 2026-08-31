#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();     

set_name("South of the Town Square");
set_items((["snow"   : "A very deep white snow",
            "dirt"  : "A light brown mixture"]));        
set_properties((["light":2, "night light":3]));
set_short("A dirt path");
set_long("Welcome to the town of Roston.  To the west a small "
         "armory can be seen.  The main road here has been cleaned "
         "of snow and leads to the square, which is north of here. ");
set_smell("default","The smell of leather is thick in the air.");
add_pre_exit_function("south", "go_south");
set_exits( ([ "west"  : ROOMS "roston8",
              "south" : ROOMS "r_crack",
              "north" : ROOMS "roston6",
              "east"  : ROOMS "roston10"]));
}
int go_south() {
  if(!this_player()->is_player()) return 0;
  return 1;
}
