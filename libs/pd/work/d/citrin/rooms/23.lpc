//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit ROOM;
void create() {
    ::create();
    set_name("near a lake");
    set_short("near a lake");
    set_long("A catwalk crosses the overflow of the lake to the northwest.  "
      "The lake seems to have a light green color probally from the high "
      "content of vegetation in the water.  Frogs can be seen jumping "
      "around here and there.");
    set_exits(([
	"northwest":ROOMS"21",
	"southeast":ROOMS"47",
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

int go_southwest() {
    if(this_player()->query_stats("wisdom") < 20+random(20) ) {
	write("You climb off of the catwalk and fall flat on your face.");
	if(this_player()->query_level() > 19) 
	    this_player()->set_env("TITLE", "$N is covered in mud.");
	return 1;
    }
    write("You jump off the catwalk to the soft mud below.\n");
    return 1;
}

