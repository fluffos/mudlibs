#include <std.h>
#include <arlonpath.h>
inherit ROOM;

void create() {
    ::create();
    set_short("A chicken pen.");
    set_long(
      "A small chicken pen, a fence surrounds the entire area with a gate leading out to the north. A few crude made roosts sit to the south end of the pen."
    );
    set_night_long(
      "A small chicken pen, a fence surrounds the entire area with a gate leading out to the north. A few crude made roosts sit to the south end of the pen."
    );
    set_exits( 
      (["north" : FARM3"room/farmyard",
      ]) );
    set_property("light", 2);
    set_property("night light", 1);
    set_items(
      (["fence" : "A wall made of wire meant to keep chickens from getting out.",
        "gate" : "A crude mage door to this pen.",
        "roosts" : "A box with a crude nest inside for collecting eggs.",
      ]) );
    set_inventory( ([ MOBS+"chicken" : 4 ]) );
}

void reset() {
    ::reset();
    if(!present("rooster"))
        new(MOBS+"rooster")->move(this_object());
}
