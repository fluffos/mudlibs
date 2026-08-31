#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^RESET%^ORANGE%^Becoming brighter again, the chill in the room becomes abundant.  Wondering still %^BOLD%^%^YELLOW%^where the draft is coming from, the torches flicker even more.\n");
    set_items( ([ "torch": "%^BOLD%^%^BLACK%^The torches are flickering faster." ]) );
    set_exits( ([ "east" : ROOMS+"hamen_tomb_71", "west": ROOMS+"hamen_tomb_67" ]) );
    new(MON+"baby_red_scorpion")->move(this_object());
    new(MON+"unwrapped_mummy")->move(this_object());
    new(MON+"unwrapped_mummy")->move(this_object());
}
