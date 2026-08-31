#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "Above a passage leading further down");
    set("long",
	"A tunnel through the rocks leads south, but slopes down to the next "
	"level down. Stalagtites and Stalagmites reach from the ceiling and "
	"floor either up or down. The northern part of the cave approaches the "
	"surface level of the cave."
    );
    set_items(([
	"tunnel" : "A tunnel of stone and dirt."
    ]));
    set_exits(([
	"north" : ROOMS"cult/cave3",
	"down"  : ROOMS"cult/cave5",
    ]));
}
