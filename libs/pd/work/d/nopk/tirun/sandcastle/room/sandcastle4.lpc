#include <sandcastle.h>
#include <std.h>

inherit ROOM;

void create() {
::create();
set_properties((["light": 2, "night light" : 2, "indoors" : 1]) );
set_short("North West Room");
set_long("The room is darker, you feel like something is watching you. The walls, ceiling, and floors in this room show signs of decay, large scratch marks obvious on the walls. They are the signs of a big fight. Exits lead south and east.");
set_items((["room" : "This room is unnerving, scary, and darker. Signs that it is frequently and recently used.", "ceiling" : "Large scratch marks line the ceiling, making you wonder if it will fall in...", "walls" : "Long and deep scratch marks run across the walls, causing you to ponder what sort of creature would do this.", "floor" : "It just seems like you're stepping on pebbles to begin with, then you notice how similar to bit of a crab's exoskeleton it all looks..."]));
set_smell("default", "It smells like dead and old seafood.");
set_listen("default", "You can hear a clicking noise, and the extremely faint sound of the Ocean.");
set_exits( (["south" : ROOMS "sandcastle2", "east" : ROOMS "sandcastle5"]) );
}

void reset() {
::reset();
if (!present("crab"))
new(MOB "bosscrab")->move(this_object());
}
