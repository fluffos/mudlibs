#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a path in the snow");
    set_short("a path in the snow");
    set_long("The path between the rocks seem to come to a small cave entrance.  The only way "
      "out of the path between the rocks would be back the way you came from.");
    set_exits(([
	"cave":ROOMS"cave_1",
	"west":ROOMS"sr4",
      ]));
    set_items(([
	({"mountain", "mountain peak", "peak"}):"The mountain peak is covered with snow.  "
	"It looks like an avalanche could happen at any moment.",
	({"path", "paths"}):"There seems to be several paths that lead up "
	"the side of the mountain.",
      ]));
}
