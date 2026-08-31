#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^YELLOW%^The writings on the walls seem dimmer than before, but are still noticable under the Sphinx. Cracks are beginning to form at the base of the walls. The noise in the distance is getting louder the more the path leads west. There must be some big creature to the west.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'.", "sphinx" : "%^YELLOW%^The Sphinx's eyes seem to watch you as you move around the room." ]) );
    set_exits( ([ "west" : ROOMS+"hamen_tomb_5", "east" : ROOMS+"hamen_tomb_1" ]) );
}
void reset() {
    ::reset();
    if (!present("rattlesnake", this_object()))
	new(MON+"rattlesnake")->move(this_object());
    if (!present("scorpion", this_object()))
	new(MON+"baby_red_scorpion")->move(this_object());
}
