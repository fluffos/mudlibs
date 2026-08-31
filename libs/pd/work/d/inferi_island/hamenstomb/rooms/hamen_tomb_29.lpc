#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^YELLOW%^The palace walls are now directly to the north. The palace is beautiful with its %^WHITE%^white pillars %^YELLOW%^and its many nooks and gazebos. Oddly enough, the ground is now made of the %^GREEN%^greenest%^YELLOW%^ looking grass anyone has ever laid eyes on. There are gaurdians all around ensuring the saftey of the King.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'." ]) );
    set_exits( ([ "east" : ROOMS+"mid_7", "west" : ROOMS+"hamen_tomb_27", "north" : ROOMS+"hamen_tomb_31"]) );
}
void reset() {
    ::reset();
    if (!present("magi", this_object()))
	new(MON+"magi")->move(this_object());
    if (!present("sekhmet", this_object()))
	new(MON+"sekhmet")->move(this_object());
    if (!present("bast", this_object()))
	new(MON+"bast")->move(this_object());
}
