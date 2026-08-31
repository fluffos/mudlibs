#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^WHITE%^The top of the palace is lined with columns and windows. The light from the sky above is bright and makes it harder to see at first. The King's bed lays between two pillars, and there is a stone fireplace laid at the end. A large picture of King Hamen and Queen Senamun sits above the fireplace. This room is obvioulsy one of royalty.\n");
    set_exits( ([ "down" : ROOMS+"hamen_tomb_39" ]) );
}
void reset() {
    ::reset();
    if (!present("hamen", this_object()))
	new(MON+"king_hamen")->move(this_object());
}
