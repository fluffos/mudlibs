#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^The ceiling in this part of the cave seems to be leaking large amounts of %^RESET%^%^BLUE%^water%^BOLD%^%^BLACK%^, and through that, the entire floor is covered in a shallow %^BLUE%^pool%^BOLD%^%^BLACK%^.  The dripping of %^RESET%^%^BLUE%^water droplets%^BOLD%^%^BLACK%^, mixed with adventurers sloshing through the %^BLUE%^water%^BLACK%^, make for a melodic noise loud enough to cover up the bats and rodents.  There is no way to escape the %^BLUE%^water%^BLACK%^; even boulders higher than the pool have been splashed wet.  Oddly, %^WHITE%^crystals %^BLACK%^appear only on the walls in this room, but not on the ceiling or ground.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "west" : DRAG_ROOMS "ogre14", "southwest" : DRAG_ROOMS "ogre20",
      "east" : DRAG_ROOMS"py/entrance",
    ]) );
}
void reset() {
    ::reset();
    if (!present("ogre1", this_object()))
	new(DRAG_MOBS "ogre1")->move(this_object());
    if (!present("ogre2", this_object()))
	new(DRAG_MOBS "ogre2")->move(this_object());
}
