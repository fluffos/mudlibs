#include <std.h>
#include <arlon2.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "indoors" : 1, "light" : 2, "town" : 1, "night light" : 2]) );
set_smell("default", "The smell of hay and horse manure overpowers the smell of the ocean.");
set_listen("default", "The sound of horses neighing is present.");
set_short("Arlon stables");
set_long("The stables in Arlon are very small and old fashioned in comparison to the rest of the city.  There is a small trough full of water and hay, and additional hay on the ground.  There are two fenced areas where horses can be kept.");
    set_exits( ([
       "out" : ROOMS "21",

    ]) );
set_items(([
({"trough", "water", "hay"}) : "A very old looking trough is full of water and hay.",
({"fence"}) : "There is a fence made of steel, that creates two stalls for the horses to rest in.",
]));
}
void reset() {
    ::reset();
    if(!present("horse")){
        new(MOB"horse")->move(this_object());
        new(MOB"horse")->move(this_object());
}
    if(!present("hay")){
        new(OBJ"hay")->move(this_object());
}
}

