#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "Traveling down, into the heart of the cave");
    set("long",
	"The cave light is becoming dimmer and dimmer and the "
        "horrible stench is constantly growing. The walls of rock "
        "look to be very thick.");
    set_exits(([ "down" : ROOMS"daroq/cave2",
                 "up" : ROOMS"daroq/entrance" ]));
}

void reset() {
 ::reset();
   if (!present("daroq"))
      new(MOB"takdar")->move(this_object());
}
