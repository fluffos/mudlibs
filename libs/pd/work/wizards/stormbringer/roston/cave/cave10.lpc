#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();
    set_name("north of town square");
    set_items((["snow"   : "A very deep white snow",
	"cracks" : "A huge hole in the ground",
	"vapors" : "A weird looking mist",
	"dirt"  : "A light brown mixture"]));
    set_properties((["light":2, "night light":2]));
    set_short("A snow path");
    set_long("This is part of the Cave, where there walls seem "
      "closeing in on you. The vapors leak up and smell like "
      "acid. The cracks in the ground are very deep.");

    set_exits( (["west"  : ROSTON"cave/cave3"]));    

}



void reset() {

    if(!present("hunter"))
    {
	new(ROSTON"cave/hunter2")->move(this_object());
    }

}                               
