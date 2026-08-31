#include <std.h>
#include <tirun.h>

inherit BEACH;

void create() {
    ::create();
    set_property("no castle", 1);
    set_property("light", 2);
    set_property("beach",1);
    set_max_catch(15);
    set_max_fishing(4);
    set_chance(10);
    set_property("night light", 1);
    set("short", "Nearing a forest");
    set_long("The hot sands end right to the south "
             "of here, where a huge forest lies. The "
             "humid air somehow reminds you of better days.");
    set_exits( 
          (["north" : ROOMS"beach6",
        "south" : "/d/nopk/arlon/room/s_gates",
          "west": "/d/waterworld/level1/rooms/room-1g2",
            ]) );
}
