#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Along the path, on the side of the mountain to the south, there is a small patch of shrubs engulfed in flames. In this area, there is a combined group of noises between the thunder, the v%^WHITE%^u%^BLACK%^lt%^WHITE%^u%^BLACK%^r%^WHITE%^e%^BLACK%^s and the sound of voices. The ground becomes a little slippery as a few raindrops begin to fall, making it harder to walk. A few caves can be seen up the mountain.%^RESET%^");
    set_items( ([ "shrubs": "%^BOLD%^%^BLACK%^These shrubs are blazing with fire." ]) );
    set_exits( ([ "north" : MARSHROOM+"marsh_5", "south": MARSHROOM+"marsh_7" ]) );
}
void reset() {
    ::reset();
    if (!present("halfelf", this_object()))
	new(MARSHMON+"inferi_halfelf")->move(this_object());
    if (!present("sauran", this_object()))
	new(MARSHMON+"inferi_sauran")->move(this_object());
}
