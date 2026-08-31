#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^A stretch of stalactite and stalagmite bound cave is spread out in a very dangerous fashion.  Jagged chunks of rock commonly fall to the ground from the stalactites, shattering around the room.  The stalagmites cause difficulty for traveling through; many paths lead to dead ends.  Dead rodents and bats litter the floor as victims to the falling rock.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([
      "north" : DRAG_ROOMS "ogre77",
      "down" : DRAG_ROOMS "ogrekingentrance"
    ]) );
}
void reset() {
    ::reset();
    if (!present("ogre5", this_object()))
	new(DRAG_MOBS "ogre5")->move(this_object());
    if (!present("ogre6", this_object()))
	new(DRAG_MOBS "ogre6")->move(this_object());
}
