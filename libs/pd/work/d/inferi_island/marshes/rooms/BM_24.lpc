#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^The path subsides causing the water to be the only way to move on. The water is shallow enough, but there are dead corpses floating around in it. The water is very mucky and looks like it will take more effort to walk through than on land. One of the corpses opens their eyes.%^RESET%^");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "water": "%^RESET%^%^BLUE%^The water is thick with mud and thick with bodies.  You see and feel dead things around you.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : MARSHROOM+"BM_48", "northeast" : MARSHROOM+"BM_50", "west" : MARSHROOM+"BM_22", "south" : MARSHROOM+"BM_20"]) );
    add_pre_exit_function("northeast", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}
