#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a path in the snow");
    set_short("a path in the snow");
    set_long("The mountains base begins here.  Looking up, you can "
      "see various paths up the sides of the mountain.  The path continues "
      "along the base of the mountain.  A path also seems to branch off between two "
      "sharp rises of rock to the east.");
    set_exits(([
	"north":ROOMS"sr5",
	"west":ROOMS"sr3",
        "east":ROOMS"cave_entrance",
      ]));
    set_items(([
	({"mountain", "mountain peak", "peak"}):"The mountain peak is covered with snow.  "
	"It looks like an avalanche could happen at any moment.",
	({"path", "paths"}):"There seems to be several paths that lead up "
	"the side of the mountain.",
      ]));
}
