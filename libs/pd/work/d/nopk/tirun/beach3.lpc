#include <std.h>
#include <tirun.h>

inherit BEACH;

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
   set_long("What looks like a pier is visible to the west. "
            "You notice fresh footprints in the wet sand. This beach "
            "seems pretty popular. Several small waves lap against "
            "the shore every now and then.");
   set_items( ([
      "footprints" : "A small child's footprints, they seem pretty fresh.",
      "pier" : "It is barly visible from here.",
        "waves" : "The waves occasionally lap against the shore."]) );
    set_exits( 
          (["west" : ROOMS"beach2",
            "east" : ROOMS"beach4",
            "south" : "/d/waterworld/level1/rooms/room-1f1" ]) );
}

void reset() {
 ::reset();
   if (!present("child"))
      new(MOB"child")->move(this_object());
}
