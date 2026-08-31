#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The path seems to grow more narrow causing the rocks to be utilized for balance or to be climbed on. The clouds above clap with thunder threatening to pour rain. From this area, a large marsh can be seen to the north. Something can be seen floating in its marshy waters.%^RESET%^");
    set_items( ([ "water": "%^BOLD%^%^BLACK%^There are dead faces in the water, these are the faces of those who came, fought and died.", "marsh": "%^RESET%^%^ORANGE%^This looks like a sad place full of death." ]) );
    set_exits( ([ "north" : MARSHROOM+"marsh_32", "south" : MARSHROOM+"marsh_34" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}
