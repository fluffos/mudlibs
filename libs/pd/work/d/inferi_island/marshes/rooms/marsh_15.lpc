#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The path ahead splits around a tall spire. A large skull of some unknown beast rests on top it. Small puddles of dark, putrid water dot the ground. Just past the spire the path forks, one path leading to a cave that has been blocked by an avalanche and the other leading into a what looks like a graveyard. The bodies are piled on top of one another and the v%^WHITE%^u%^BLACK%^lt%^WHITE%^u%^BLACK%^r%^WHITE%^e%^BLACK%^s are rested atop them pecking at their rotting flesh.%^RESET%^");
    set_exits( ([ "southeast" : MARSHROOM+"marsh_16", "northwest" : MARSHROOM+"marsh_8" ]) );
}
void reset() {
    ::reset();
    if (!present("gnoll", this_object()))
	new(MARSHMON+"inferi_gnoll")->move(this_object());
    if (!present("nymph", this_object()))
	new(MARSHMON+"inferi_nymph")->move(this_object());
}
