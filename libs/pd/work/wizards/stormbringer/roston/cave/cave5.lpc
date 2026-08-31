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
    set_long("This is part of the Cave, to the east this is the "
      "resting spot of great elder creatures from the mountains "
      "of Roston. Only few great hunters come here to kill "
      "these great elder creatures.");

    set_exits( (["north"  : ROSTON"cave/cave6",  
	"south"  : ROSTON"cave/cave3"]));
}



void reset() {
    ::reset();

    if(!present("bear"))
    {
	new(MOB"m_bear")->move(this_object());
    }

}
