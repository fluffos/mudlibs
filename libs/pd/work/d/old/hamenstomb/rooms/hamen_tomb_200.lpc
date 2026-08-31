#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^%^YELLOW%^As you enter the room, you notice there are many writings on the walls.  Wondering still where the draft is coming from, you shiver like the torches.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'.", "torch": "%^BOLD%^%^BLACK%^The torches are flickering as if shivering from the cold." ]) );
    set_exits( ([ "east": ROOMS+"hamen_tomb_198", "west": ROOMS+"hamen_tomb_202" ]) );
    new(MON+"unwrapped_mummy")->move(this_object());
    new(MON+"wearied_one")->move(this_object());
    new(MON+"wearied_one")->move(this_object());
    new(MON+"black_vulture")->move(this_object());
}
