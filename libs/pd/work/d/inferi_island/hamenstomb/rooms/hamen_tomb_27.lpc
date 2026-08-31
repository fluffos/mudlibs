#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^YELLOW%^The palace walls are now in view and not very far from this room. The walls are bare and the ground is golden like the walls. The clear path to the north is leading straight toward the King inside his palace. There is a loud moaning sound towards the south.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'." ]) );
    set_exits( ([ "east" : ROOMS+"hamen_tomb_29", "south" : ROOMS+"hamen_tomb_25"]) );
}
