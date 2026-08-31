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
         "out":DEN"15",
      ]));
    set_properties((["light":1,"night light":1,"cave":1,"indoors":1,]));
}

void reset() {
    ::reset();
    if(!present("dragon cub")) {
	new(MON"dragoncub")->move(this_object());
	new(MON"dragoncub")->move(this_object());
    }
    if(!present("mother dragon"))
	new(MON"motherdragon")->move(this_object());
    if(!present("carcass"))
	add_mon();
}

void add_mon() {
    ob = new("/std/food_poisoned");
    ob->set_weight(5);
    ob->set_name("carcass");
    ob->set_id(({"carcass"}));
    ob->set_long("The carcass seems to have been here for awhile.");
    ob->set_short("a decaying carcass");
    ob->set_strength(10);
    ob->move(this_object());
}

