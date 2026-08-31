//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("Citrin Forest");
    set_short("a lost in a forest");
    set_long("The air is very humid.  Trees surround most of the path.  "
      "The ground has turned slightly muddy from the start of the "
      "overflow of the lake.  A catwalk can be seen to the southeast "
      "that allows you to go over the overflow.");
    set_items(([
      ]));
    set_exits(([
	"southeast":ROOMS"18",
	"northeast":ROOMS"75",
	"southwest":ROOMS"17",
	"northwest":ROOMS"15",
      ]));
    set_pre_exit_functions( ({"southeast"}), ({"go_southeast"}) );
    set_properties((["light":1,"night light":1,"forest":1,]));
}

int go_southeast() {
    if(!this_player()->is_player()) return 0;
    write("You climb up onto the catwalk.\n");
    return 1;
}

