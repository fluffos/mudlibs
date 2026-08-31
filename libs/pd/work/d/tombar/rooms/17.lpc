// Coded by Whit

#include <std.h>
#include <tombar.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a long, black hallway");
    set_long("These long hallways seem to last forever.  There seems "
      "to be no rooms other than the narrow hallway itself.  The walls, "
      "floor, and ceiling are all covered with water from the dripping "
      "ceiling.");
    set_items(([
	"ceiling" : "The ceiling is made of black stone.  It is wet from "
	"water that leaks through the cracks.",
	"floor" : "The floor is wet with water.",
      ]));
    set_exits(([
	"north" : ROOMS"16",
	"east" : ROOMS"18",
	"southeast" : ROOMS"19",
      ]));

}

void reset() {
    ::reset();
    if(!present("bat"))
	new(MON"bat")->move(this_object());
}
