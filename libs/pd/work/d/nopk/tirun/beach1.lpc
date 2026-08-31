#include <std.h>
#include <tirun.h>

inherit PIER;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 2);
    set_property("beach",1);
    set_max_catch(15);
    set_max_fishing(4);
    set_chance(10);
    set("short", "Entrance to the beach");
   set_long("A white sand beach runs east from here. A small stairway "
            "leads up to the Tirun docks. Random bits of shell, "
            "seaweed and debris get washed ashore from time to time. "
            "Tirun's walls dominate the skyline to the north. The ocean "
            "is to the south. ");
      set_smell("default", "Rotting fish offend your nostrils.");
      set_smell("fish", "They smell as if they have been out for days.");
    set_items(
	(["port" : "Ships from all over Carnage dock here to "
	    "do business in Tirun.",
          "waves" : "The waves constantly splash against the shore.",
          "ladder" : "A short rope ladder has been hung here to "
                    "help people to climb up to the pier.",
	  "torches" : "They light up the pier at night."]) );
    set_exits( 
          (["up" : "/d/nopk/tirun/pier",
            "east" : ROOMS"beach2",
            "south": "/d/waterworld/level1/rooms/room-1d1",
            ]) );
}

void reset() {
  ::reset();
    if(present("crab")) return;
   new(MOB"crab")->move(this_object());
}

