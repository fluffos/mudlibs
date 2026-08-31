#include <sandcastle.h>
#include <std.h>

inherit ROOM;

void create() {
::create();
set_properties((["light" : 1, "night light" : 1, "indoors" : 1]) );
set_short("The Secret Sand Chamber");
set_long("Blood is splattered and painted in long lines along the walls, blobs of dried blood on the floors, and even splatter patterns on the ceiling. This seems to have been a sacrifical chamber of some sort. Either that or a make shift butchers. It sure is dark.");
set_items((["room" : "This room is almost completely painted in blood. Old spirits %^BOLD%^%^BLACK%^haunt%^RESET%^ this room.", "floor" : "Signs of heavy bleeding cover the floor.", "walls" : "Splatter patterns mark the walls, signs of violent blows, or someone being dragged, bleeding, across the walls.", "ceiling" : "There is little blood up there, but there is still some, which is discerning..."]));
set_smell("default", "The smell of blood, fresh and dry, cakes your nostrils.");
set_listen("default", "You hear a deafening silence fill this %^BOLD%^%^BLACK%^haunted%^RESET%^ %^CYAN%^room.");
set_exits( (["out" : ROOMS "sandcastle8"]) );
}
