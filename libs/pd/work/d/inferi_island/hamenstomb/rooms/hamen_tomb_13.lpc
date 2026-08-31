#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^YELLOW%^The path seems to be made of dirt the more north it leads. The walls are still golden in color, but they look as if they are now a pure gold, real gold. This area is laid with ancient egyptians artifacts: basts, tombs, sphinx fixtures and many more things. Some of the tombs have been left opened.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'.", "sphinx" : "%^YELLOW%^The Sphinx's eyes seem to watch you as you move around the room." ]) );
    set_exits( ([ "southwest" : ROOMS+"hamen_tomb_11", "northeast" : ROOMS+"hamen_tomb_15", "south" : ROOMS+ "lup_1"]) );
}
