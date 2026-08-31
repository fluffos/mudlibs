#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a path in the snow");
    set_short("a path in the snow");
    set_long("The path begins to get rocky under the snow.  The mountain "
      "is ever closer.  A faint breeze blows through the plains.");
    set_exits(([
	"southwest":ROOMS"sr1",
	"northeast":ROOMS"sr3",
      ]));
    set_items(([
	({"mountain", "mountain peak", "peak"}):"The mountain peak is covered with snow.  "
	"It looks like an avalanche could happen at any moment.",
      ]));
}

