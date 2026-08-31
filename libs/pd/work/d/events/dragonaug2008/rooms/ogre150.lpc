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
    set_long("%^BOLD%^%^BLACK%^Shadows dance off the cave walls as if moving to a slow internal beat.  Although the darkness slinks into the corners of the area, small %^WHITE%^white crystals %^BLACK%^peek out from the crevices, allowing the cavern to be magically %^WHITE%^lit%^BLACK%^.  Tiny droplets of %^RESET%^%^BLUE%^water %^BOLD%^%^BLACK%^trickle down the maze of %^WHITE%^crystals %^BLACK%^toward a little %^BLUE%^pool %^BLACK%^on the rock floor.  The %^RESET%^%^BLUE%^water %^BOLD%^%^BLACK%^sings a soft song against the ground, providing more rhythm for the dancing shadows.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "west" : DRAG_ROOMS "ogre149", "north" : DRAG_ROOMS "ogre146", "east" : DRAG_ROOMS "ogre151", "northwest" : DRAG_ROOMS "ogre145", "northeast" : DRAG_ROOMS "ogre147", "south" : DRAG_ROOMS "ogre153" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre8", this_object()))
	new(DRAG_MOBS "ogre8")->move(this_object());
    if (!present("ogre9", this_object()))
	new(DRAG_MOBS "ogre9")->move(this_object());
    if (!present("ogre2", this_object()))
	new(DRAG_MOBS "ogre2")->move(this_object());
    if (!present("ogre3", this_object()))
	new(DRAG_MOBS "ogre3")->move(this_object());
}
