#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
    set_short( "a small shack" );
    set_long("This small shack is tattered and void of any permanent fixtures.  The windows are boarded up, but there is a small lantern in the corner to illuminate the room.  It looks as if someone has been hiding out here.");
set_exits(([
"out" : ROOMS"tundra/hidden",

]));
    set_items( ([

]) );
    set_smell("default",  "The wood seems to be rotting, creating a pungent odor.");
    set_listen("default", "It is very silent and still.");

        if(!present("dthief"))
          new(MOB "dthief")->move(this_object());
}
