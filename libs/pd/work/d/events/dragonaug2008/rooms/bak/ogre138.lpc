#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^WHITE%^Crystalline stalactites glitter %^BLACK%^dangerously overhead.  A faint concentration of %^YELLOW%^gold flickering dust %^BLACK%^can be seen fluttering from the cracks in the ceiling to the floor, %^YELLOW%^lighting up %^BLACK%^a tolerable path through the cave.  Thick %^WHITE%^crystallized pieces %^BLACK%^stick up from the floor at every angle.  One especially %^WHITE%^bright crystal %^BLACK%^seems almost to %^YELLOW%^glow%^BLACK%^.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northwest" : DRAG_ROOMS "ogre126", "south" : DRAG_ROOMS "ogre146", "east" : DRAG_ROOMS "ogre139" ]) );
}
