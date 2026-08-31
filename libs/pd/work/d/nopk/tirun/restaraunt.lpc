#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The Weeping Willow Restaurant");
    set("long",
        "%^GREEN%^The Weeping Willow Restaurant%^RESET%^\n" 
"Within the walls of the restaurant, a hungry adventurer "
        "can always find something to satisfy his or her hunger. A steaming "
        "is heard from the back room and the food being cooked can be smelled "
        "from here. The Weeping Willow serves the best food in Tirun.");
    set_smell("default", "The delicious smell of cooking foods fills the air.");
    set_smell("foods", "Venison, Rabbit, and some other food can be smelled.");
    set_smell("food", "Venison, Rabbit, and some other food can be smelled.");
    set_items(([
        "room"  : "The back room is where the food is prepared.",
        "walls" : "Inside these walls many adventurers have eaten their fill."
    ]));
    set_exits(([
        "out" : ROOMS + "whonin3"
    ]));
}

void reset() {
  ::reset();
    if(!present("waitress")) 
      new(MOB"waitress")->move(this_object());
}

