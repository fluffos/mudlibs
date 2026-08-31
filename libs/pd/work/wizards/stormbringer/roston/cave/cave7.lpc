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
    set_long("This is a part of the cave where Elder creatures "
      "come to rest after there long days. There is tons "
      "of blood all over the walls, its as if there was "
      "a killing here.");

    set_exits( (["east"  : ROSTON"cave/cave6"]));
}



void reset() {
    ::reset();

    if(!present("bear"))
    {
	new(ROSTON"cave/e_bear")->move(this_object()); 
    }

}
