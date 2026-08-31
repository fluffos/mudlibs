//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a cave");
    set_short("a cave");
    set_long("Darkness seems to be everywhere.  The ground is covered "
      "with a green mold from the dampness of the cave.  The "
      "walls of the cave are damp.  Water drips constantly "
      "from the ceiling.  A small den is to the east.");
    set_items(([
      ]));
    set_exits(([
	"south":DEN"6",
	"enter":DEN"9",
	"north":DEN"10",
      ]));
    set_properties((["light":1,"night light":1,"cave":1,"indoors":1,]));
}

