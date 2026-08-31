// Coded by Whit

#include <std.h>
#include <tombar.h>
int go_out() {
    if(!this_player()->is_player()) return 0;
    return 1;
}

inherit ROOM;

void create() {
    ::create();
    set_name("Tombar temple");
    set_long("Countless pathways seem to spread out further ahead.  The darkness seems "
      "to swallow any light that tries to enter the area.  Ancient symbols cover the "
      "walls.");
    set_properties(([ "light": 1, "night light": 1 ]));
    set_smell("default", "The air is stagnant.");
    set_listen("default", "Water can be heard dripping.");
    set_exits(([
	"north" : ROOMS"2",
        "out" : ROOMS"island/3",
      ]));
    set_items(([
	"wall" : "There are several markings on the wall.",
	"markings" : "They seems to show of fierce battles that have been undertaken.",
	"ceiling" : "Water drips from the ceiling.",
      ]));

}
