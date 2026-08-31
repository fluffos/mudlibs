#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "Southern end of a small passage");
    set("long",
	"This is the southern end of the passage on this part of the cave. The "
	"passage leads only north from here, and down deeper into the darkest "
	"parts of the cave. An iron trap door blocks the exit down."
    );
    set_items(([
    ]));
    set_exits(([
	"north" : ROOMS"cult/cave5",
	"down"  : ROOMS"cult/cave7",
    ]));
}
