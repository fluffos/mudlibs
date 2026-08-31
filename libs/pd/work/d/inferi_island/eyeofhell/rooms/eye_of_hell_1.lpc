#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^BLACK%^This is the entrance to the '%^RED%^Oculus Inferi%^BLACK%^', otherwise known as the '%^RED%^Eye of Hell%^BLACK%^'. It is dark, with a faint glow of %^RED%^fire %^BLACK%^supplying little light. One look up at the hole in the roof and it seems it could be easy to climb out of. Wailing and screaming can be heard coming from all directions.%^RESET%^");
    set_items( ([ "hole": "%^BOLD%^%^BLACK%^This is the only way out of the eye. The hole looks as if it can be climbed out of.%^RESET%^" ]) );
    set_exits( ([ "northeast": HELLROOM+"eye_of_hell_42", "southeast": HELLROOM+"eye_of_hell_2" ]) );
}
void init() {
    ::init();
    add_action("climb_out", "climb");
}
int climb_out(string str) {
    if (!str || str != "out") return notify_fail("Climb what?\n");
    write("%^BOLD%^%^BLACK%^You climb out of the room in which you came and dig your way out of the eye of hell.");
    this_player()->move_player(ROOMS+"rden_11");
    return 1;
}
