#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
   set_property("mountain",1);
    set_property("no castle", 1);
    set("short", "Heading down the Daroq Mountain Pass");
    set("long",
	"Rocks jut upwards along the side of the stoney Daroq "
        "mountain pass. A strange wave of heat overcomes you. "
        "The stone walls of the pass go higher, but are far "
        "too steep to climb here.");
    set_listen("default", "Strange noises can be heard above you.");
    set_listen("noises", "It sounds like many small creatures scurring about.");
    set_items(([
        "walls" : "The walls of the pass are too steep to climb.",
        "rocks" : "The rocks jut forth from the ground.",
        "ground" : "The ground is stone, like the mountains around it."
    ]));
    set_exits(([ "east" : ROOMS"pass5",
                 "west" : ROOMS"pass7" ]));
}

void reset() {
 ::reset();
/*   if (!present("balrog")) {
      new(MOB"balrog2")->move(this_object());
      new(MOB"balrog2")->move(this_object());
   }*/
}
