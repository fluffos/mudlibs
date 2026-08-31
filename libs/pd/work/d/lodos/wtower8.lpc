#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Climbing up a tower along the stairs");
    set_properties((["light" : 2, "indoors" : 1 ]));
    set_long("The baron's quarters are rather comfortable looking. A "
      "large, fluffy chair sits against a wall next to a large bookcase, "
      "and a chandelier hangs from high on the ceiling above a table. The "
      "carpet is red and the walls are painted white.");
    set_exits(([ "down" : ROOMS"wtower7" ]));
    set_items(([
	"room" : "This is the baron's room",
	"chair" : "It is large and soft, the perfect reading chair.",
	"walls" : "The walls have been painted white.",
	"carpet" : "King's red.",
	"bookcase" : "Full of excellent books waiting to be read.",
	"chandelier" : "It hangs just above the table top.",
	"table" : "The table is made out of gold."
      ]));
}

void reset() {
    ::reset();
    if (!present("baron"))
	make(MOB"baron");
    if (!present("paladin")) {
	make(MOB"paladin");
	make(MOB"paladin");
	present("paladin 2", this_object())->set_swarm(1);
    }
    present("paladin", this_object())->set_swarm(1);
}
