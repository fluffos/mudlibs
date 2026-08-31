// Coded by Whit
#include <std.h>
#include <tombar.h>
inherit ROOM;
void create() {
    ::create();
    set_name("a long, black hallway");
    set_long("The hallway seems to end at a set of spiral stairs.  The "
      "stairs lead down, into further darkness.");
    set_items(([
	"ceiling" : "The ceiling is made of black stone.  It is wet from "
	"water that leaks through the cracks.",
	"floor" : "The floor is wet with water.",
      ]));
    set_exits(([
	"northeast" : ROOMS"37",
       "down" : ROOMS"40",
      ]));
}
void reset() {
    ::reset();
    /*
	if(!present("rat")) {
	    new(MON"rat")->move(this_object());
	    new(MON"rat")->move(this_object());
	}
    */
}

