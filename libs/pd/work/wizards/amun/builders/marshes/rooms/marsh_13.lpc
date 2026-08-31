#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^A recent rockslide has laid a small hill of rocks barring the way. The top of the small hill provides an excellent view of the surrounding areas.  The view is far from spectacular, nothing but dull gray rock as far as the eye can see.  The path remains clear on the otherside of the hill heading deeper into the mountain.%^RESET%^");
    set_exits( ([ "northeast" : MARSHROOM+"marsh_8", "southwest": MARSHROOM+"marsh_14" ]) );
}
void reset() {
    ::reset();
    if (!present("giant", this_object()))
	new(MARSHMON+"inferi_giant")->move(this_object());
    if (!present("minotaur", this_object()))
	new(MARSHMON+"inferi_minotaur")->move(this_object());
}
