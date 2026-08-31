#include <std.h>
#include <tirun.h>
#include <daemons.h>

inherit BEACH;
#include <ocean.h>

void create() {
    ::create();
    set_property("no castle", 1);
    set_property("light", 3);
    set_property("night light", 2);
    set_property("beach",1);
    set_max_catch(15);
    set_max_fishing(4);
    set_chance(10);
    set("short", "The Tirun shores");
   set_long("A white sand beach runs east and west from here. A dock "
            "juts out over the ocean to the west. Random bits of shell, "
            "seaweed and debris get washed ashore from time to time. "
            "Tirun's walls dominate the skyline to the north. The ocean "
            "is to the south. ");
   set_items( ([
          "waves" : "The waves constantly splash against the shore.",
      "fog" : "A thin fog is starting to spread over the beach.",
      "waves" : "The waves constantly splash against the shore."]) );
   set_exits( ([
        "west" : ROOMS"beach1",
        "east" : ROOMS"beach3",
        "south": "/d/waterworld/level1/rooms/room-1e1",
            ]) );
   set_letter("a");
}

// int *query_coords() { return OCEAN_D->query_coord_from_letter("a"); }

