#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^%^RED%^The room is all of a sudden bursting with a bright red light.  The writings on the walls are in a deep %^BLACK%^black%^RED%^.  The flooring is very loose.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'." ]) );
    set_exits( ([ "east": ROOMS+"hamen_tomb_143", "west": ROOMS+"hamen_tomb_139" ]) );
    new(MON+"bast")->move(this_object());
    new(MON+"sekhmet")->move(this_object());
    new(MON+"bast")->move(this_object());
    new(MON+"sekhmet")->move(this_object());
}
