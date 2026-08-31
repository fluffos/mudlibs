#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("castle25");
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
 set_exits( (["northeast" : ROOMS"castle15", 
              "southwest" : ROOMS"castle20",
              "southeast" : ROOMS"castle19"]) );



}


