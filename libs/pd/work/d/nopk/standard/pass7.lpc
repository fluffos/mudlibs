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
      "The pass leads east and west right through the Daroq "
      "mountains. The tall stone walls line the sides of this "
      "dreary pass.");
    set_items(([
	"walls" : "The walls of the pass are too steep to climb.",
	"rocks" : "The rocks jut forth from the ground.",
	"pass" : "The pass leads east and west, across the Daroq mountains."
      ]));
    set_exits(([ "east" : ROOMS"pass6",
	"west" : ROOMS"pass8" ]));
}

void reset() {
    ::reset();
    if (!present("gob"))
	new(MOB"gob")->move(this_object());
}
