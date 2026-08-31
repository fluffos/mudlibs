#include <std.h>
#include <tirun.h>

inherit BEACH;

void create() {
    ::create();
    set_property("no castle", 1);
    set_property("light", 2);
    set_max_catch(15);
    set_max_fishing(4);
    set_chance(10);
    set_property("night light", 1);
    set("short", "The Tirun shores");
    set_long("The relaxing blue waves wash against "
             "the hot sand of the beach, often washing "
             "strange objects ashore. A strange mist and "
             "fog fill the air.");
    set_exits( 
          (["north" : ROOMS"beach5",
        "south" : ROOMS"beach7",
          "west": "/d/waterworld/level1/rooms/room-1g1",
            ]) );
}
void reset() {
 ::reset();
   if (!present("log"))
      new(OBJ"log")->move(this_object());
}
