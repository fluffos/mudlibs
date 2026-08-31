#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^YELLOW%^As you walk up towards the top of the pyramid, you notice a draft as there are windows all around you.  The pyramid is now in bright gold and you feel a royal presence.\n");
    set_items( ([ "windows": "%^BOLD%^%^CYAN%^You look out the window and see a clear bright blue sky.  It seems to always be daytime around here." ]) );
    set_exits( ([ "northwest": ROOMS+"hamen_tomb_391", "northeast": ROOMS+"hamen_tomb_392", "down": ROOMS+"hamen_tomb_387" ]) );
    new(MON+"hyu")->move(this_object());
}
