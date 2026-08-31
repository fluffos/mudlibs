#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^Hundreds of grooves run the height of the wall, etched by centuries of dripping %^RESET%^%^BLUE%^water%^BOLD%^%^BLACK%^.  A lone %^RESET%^mushroom %^BOLD%^%^BLACK%^grows out from the side of a stalagmite.  Shadows twist and turn around every boulder, allowing their darkness to peek out around the cavern, only to be decimated by the %^WHITE%^crystals%^BLACK%^.  Tiny %^BLUE%^pools of water %^BLACK%^dot the floor.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "southwest" : DRAG_ROOMS "ogre73", "northwest" : DRAG_ROOMS "ogre51"]) );
}
