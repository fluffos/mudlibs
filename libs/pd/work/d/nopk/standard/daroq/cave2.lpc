#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 1);
    set("short", "Traveling down, into the heart of the cave");
    set("long",
        "Walls enclose this space on every side, allowing travel in two "
        "directions; up and down, both through small passageways "
        "through this cave. A nervous quiet fills the air.");
    set_smell("default", "A putrid stench fills the air.");
    set_exits(([ "down" : ROOMS"daroq/cave3",
                 "up" : ROOMS"daroq/cave1" ]));
}

void reset() {
 ::reset();
   if (!present("daroq")) {
      new(MOB"takdar")->move(this_object());
      new(MOB"takdar")->move(this_object());
   }
}
