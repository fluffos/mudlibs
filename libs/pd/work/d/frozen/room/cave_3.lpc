#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a cavern in the rock");
    set_short("a cavern in the rock");
    set_long("The cave seems to split into two separate paths.  It seems to be getting darker now.");
    set_exits(([
	"south":ROOMS"cave_2",
	"northeast":ROOMS"cave_5",
        "northwest":ROOMS"cave_4",
      ]));
    set_listen("default", "The air shimmers in the cold.");
    set_items(([
	({"wall", "walls", "diamond"}):"The walls are made out of pure diamond.  Too bad you couldn't mine it!",
      ]));
}
