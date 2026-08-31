#include <std.h>
#include <tirun.h>

inherit BEACH;

void create() {
    ::create();
    set_property("no castle", 1);
    set_property("light", 3);
    set_property("beach",1);
    set_max_catch(15);
    set_max_fishing(4);
    set_chance(10);
    set_property("night light", 2);
    set("short", "The Tirun shores");
    set_long("The beach shore leads to the south "
             "along the ocean side. You notice a forest "
             "to the south.");
    set_exits( 
          (["west" : ROOMS"beach4",
//           "shack" : ROOMS "fishshack",
        "south" : ROOMS"beach6",
     "southwest": "/d/waterworld/level1/rooms/room-1g1",
            ]) );
}
