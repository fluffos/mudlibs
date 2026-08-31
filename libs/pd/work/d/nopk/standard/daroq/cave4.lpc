#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set("short", "Traveling down, into the heart of the cave");
    set("long",
      "The stench in this room is worse than all the others. The "
      "Daroq species, much like the orcs, use a single room in their "
      "tunnels as a dump for their crap. The stench is a stomach-wrenching affair.");
    set_smell("default", "A putrid stench fills the air.");
    set_exits(([ "down" : ROOMS"daroq/cave5",
	"up" : ROOMS"daroq/cave3" ]));
}

void reset() {
    ::reset();
    if (!present("tak'daroq")) {
	new(MOB"takdaroq")->move(this_object());
	new(MOB"takdaroq")->move(this_object());
	new(MOB"takdaroq")->move(this_object());
    }
}
