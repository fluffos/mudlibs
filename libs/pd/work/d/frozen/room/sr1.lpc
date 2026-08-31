#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a path in the snow");
    set_short("a path in the snow");
    set_long("The mountain seems to get closer.  Snow covers its "
      "peaks, making it look menacing.  The snow seems to be getting "
      "deeper the closer to the mountain you go.");
    set_exits(([
	"southwest":ROOMS"snow3",
	"northeast":ROOMS"sr2",
      ]));
    set_items(([
	({"mountain", "mountain peak", "peak"}):"The mountain peak is covered with snow.  "
	"It looks like an avalanche could happen at any moment.",
      ]));
}

