#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^WHITE%^This is the second level of the palace. There are stairs towards the north that lead further up the palace. There are pictures along the wall that show the family of King Hamen. The columns along the walls reach all the way up to the ceiling.%^RESET%^");
    set_exits( ([ "east" : ROOMS+"center_2", "northeast" : ROOMS+"hamen_tomb_35", "south" : ROOMS+"hamen_tomb_31", "southeast" : ROOMS+"center_1"]) );
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
