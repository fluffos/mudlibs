//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("Citrin Forest");
    set_short("a lost in a forest");
    set_long("The path ends to the southwest as the trees become really "
      "dense.  All the surrounding seem to blend and mix in the seemingly "
      "endless dark abyss.");
    set_items(([
	"trees":"All the trees seem to look alike.",
      ]));
    set_exits(([
	"northeast":ROOMS"16",
	"west":DEN"1",
      ]));
    //     skip_obvious();
    set_properties((["light":1,"night light":1,"forest":1,]));
}

void init() {
    ::init();
    add_action("go_west", "west");
}

int go_west() {
    if(!this_player()->is_player()) return 1;
    else this_player()->move_player(DEN"1");
    return 1;
}

