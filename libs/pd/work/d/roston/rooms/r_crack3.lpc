#include <std.h>
#include <roston.h>
inherit ROOM;

void create() {
    ::create();
    set_name("Crack to Roston");
    set_items((["snow"   : "A very deep white snow",
	"dirt"  : "A light brown mixture"]));
    set_properties((["light":2, "night light":3]));
    set_short("Crack in roston");
    set_long("This is a great opening in the ground. It seems to "
      "lead all around the under the earth, its so nice "
      "you could stay here for ever. ");

    set_exits( ([ "up" : ROOMS "r_crack2",
	"down" : ROOMS "r_crack4" ]));
}

void reset() {
    ::reset();
    if(!present("bear"))
    {
	new(MOB"m_bear")->move(this_object());
	new(MOB"m_bear")->move(this_object());
	new(MOB"m_bear")->move(this_object());
    }
}                  
