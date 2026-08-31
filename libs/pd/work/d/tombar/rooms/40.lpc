// Coded by Whit
#include <std.h>
#include <tombar.h>
inherit DARKNESS;
void create() {
    ::create();
    set_name("a long, black hallway");
    set_long("It is very dark down here.  Its hard to see anything.  The "
      "glow of your orb is the only thing allowing you to see where you "
      "are going.");
    set_items(([
	"ceiling" : "The ceiling is made of black stone.  It is wet from "
	"water that leaks through the cracks.",
	"floor" : "The floor is wet with water.",
      ]));
    set_exits(([
	"up" : ROOMS"38",
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

