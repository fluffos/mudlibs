//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit ROOM;
void create() {
    ::create();
    set_name("near a lake");
    set_short("near a lake");
    set_long("The ground here is idea for slimy things.  The ground is almost "
      "nothing but green slime that seems to be originating from the "
      "water that comes from the west.  A catwalk is to the east allowing "
      "travelers to walk over the runoff.");
    set_smell("default", "There is a horrible stench here.");
    set_exits(([
	"east":ROOMS"19",
      ]));
    set_pre_exit_functions( ({"east"}), ({"go_east"}) );
    set_properties((["light":1,"night light":1,"forest":1,]));
}

int go_east() {
    write("You climb onto the catwalk to cross the overflow.\n");
    return 1;
}

void reset() {
    int i = 10;
    ::reset();
    if(!present("blob")) {
	while(i--) {
	    new(MON"blob")->move(this_object());
	}
    }
}
