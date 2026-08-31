#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^BLACK%^As you leave the docks, you notice there are more dead faces in the waters around you.  Feeling a little uneasy, you continue forward.  You hear a giant roar coming from somewhere past the marsh.\n");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died." ]) );
    set_exits( ([ "north" : MARSHROOM+"entrance2", "southwest": MARSHROOM+"docks" ]) );
}
