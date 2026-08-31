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
    set_long("%^BOLD%^%^BLACK%^A crystalline light system seems to be, for the most part, absent from this room.  A faint concentration of %^RESET%^%^ORANGE%^gold flickering dust %^BOLD%^%^BLACK%^can be seen fluttering from the cracks in the ceiling to the floor, %^RESET%^%^ORANGE%^lighting %^BOLD%^%^BLACK%^up a tolerable path through the cave.  A bat screeches and winds through cracks in the ceiling, bouncing back and forth on the cave walls as a symphony of sound.  Sitting side by side is a couple of boulders covered in %^YELLOW%^glittering gold%^BLACK%^.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northwest" : DRAG_ROOMS "ogre99", "southeast" : DRAG_ROOMS "ogre123" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre6", this_object()))
	new(DRAG_MOBS "ogre6")->move(this_object());
    if (!present("ogre4", this_object()))
	new(DRAG_MOBS "ogre4")->move(this_object());
    if (!present("ogre7", this_object()))
	new(DRAG_MOBS "ogre7")->move(this_object());
    if (!present("ogre9", this_object()))
	new(DRAG_MOBS "ogre9")->move(this_object());
}
