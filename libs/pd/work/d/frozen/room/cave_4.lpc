#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a cavern in the rock");
    set_short("a cavern in the rock");
    set_long("The path stops as the cave turns into a small cavern.  The sound of ");
    set_exits(([
	"south":ROOMS"cave_1",
	"north":ROOMS"cave_3",
      ]));
    set_items(([
	({"wall", "walls", "diamond"}):"The walls are made out of pure diamond.  Too bad you couldn't mine it!",
      ]));
}
