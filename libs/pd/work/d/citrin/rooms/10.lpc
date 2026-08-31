#include <std.h>
#include <citrin.h>

inherit VIRTUALROOM;
void reset() {
    int i;
    ::reset();
    if(random(2)) i = 2;
    else i = 1;
    if(!present("shadow")) {
	while(i--) {
	    new(MON"shadow")->move(this_object());
	}
    }
}

void create() {
    set_server(SERVER);
    ::create();
    set_exits(([
	"west":ROOMS"9",
	"south":ROOMS"72",
	"east":ROOMS"71",
	"northeast":ROOMS"11",
      ]));
   set_invis_exits(({"west","south","east","northeast"}));
}

