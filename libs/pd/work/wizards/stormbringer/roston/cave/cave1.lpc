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
    set_long("This is the entrance of a giant cave. The cracks "
      "in the ground seem to have vapors pouring out of "
      "them. This Cave is for the elder creatures of this "
      "land, known as the mountains of Roston.");

    set_exits( (["north"  : ROSTON"cave/cave2",
	"south"  : ROSTON"cave/cave20",
	"east"   : ROSTON"cave/cave15",
	"west"   : ROOMS"roston53"]));
}
void reset(){
    ::reset();
    if(!present("bear"))new(MOB"g_bear")->move(this_object());
}
