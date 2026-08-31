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
    set_long("This is the peak of a giant mountain.  The "
      "snow is very deep here, and overlooks the town of "
      "Roston.");

    set_exits( ([ 
	"south" : ROOMS "roston30",
	"west"  : ROOMS "roston32",
	"east"  : ROOMS "roston33"]));

}
void reset() {

    if(!present("snake"))
    {
	new(MOB "snake")->move(this_object());
    }

}                                                                                       
