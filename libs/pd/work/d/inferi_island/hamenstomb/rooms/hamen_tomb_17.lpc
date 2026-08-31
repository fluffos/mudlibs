#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^YELLOW%^The ground is not completely dirt, allowing the pure gold walls to be dimmed slightly. There are mummified corpses hanging around everywhere. A large bast stands guard at both entrances and exits. They are said to be the guardians of evil in the egyptian times. They are the protectors of the home.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'." ]) );
    set_exits( ([ "southwest" : ROOMS+"hamen_tomb_15", "northeast" : ROOMS+"mid_6", "south" : ROOMS+"lup_2", "west" : ROOMS+"hamen_tomb_19"]) );
}
void reset() {
    ::reset();
    if (!present("mummy", this_object()))
	new(MON+"unwrapped_mummy")->move(this_object());
    if (!present("mummy", this_object()))
	new(MON+"mummy")->move(this_object());
    if (!present("bast", this_object()))
	new(MON+"bast")->move(this_object());
    if (!present("bast", this_object()))
	new(MON+"bast")->move(this_object());
}
