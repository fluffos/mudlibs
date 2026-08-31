#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();
    set_name("north of town square");
    set_items((["snow"   : "A very deep white snow",
	"ice"    : "A very hard and thick piece of ice",
	"dirt"  : "A light brown mixture"]));
    set_properties((["light":2, "night light":2]));
    set_short("A Cavern");
    set_long("This part of the cavern is very huge. The walls "
      "are covered with giant fragments of ice.  The walls encompass "
      "the area.");

    set_exits(([ "west" : ROOMS "roston47",]));

}                              

void reset() {

    ::reset();
    if(!present("bear"))
    {
	new(MOB "p_bear")->move(this_object());
    }

}                 
