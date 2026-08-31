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
    set_long("%^BOLD%^%^BLACK%^What looks like rock formed coral sits along the sides of the cavern walls.  Hanging off of the ceiling are sharply daggered rock formed icicles daring someone to make a sound.  The area is %^RESET%^%^ORANGE%^dimly lit %^BOLD%^%^BLACK%^through a small hole in the side of the cave, but offers no help in the area of guidance.  The sides of the walls look like they've been eaten by a field of %^RESET%^%^GREEN%^moss%^BOLD%^%^BLACK%^, and also look as if they are closing inward.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "north" : DRAG_ROOMS "ogre87", "west" : DRAG_ROOMS "ogre156", "southeast" : DRAG_ROOMS "ogre112" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre5", this_object()))
	new(DRAG_MOBS "ogre5")->move(this_object());
}
