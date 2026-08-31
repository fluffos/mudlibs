//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit ROOM;
void create() {
    ::create();
    set_name("near a lake");
    set_short("near a lake");
    set_long("The air is dry and cool.  The ground is soft, almost muddy.  "
      "Small bones are seen in the ground half buried.  A catwalk can be "
      "seen to the northwest where the start of the lake overflow is.  "
      "The light here is colored almost green from the reflection from "
      "the green water.");
    set_exits(([
	"northwest":ROOMS"23",
	"east":ROOMS"46",
	"southwest":ROOMS"24",
      ]));
    set_items((["ground":"Small bones are sticking up from it.",
	({"bones","small bones"}):"They are the remains of what "
	"is left of small woodland creatures that have sank "
	"into the mud.",
	"lake":"A green glow comes from it.",
	"catwalk":"Its used to help people cross the overflow.",
      ]));
    set_properties((["light":1,"night light":1,"forest":1,]));
    set_pre_exit_functions(({"northwest"}), ({"go_northwest"}));
}

void reset() {
    ::reset();
    if(!present("frog"))
	new(MON"frog")->move(this_object());
}

int go_northwest() {
    write("You climb on the catwalk to cross the overflow.\n");
    return 1;
}

