#include <std.h>
#include <arlonpath.h>
inherit ROOM;

void create() {
    ::create();
    set_short("A siloh.");
    set_long(
      "An old siloh used for storing crops. The siloh is leaning a little to the left. Small pieces of corn liter the floor. A large door leads outside. "
    );
    set_night_long(
      "An old siloh used for storing crops. The siloh is leaning a little to the left. Small pieces of corn liter the floor. A large door leads outside. "
    );
    set_exits( 
      (["out" : FARM3"room/farmyard",
      ]) );
    set_property("indoors", 1);
    set_property("light", 1);
    set_property("night light", 0);
    set_items(
      (["corn" : "Partially eaten single pieces of corn.",
        "door" : "A large covered portal leading outside",
      ]) );
    set_inventory( ([ MOBS+"rat2" : 11 ]) );
}
void reset() {
    ::reset();
    if(!present("rat3"))
        new(MOBS+"rat3")->move(this_object());
}
