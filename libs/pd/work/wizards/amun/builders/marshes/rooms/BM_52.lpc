#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Smoke has built up dramatically in this area from sporadic fires that it is hard to see. Through the smoke, v%^WHITE%^u%^BLACK%^lt%^WHITE%^u%^BLACK%^r%^WHITE%^e%^BLACK%^s can be seen swooping down picking at the dead bodies in the marsh waters. A hand can be seen grasping the earth trying to pull a dead body from the waters. A clap of thunder booms across the sky.%^RESET%^");
    set_items( ([ "hand": "%^BOLD%^%^BLACK%^The rotten hand is pulling a corpse out of the murky water.", "water": "%^RESET%^%^BLUE%^The water is thick with mud and thick with bodies.", "body": "These bodies are those of many races." ]) );
    set_exits( ([ "southeast" : MARSHROOM+"BM_62", "north" : MARSHROOM+"BM_54", "northwest" : MARSHROOM+"BM_46", "west" : MARSHROOM+"BM_44", "southwest" : MARSHROOM+"BM_4" ]) );
}
