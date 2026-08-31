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
    set_long("This is a giant hole in the side of the mountain.  There seems "
      "to be tons of hay and food on the ground.");

    set_exits( (["west"  : ROOMS "roston37",]));
}
void reset() {               
    ::reset();

    if(!present("yetti"))
    {
	new(MOB "b_yetti")->move(this_object());
	new(MOB "b_yetti")->move(this_object());
	new(MOB "b_yetti")->move(this_object());
	new(MOB "b_yetti")->move(this_object());
    }

}                   
