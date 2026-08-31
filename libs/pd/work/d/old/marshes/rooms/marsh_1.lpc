#include <std.h>
#include <amun.h>
inherit ROOM;
object ob;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^BLACK%^Walking into the room, the sense of dread returns to you.  You hear the silence of the dead.\n");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died." ]) );
    set_exits( ([ "north" : MARSHROOM+"marsh_18", "west": MARSHROOM+"marsh_2", "southeast": MARSHROOM+"marsh_square" ]) );
}
