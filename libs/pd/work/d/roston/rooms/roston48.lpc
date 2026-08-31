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
    set_long("The carven walls have began to crack, the ice seems "
      "to have melted away.  There is a huge crack in the wall, and "
      "moisture in the air.");
    set_exits(([  "crack" : ROOMS "roston49",
	"south" : ROOMS "roston46",]));
}
void reset() {               

    ::reset();
    if(!present("dragon"))
    {
	new(MOB "dragon")->move(this_object());
    }

}                           
