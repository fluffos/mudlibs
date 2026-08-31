#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^RED%^A bright red aura illuminates this room. This cave is the home of a great and giant dragon. Those who dwell in the marshes are doomed to die painfully to him. Water is dripping from the roof and there is lush grass all around. This seems to be the only place in the marsh that has vegetation.%^RESET%^");
    set_exits( ([ "out" : MARSHROOM+"BM_42" ]) );
}
void reset() {
    ::reset();
    if (!present("dragon", this_object()))
	new(MARSHMON+"dragon")->move(this_object());
}
