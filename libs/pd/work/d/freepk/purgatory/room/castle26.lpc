#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     add_pre_exit_function("northeast","go_stairs");
     set_name("castle26");
     set_short("The Purgatory Castle");
     set_long("%^CYAN%^In the outer hallways of the castle, not much is going on. "
"%^CYAN%^Not many people wander this far out and the only servants "
"%^CYAN%^that can be seen are dusting and doing other chores.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"       : 1,
        "no steal"    : 1,
]));
//     set_listen("default", "Screams can faintly be heard from the northeast...");
     set_listen("default", "Screams can faintly be heard in the distance.");
 set_exits( (["northwest" : ROOMS"castle28", 
              "southeast" : ROOMS"castle27",
              "southwest" : ROOMS"castle13",
//              "northeast" : ROOMS"dungeon1",
  ]) );



}
int go_stairs() {
  if(!this_player()->is_player()) return 0;
  return 1; }
