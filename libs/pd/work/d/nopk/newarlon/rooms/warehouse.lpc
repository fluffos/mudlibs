#include <std.h>
#include <arlon2.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 2, "warehouse" : 1, "night light" : 2]) );
set_smell("default", "The smell of freshly cut wood is strongly present.");
set_listen("default", "The ocean and warehouse workers can be heard.");
set_short("Arlon warehouse");
set_long("This warehouse is one very simple and very large room.  Wooden planks and boards are stacked neatly throughout it, as well as display cases and other wooden goods.  It is a very eerie building.  There are windows covering the walls looking out toward the ocean.");
    set_exits( ([
       "west" : ROOMS "roads/62",

    ]) );
set_inventory( ([ MOB"warehouseworker" : 3, ]) );
set_items(([
({"wooden planks", "planks", "boards", "wooden boards"}) : "Freshly cut wooden planks and boards are stacked neatly in piles, ready for distribution.",
({"display cases", "wooden goods"}) : "Display cases, bookcases, and shelves are conveniently stored to be space efficient.",
({"window", "windows"}) : "Large windows look out upon the ocean, bringing some peace to this place.",
]));
}
/*
void reset() {
    ::reset();
    if(!present("warehouseworker")){
        new(MOB"warehouseworker")->move(this_object());
        new(MOB"warehouseworker")->move(this_object());
}
}
*/

