#include <std.h>
#include <citrin.h>

inherit VIRTUALROOM;
void reset() {
    int i;
    ::reset();
    if(random(2)) i = 2;
    else i = 1;
    if(!present("goblin")) {
	while(i--) {
	    new(MON"goblin")->move(this_object());
	}
    }
}

void create() {
    set_server(SERVER);
    ::create();
    set_exits(([
	"southwest":ROOMS"15",
	"northeast":ROOMS"13",
      ]));
    set_invis_exits(({"northeast", "southwest"}));
}

