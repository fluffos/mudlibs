#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "A kitchen");
    set("long",
	"This seems to be a makeshift kitchen within the cave. Two metal tables "
	"are in this room. There are small pools of blood on the ground and upon "
	"the tables. What could have possibly left such a mess?"
    );
    set_items(([
    ]));
    set_exits(([
	"west" : ROOMS"cult/cave5"
    ]));
}
