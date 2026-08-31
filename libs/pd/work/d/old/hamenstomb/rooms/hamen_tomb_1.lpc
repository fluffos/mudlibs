#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^YELLOW%^You walk into the pyramid and you notice there are many writings on the walls. The room is filled with light but the halls to your right and left seem to grow %^RESET%^%^ORANGE%^darker a%^BOLD%^%^BLACK%^nd darker, 
only a few torches %^WHITE%^light your way.\n");
set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'." ]) );
set_exits( ([ "west" : ROOMS+"hamen_tomb_3", "east" : ROOMS+"hamen_square" ]) );
 }
