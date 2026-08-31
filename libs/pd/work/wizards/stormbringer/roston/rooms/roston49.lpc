#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();
    set_name("north of town square");
    set_items((["hay" : "A dark brown piece of hay",
	"snow"   : "A very deep white snow",
	"dirt"  : "A light brown mixture"]));
    set_properties((["light":2, "night light":2]));
    set_short("A Cavern");
    set_long("This is a space made by a giant crack in the cavern wall. "
      "From the looks of it, somebody lives in here. "
      "There is a bale of hay in the middle of the cave.");

    set_exits(([ "out" : ROOMS "roston48"]));

}
void reset() {      
    ::reset();

    if(!present("wizard"))
    {
	new(MOB "wizard")->move(this_object());
    }

}                        
