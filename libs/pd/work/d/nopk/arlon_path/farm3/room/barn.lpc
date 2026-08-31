#include <std.h>
#include <arlonpath.h>
inherit ROOM;

void create() {
    ::create();
    set_short("A rickety barn.");
    set_long(
      "A rickety old barn. The barn has a couple of stalls for animals, some hey piled in one corner, and a water trough. A large door leads outside. "
    );
    set_night_long(
      "A rickety old barn. The barn has a couple of stalls for animals, some hey piled in one corner, and a water trough. A large door leads outside. "
    );
    set_exits( 
      (["out" : FARM3"room/farmyard",
      ]) );
    set_property("indoors", 1);
    set_property("light", 1);
    set_property("night light", 0);
    set_items(
      (["trogh" : "A container for holding drinking water for animals.",
        "door" : "A large covered portal leading outside",
      ]) );

}
void reset() {
    ::reset();
    if(!present("cow"))
        new(MOBS+"cow")->move(this_object());
    if(!present("nag"))
        new(MOBS+"nag")->move(this_object());
}
