//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;
object ob;
void add_mon();
void create() {
    ::create();
    set_name("a cave");
    set_short("a cave");
    set_long("The dampness of the cave causes the room to be warm.  "
      "Small slivers of meat are here laying beside a small "
      "nest made from grass, straw, and twigs from the "
      "nearby forest.");
    set_smell("default", "An incredible stentch is here.");
    set_items(([
      ]));
    set_exits(([
        "out":DEN"18",
      ]));
    set_properties((["light":1,"night light":1,"cave":1,"indoors":1,]));
}

void reset() {
    ::reset();
    if(!present("rat"))
	new(MON"slimyrat")->move(this_object());
}

