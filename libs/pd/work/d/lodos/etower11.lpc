#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("At the end of the staircase");
    set_properties((["light" : 1, "town" : 1, "indoors" : 1,
	"building" : 1]));
    set_long("The winding, twisting, spiral stairway ends here, coming "
      "to a stop in the center of the room. A ladder leads up, into a "
      "room. Blue light pours down into this room from above, making "
      "it darker.");
    set_exits(([ "east" : ROOMS"etower10",
	"up" : ROOMS"etower12"]));
    set_items(([
	"stairway" : "The stairway comes to a halt here, but leads east.",
	"ladder" : "An old silver ladder has been pulled through a hole in the ceiling.",
	"celing" : "A large passageway has been carved out of the ceiling.",
	"hole" : "It is the only way up.",
	"light" : "The %^BOLD%^%^BLUE%^blue%^RESET%^ light pours into this room."
      ]));
}

void reset() {
    ::reset();
    if (!present("soldier")) {
	make(MOB"soldier");
	make(MOB"soldier");
	make(MOB"soldier2");
	make(MOB"soldier2");
    }
}
