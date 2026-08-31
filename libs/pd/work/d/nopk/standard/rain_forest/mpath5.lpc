#include <rain.h>
#include <std.h>
inherit ROOM;

  void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
    set_short("Outside general store");
    set_long("A small dirt path. "
             "To the east is a small general store. To the "
             "southeast is the palace and to the northeast is the "
             "town square.");
    set_items(([ ({ "general store", "store" }) : "This is a small "
                    "wooden building with some old things laying out"
                    "side."]));
    set_exits((["north": ROOMS"mpath4",
                "southeast": ROOMS"pgate",
                "east" : ROOMS"shop3"]));

}
