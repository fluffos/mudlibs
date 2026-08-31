#include <rain.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
    set_short("Guard room");
    set_long("This is the guard room. "
      "To the east there is the housing district. To the west "
      "is the merchants. Far off to the south is the "
      "palace. Directly to the south is the square.");
    set_items((["palace" : "The palace is a huge stone structure"
	" which towers 2 stories high"]));
    set_exits((["north": ROOMS"village2",
	"east" : ROOMS"hpath1",
	"west" : ROOMS"mpath1",
	"south": ROOMS"square"]));
}           


void reset() {
    ::reset();
    if (!present("elven guard")) {
	new(MOB"bguard")->move(this_object());
	new(MOB"bguard")->move(this_object());
	new(MOB"bguard")->move(this_object());
    }
}
