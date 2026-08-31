#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();
    set_name("north of town square");
    set_items((["snow"   : "A very deep white snow",
	"ice" : "A deep water that is frozen over ",
	"dirt"  : "A light brown mixture"]));
    set_properties((["light":2, "night light":2]));
    set_short("A snow path");
    set_long("This is a dark place in the cavern.  The cavern walls "
      "are sinking.  The ice on the wall is beginning to melt away.");

    set_exits( (["east" : ROOMS "roston47",]));
}   
void reset() {
    ::reset();
    if(!present("snake"))
    {
	new(MOB "snake")->move(this_object());
    }

}           
