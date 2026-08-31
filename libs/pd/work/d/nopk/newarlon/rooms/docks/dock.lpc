#include <std.h>
#include <arlon2.h>
inherit DOCKS;

void create() {
::create();
set_properties( ([ "light" : 2, "town" : 1, "night light" : 2]) );
set_smell("default", "The salty smell of ocean air is everywhere.");
set_listen("default", "The sound of waves crashing and sailors can be heard here.");
set_short("Arlon Dock");
set_long("The planks of the docks seem to be very stable and preserved. Land can be seen in the ocean quite far in the distance. There are white stains here from pelicans and seagulls leaving their mark. There are wooden poles every few feet, holding the dock in place. This end of the dock seems to be a landing place for ships.");
set_letter("E");
    set_exits( ([
       "north" : ROOMS+"docks/97",

    ]) );
set_items(([
      ({"planks", "dock"}) : "The dock is made up of dark wooden planks, nearly flawless.",
            ({"land", "distance"}) : "Some future adventure waits across the ocean!",
      ({"white stains", "stains", "poop"}) : "It should be fairly obvious what these stains are.",
            ({"poles", "wooden poles"}) : "Used to regulate the height of the dock, these poles are also very fashionable.",
]));
}

