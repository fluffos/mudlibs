//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;
int done;
void create() {
    ::create();
    set_name("a cave");
    set_short("a cave");
    set_long("The dampness of the cave causes the room to be warm.  "
      "Small slivers of meat are here laying beside a small "
      "nest made from grass, straw, and twigs from the "
      "nearby forest.");
    set_smell("default", "The smell of death lingers in the air.");
    set_items(([
      ]));
    set_exits(([
	"out":DEN"8",
      ]));
    set_properties((["light":1,"night light":1,"cave":1,"indoors":1,]));
}

void reset() {
    ::reset();
    if(!present("dragon cub")) {
	new(MON"dragoncub")->move(this_object());
	new(MON"dragoncub")->move(this_object());
    }
    /* if(!present("mother dragon"))
    new(MON"motherdragon")->move(this_object());
    */
}

