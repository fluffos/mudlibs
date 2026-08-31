#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_short("A quaint home.");
    set_long(
      "Despite the outside appearance, the inside is quite chaotic!  "
      "The mother here is running around in circles, panicking about her "
      "son's condition.  Meanwhile, the son lays on a small bed, looking "
      "very pale.");
    set_exits( (["out" : ROOMS"sparthos4"]) );
    set_property("light", 3);
    set_property("night light", 2);
    set_property("indoors", 1);
    set_items(
      (["bed" : "The bed is nice and comfy, but the child is unable to enjoy it.",
	"house" : "The interior has been nicely decorated, but recently "
	"has not been cleaned."
      ]) );
}

void reset() {
    ::reset();
    if(!present("mother"))
new("/d/nopk/tirun/obj/mon/mother")->move(this_object());
    if(!present("child"))
new("/d/nopk/tirun/obj/mon/sickly")->move(this_object());
}
