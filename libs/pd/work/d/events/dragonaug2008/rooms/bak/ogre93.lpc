#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^The ceiling in this stretch of rock creeps down to the ground, barely presenting a passage out.  Without a second glance, this could be a dead end.  Rodents scurry between the opening, squeaking back and forth.  The %^WHITE%^white crystals %^BLACK%^seem to be in a less concentrated state toward the opening.  %^WHITE%^Light %^BLACK%^invades the room through numerous holes in the slanting ceiling.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northeast" : DRAG_ROOMS "ogre76", "west" : DRAG_ROOMS "ogre92" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre3", this_object()))
	new(DRAG_MOBS "ogre3")->move(this_object());
    if (!present("ogre2", this_object()))
	new(DRAG_MOBS "ogre2")->move(this_object());
    if (!present("ogre1", this_object()))
	new(DRAG_MOBS "ogre1")->move(this_object());
}
