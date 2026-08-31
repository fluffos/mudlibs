#include <std.h>
#include <citrin.h>

inherit VIRTUALROOM;
void create() {
    set_server(SERVER);
    ::create();
    set_exits(([
	"southwest":ROOMS"10",
	"east":ROOMS"12",
      ]));
    set_invis_exits(({"southwest","east"}));
}

