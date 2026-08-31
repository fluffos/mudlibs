#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^RESET%^ORANGE%^You walk into the pyramid and you notice there are many writings on the walls. It is beginning to get harder to read them as it is getting darker, You may still be able to make them out.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'." ]) );
    set_exits( ([ "east" : ROOMS+"hamen_tomb_12", "west" : ROOMS+"hamen_tomb_8" ]) );
}
