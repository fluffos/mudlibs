//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit ROOM;
void create() {
    ::create();
    set_name("near a lake");
    set_short("near a lake");
    set_long("The ground under the catwalk is very muddy and wet from "
      "the overfill of the lake.  Small ferns have managed to grow up "
      "through the cracks of the catwalk.  The catwalk ends to the "
      "southeast.");
    set_exits(([
	"north":ROOMS"19",
	"southwest":ROOMS"22",
	"southeast":ROOMS"23",
      ]));
    set_pre_exit_functions( ({"southeast"}), ({"go_southeast"}));
    set_properties((["light":1,"night light":1,"forest":1,]));
}

void reset() {
    ::reset();
    if(!present("fern"))
	new(OBJ"fern")->move(this_object());
}

int go_southeast() {
    write("You climb off of the catwalk.\n");
    return 1;
}

