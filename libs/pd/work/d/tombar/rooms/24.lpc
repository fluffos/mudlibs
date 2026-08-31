#include <std.h>
#include <tombar.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Tombar Temple");
    set_long("The hallways seem to last forever.  The longer the pathways go the more dangerous "
      "it becomes.  The constant drip from the ceiling breaks all silence that is bestowed in these "
      "tunnels.  The walls are plastered with the riminents of old adventurers that dared to enter "
      "the sacred temple.");
    set_items(([
	"wall" : "The walls are marked with the blood of past adventurers.",
      ]));
    set_listen("default", "Every sound echoes throughout the hallway.");
    set_exits(([
	"northeast" : ROOMS"23",
      ]));
}
