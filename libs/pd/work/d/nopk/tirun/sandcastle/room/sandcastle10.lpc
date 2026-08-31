#include <sandcastle.h>
#include <std.h>

inherit ROOM;

void create() {
::create();
set_properties((["light" : 2, "night light" : 1, "indoors" : 1]) );
set_short("East Upstairs");
set_long("You have now gone east into a room which doesn't feel safe at all. Broken bits of shell lie everywhere on the floor, some pieces stuck into the walls and ceiling, the force by which they were forced into sand must have been strong. This is the room where sad and old crabs come to die.");
set_night_long("You have now gone east into a room which doesn't feel safe at all. Broken bits of shell lie everywhere on the floor, some pieces stuck into the walls and ceiling, stepping around here at night is probably very dangerous indeed. This is the room where sad and old crabs come to die.");
set_items((["room" : "This room is old, broken and tragic, very well resembling the crabs which come here to die.", "walls" : "There are bits of broken shell sticking out of the walls, an accident waiting to happen.", "ceiling" : "Large bits of shell jut out from above, causing you to duck your head every now and then.", "floor" : "Shell is littering the floor, it crunches beneath you as you walk upon it.", "shell" : "It is broken bits of crab exoskeleton, from the crabs who have died here. There is no explanation as to why it's in broken pieces though..."]));
set_smell("default", "It smells like dead crab warmed up in here.");
set_listen("default", "The sound of crunching and clicking is all there is...");
set_exits( (["west" : ROOMS "sandcastle7"]) );
}

void reset() {
::reset();
if (!present("crab"))
new(MOB "crab2")->move(this_object());
}
