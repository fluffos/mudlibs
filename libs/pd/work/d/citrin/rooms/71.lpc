#include <std.h>
#include <citrin.h>

inherit VIRTUALROOM;
void create() {
    set_server(SERVER);
    ::create();
    set_exits(([
	"west":ROOMS"10",
	"southeast":ROOMS"70",
      ]));
    set_invis_exits(({"west","southeast"}));
}

