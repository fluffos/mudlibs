#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^Through every hidden crack a shadow spins the illusion of company throughout this room.  A soft buzzing can be heard all around, but the source is unknown.  Some rocks seem to be %^YELLOW%^caked in gold%^BLACK%^, but as the %^WHITE%^light from little white crystals %^BLACK%^are embedded into the ground is blocked, the shimmer vanishes and plain stone remains.  A musky scent fills the room, perhaps a sign of battle lust ahead.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "southwest" : DRAG_ROOMS "ogre107", "north" : DRAG_ROOMS "ogre79" ]) );
}
