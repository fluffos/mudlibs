#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^BLACK%^Walking into the room, the sense of dread returns to you.  You hear the silence of the dead.\n");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died." ]) );
    set_exits( ([ "south" : MARSHROOM+"marsh_22", "north" : MARSHROOM+"marsh_74" ]) );
    add_pre_exit_function("north", "go_north");
}
int go_north() {
    if(!this_player()->is_player()) return 0;
    return 1;
}
