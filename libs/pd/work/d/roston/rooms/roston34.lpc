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
    set_long("There seems to be a giant hole in the face "
      "of the hill. There are very large prints on the "
      "ground, ice begins to form on the ground.");
    set_exits( ([ "south" : ROOMS "roston37",
	"north" : ROOMS "roston35",
	"east" : ROOMS "roston32"]));
}

void reset() {                       

    if(!present("yetti"))
    {
	new(MOB "yetti")->move(this_object());
    }

}              
