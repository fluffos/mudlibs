#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^An odd sort of emptiness fills this area of the caves.  There are a few rare and largely out of place stones littered around the ground, but nothing large enough to sit on.  Oddlyenough and with unknown origins, a light fills the room.  Nothing but the echoes of footsteps can be heard, save a soft buzzing sound coming from ahead.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northeast" : DRAG_ROOMS "ogre16", "southeast" : DRAG_ROOMS "ogre27" ]) );
}
