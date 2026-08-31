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
    set_long("%^BOLD%^%^BLACK%^Small %^WHITE%^sparkles %^BLACK%^trickle along the cave walls, as if there were a million %^WHITE%^f%^YELLOW%^i%^WHITE%^refli%^YELLOW%^e%^WHITE%^s%^BLACK%^ lighting the way for onlookers.  However, they %^WHITE%^sparkle so brilliantly %^BLACK%^that it is hard for onlookers to focus on anything else.  The %^BLUE%^water %^BLACK%^sings a soft song against the ground, providing more rhythm for the dancing shadows.  Despite the musty feeling, a small breeze flows in through a small hole in the side of the cave walls.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northeast" : DRAG_ROOMS "ogre120" ]) );
}
void reset() {
    ::reset();

  if(!present("light column")) {
    object col = new(DRAG_ITEMS"lightcolumn");
    if(col) col->set_number(3);
    if(col) col->move(this_object());
  }
}
