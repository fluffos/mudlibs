#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^BLACK%^It is becoming almost pitch black again.  The torches are beginning to flicker less and less the farther you move into the pyramid.\n");
    set_items( ([ "torch": "%^BOLD%^%^BLACK%^The torches are beginning flickering less." ]) );
    set_exits( ([ "east": ROOMS+"hamen_tomb_238", "west": ROOMS+"hamen_tomb_242" ]) );
}
