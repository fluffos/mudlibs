#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a cavern in the rock");
    set_short("a cavern in the rock");
    set_long("The walls of the cave seem to be made out of pure diamond and crystal.  The small amount of light in the "
      "cave makes the walls shimmer and gleem.  The cave seems to go further into the darkness.");
    set_exits(([
	"north":ROOMS"cave_2",
	"out":ROOMS"cave_entrance",
      ]));
    set_items(([
	({"wall", "walls", "diamond"}):"The walls are made out of pure diamond.  Too bad you couldn't mine it!",
      ]));
}
