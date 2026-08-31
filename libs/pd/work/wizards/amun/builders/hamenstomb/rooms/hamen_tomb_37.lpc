#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^WHITE%^This room is laced with pictures of royalty. Columns line the walls, and the sun windows offer a lot of light making the sculptures and the walls shine brightly. To the north, the stairs leading to the Kings bedroom can be seen. From the balcony, the lower floors of the palace can be seen to be bright and active.\n");
    set_exits( ([ "southeast": ROOMS+"hamen_tomb_36", "northeast": ROOMS+"hamen_tomb_39" ]) );
}
void reset() {
    ::reset();
    if (!present("timin", this_object()))
	new(MON+"timin")->move(this_object());
}
