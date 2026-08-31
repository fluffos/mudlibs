#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();
    set_name("north of town square");
    set_items((["snow"   : "A very deep white snow",
	"dirt"  : "A light brown mixture"]));
    set_properties((["light":2, "night light":2]));
    set_short("A snow path");
    set_long("There is a giant hole in the middle of the ground. "
      "The hole seems to never end. The ground has tons "
      "of cracks on the surface, and the snow is almost gone.");

    set_exits( (["east" : ROOMS "roston42",
	"hole" : ROOMS "roston45"]));
}
void reset() {                    
    ::reset();
    if(!present("snake"))
    {
	new(MOB "snake")->move(this_object());
    }

}                            
