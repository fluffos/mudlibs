#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();         

    set_name("north of square");
    set_items((["snow"   : "A very deep white snow",
	"dirt"  : "A light brown mixture"]));        
    set_properties((["light":2, "night light":3]));
    set_short("A dirt path");
    set_long("A large white palace looms to the east of here.  The "
      "snow is getting deeper as the path heads north, and the dirt "
      "is getting lighter.  The path seems to be getting "
      "wider as it leads south back into town.");

    set_exits( ([ "north" : ROOMS "roston30",
	"east"  : ROOMS "roston18", 
	"south" : ROOMS "roston16" ]));
}                            
void reset() {
    ::reset();
    if(!present("spy"))
    {
	new(MOB "spy")->move(this_object());
    }

}                        
