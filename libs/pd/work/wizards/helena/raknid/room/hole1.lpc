#include <std.h>
#include <hole.h>


inherit ROOM;

void create() {
  ::create();
    set_properties(([ "light" : 1, "night light" : 1, "indoors" : 1, "no bump" : 1, "no teleport" : 1, "no gate" : 1 ]));
    set_short("Raknid Hole");
    set_smell("default", "The smell of decaying and rotting flesh is extremely strong here.");
    set_listen("default", "A eerie silence, accompanied by some oddly familiar scratching sounds.");
    set_long("Upon entering this dark hole, you find not only can you stand upright in it, but its circular entrance and tunnel have been dug out long ago, ages showing on the walls. The floor is covered in a %^BOLD%^%^WHITE%^strange sticky white substance%^RESET%^. The only exits are out, and north.");
    set_items((["walls" : "Roughly dug out by someone...or something, a very long time ago. The same white sticky substance on the floor is attached to the walls as well.", "floor" : "A kind of blanket of this strange substance covers the floor. Not hard to walk on, but sticky to the touch.", "ceiling" : "With the hole dug out in a cylinder shape, the ceiling is as rougly cut out as the walls."]));
    set_exits( (["north" : ROOMS"hole2", "out" : "/wizards/detach/forbiden/rooms/room150"]) );
}
