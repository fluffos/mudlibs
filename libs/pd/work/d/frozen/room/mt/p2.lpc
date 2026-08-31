#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a path up the mountain");
    set_short("a path in the snow");
    set_long("The path seems very dangerous and slick.  "
      "The path splits up into two directions here, one going up"
      " and the other going to the east.");
    set_exits(([
	"down":ROOMS"mt/p1",
	"east":ROOMS"mt/p3",
	"up":ROOMS"mt/p",
      ]));
    set_items(([
	({"mountain", "mountain peak", "peak"}):"The mountain peak is covered with snow.  "
	"It looks like an avalanche could happen at any moment.",
	({"path", "paths"}):"The path seems very dangerous.",
      ]));
}


