#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^BLACK%^You have arrived at the entrance to the '%^RED%^Oculus Inferi%^BLACK%^', otherwise known as the '%^RED%^Eye of Hell%^BLACK%^'.  It is dark in this holding room and you can hear wailing and screaming coming from all directions echoing off the walls.  You look up at the hole in which you fell and see you may be able to climb out of it.\n");
    set_exits( ([ "northeast": HELLROOM+"eye_of_hell_42", "southeast": HELLROOM+"eye_of_hell_2" ]) );
}
void init() {
    ::init();
    add_action("climb_out", "climb");
}
int climb_out(string str) {
    if (!str || str != "out") return notify_fail("Climb what?\n");
    write("%^BOLD%^%^BLACK%^You climb out of the room in which you came and dig your way out of the eye of hell.");
    this_player()->move_player(ROOMS+"hamen_tomb_143");
    return 1;
}
