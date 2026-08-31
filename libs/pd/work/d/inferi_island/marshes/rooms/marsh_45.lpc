#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The path ahead splits around a tall spire. A large skull of some unknown beast rests on top it. Small puddles of dark, putrid water dot the ground. Just past the spire the path forks, one path leading to a cave that has been blocked by an avalanche and the other leading into a what looks like a graveyard. The bodies are piled on top of one another and the v%^WHITE%^u%^BLACK%^lt%^WHITE%^u%^BLACK%^r%^WHITE%^e%^BLACK%^s are rested atop them pecking at their rotting flesh.%^RESET%^");
    set_exits( ([ "east" : MARSHROOM+"marsh_46", "west" : MARSHROOM+"marsh_44" ]) );
    add_pre_exit_function("east", "sp_sap");
    add_pre_exit_function("west", "sp_sap");
}
