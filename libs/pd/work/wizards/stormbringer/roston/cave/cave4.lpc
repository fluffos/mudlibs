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
    set_long("In this part of the cave, the walls make it difficult for "
      "escape.  The vapors fluctuate in color, and creatures often rest "
      "in this area.");

    set_exits( (["east"  : ROSTON"cave/cave3"]));
}



void reset() {
    ::reset();
    if(!present("elder hunter"))
    {
	new(ROSTON"cave/hunter2")->move(this_object());
    }

}     
