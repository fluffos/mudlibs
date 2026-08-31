#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "Northern end of a small passage");
    set("long",
	"This is the north end of a small pass through this part of the cave. "
	"A thick wooden door is here blocking off a room east. Further south "
	"this small passage goes further into the cave. You are surrounded by "
	"rocks all around."
    );
    set_items(([
    ]));
    set_exits(([
	"up"    : ROOMS"cult/cave4",
	"east"  : ROOMS"cult/kitchen",
	"south" : ROOMS"cult/cave6",
    ]));
}
