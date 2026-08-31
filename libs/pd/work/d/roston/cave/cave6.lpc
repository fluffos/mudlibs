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
    set_long("This is one part of this giant cave. It is to the "
      "north of the entrance. This is where elder creatures come"
      " to sleep off there battle for food. This room seems to be "
      "very dark.");

    set_exits( (["west"  : ROSTON"cave/cave7",    
	"south"  : ROSTON"cave/cave5",
	"east"   : ROSTON"cave/cave8"]));
}



void reset() {
    ::reset();

    if(!present("bat"))
    {
	new(ROSTON"cave/bat")->move(this_object());   
    }

}      
