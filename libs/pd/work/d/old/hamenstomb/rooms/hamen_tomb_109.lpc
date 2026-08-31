#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^%^YELLOW%^The light is staying unusually bright this far up in the pyramid, you notice there are many writings on the walls.  Wondering still where the draft is coming from, you shiver like the torches.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'.", "torch": "%^BOLD%^%^BLACK%^The torches are flickering as if shivering from the cold." ]) );
    set_exits( ([ "west" : ROOMS+"hamen_tomb_111", "east": ROOMS+"hamen_tomb_107", "up": ROOMS+"hamen_tomb_113" ]) );
    new(MON+"giant_lion")->move(this_object());
    new(MON+"giant_lion")->move(this_object());
}
