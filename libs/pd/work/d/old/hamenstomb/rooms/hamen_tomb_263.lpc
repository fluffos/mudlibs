#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^BLACK%^It is now very dim where you walk. There is a single torch in the room and it is flickering as if there is a draft coming from somewhere.\n");
    set_items( ([ "torch": "%^BOLD%^%^BLACK%^The torch is flickering softly." ]) );
    set_exits( ([ "east": ROOMS+"hamen_tomb_261", "west": ROOMS+"hamen_tomb_265" ]) );
}
