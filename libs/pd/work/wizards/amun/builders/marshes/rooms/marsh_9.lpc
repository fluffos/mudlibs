#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^A large cave lies to the east, large eyes can be seen peeking out ready to attack anyone who gets too close. Deciding everything looks safe, the eyes disappear. The rocks open up to where the marshes can be seen for miles on end. Something can be seen coming out of the marshy waters and ducking behind a shrub.%^RESET%^");
    set_items( ([ "cave": "%^BOLD%^%^BLACK%^Large eyes can be seen peeking out ready to attack anyone who gets too close." ]) );
    set_exits( ([ "northwest": MARSHROOM+"marsh_10", "southeast": MARSHROOM+"marsh_8" ]) );
}
void reset() {
    ::reset();
    if (!present("dwarf", this_object()))
	new(MARSHMON+"inferi_dwarf")->move(this_object());
    if (!present("halfling", this_object()))
	new(MARSHMON+"inferi_halfling")->move(this_object());
}
