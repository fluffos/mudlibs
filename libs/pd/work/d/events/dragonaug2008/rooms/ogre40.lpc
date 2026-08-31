#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_items(([ "crystals" : "Natural formations that are translucent and multifaceted.",
    "shadows" : "They spread out from every rock and crevice.",
    ({"water","pool"}) : "Water that drips and collects in the cave.",
    "stalagmites" : "Sharp extensions of rock that stick up from the ground.",
    "stalactites" : "Sharp outcroppings of rock that hang from the ceiling.",
    "dust" : "Sparkling gold colored dust that lies on the rocks here.",
    "icicles" : "Long, sharp drippings that have slowly frozen into stalactite shape.",
    ({ "insects", "fireflies" }) : "They flit around.",
    ({ "rodents", "bats" }) : "They squeak and get out of sight as quickly as possible.",
    "rocks" : "Many small bits of rock that lie around the cave floor.",
    "wood" : "Charred completely black.",
    "sparkles" : "Whitish sparkling bits of rock.",
    "skeleton" : "It is unidentifiable.",
  ]));
    set_long("%^BOLD%^%^BLACK%^The ceiling in this part of the cave seems to be leaking large amounts of %^RESET%^%^BLUE%^water%^BOLD%^%^BLACK%^, and through that, the entire floor is covered in a shallow %^BLUE%^pool%^BOLD%^%^BLACK%^.  The dripping of %^RESET%^%^BLUE%^water droplets%^BOLD%^%^BLACK%^, mixed with adventurers sloshing through the %^BLUE%^water%^BLACK%^, make for a melodic noise loud enough to cover up the bats and rodents.  There is no way to escape the %^BLUE%^water%^BLACK%^; even boulders higher than the pool have been splashed wet.  Oddly, %^WHITE%^crystals %^BLACK%^appear only on the walls in this room, but not on the ceiling or ground.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northeast" : DRAG_ROOMS "ogre35", "southeast" : DRAG_ROOMS "ogre45" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre4", this_object()))
	new(DRAG_MOBS "ogre4")->move(this_object());
    if (!present("ogre4", this_object()))
	new(DRAG_MOBS "ogre4")->move(this_object());
    if (!present("ogre1", this_object()))
	new(DRAG_MOBS "ogre1")->move(this_object());
}
