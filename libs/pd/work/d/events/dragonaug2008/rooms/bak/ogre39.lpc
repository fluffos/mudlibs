#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^Darkness fills this room, the only light coming artificially, through magic or torch.  Bats creep over the ceiling, squeaking violently from each and every corner of the room.  Rodents scurry throughout the ground, brushing up against un-expecting travelers.   Blackened shadows cling to the walls, showing an occasional shine of metal just beyond direct view.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "north" : DRAG_ROOMS "ogre34", "southwest" : DRAG_ROOMS "ogre43", "south" : DRAG_ROOMS "ogre44" ]) );
}
