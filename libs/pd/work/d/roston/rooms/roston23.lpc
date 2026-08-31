#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();
    set_name("west of roston square");
    set_items((["snow"   : "A very deep white snow",
	"dirt"  : "A light brown mixture"]));     
    set_properties((["light":2,"nightlight":3]));
    set_property("no attack", 1);
    set_short("info room");   
    set_long("This is a dirt path, the snow is melting. This "
      "path is well used, there is a old bard in the "
      "middle of the path, there is a house to the west.");

    set_exits((["east" : ROOMS "roston2"]));
}                                                     
void reset() {
    ::reset();

    if(!present("bard"))
    {
	new(MOB "bard")->move(this_object());
    }

}                                      
