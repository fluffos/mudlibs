#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("The Ogre King's Throne Room");
    set_long("The throne room has collapsed into nothing but ruins. Pillars and rubble litter the ground. There are hundreds of crushed ogre bits all around. There is a small passage to the south leading back out of the throne room.");
    set_exits( ([
      "out" : DRAG_ROOMS "ogrekingentrance",
    ]) );
}
