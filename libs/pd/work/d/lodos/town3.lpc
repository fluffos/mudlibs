#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("On a path leading east");
    set_property("light", 2);
    set_properties(([ "town" : 1 ]));
    set_long("To the southwest the temple to Omicron lies, and "
      "to the west is the Lodos town square. A small shop "
      "can be seen to the northwest. There is an "
      "old dirt path, though it looks often traveled.");
    set_exits(([ "west" : ROOMS"town2",
	"east" : ROOMS"etown4" ]));
}

void reset() {
    ::reset();
    if (!present("townsman"))
	new(MOB"townsman")->move(this_object());
}
