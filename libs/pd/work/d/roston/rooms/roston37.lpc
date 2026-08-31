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
    set_long("To the east, there is a large building.  There "
      "seems to be a large hole in the wall, and many large "
      "tracks cover the floor.");

    set_exits( (["west"  : ROOMS "roston38",
	"east" :  ROOMS "roston39",
	"north" : ROOMS "roston34"]));
}
void reset() {              

    if(!present("yetti"))
    {
	new(MOB "f_yetti")->move(this_object());
    }

}                                  
