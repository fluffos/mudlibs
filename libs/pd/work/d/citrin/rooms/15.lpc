//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("Citrin Forest");
    set_short("a lost in a forest");
    set_long("A very small amount of light seems to be "
      "escaping from the trees letting some sight of what "
      "is hidden deep in the forest.");
    set_items(([
	"trees":"All the trees seem to look alike.",
      ]));
    set_exits(([
	"southeast":ROOMS"16",
	"northeast":ROOMS"14",
      ]));
    //     skip_obvious();
    set_properties((["light":1,"night light":1,"forest":1,]));
}

