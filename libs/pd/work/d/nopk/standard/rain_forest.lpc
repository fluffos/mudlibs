#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
  ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("forest", 1);
    set("short", "Deep in the rain forest");
    set("long",
        "Deep inside a forest.  The air is thick with humidity.  Leaves drip as small bugs crawl over them, causing the droplets to gather and fall.");
    set_smell("default", "The humid air stifils your senses.");
    set_listen("default", "You hear animals scattering to run away from you.");
    set_items(
        ([ "forest" : "A very humid jungle away from civilization."]) );
    set_exits( 
              (["southwest" : ROOMS"jungle",
                "east"      : ROOMS"rain_forest/path"]) );
}
