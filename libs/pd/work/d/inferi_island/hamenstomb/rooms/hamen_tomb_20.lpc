#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^YELLOW%^The path turns back into one of a golden road. The walls are glowing with scriptures and pictures of sphinxws. This area is filled with ancient egyptians artifacts: basts, tombs, sphinx fixtures and many more things. Some of the tombs have been left opened.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'.", "sphinx" : "%^YELLOW%^The Sphinx's eyes seem to watch you as you move around the room." ]) );
    set_exits( ([ "north" : ROOMS+"hamen_tomb_22", "west" : ROOMS+"hamen_tomb_18"]) );
}
