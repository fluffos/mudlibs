#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();
    set_name("north of town square");
    set_items((["snow"   : "A very deep white snow",
	"ice"    : "A very hard and thick pice of ice",
	"dirt"  : "A light brown mixture"]));
    set_properties((["light":2, "night light":2]));
    set_short("A Cavern");
    set_long("This is the southern part of the cavern, the walls are "
      "covered in ice.  The cavern walls surround the area.");
    set_exits(([  "north" : ROOMS "roston45",
	"east" :  ROOMS "roston50",
	"west" :  ROOMS "roston51",]));
}
void reset() {  
    ::reset();

    if(!present("hunter"))
    {
	new(MOB "hunter")->move(this_object());
    }

}       
