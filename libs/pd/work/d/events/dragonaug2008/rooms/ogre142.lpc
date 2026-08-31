#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_no_clean(1);
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
    set_long("%^BOLD%^%^WHITE%^The light in this turn of the cave is so overpowering that even some creatures would need to cover their eyes.  An absence of regular stone and an excess of white crystals create a blinding aura which is inescapable.  There are %^YELLOW%^golden flakes %^WHITE%^littering every inch of the room, which adds to the visual discomfort.  Although there are no shadows in this room, an odd sense that there are lurkers remain.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northeast" : DRAG_ROOMS "ogre133" ]) );
}
void reset() {
    ::reset();
  if (!sizeof(children(DRAG_ITEMS+"crystal_statue")) && DRAG_D->query_data("canloadcrystaldragon") == 1)
    load_object(DRAG_ITEMS+"crystal_statue")->move(this_object());
}
