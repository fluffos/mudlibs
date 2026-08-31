#include <std.h>
#include <citrin.h>

inherit VIRTUALROOM;
void create() {
    set_server(SERVER);
    ::create();
    set_exits(([
	"southwest":ROOMS"14",
	"north":ROOMS"9",
      ]));
    set_invis_exits(({"north","southwest"}));
}

