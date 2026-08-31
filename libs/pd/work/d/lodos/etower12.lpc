#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("At the end of the staircase");
    set_properties((["light" : 1, "indoors" : 1, "town" : 1,
	"building" : 1]));
    set_long("The entire room is bathed in a %^BOLD%^%^CYAN%^soft,%^BLUE%^ "
      "blue%^RESET%^ %^CYAN%^light%^RESET%^. There are two windows on "
      "each wall, so the room smells fresh and clean. Magic is in the "
      "air. This place looks somewhat like a shop");
    set_exits(([ "down" : ROOMS"etower11" ]));
    set_items(([
	"shop" : "This room looks like a shop, somewhat.",
	"light" : "The room is flooded in this light.",
	"magic" : "Sparks flicker about the edges of the room.",
	"windows" : "Two windows on each wall let plenty of fresh air in."
      ]));
}

void reset() {
    ::reset();
    if (!present("magician"))
	make(MOB"mage");
}
