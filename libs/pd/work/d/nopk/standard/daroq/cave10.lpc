#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 1);
    set("short", "In a tunnel within the daroq caves");
    set("long",
        "This small passageway continues up and down. A foul stench arises from below, "
        "farther in the cave.");
    set_exits(([ "up" : ROOMS"daroq/cave11",
                 "down" : ROOMS"daroq/cave9" ]));
}

void reset() {
 ::reset();
   if (!present("balrog"))
      new(MOB"balrog2")->move(this_object());
}
